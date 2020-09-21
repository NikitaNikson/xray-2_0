// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4RTTI_H
#define WM4RTTI_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"
#include "Wm4RttiMCR.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Rtti
{
public:
    // The name must be unique among all objects in the system.  In the Wm4
    // namespace, a class Foo should use "Wm4.Foo".  If an application has
    // another namespace, SomeName, then the name should be "SomeName.Foo".
    Rtti (const char* acName, const Rtti* pkBaseType);
    ~Rtti ();

    const char* GetName () const;
    int GetDiskUsed () const;

    bool IsExactly (const Rtti& rkType) const;
    bool IsDerived (const Rtti& rkType) const;

private:
    const char* m_acName;
    const Rtti* m_pkBaseType;
};

#include "Wm4Rtti.inl"

}

#endif
