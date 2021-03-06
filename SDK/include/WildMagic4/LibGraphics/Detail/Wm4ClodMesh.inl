// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
inline int ClodMesh::GetRecordQuantity () const
{
    return m_spkRecordArray->GetQuantity();
}
//----------------------------------------------------------------------------
inline int& ClodMesh::TargetRecord ()
{
    return m_iTargetRecord;
}
//----------------------------------------------------------------------------
inline int ClodMesh::GetAutomatedTargetRecord ()
{
    return m_iTargetRecord;
}
//----------------------------------------------------------------------------
