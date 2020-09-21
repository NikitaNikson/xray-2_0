// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4SamplerInformation.h"
using namespace Wm4;

//----------------------------------------------------------------------------
SamplerInformation::SamplerInformation (const std::string& rkName, Type eType,
    int iTextureUnit)
    :
    m_kName(rkName)
{
    m_eType = eType;
    m_iTextureUnit = iTextureUnit;

    switch (m_eType)
    {
    case SAMPLER_1D:
        m_iDimension = 1;
        break;
    case SAMPLER_2D:
        m_iDimension = 2;
        break;
    case SAMPLER_3D:
        m_iDimension = 3;
        break;
    case SAMPLER_CUBE:
        m_iDimension = 2;
        break;
    case SAMPLER_PROJ:
        m_iDimension = 2;
        break;
    default:
        assert(false);
        m_iDimension = 0;
        break;
    }
}
//----------------------------------------------------------------------------
SamplerInformation::~SamplerInformation ()
{
}
//----------------------------------------------------------------------------
