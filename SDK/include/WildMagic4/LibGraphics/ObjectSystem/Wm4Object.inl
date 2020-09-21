// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
// run-time type information
//----------------------------------------------------------------------------
inline const Rtti& Object::GetType () const
{
    return TYPE;
}
//----------------------------------------------------------------------------
inline bool Object::IsExactly (const Rtti& rkType) const
{
    return GetType().IsExactly(rkType);
}
//----------------------------------------------------------------------------
inline bool Object::IsDerived (const Rtti& rkType) const
{
    return GetType().IsDerived(rkType);
}
//----------------------------------------------------------------------------
inline bool Object::IsExactlyTypeOf (const Object* pkObj) const
{
    return pkObj && GetType().IsExactly(pkObj->GetType());
}
//----------------------------------------------------------------------------
inline bool Object::IsDerivedTypeOf (const Object* pkObj) const
{
    return pkObj && GetType().IsDerived(pkObj->GetType());
}
//----------------------------------------------------------------------------
template <class T>
T* StaticCast (Object* pkObj)
{
    return (T*)pkObj;
}
//----------------------------------------------------------------------------
template <class T>
const T* StaticCast (const Object* pkObj)
{
    return (const T*)pkObj;
}
//----------------------------------------------------------------------------
template <class T>
T* DynamicCast (Object* pkObj)
{
    return pkObj && pkObj->IsDerived(T::TYPE) ? (T*)pkObj : 0;
}
//----------------------------------------------------------------------------
template <class T>
const T* DynamicCast (const Object* pkObj)
{
    return pkObj && pkObj->IsDerived(T::TYPE) ? (const T*)pkObj : 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
inline void Object::SetName (const std::string& rkName)
{
    m_kName = rkName;
}
//----------------------------------------------------------------------------
inline const std::string& Object::GetName () const
{
    return m_kName;
}
//----------------------------------------------------------------------------
inline unsigned int Object::GetID () const
{
    return m_uiID;
}
//----------------------------------------------------------------------------
inline unsigned int Object::GetNextID ()
{
    return ms_uiNextID;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// smart pointers
//----------------------------------------------------------------------------
inline void Object::IncrementReferences ()
{
    m_iReferences++;
}
//----------------------------------------------------------------------------
inline int Object::GetReferences () const
{
    return m_iReferences;
}
//----------------------------------------------------------------------------
