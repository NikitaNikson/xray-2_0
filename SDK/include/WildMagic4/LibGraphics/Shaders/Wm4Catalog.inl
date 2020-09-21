// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
template <class T>
Catalog<T>::Catalog (const std::string& rkName)
    :
    m_kName(rkName)
{
    // The same name may not be used by two catalogs.
    assert(!GetCatalog(m_kName));

    ms_apkCatalogs.push_back(this);
}
//----------------------------------------------------------------------------
template <class T>
Catalog<T>::~Catalog ()
{
    typename std::vector<Catalog*>::iterator pkEnd = ms_apkCatalogs.end();
    typename std::vector<Catalog*>::iterator pkIter =
        std::find(ms_apkCatalogs.begin(),pkEnd,this);
    assert(pkIter != pkEnd);

    ms_apkCatalogs.erase(pkIter);
    if (ms_pkActive == this)
    {
        ms_pkActive = 0;
    }
}
//----------------------------------------------------------------------------
template <class T>
const std::string& Catalog<T>::GetName () const
{
    return m_kName;
}
//----------------------------------------------------------------------------
template <class T>
bool Catalog<T>::Insert (T* ptObject)
{
    if (!ptObject)
    {
        assert(false);
        return false;
    }

    // Attempt to find the object in the catalog.
    const std::string& rkName = ptObject->GetName();
    if (m_kEntry.find(rkName) != m_kEntry.end())
    {
        // The object already exists in the catalog.
        return true;
    }

    // The object does not exist in the catalog, so insert it.
    m_kEntry.insert(std::make_pair(rkName,ptObject));
    return true;
}
//----------------------------------------------------------------------------
template <class T>
bool Catalog<T>::Remove (T* ptObject)
{
    if (!ptObject)
    {
        assert(false);
        return false;
    }

    // Attempt to find the object in the catalog.
    MapIterator pkIter = m_kEntry.find(ptObject->GetName());
    if (pkIter == m_kEntry.end())
    {
        // The object does not exist in the catalog.
        return false;
    }

    // The object exists in the catalog, so remove it.
    m_kEntry.erase(pkIter);
    return true;
}
//----------------------------------------------------------------------------
template <class T>
T* Catalog<T>::Find (const std::string& rkName)
{
    // Attempt to find the object in the catalog.
    MapIterator pkIter = m_kEntry.find(rkName);
    if (pkIter != m_kEntry.end())
    {
        // The object exists in the catalog, so return it.
        return pkIter->second;
    }

    // Attempt to load the object from disk.
    T* ptObject = T::Load(rkName);
    if (ptObject)
    {
        // The object exists on disk and is already in the catalog.  The
        // (name,program) pair was automatically inserted into m_kEntry by
        // T::Load, so there is no need to insert it again explicitly.
        return ptObject;
    }

    // The program does not exist.
    return 0;
}
//----------------------------------------------------------------------------
template <class T>
bool Catalog<T>::PrintContents (const std::string& rkFilename) const
{
    const char* acDecorated = System::GetPath(rkFilename.c_str(),
        System::SM_WRITE);

    if (acDecorated)
    {
        std::ofstream kOStr(acDecorated);
        assert(kOStr);

        MapCIterator pkIter;
        for (pkIter = m_kEntry.begin(); pkIter != m_kEntry.end(); pkIter++)
        {
            // TO DO.  Implement T::PrintContents (or some such) to allow
            // a call here that writes T-specific informtion to the file.
            kOStr << pkIter->first << std::endl;
            kOStr << std::endl;
        }
        kOStr.close();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
template <class T>
void Catalog<T>::SetActive (Catalog* pkActive)
{
    ms_pkActive = pkActive;
}
//----------------------------------------------------------------------------
template <class T>
Catalog<T>* Catalog<T>::GetActive ()
{
    return ms_pkActive;
}
//----------------------------------------------------------------------------
template <class T>
Catalog<T>* Catalog<T>::GetCatalog(const std::string& rkName)
{
    typename std::vector<Catalog*>::iterator pkIter =
	    ms_apkCatalogs.begin();
    typename std::vector<Catalog*>::iterator pkEnd = ms_apkCatalogs.end();
    for (/**/; pkIter != pkEnd; ++pkIter)
    {
        if ((*pkIter)->GetName() == rkName)
        {
            return *pkIter;
        }
    }
    return 0;
}
//----------------------------------------------------------------------------
template <class T>
void Catalog<T>::SetActive(const std::string& rkName)
{
    Catalog* pkCatalog = GetCatalog(rkName);
    assert(pkCatalog);
    if(pkCatalog)
    {
        SetActive(pkCatalog);
    }
}
//----------------------------------------------------------------------------
template <class T>
bool Catalog<T>::RemoveAll (T* ptObject)
{
    bool bRemoved = false;
    typename std::vector<Catalog*>::iterator pkIter = ms_apkCatalogs.begin();
    typename std::vector<Catalog*>::iterator pkEnd = ms_apkCatalogs.end();
    for (/**/; pkIter != pkEnd; ++pkIter)
    {
        if ((*pkIter)->Remove(ptObject))
        {
            bRemoved = true;
        }
    }
    return bRemoved;
}
//----------------------------------------------------------------------------
