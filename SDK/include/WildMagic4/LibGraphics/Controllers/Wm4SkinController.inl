// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int SkinController::GetVertexQuantity () const
{
    return m_iVertexQuantity;
}
//----------------------------------------------------------------------------
inline int SkinController::GetBoneQuantity () const
{
    return m_iBoneQuantity;
}
//----------------------------------------------------------------------------
inline Node* SkinController::GetBone (int iBone) const
{
    assert(0 <= iBone && iBone < m_iBoneQuantity);
    return m_apkBones[iBone];
}
//----------------------------------------------------------------------------
inline float& SkinController::Weight (int iVertex, int iBone)
{
    assert(0 <= iVertex && iVertex < m_iVertexQuantity);
    assert(0 <= iBone && iBone < m_iBoneQuantity);
    return m_aafWeight[iVertex][iBone];
}
//----------------------------------------------------------------------------
inline Vector3f& SkinController::Offset (int iVertex, int iBone)
{
    assert(0 <= iVertex && iVertex < m_iVertexQuantity);
    assert(0 <= iBone && iBone < m_iBoneQuantity);
    return m_aakOffset[iVertex][iBone];
}
//----------------------------------------------------------------------------
