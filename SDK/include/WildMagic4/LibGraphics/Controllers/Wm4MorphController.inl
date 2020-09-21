// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int MorphController::GetTargetQuantity () const
{
    return m_iTargetQuantity;
}
//----------------------------------------------------------------------------
inline int MorphController::GetKeyQuantity () const
{
    return m_iKeyQuantity;
}
//----------------------------------------------------------------------------
inline void MorphController::SetVertices (int i, Vector3fArray* pkVertices)
{
    assert(0 <= i && i < m_iTargetQuantity);
    assert(pkVertices && pkVertices->GetQuantity() == m_iVertexQuantity);
    m_aspkVertices[i] = pkVertices;
}
//----------------------------------------------------------------------------
inline Vector3fArray* MorphController::GetVertices (int i) const
{
    assert(0 <= i && i < m_iTargetQuantity);
    return m_aspkVertices[i];
}
//----------------------------------------------------------------------------
inline void MorphController::SetTimes (FloatArray* pkTimes)
{
    m_spkTimes = pkTimes;
}
//----------------------------------------------------------------------------
inline FloatArray* MorphController::GetTimes () const
{
    return m_spkTimes;
}
//----------------------------------------------------------------------------
inline void MorphController::SetWeights (int i, FloatArray* pkWeights)
{
    assert(0 <= i && i < m_iKeyQuantity);
    m_aspkWeights[i] = pkWeights;
}
//----------------------------------------------------------------------------
inline FloatArray* MorphController::GetWeights (int i) const
{
    assert(0 <= i && i < m_iKeyQuantity);
    return m_aspkWeights[i];
}
//----------------------------------------------------------------------------
