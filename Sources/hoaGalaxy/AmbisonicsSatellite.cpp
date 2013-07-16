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

#include "AmbisonicsSatellite.h"

Satellite::Satellite(Star* aCentralStar, double anEllipticAngle, double aRadiusPrincipal, double aRadiusSecondary) : Star(0., 0.)
{
    m_central_star = aCentralStar;
    m_radius_principal = 0.;
    m_radius_secondary = 0.;
    m_elliptic_angle   = 0.;
    m_starting_angle   = 0.;
    m_rotation_time    = 1000.;
    setEllipse(aRadiusPrincipal, aRadiusSecondary, anEllipticAngle);
}

void Satellite::setEllipse(double anEllipticAngle, double aRadiusPrincipal, double aRadiusSecondary)
{
    setEllipticAngle(anEllipticAngle);
    setRadiusPrincipal(aRadiusPrincipal);
    setRadiusSecondary(aRadiusSecondary);
}

void Satellite::setRadiusPrincipal(double aRadius)
{
    if(m_galaxy_limit >= 0)
        m_radius_principal = Tools::clip(aRadius, 0., m_galaxy_limit - m_central_star->getRadius());
    else
        m_radius_principal = Tools::clip_min(aRadius, 0.);
    
    if(m_radius_principal < m_radius_secondary);
    {
        double aRadius = m_radius_principal;
        m_radius_principal = m_radius_secondary;
        setRadiusSecondary(aRadius);
        setEllipticAngle(m_elliptic_angle+CICM_PI2);
        setStartingAngle(m_starting_angle-CICM_PI2);
    }
}

void Satellite::setRadiusSecondary(double aRadius)
{
    
}

void Satellite::setEllipticAngle(double anAngle)
{
    m_elliptic_angle = Tools::radianWrap(anAngle);
}

void setEllipseCoordinatePolar(double anAbscissa, double anOrdinate)
{
    
}

void setEllipseCoordinateCartesian(double anAbscissa, double anOrdinate)
{
    
}

void Satellite::setStartingAngle(double anAngle)
{
    
}

void Satellite::setRotationTime(double aTimeInMs)
{
    
}

double Satellite::getRadiusPrincipal()
{
    return m_radius_principal;
}

double Satellite::getRadiusSecondary()
{
    return m_radius_secondary;
}

double Satellite::getEllipticAngle()
{
    return m_elliptic_angle;
}

double Satellite::getStartingAngle()
{
    return m_starting_angle;
}

double Satellite::getRotationTime()
{
    return m_rotation_time;
}


Satellite::~Satellite()
{
    ;
}