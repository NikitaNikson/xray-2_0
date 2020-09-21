// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4COLLAPSERECORDARRAY_H
#define WM4COLLAPSERECORDARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4CollapseRecord.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CollapseRecordArray : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    CollapseRecordArray (int iQuantity = 0, CollapseRecord* akArray = 0);
    CollapseRecordArray (const CollapseRecordArray& rkShared);
    virtual ~CollapseRecordArray ();

    CollapseRecordArray& operator= (const CollapseRecordArray& rkShared);

    int GetQuantity () const;
    CollapseRecord* GetData () const;
    operator const CollapseRecord* () const;
    operator CollapseRecord* ();
    const CollapseRecord& operator[] (int i) const;
    CollapseRecord& operator[] (int i);

protected:
    int m_iQuantity;
    CollapseRecord* m_akArray;
};

WM4_REGISTER_STREAM(CollapseRecordArray);
typedef Pointer<CollapseRecordArray> CollapseRecordArrayPtr;
#include "Wm4CollapseRecordArray.inl"

}

#endif
