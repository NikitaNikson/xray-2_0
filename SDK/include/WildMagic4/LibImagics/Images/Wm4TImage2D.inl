// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
template <class T>
TImage2D<T>::TImage2D (int iXBound, int iYBound, T* atData)
    :
    TImage<T>(2)
{
    int* aiBound = WM4_NEW int[2];
    aiBound[0] = iXBound;
    aiBound[1] = iYBound;
    this->SetBounds(aiBound);
    SetData(atData);
}
//----------------------------------------------------------------------------
template <class T>
TImage2D<T>::TImage2D (const TImage2D& rkImage)
    :
    TImage<T>(rkImage)
{
}
//----------------------------------------------------------------------------
template <class T>
TImage2D<T>::TImage2D (const char* acFilename)
    :
    TImage<T>(acFilename)
{
}
//----------------------------------------------------------------------------
template <class T>
T& TImage2D<T>::operator() (int iX, int iY) const
{
    // assert:  x < bound[0] && y < bound[1]
    return m_atData[iX + this->m_aiBound[0]*iY];
}
//----------------------------------------------------------------------------
template <class T>
int TImage2D<T>::GetIndex (int iX, int iY) const
{
    // assert:  x < bound[0] && y < bound[1]
    return iX + this->m_aiBound[0]*iY;
}
//----------------------------------------------------------------------------
template <class T>
void TImage2D<T>::GetCoordinates (int iIndex, int& riX, int& riY) const
{
    // assert:  iIndex < m_iQuantity
    riX = iIndex % this->m_aiBound[0];
    riY = iIndex / this->m_aiBound[0];
}
//----------------------------------------------------------------------------
template <class T>
TImage2D<T>& TImage2D<T>::operator= (const TImage2D& rkImage)
{
    return (TImage2D<T>&) TImage<T>::operator=(rkImage);
}
//----------------------------------------------------------------------------
template <class T>
TImage2D<T>& TImage2D<T>::operator= (T tValue)
{
    return (TImage2D<T>&) TImage<T>::operator=(tValue);
}
//----------------------------------------------------------------------------
