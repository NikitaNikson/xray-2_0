// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4BillboardNode.h"
#include "Wm4Renderer.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,BillboardNode,Node);
WM4_IMPLEMENT_STREAM(BillboardNode);

//----------------------------------------------------------------------------
BillboardNode::BillboardNode (Camera* pkCamera)
    :
    m_spkCamera(pkCamera)
{
}
//----------------------------------------------------------------------------
BillboardNode::~BillboardNode ()
{
}
//----------------------------------------------------------------------------
void BillboardNode::UpdateWorldData (double dAppTime)
{
    // Compute billboard's world transforms based on its parent's world
    // transform and its local transforms.  Notice that you should not call
    // Node::UpdateWorldData since that function updates its children.  The
    // children of a BillboardNode cannot be updated until the billboard is
    // aligned with the camera.
    Spatial::UpdateWorldData(dAppTime);

    if (m_spkCamera)
    {
        // Inverse-transform the camera to the model space of the billboard.
        Vector3f kCLoc = World.ApplyInverse(m_spkCamera->GetLocation());

        // To align the billboard, the projection of the camera to the
        // xz-plane of the billboard's model space determines the angle of
        // rotation about the billboard's model y-axis.  If the projected
        // camera is on the model axis (x = 0 and z = 0), ATan2 returns zero
        // (rather than NaN), so there is no need to trap this degenerate
        // case and handle it separately.
        float fAngle = Mathf::ATan2(kCLoc.X(),kCLoc.Z());
        Matrix3f kOrient(Vector3f::UNIT_Y,fAngle);
        World.SetRotate(World.GetRotate()*kOrient);
    }

    // update the children now that the billboard orientation is known
    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkChild->UpdateGS(dAppTime,false);
        }
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* BillboardNode::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = Object::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkCamera)
    {
        pkFound = m_spkCamera->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void BillboardNode::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    Node::GetAllObjectsByName(rkName,rkObjects);

    if (m_spkCamera)
    {
        m_spkCamera->GetAllObjectsByName(rkName,rkObjects);
    }
}
//----------------------------------------------------------------------------
Object* BillboardNode::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = Object::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkCamera)
    {
        pkFound = m_spkCamera->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void BillboardNode::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Node::Load(rkStream,pkLink);

    // link data
    Object* pkObject;
    rkStream.Read(pkObject);  // m_spkCamera
    pkLink->Add(pkObject);

    WM4_END_DEBUG_STREAM_LOAD(BillboardNode);
}
//----------------------------------------------------------------------------
void BillboardNode::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Node::Link(rkStream,pkLink);

    Object* pkLinkID = pkLink->GetLinkID();
    m_spkCamera = (Camera*)rkStream.GetFromMap(pkLinkID);
}
//----------------------------------------------------------------------------
bool BillboardNode::Register (Stream& rkStream) const
{
    if (!Node::Register(rkStream))
    {
        return false;
    }

    if (m_spkCamera)
    {
        m_spkCamera->Register(rkStream);
    }

    return true;
}
//----------------------------------------------------------------------------
void BillboardNode::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Node::Save(rkStream);

    // link data
    rkStream.Write(m_spkCamera);

    WM4_END_DEBUG_STREAM_SAVE(BillboardNode);
}
//----------------------------------------------------------------------------
int BillboardNode::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Node::GetDiskUsed(rkVersion) +
        WM4_PTRSIZE(m_spkCamera);
}
//----------------------------------------------------------------------------
StringTree* BillboardNode::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));

    // children
    pkTree->Append(Node::SaveStrings());

    if (m_spkCamera)
    {
        pkTree->Append(m_spkCamera->SaveStrings());
    }

    return pkTree;
}
//----------------------------------------------------------------------------
