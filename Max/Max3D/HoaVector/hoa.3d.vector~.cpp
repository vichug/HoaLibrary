/*
// Copyright (c) 2012-2014 Eliott Paris, Julien Colafrancesco & Pierre Guillot, CICM, Universite Paris 8.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "../Hoa3D.max.h"

typedef struct _hoa_vector 
{
	t_pxobject              f_ob;
    double*                 f_sig_ins;
    double*                 f_sig_outs;
    Hoa3D::Vector*          f_vector;
    int                     f_mode;
	double					f_angles_of_channels[MAX_CHANNELS * 2];
	long					f_number_of_angles;
} t_hoa_vector;

void *hoa_vector_new(t_symbol *s, long argc, t_atom *argv);
void hoa_vector_free(t_hoa_vector *x);
void hoa_vector_assist(t_hoa_vector *x, void *b, long m, long a, char *s);

void hoa_vector_bang(t_hoa_vector *x);

void hoa_vector_dsp64(t_hoa_vector *x, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags);
void hoa_vector_perform64_energy(t_hoa_vector *x, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags, void *userparam);
void hoa_vector_perform64_velocity(t_hoa_vector *x, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags, void *userparam);

t_max_err angles_set(t_hoa_vector *x, t_object *attr, long argc, t_atom *argv);

t_hoa_err hoa_getinfos(t_hoa_vector* x, t_hoa_boxinfos* boxinfos);

t_class *hoa_vector_class;

int C74_EXPORT main(void)
{	

	t_class *c;
	
	c = class_new("hoa.3d.vector~", (method)hoa_vector_new, (method)hoa_vector_free, (long)sizeof(t_hoa_vector), 0L, A_GIMME, 0);
	
	hoa_initclass(c, (method)hoa_getinfos);
	
	class_addmethod(c, (method)hoa_vector_dsp64,	"dsp64",	A_CANT, 0);
	class_addmethod(c, (method)hoa_vector_assist,   "assist",	A_CANT, 0);
	
	CLASS_ATTR_DOUBLE_VARSIZE	(c, "angles", ATTR_SET_DEFER_LOW, t_hoa_vector, f_angles_of_channels, f_number_of_angles, MAX_CHANNELS*2);
	CLASS_ATTR_LABEL			(c, "angles", 0, "Angles of Channels");
	CLASS_ATTR_ACCESSORS		(c, "angles", NULL, angles_set);
	CLASS_ATTR_ORDER			(c, "angles", 0, "2");
	// @description Set the angles of each channels in degrees. Each angles are in degrees, wrapped between 0. and 360. You must specify 2 values per channel corresponding to the azimuth value followed by the elevation value.
	
	class_dspinit(c);
	class_register(CLASS_BOX, c);	
	hoa_vector_class = c;
    
	return 0;
}

void *hoa_vector_new(t_symbol *s, long argc, t_atom *argv)
{
	t_hoa_vector *x = NULL;
	int	number_of_channels = 1;
    int mode = 1;
    x = (t_hoa_vector *)object_alloc(hoa_vector_class);
	if (x)
	{		
		if(argc && (atom_gettype(argv) == A_LONG || atom_gettype(argv+1) == A_FLOAT))
			number_of_channels = atom_getlong(argv);
        if(number_of_channels < 1)
            number_of_channels = 1;
        
        if(argc > 1 && atom_gettype(argv+1) == A_SYM && atom_getsym(argv+1) == gensym("velocity"))
			mode = 0;
        
        x->f_mode = mode;
		
		x->f_vector = new Hoa3D::Vector(number_of_channels);
		
		for (int i = 0; i < 3; i++)
			outlet_new(x, "signal");
        
		dsp_setup((t_pxobject *)x, x->f_vector->getNumberOfChannels());
        x->f_sig_ins =  new double[x->f_vector->getNumberOfChannels() * SYS_MAXBLKSIZE];
        x->f_sig_outs = new double[3 * SYS_MAXBLKSIZE];
		
		x->f_number_of_angles = x->f_vector->getNumberOfChannels() * 2;
		
		for(int i = 0; i < x->f_vector->getNumberOfChannels() * 2; i+= 2)
        {
			x->f_angles_of_channels[i] = x->f_vector->getChannelAzimuth(i/2) / HOA_2PI * 360;
			x->f_angles_of_channels[i+1] = x->f_vector->getChannelElevation(i/2) / HOA_2PI * 360;
        }
		
		attr_args_process(x, argc, argv);
	}

	return (x);
}

t_hoa_err hoa_getinfos(t_hoa_vector* x, t_hoa_boxinfos* boxinfos)
{
	boxinfos->object_type = HOA_OBJECT_3D;
	boxinfos->autoconnect_inputs = x->f_vector->getNumberOfChannels();
	boxinfos->autoconnect_outputs = 0;
	boxinfos->autoconnect_inputs_type = HOA_CONNECT_TYPE_STANDARD;
	boxinfos->autoconnect_outputs_type = HOA_CONNECT_TYPE_STANDARD;
	return HOA_ERR_NONE;
}

void hoa_vector_dsp64(t_hoa_vector *x, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags)
{
    if(x->f_mode)
        object_method(dsp64, gensym("dsp_add64"), x, hoa_vector_perform64_energy, 0, NULL);
    else
        object_method(dsp64, gensym("dsp_add64"), x, hoa_vector_perform64_velocity, 0, NULL);
        
}

void hoa_vector_perform64_energy(t_hoa_vector *x, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags, void *userparam)
{
    for(int i = 0; i < numins; i++)
    {
        cblas_dcopy(sampleframes, ins[i], 1, x->f_sig_ins+i, numins);
    }
    for(int i = 0; i < sampleframes; i++)
    {
        x->f_vector->processEnergy(x->f_sig_ins + i * numins, x->f_sig_outs + i * numouts);
    }
    for(int i = 0; i < numouts; i++)
    {
        cblas_dcopy(sampleframes, x->f_sig_outs+i, numouts, outs[i], 1);
    }
}

void hoa_vector_perform64_velocity(t_hoa_vector *x, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags, void *userparam)
{
    for(int i = 0; i < numins; i++)
    {
        cblas_dcopy(sampleframes, ins[i], 1, x->f_sig_ins+i, numins);
    }
    for(int i = 0; i < sampleframes; i++)
    {
        x->f_vector->processVelocity(x->f_sig_ins + i * numins, x->f_sig_outs + i * numouts);
    }
    for(int i = 0; i < numouts; i++)
    {
        cblas_dcopy(sampleframes, x->f_sig_outs+i, numouts, outs[i], 1);
    }
}

void hoa_vector_assist(t_hoa_vector *x, void *b, long m, long a, char *s)
{
    if(m == ASSIST_INLET)
    {
        sprintf(s,"(Signal) %s", x->f_vector->getChannelName(a).c_str());
    }
    else
    {
        if(x->f_mode)
        {
            if(a == 0)
                sprintf(s,"(Signal) Energy Vector Abscissa");
            else if(a == 1)
                sprintf(s,"(Signal) Energy Vector Ordinate");
            else if(a == 2)
                sprintf(s,"(Signal) Energy Vector Height");
        }
        else
        {
            if(a == 0)
                sprintf(s,"(Signal) Velocity Vector Abscissa");
            else if(a == 1)
                sprintf(s,"(Signal) Velocity Vector Ordinate");
            else if(a == 2)
                sprintf(s,"(Signal) Velocity Vector Height");
        }
    }
}

void hoa_vector_free(t_hoa_vector *x) 
{
	dsp_free((t_pxobject *)x);
	delete x->f_vector;
    delete [] x->f_sig_ins;
    delete [] x->f_sig_outs;
}

t_max_err angles_set(t_hoa_vector *x, t_object *attr, long argc, t_atom *argv)
{
    if(argc && argv)
    {
		short dspstate = dsp_setloadupdate(false);
        for(int i = 1, j = 0; i < x->f_vector->getNumberOfChannels() * 2 && i < argc; i+= 2, j++)
        {
            if( (atom_gettype(argv+i-1) == A_FLOAT || atom_gettype(argv+i-1) == A_LONG) &&
			   (atom_gettype(argv+i) == A_FLOAT || atom_gettype(argv+i) == A_LONG) )
			{
                x->f_vector->setChannelPosition(j, atom_getfloat(argv+i-1) / 360. * HOA_2PI, atom_getfloat(argv+i) / 360. * HOA_2PI);
			}
			
			x->f_angles_of_channels[i-1] = x->f_vector->getChannelAzimuth(j) / HOA_2PI * 360;
			x->f_angles_of_channels[i] = x->f_vector->getChannelElevation(j) / HOA_2PI * 360;
        }
		dsp_setloadupdate(dspstate);
    }
    return MAX_ERR_NONE;
}