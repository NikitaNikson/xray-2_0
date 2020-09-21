// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline bool Transformation::IsIdentity () const
{
    return m_bIsIdentity;
}
//----------------------------------------------------------------------------
inline bool Transformation::IsRSMatrix () const
{
    return m_bIsRSMatrix;
}
//----------------------------------------------------------------------------
inline bool Transformation::IsUniformScale () const
{
    return m_bIsRSMatrix && m_bIsUniformScale;
}
//----------------------------------------------------------------------------
inline const Matrix3f& Transformation::GetRotate () const
{
    assert(m_bIsRSMatrix);
    return m_kMatrix;
}
//----------------------------------------------------------------------------
inline const Matrix3f& Transformation::GetMatrix () const
{
    return m_kMatrix;
}
//----------------------------------------------------------------------------
inline const Vector3f& Transformation::GetTranslate () const
{
    return m_kTranslate;
}
//----------------------------------------------------------------------------
inline const Vector3f& Transformation::GetScale () const
{
    assert(m_bIsRSMatrix);
    return m_kScale;
}
//----------------------------------------------------------------------------
inline float Transformation::GetUniformScale () const
{
    assert(m_bIsRSMatrix && m_bIsUniformScale);
    return m_kScale.X();
}
//----------------------------------------------------------------------------
