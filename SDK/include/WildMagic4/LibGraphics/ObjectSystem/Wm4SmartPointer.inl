// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
template <class T>
Pointer<T>::Pointer (T* pkObject)
{
    m_pkObject = pkObject;
    if (m_pkObject)
    {
        m_pkObject->IncrementReferences();
    }
}
//----------------------------------------------------------------------------
template <class T>
Pointer<T>::Pointer (const Pointer& rkPointer)
{
    m_pkObject = rkPointer.m_pkObject;
    if (m_pkObject)
    {
        m_pkObject->IncrementReferences();
    }
}
//----------------------------------------------------------------------------
template <class T>
Pointer<T>::~Pointer ()
{
    if (m_pkObject)
    {
        m_pkObject->DecrementReferences();
    }
}
//----------------------------------------------------------------------------
template <class T>
Pointer<T>::operator T* () const
{
    return m_pkObject;
}
//----------------------------------------------------------------------------
template <class T>
T& Pointer<T>::operator* () const
{
    return *m_pkObject;
}
//----------------------------------------------------------------------------
template <class T>
T* Pointer<T>::operator-> () const
{
    return m_pkObject;
}
//----------------------------------------------------------------------------
template <class T>
Pointer<T>& Pointer<T>::operator= (T* pkObject)
{
    if (m_pkObject != pkObject)
    {
        if (pkObject)
        {
            pkObject->IncrementReferences();
        }

        if (m_pkObject)
        {
            m_pkObject->DecrementReferences();
        }

        m_pkObject = pkObject;
    }
    return *this;
}
//----------------------------------------------------------------------------
template <class T>
Pointer<T>& Pointer<T>::operator= (const Pointer& rkPointer)
{
    if (m_pkObject != rkPointer.m_pkObject)
    {
        if (rkPointer.m_pkObject)
        {
            rkPointer.m_pkObject->IncrementReferences();
        }

        if (m_pkObject)
        {
            m_pkObject->DecrementReferences();
        }

        m_pkObject = rkPointer.m_pkObject;
    }
    return *this;
}
//----------------------------------------------------------------------------
template <class T>
bool Pointer<T>::operator== (T* pkObject) const
{
    return m_pkObject == pkObject;
}
//----------------------------------------------------------------------------
template <class T>
bool Pointer<T>::operator!= (T* pkObject) const
{
    return m_pkObject != pkObject;
}
//----------------------------------------------------------------------------
template <class T>
bool Pointer<T>::operator== (const Pointer& rkPointer) const
{
    return m_pkObject == rkPointer.m_pkObject;
}
//----------------------------------------------------------------------------
template <class T>
bool Pointer<T>::operator!= (const Pointer& rkPointer) const
{
    return m_pkObject != rkPointer.m_pkObject;
}
//----------------------------------------------------------------------------
