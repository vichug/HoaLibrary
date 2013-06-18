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

#ifndef DEF_AMBISONICS
#define DEF_AMBISONICS

#include "../CicmLibrary/CicmDefine.h"
#include "../CicmLibrary/CicmTools.h"
#include "../CicmLibrary/CicmLine.h"

class Ambisonics
{
protected:
	long	m_order;
	long	m_number_of_harmonics;
	long	m_number_of_inputs;
	long	m_number_of_outputs;
	long	m_vector_size;
    long	m_sampling_rate;

public:
	Ambisonics(long anOrder = 1, long aVectorSize = 0, double aSamplingRate = 44100.);
	long getOrder();
	long getNumberOfHarmonics();
	long getNumberOfInputs();
	long getNumberOfOutputs();
	long getVectorSize();
	long getSamplingRate();
    long getHarmonicIndex(long anIndex);
    long getHarmonicOrder(long anIndex);
    std::string  getHarmonicsName(long anIndex);
    
	void setVectorSize(long aVectorSize);
    void setSamplingRate(long aSamplingRate);

	~Ambisonics();
	
	/* Perform sample by sample */
	inline void process(float* inputs, float* outputs)
	{	
		for(int i = 0; i < m_number_of_harmonics; i++)
			outputs[i] = inputs[i];
	}
    
    /* Perform sample by sample */
	inline void process(double* inputs, double* outputs)
	{
		for(int i = 0; i < m_number_of_harmonics; i++)
			outputs[i] = inputs[i];
	}
	
	/* Perform block sample */
	inline void process(float** inputs, float** outputs)
	{
        float* input_pointor;
        float* output_pointor;
        for(int i = 0; i < m_number_of_harmonics; i++)
        {
            input_pointor = inputs[i];
            output_pointor = outputs[i];
			for(int j = 0; j < m_vector_size; j++)
            {
				output_pointor[j] = input_pointor[j];
			}
		}
	}
    
    /* Perform block sample */
	inline void process(double** inputs, double** outputs)
	{
        double* input_pointor;
        double* output_pointor;
        for(int i = 0; i < m_number_of_harmonics; i++)
        {
            input_pointor = inputs[i];
            output_pointor = outputs[i];
			for(int j = 0; j < m_vector_size; j++)
            {
				output_pointor[j] = input_pointor[j];
			}
		}
	}
};



#endif


