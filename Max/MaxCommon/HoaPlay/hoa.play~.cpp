/*
// Copyright (c) 2012-2014 Eliott Paris, Julien Colafrancesco & Pierre Guillot, CICM, Universite Paris 8.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "HoaCommon.max.h"

t_class *play_class;

void *play_new(t_symbol *s, int argc, t_atom *argv);

int C74_EXPORT main(void)
{
	t_class *c;

	c = class_new("hoa.play~", (method)play_new, (method)NULL, (short)sizeof(0), 0L, A_GIMME, 0);
	hoa_initclass(c, NULL);
	class_register(CLASS_BOX, c);
	play_class = c;
}

void *play_new(t_symbol *s, int argc, t_atom *argv)
{
	t_object *x;
	t_atom arguments[1];
	int order = 1;
	long channels = 1;
	if(atom_gettype(argv) == A_LONG || atom_gettype(argv) == A_FLOAT)
		order = atom_getlong(argv);

	if(order < 1)
		order = 1;
	
	if (s == gensym("hoa.play") || gensym("hoa.2d.play"))
		channels = order * 2 + 1;
	else if (s == gensym("hoa.3d.play"))
		channels = (order+1) * (order+1);
	
	atom_setlong(arguments, order * 2 + 1);
	x = (t_object *)object_new_typed(CLASS_BOX, gensym("sfplay~"), 1, arguments);
	
	return x;
}


