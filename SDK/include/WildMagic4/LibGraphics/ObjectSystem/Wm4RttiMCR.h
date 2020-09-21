// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4RTTIMCR_H
#define WM4RTTIMCR_H

//----------------------------------------------------------------------------
#define WM4_DECLARE_RTTI \
public: \
    static const Rtti TYPE; \
    virtual const Rtti& GetType () const { return TYPE; }
//----------------------------------------------------------------------------
#define WM4_DECLARE_TEMPLATE_RTTI \
public: \
    WM4_GRAPHICS_ITEM static const Rtti TYPE; \
    virtual const Rtti& GetType () const { return TYPE; }
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_RTTI(nsname,classname,baseclassname) \
    const Rtti classname::TYPE(#nsname"."#classname,&baseclassname::TYPE)
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_TEMPLATE_RTTI(nsname,classname,baseclassname) \
    template <> \
    const Rtti classname::TYPE(#nsname"."#classname,&baseclassname::TYPE)
//----------------------------------------------------------------------------

#endif
