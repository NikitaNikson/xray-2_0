// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4NAMEIDMCR_H
#define WM4NAMEIDMCR_H

//----------------------------------------------------------------------------
#define WM4_DECLARE_NAME_ID \
public: \
    virtual Object* GetObjectByName (const std::string& rkName); \
    virtual void GetAllObjectsByName (const std::string& rkName, \
        std::vector<Object*>& rkObjects); \
    virtual Object* GetObjectByID (unsigned int uiID)
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_DEFAULT_NAME_ID(classname,baseclassname) \
Object* classname::GetObjectByName (const std::string& rkName) \
{ \
    return baseclassname::GetObjectByName(rkName); \
} \
\
void classname::GetAllObjectsByName (const std::string& rkName, \
    std::vector<Object*>& rkObjects) \
{ \
    baseclassname::GetAllObjectsByName(rkName,rkObjects); \
} \
\
Object* classname::GetObjectByID (unsigned int uiID) \
{ \
    return baseclassname::GetObjectByID(uiID); \
}
//----------------------------------------------------------------------------

#endif
