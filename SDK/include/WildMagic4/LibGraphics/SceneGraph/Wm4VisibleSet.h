// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4VISIBLESET_H
#define WM4VISIBLESET_H

#include "Wm4GraphicsLIB.h"
#include "Wm4VisibleObject.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VisibleSet
{
public:
    VisibleSet (int iMaxQuantity = 0, int iGrowBy = 0);
    virtual ~VisibleSet ();

    int GetQuantity () const;
    VisibleObject* GetVisible ();
    VisibleObject& GetVisible (int i);

    // Creates a VisibleObject from the input and appends it to the end of the
    // VisibleObject array.
    void Insert (Spatial* pkObject, Effect* pkGlobalEffect);
    void Clear ();
    void Resize (int iMaxQuantity, int iGrowBy);

private:
    enum
    {
        VS_DEFAULT_MAX_QUANTITY = 32,
        VS_DEFAULT_GROWBY = 32,
    };

    int m_iMaxQuantity, m_iGrowBy, m_iQuantity;
    VisibleObject* m_akVisible;
};

#include "Wm4VisibleSet.inl"

}

#endif
