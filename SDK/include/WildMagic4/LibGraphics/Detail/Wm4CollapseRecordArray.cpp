// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4CollapseRecordArray.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,CollapseRecordArray,Object);
WM4_IMPLEMENT_STREAM(CollapseRecordArray);
WM4_IMPLEMENT_DEFAULT_NAME_ID(CollapseRecordArray,Object);

//----------------------------------------------------------------------------
CollapseRecordArray::CollapseRecordArray (int iQuantity,
    CollapseRecord* akArray)
{
    m_iQuantity = iQuantity;
    m_akArray = akArray;
}
//----------------------------------------------------------------------------
CollapseRecordArray::CollapseRecordArray (const CollapseRecordArray& rkShared)
{
    m_akArray = 0;
    *this = rkShared;
}
//----------------------------------------------------------------------------
CollapseRecordArray::~CollapseRecordArray ()
{
    WM4_DELETE[] m_akArray;
}
//----------------------------------------------------------------------------
CollapseRecordArray& CollapseRecordArray::operator= (
    const CollapseRecordArray& rkShared)
{
    WM4_DELETE[] m_akArray;
    m_iQuantity = rkShared.m_iQuantity;
    if (rkShared.m_akArray)
    {
        m_akArray = WM4_NEW CollapseRecord[m_iQuantity];
        for (int i = 0; i < m_iQuantity; i++)
        {
            m_akArray[i] = rkShared.m_akArray[i];
        }
    }
    else
    {
        m_akArray = 0;
    }
    return *this;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void CollapseRecordArray::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);
    rkStream.Read(m_iQuantity);
    m_akArray = WM4_NEW CollapseRecord[m_iQuantity];

    for (int i = 0; i < m_iQuantity; i++)
    {
        rkStream.Read(m_akArray[i].VKeep);
        rkStream.Read(m_akArray[i].VThrow);
        rkStream.Read(m_akArray[i].VQuantity);
        rkStream.Read(m_akArray[i].TQuantity);
        rkStream.Read(m_akArray[i].IQuantity);
        if (m_akArray[i].IQuantity > 0)
        {
            m_akArray[i].Index = WM4_NEW int[m_akArray[i].IQuantity];
            rkStream.Read(m_akArray[i].IQuantity,m_akArray[i].Index);
        }
        else
        {
            m_akArray[i].Index = 0;
        }
    }

    WM4_END_DEBUG_STREAM_LOAD(CollapseRecordArray);
}
//----------------------------------------------------------------------------
void CollapseRecordArray::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool CollapseRecordArray::Register (Stream& rkStream) const
{
    return Object::Register(rkStream);
}
//----------------------------------------------------------------------------
void CollapseRecordArray::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);
    rkStream.Write(m_iQuantity);

    for (int i = 0; i < m_iQuantity; i++)
    {
        rkStream.Write(m_akArray[i].VKeep);
        rkStream.Write(m_akArray[i].VThrow);
        rkStream.Write(m_akArray[i].VQuantity);
        rkStream.Write(m_akArray[i].TQuantity);
        rkStream.Write(m_akArray[i].IQuantity);
        if (m_akArray[i].IQuantity > 0)
        {
            rkStream.Write(m_akArray[i].IQuantity,m_akArray[i].Index);
        }
    }

    WM4_END_DEBUG_STREAM_SAVE(CollapseRecordArray);
}
//----------------------------------------------------------------------------
int CollapseRecordArray::GetDiskUsed (const StreamVersion& rkVersion) const
{
    int iSize = Object::GetDiskUsed(rkVersion) +
        sizeof(m_iQuantity);

    for (int i = 0; i < m_iQuantity; i++)
    {
        iSize += sizeof(m_akArray[i].VKeep);
        iSize += sizeof(m_akArray[i].VThrow);
        iSize += sizeof(m_akArray[i].VQuantity);
        iSize += sizeof(m_akArray[i].TQuantity);
        iSize += sizeof(m_akArray[i].IQuantity);
        iSize += m_akArray[i].IQuantity*sizeof(m_akArray[i].Index[0]);
    }

    return iSize;
}
//----------------------------------------------------------------------------
StringTree* CollapseRecordArray::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));

    // children
    pkTree->Append(Object::SaveStrings());

    StringTree* pkChild = WM4_NEW StringTree;
    pkChild->Append(Format("records"));
    pkChild->Append(Format("quantity =",m_iQuantity));
    for (int i = 0; i < m_iQuantity; i++)
    {
        const CollapseRecord& rkRecord = m_akArray[i];
        const size_t uiSize = 128;
        char* acString = WM4_NEW char[uiSize];
        System::Sprintf(acString,uiSize,
            "%d: keep = %d, throw = %d, vq = %d, tq = %d, iq = %d",i,
            rkRecord.VKeep,rkRecord.VThrow,rkRecord.VQuantity,
            rkRecord.TQuantity,rkRecord.IQuantity);

        pkChild->Append(acString);
    }
    pkTree->Append(pkChild);

    return pkTree;
}
//----------------------------------------------------------------------------
