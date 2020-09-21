// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MASSSPRINGVOLUME_H
#define WM4MASSSPRINGVOLUME_H

#include "Wm4PhysicsLIB.h"
#include "Wm4ParticleSystem.h"

namespace Wm4
{

template <class Real, class TVector>
class WM4_PHYSICS_ITEM MassSpringVolume : public ParticleSystem<Real,TVector>
{
public:
    // Construction and destruction.  This class represents an SxRxC array of
    // masses lying on in a volume and connected by an array of springs.  The
    // masses are indexed by mass[s][r][c] for 0 <= s < S, 0 <= r < R, and
    // 0 <= c < C.  The mass at interior position X[s][r][c] is connected by
    // springs to the masses at positions X[s][r-1][c], X[s][r+1][c],
    // X[s][r][c-1], X[s][r][c+1], X[s-1][r][c], and X[s+1][r][c].  Boundary
    // masses have springs connecting them to the obvious neighbors ("face"
    // mass has 5 neighbors, "edge" mass has 4 neighbors, "corner" mass has 3
    // neighbors).  The masses are arranged in lexicographical order:
    // position[c+C*(r+R*s)] = X[s][r][c] for 0 <= s < S, 0 <= r < R, and
    // 0 <= c < C.  The other arrays are stored similarly.
    MassSpringVolume (int iSlices, int iRows, int iCols, Real fStep);
    virtual ~MassSpringVolume ();

    int GetSlices () const;
    int GetRows () const;
    int GetCols () const;
    void SetMass (int iSlice, int iRow, int iCol, Real fMass);
    Real GetMass (int iSlice, int iRow, int iCol) const;
    TVector*** Positions3D () const;
    TVector& Position (int iSlice, int iRow, int iCol);
    TVector*** Velocities3D () const;
    TVector& Velocity (int iSlice, int iRow, int iCol);

    // Each interior mass at (s,r,c) has 6 adjacent springs.  Face masses
    // have only 5 neighbors, edge masses have only 4 neighbors, and corner
    // masses have only 3 neighbors.  Each mass provides access to 3 adjacent
    // springs at (s,r,c+1), (s,r+1,c), and (s+1,r,c).  The face, edge, and
    // corner masses provide access to only an appropriate subset of these.
    // The caller is responsible for ensuring the validity of the (s,r,c)
    // inputs.
    Real& ConstantS (int iSlice, int iRow, int iCol);  // spring to (s+1,r,c)
    Real& LengthS (int iSlice, int iRow, int iCol);    // spring to (s+1,r,c)
    Real& ConstantR (int iSlice, int iRow, int iCol);  // spring to (s,r+1,c)
    Real& LengthR (int iSlice, int iRow, int iCol);    // spring to (s,r+1,c)
    Real& ConstantC (int iSlice, int iRow, int iCol);  // spring to (s,r,c+1)
    Real& LengthC (int iSlice, int iRow, int iCol);    // spring to (s,r,c+1)

    // Callback for acceleration (ODE solver uses x" = F/m) applied to
    // particle i.  The positions and velocities are not necessarily
    // m_akPosition and m_akVelocity since the ODE solver evaluates the
    // impulse function at intermediate positions.
    virtual TVector Acceleration (int i, Real fTime,
        const TVector* akPosition, const TVector* akVelocity);

    // The default external force is zero.  Derive a class from this one to
    // provide nonzero external forces such as gravity, wind, friction,
    // and so on.  This function is called by Acceleration(...) to append the
    // acceleration F/m generated by the external force F.
    virtual TVector ExternalAcceleration (int i, Real fTime,
        const TVector* akPosition, const TVector* akVelocity);

protected:
    using ParticleSystem<Real,TVector>::m_afInvMass;
    using ParticleSystem<Real,TVector>::m_akPosition;
    using ParticleSystem<Real,TVector>::m_akVelocity;

    int GetIndex (int iSlice, int iRow, int iCol) const;
    void GetCoordinates (int i, int& riSlice, int& riRow, int& riCol) const;

    int m_iSlices;              // S
    int m_iRows;                // R
    int m_iCols;                // C
    int m_iSliceQuantity;       // R*C
    TVector*** m_aaakPosition;  // S-by-R-by-C
    TVector*** m_aaakVelocity;  // S-by-R-by-C

    int m_iSlicesM1;            // S-1
    int m_iRowsM1;              // R-1
    int m_iColsM1;              // C-1
    Real*** m_aaafConstantS;    // (S-1)-by-R-by-C
    Real*** m_aaafLengthS;      // (S-1)-by-R-by-C
    Real*** m_aaafConstantR;    // S-by-(R-1)-by-C
    Real*** m_aaafLengthR;      // S-by-(R-1)-by-C
    Real*** m_aaafConstantC;    // S-by-R-by-(C-1)
    Real*** m_aaafLengthC;      // S-by-R-by-(C-1)
};

typedef MassSpringVolume<float,Vector3f> MassSpringVolume3f;
typedef MassSpringVolume<double,Vector3d> MassSpringVolume3d;

}

#endif
