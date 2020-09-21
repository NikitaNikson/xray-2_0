// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void Culler::SetCamera (const Camera* pkCamera)
{
    m_pkCamera = pkCamera;
}
//----------------------------------------------------------------------------
inline const Camera* Culler::GetCamera () const
{
    return m_pkCamera;
}
//----------------------------------------------------------------------------
inline const float* Culler::GetFrustum () const
{
    return m_afFrustum;
}
//----------------------------------------------------------------------------
inline VisibleSet& Culler::GetVisibleSet ()
{
    return m_kVisible;
}
//----------------------------------------------------------------------------
inline void Culler::Insert (Spatial* pkObject, Effect* pkGlobalEffect)
{
    m_kVisible.Insert(pkObject,pkGlobalEffect);
}
//----------------------------------------------------------------------------
inline int Culler::GetPlaneQuantity () const
{
    return m_iPlaneQuantity;
}
//----------------------------------------------------------------------------
inline const Plane3f* Culler::GetPlanes () const
{
    return m_akPlane;
}
//----------------------------------------------------------------------------
inline void Culler::SetPlaneState (unsigned int uiPlaneState)
{
    m_uiPlaneState = uiPlaneState;
}
//----------------------------------------------------------------------------
inline unsigned int Culler::GetPlaneState () const
{
    return m_uiPlaneState;
}
//----------------------------------------------------------------------------
inline void Culler::PushPlane (const Plane3f& rkPlane)
{
    if (m_iPlaneQuantity < VS_MAX_PLANE_QUANTITY)
    {
        // The number of user-defined planes is limited.
        m_akPlane[m_iPlaneQuantity++] = rkPlane;
    }
}
//----------------------------------------------------------------------------
inline void Culler::PopPlane ()
{
    if (m_iPlaneQuantity > Camera::VF_QUANTITY)
    {
        // Frustum planes may not be removed from the stack.
        m_iPlaneQuantity--;
    }
}
//----------------------------------------------------------------------------
