// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4ClodTerrainVertex.h"
using namespace Wm4;

//----------------------------------------------------------------------------
ClodTerrainVertex::ClodTerrainVertex ()
{
    m_akDependent[0] = 0;
    m_akDependent[1] = 0;
    m_bEnabled = false;
}
//----------------------------------------------------------------------------
void ClodTerrainVertex::Enable ()
{
    m_bEnabled = true;

    if (m_akDependent[0])
    {
        if (!m_akDependent[0]->m_bEnabled)
        {
            m_akDependent[0]->Enable();
        }
    }
    
    if (m_akDependent[1])
    {
        if (!m_akDependent[1]->m_bEnabled)
        {
            m_akDependent[1]->Enable();
        }
    }
}
//----------------------------------------------------------------------------
void ClodTerrainVertex::Disable ()
{
    m_bEnabled = false;
    
    if (m_akDependent[0])
    {
        if (m_akDependent[0]->m_bEnabled)
        {
            m_akDependent[0]->Disable();
        }
    }

    if (m_akDependent[1])
    {
        if (m_akDependent[1]->m_bEnabled)
        {
            m_akDependent[1]->Disable();
        }
    }
}
//----------------------------------------------------------------------------
