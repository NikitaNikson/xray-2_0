// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int MTEdge::GetLabel () const
{
    return m_iLabel;
}
//----------------------------------------------------------------------------
inline int& MTEdge::Label ()
{
    return m_iLabel;
}
//----------------------------------------------------------------------------
inline int MTEdge::GetVertex (int i) const
{
    return m_aiVertex[i];
}
//----------------------------------------------------------------------------
inline int& MTEdge::Vertex (int i)
{
    return m_aiVertex[i];
}
//----------------------------------------------------------------------------
inline int MTEdge::GetTriangle (int i) const
{
    return m_aiTriangle[i];
}
//----------------------------------------------------------------------------
inline int& MTEdge::Triangle (int i)
{
    return m_aiTriangle[i];
}
//----------------------------------------------------------------------------
