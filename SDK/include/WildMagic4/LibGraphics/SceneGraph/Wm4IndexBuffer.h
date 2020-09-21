// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4INDEXBUFFER_H
#define WM4INDEXBUFFER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4Bindable.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM IndexBuffer : public Object, public Bindable
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    IndexBuffer (int iIQuantity);
    IndexBuffer (const IndexBuffer* pkIBuffer);
    virtual ~IndexBuffer ();

    // Access to indices.
    int operator[] (int i) const;
    int& operator[] (int i);

    // Direct access to the index buffer data.  The quantity is the number of
    // int elements.  The number of bytes for the entire index buffer is
    // GetIndexQuantity()*sizeof(int).
    int GetIndexQuantity () const;
    int* GetData ();
    const int* GetData () const;

    // An application might want to vary the "active quantity" of indices.
    // Use this function to do so.  It does not change the data storage,
    // only the m_iQuantity member.  The caller is responsible for saving the
    // full quantity of indices and resetting this when finished with the
    // index buffer.  The caller also should not pass in a quantity that is
    // larger than the original full quantity.
    void SetIndexQuantity (int iIQuantity);

    // The offset into the indices is used by the renderer for drawing.  The
    // ability to set this is useful when multiple geometric primitives share
    // an index buffer, each primitive using a continguous set of indices.  In
    // this case, SetIndexQuantity and SetOffset will be called dynamically
    // during the application for each such geometric primitive.
    void SetOffset (int iOffset);
    int GetOffset () const;

protected:
    // streaming support
    IndexBuffer ();

    int m_iIQuantity;
    int* m_aiIndex;
    int m_iOffset;
};

WM4_REGISTER_STREAM(IndexBuffer);
typedef Pointer<IndexBuffer> IndexBufferPtr;
#include "Wm4IndexBuffer.inl"

}

#endif
