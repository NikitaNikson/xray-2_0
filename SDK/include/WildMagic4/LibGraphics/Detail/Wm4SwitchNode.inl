// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline void SwitchNode::SetActiveChild (int iActiveChild)
{
    assert(iActiveChild == SN_INVALID_CHILD || iActiveChild < GetQuantity());
    m_iActiveChild = iActiveChild;
}
//----------------------------------------------------------------------------
inline int SwitchNode::GetActiveChild () const
{
    return m_iActiveChild;
}
//----------------------------------------------------------------------------
inline void SwitchNode::DisableAllChildren ()
{
    m_iActiveChild = SN_INVALID_CHILD;
}
//----------------------------------------------------------------------------
