// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4PhysicsPCH.h"
#include "Wm4MassSpringSurface.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real, class TVector>
MassSpringSurface<Real,TVector>::MassSpringSurface (int iRows, int iCols,
    Real fStep)
    :
    ParticleSystem<Real,TVector>(iRows*iCols,fStep)
{
    m_iRows = iRows;
    m_iCols = iCols;
    m_iRowsM1 = m_iRows-1;
    m_iColsM1 = m_iCols-1;

    m_aakPosition = WM4_NEW TVector*[m_iRows];
    m_aakVelocity = WM4_NEW TVector*[m_iRows];
    for (int iRow = 0; iRow < m_iRows; iRow++)
    {
        m_aakPosition[iRow] = &m_akPosition[m_iCols*iRow];
        m_aakVelocity[iRow] = &m_akVelocity[m_iCols*iRow];
    }

    Allocate<Real>(m_iCols,m_iRowsM1,m_aafConstantR);
    Allocate<Real>(m_iCols,m_iRowsM1,m_aafLengthR);
    Allocate<Real>(m_iColsM1,m_iRows,m_aafConstantC);
    Allocate<Real>(m_iColsM1,m_iRows,m_aafLengthC);
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
MassSpringSurface<Real,TVector>::~MassSpringSurface ()
{
    WM4_DELETE[] m_aakPosition;
    WM4_DELETE[] m_aakVelocity;
    Deallocate<Real>(m_aafConstantR);
    Deallocate<Real>(m_aafLengthR);
    Deallocate<Real>(m_aafConstantC);
    Deallocate<Real>(m_aafLengthC);
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
int MassSpringSurface<Real,TVector>::GetRows () const
{
    return m_iRows;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
int MassSpringSurface<Real,TVector>::GetCols () const
{
    return m_iCols;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
void MassSpringSurface<Real,TVector>::SetMass (int iRow, int iCol, Real fMass)
{
    assert(0 <= iRow && iRow < m_iRows && 0 <= iCol && iCol < m_iCols);
    ParticleSystem<Real,TVector>::SetMass(GetIndex(iRow,iCol),fMass);
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
Real MassSpringSurface<Real,TVector>::GetMass (int iRow, int iCol) const
{
    assert(0 <= iRow && iRow < m_iRows && 0 <= iCol && iCol < m_iCols);
    return ParticleSystem<Real,TVector>::GetMass(GetIndex(iRow,iCol));
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
TVector** MassSpringSurface<Real,TVector>::Positions2D () const
{
    return m_aakPosition;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
TVector& MassSpringSurface<Real,TVector>::Position (int iRow, int iCol)
{
    assert(0 <= iRow && iRow < m_iRows && 0 <= iCol && iCol < m_iCols);
    return ParticleSystem<Real,TVector>::Position(GetIndex(iRow,iCol));
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
TVector** MassSpringSurface<Real,TVector>::Velocities2D () const
{
    return m_aakVelocity;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
TVector& MassSpringSurface<Real,TVector>::Velocity (int iRow, int iCol)
{
    assert(0 <= iRow && iRow < m_iRows && 0 <= iCol && iCol < m_iCols);
    return ParticleSystem<Real,TVector>::Velocity(GetIndex(iRow,iCol));
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
Real& MassSpringSurface<Real,TVector>::ConstantR (int iRow, int iCol)
{
    assert(0 <= iRow && iRow < m_iRows-1 && 0 <= iCol && iCol < m_iCols);
    return m_aafConstantR[iRow][iCol];
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
Real& MassSpringSurface<Real,TVector>::LengthR (int iRow, int iCol)
{
    assert(0 <= iRow && iRow < m_iRows-1 && 0 <= iCol && iCol < m_iCols);
    return m_aafLengthR[iRow][iCol];
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
Real& MassSpringSurface<Real,TVector>::ConstantC (int iRow, int iCol)
{
    assert(0 <= iRow && iRow < m_iRows && 0 <= iCol && iCol < m_iCols-1);
    return m_aafConstantC[iRow][iCol];
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
Real& MassSpringSurface<Real,TVector>::LengthC (int iRow, int iCol)
{
    assert(0 <= iRow && iRow < m_iRows && 0 <= iCol && iCol < m_iCols-1);
    return m_aafLengthC[iRow][iCol];
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
TVector MassSpringSurface<Real,TVector>::Acceleration (int i, Real fTime,
    const TVector* akPosition, const TVector* akVelocity)
{
    // Compute spring forces on position X[i].  The positions are not
    // necessarily m_akPosition since the RK4 solver in ParticleSystem
    // evaluates the acceleration function at intermediate positions.  The
    // edge and corner points of the surface of masses must be handled
    // separately since each has fewer than four springs attached to it.

    TVector kAcceleration = ExternalAcceleration(i,fTime,akPosition,
        akVelocity);

    TVector kDiff, kForce;
    Real fRatio;

    int iRow, iCol, iPrev, iNext;
    GetCoordinates(i,iRow,iCol);

    if (iRow > 0)
    {
        iPrev = i - m_iCols;  // index to previous row-neighbor
        kDiff = akPosition[iPrev] - akPosition[i];
        fRatio = LengthR(iRow-1,iCol)/kDiff.Length();
        kForce = ConstantR(iRow-1,iCol)*(((Real)1.0)-fRatio)*kDiff;
        kAcceleration += m_afInvMass[i]*kForce;
    }

    if (iRow < m_iRowsM1)
    {
        iNext = i + m_iCols;  // index to next row-neighbor
        kDiff = akPosition[iNext] - akPosition[i];
        fRatio = LengthR(iRow,iCol)/kDiff.Length();
        kForce = ConstantR(iRow,iCol)*(((Real)1.0)-fRatio)*kDiff;
        kAcceleration += m_afInvMass[i]*kForce;
    }

    if (iCol > 0)
    {
        iPrev = i - 1;  // index to previous col-neighbor
        kDiff = akPosition[iPrev] - akPosition[i];
        fRatio = LengthC(iRow,iCol-1)/kDiff.Length();
        kForce = ConstantC(iRow,iCol-1)*(((Real)1.0)-fRatio)*kDiff;
        kAcceleration += m_afInvMass[i]*kForce;
    }

    if (iCol < m_iColsM1)
    {
        iNext = i + 1;  // index to next col-neighbor
        kDiff = akPosition[iNext] - akPosition[i];
        fRatio = LengthC(iRow,iCol)/kDiff.Length();
        kForce = ConstantC(iRow,iCol)*(((Real)1.0)-fRatio)*kDiff;
        kAcceleration += m_afInvMass[i]*kForce;
    }

    return kAcceleration;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
TVector MassSpringSurface<Real,TVector>::ExternalAcceleration (int, Real,
    const TVector*, const TVector*)
{
    return TVector::ZERO;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
int MassSpringSurface<Real,TVector>::GetIndex (int iRow, int iCol) const
{
    return iCol + m_iCols*iRow;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
void MassSpringSurface<Real,TVector>::GetCoordinates (int i, int& riRow,
    int& riCol) const
{
    riCol = i % m_iCols;
    riRow = i / m_iCols;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_PHYSICS_ITEM
class MassSpringSurface<float,Vector2f>;

template WM4_PHYSICS_ITEM
class MassSpringSurface<float,Vector3f>;

template WM4_PHYSICS_ITEM
class MassSpringSurface<double,Vector2d>;

template WM4_PHYSICS_ITEM
class MassSpringSurface<double,Vector3d>;
//----------------------------------------------------------------------------
}
