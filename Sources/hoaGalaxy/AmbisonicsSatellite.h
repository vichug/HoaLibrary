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


#ifndef DEF_AMBISONICSSATELLITE
#define DEF_AMBISONICSSATELLITE

#include "AmbisonicsStar.h"

class Satellite : public Star
{
private:    
    double                  m_radius_principal;
    double                  m_radius_secondary;
    double                  m_elliptic_angle;
    double                  m_starting_angle;
    double                  m_rotation_time;
    
    Star*                   m_central_star;
public:
    Satellite(Star* aCentralStar, double anEllipticAngle = 0., double aRadiusPrincipal = 0., double aRadiusSecondary = 0.);

    void setEllipse(double anEllipticAngle, double aRadiusPrincipal, double aRadiusSecondary);
	void setRadiusPrincipal(double aRadius);
    void setRadiusSecondary(double aRadius);
    void setEllipticAngle(double anAngle);
    void setEllipseCoordinatePolar(double anAbscissa, double anOrdinate);
    void setEllipseCoordinateCartesian(double anAbscissa, double anOrdinate);
    
    void setStartingAngle(double anAngle);
    void setRotationTime(double aTimeInMs);
    
    double getRadiusPrincipal();
    double getRadiusSecondary();
    double getEllipticAngle();
    double getStartingAngle();
    double getRotationTime();
    
    void tick()
    {
        
    }
    
	~Satellite();
};

#endif

