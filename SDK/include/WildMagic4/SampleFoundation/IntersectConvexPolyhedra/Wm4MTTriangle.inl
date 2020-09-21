// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int MTTriangle::GetLabel () const
{
    return m_iLabel;
}
//----------------------------------------------------------------------------
inline int& MTTriangle::Label ()
{
    return m_iLabel;
}
//----------------------------------------------------------------------------
inline int MTTriangle::GetVertex (int i) const
{
    return m_aiVertex[i];
}
//----------------------------------------------------------------------------
inline int& MTTriangle::Vertex (int i)
{
    return m_aiVertex[i];
}
//----------------------------------------------------------------------------
inline int MTTriangle::GetEdge (int i) const
{
    return m_aiEdge[i];
}
//----------------------------------------------------------------------------
inline int& MTTriangle::Edge (int i)
{
    return m_aiEdge[i];
}
//----------------------------------------------------------------------------
inline int MTTriangle::GetAdjacent (int i) const
{
    return m_aiAdjacent[i];
}
//----------------------------------------------------------------------------
inline int& MTTriangle::Adjacent (int i)
{
    return m_aiAdjacent[i];
}
//----------------------------------------------------------------------------
