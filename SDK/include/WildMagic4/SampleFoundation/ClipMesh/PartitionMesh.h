// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef PARTITIONMESH_H
#define PARTITIONMESH_H

#include "Wm4EdgeKey.h"
#include "Wm4Plane3.h"
using namespace Wm4;

class PartitionMesh
{
public:
    PartitionMesh (const std::vector<Vector3f>& rkVertices,
        const std::vector<int>& rkIndices, const Plane3f& rkPlane,
        std::vector<Vector3f>& rkClipVertices, std::vector<int>& rkNegIndices,
        std::vector<int>& rkPosIndices);

private:
    void ClassifyVertices (const std::vector<Vector3f>& rkClipVertices);
    void ClassifyEdges (std::vector<Vector3f>& rkClipVertices);
    void ClassifyTriangles (std::vector<Vector3f>& rkClipVertices,
        std::vector<int>& rkNegIndices, std::vector<int>& rkPosIndices);

    void AppendTriangle (std::vector<int>& rkIndices, int iV0, int iV1,
        int iV2);

    void SplitTrianglePPM (std::vector<int>& rkNegIndices,
        std::vector<int>& rkPosIndices, int iV0, int iV1, int iV2);

    void SplitTriangleMMP (std::vector<int>& rkNegIndices,
        std::vector<int>& rkPosIndices, int iV0, int iV1, int iV2);

    void SplitTrianglePMZ (std::vector<int>& rkNegIndices,
        std::vector<int>& rkPosIndices, int iV0, int iV1, int iV2);

    void SplitTriangleMPZ (std::vector<int>& rkNegIndices,
        std::vector<int>& rkPosIndices, int iV0, int iV1, int iV2);

    const std::vector<int>& m_rkIndices;
    const Plane3f& m_rkPlane;

    // Stores the signed distances from the vertices to the plane.
    std::vector<float> m_kSignedDistance;

    // Stores the edges whose vertices are on opposite sides of the
    // plane.  The key is a pair of indices into the vertex array.
    // The value is the point of intersection of the edge with the
    // plane and an index into m_kVertices (the index is larger or
    // equal to the number of vertices of incoming rkVertices).
    std::map<EdgeKey,std::pair<Vector3f, int> > m_kEMap;
};

#endif
