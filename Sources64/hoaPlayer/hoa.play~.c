/**
 * HoaLibrary : A High Order Ambisonics Library
 * Copyright (c) 2012-2013 Julien Colafrancesco, Pierre Guillot, Eliott Paris, CICM, Universite Paris-8.
 * All rights reserved.
 *
 * Website  : http://www.mshparisnord.fr/hoalibrary/
 * Contacts : cicm.mshparisnord@gmail.com
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *	- Redistributions may not be sold, nor may they be used in a commercial product or activity.
 *  - Redistributions of source code must retain the above copyright notice, 
 *		this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *		this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *  - Neither the name of the CICM nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ext.h"
#include "ext_obex.h"
#include "ext_common.h"

void *play_class;

void *play_new(t_symbol *s, int argc, t_atom *argv);

int main(void)
{
	t_class *c;

	c = class_new("hoa.play~", (method)play_new, (method)NULL, (short)sizeof(0), 0L, A_GIMME, 0);
	
	class_register(CLASS_BOX, c);
	play_class = c;
	
	class_findbyname(CLASS_NOBOX, gensym("hoa.encoder~"));
}

void *play_new(t_symbol *s, int argc, t_atom *argv)
{
	t_object *x;
	t_atom arguments[1];
	int order = 4;
	if(atom_gettype(argv) == A_LONG)
		order = atom_getlong(argv);
	else if(atom_gettype(argv) == A_FLOAT)
		order = atom_getfloat(argv);

	if(order < 1)
		order = 1;
	
	atom_setlong(arguments, order * 2 + 1);
	x = (t_object *)object_new_typed(CLASS_BOX, gensym("sfplay~"), 1, arguments);
	
	return x;
}	


