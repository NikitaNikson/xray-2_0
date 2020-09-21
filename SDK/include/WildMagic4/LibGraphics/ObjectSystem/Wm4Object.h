// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4OBJECT_H
#define WM4OBJECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Main.h"
#include "Wm4Rtti.h"
#include "Wm4NameIdMCR.h"
#include "Wm4SmartPointer.h"
#include "Wm4Stream.h"
#include "Wm4StringTree.h"

namespace Wm4
{

class Controller;

class WM4_GRAPHICS_ITEM Object
{
// root class of object system
public:
    virtual ~Object ();
protected:
    Object ();

// run-time type information system
public:
    static const Rtti TYPE;
    virtual const Rtti& GetType () const;
    bool IsExactly (const Rtti& rkType) const;
    bool IsDerived (const Rtti& rkType) const;
    bool IsExactlyTypeOf (const Object* pkObject) const;
    bool IsDerivedTypeOf (const Object* pkObject) const;

// controller system
public:
    int GetControllerQuantity () const;
    Controller* GetController (int i) const;
    void AttachController (Controller* pkController);
    void DetachController (Controller* pkController);
    void DetachAllControllers ();
    bool UpdateControllers (double dAppTime);
private:
    // controllers
    std::vector<Pointer<Object> > m_kControllers;

// copying system
public:
    Pointer<Object> Copy (bool bUniqueNames = true) const;
    static char NameAppend;

// name-ID system
public:
    void SetName (const std::string& rkName);
    const std::string& GetName () const;
    unsigned int GetID () const;
    static unsigned int GetNextID ();
    virtual Object* GetObjectByName (const std::string& rkName);
    virtual void GetAllObjectsByName (const std::string& rkName,
        std::vector<Object*>& rkObjects);
    virtual Object* GetObjectByID (unsigned int uiID);
private:
    std::string m_kName;
    unsigned int m_uiID;
    static unsigned int ms_uiNextID;

// smart pointer system
public:
    void IncrementReferences ();
    void DecrementReferences ();
    int GetReferences () const;
    static THashTable<unsigned int,Object*>* InUse;
    static void PrintInUse (const char* acFilename, const char* acMessage);
private:
    int m_iReferences;

// streaming system
public:
    enum { FACTORY_MAP_SIZE = 256 };
    static TStringHashTable<FactoryFunction>* ms_pkFactory;
    static bool RegisterFactory ();
    static void InitializeFactory ();
    static void TerminateFactory ();
    static Object* Factory (Stream& rkStream);
    virtual void Load (Stream& rkStream, Stream::Link* pkLink);
    virtual void Link (Stream& rkStream, Stream::Link* pkLink);
    virtual bool PostLink () { return true; }
    virtual bool Register (Stream& rkStream) const;
    virtual void Save (Stream& rkStream) const;
    virtual int GetDiskUsed (const StreamVersion& rkVersion) const;
    virtual StringTree* SaveStrings (const char* acTitle = 0);
private:
    static bool ms_bStreamRegistered;
};

// static and dynamic type casting
template <class T> T* StaticCast (Object* pkObj);
template <class T> const T* StaticCast (const Object* pkObj);
template <class T> T* DynamicCast (Object* pkObj);
template <class T> const T* DynamicCast (const Object* pkObj);

WM4_REGISTER_STREAM(Object);
typedef Pointer<Object> ObjectPtr;
#include "Wm4Object.inl"

}

#endif
