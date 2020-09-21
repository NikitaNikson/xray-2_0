// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4LATTICE_H
#define WM4LATTICE_H

#include "Wm4ImagicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_IMAGICS_ITEM Lattice
{
public:
    // abstract base class for TImage
    virtual ~Lattice ();

    // data access
    int GetDimensions () const;
    const int* GetBounds () const;
    int GetBound (int i) const;
    int GetQuantity () const;
    const int* GetOffsets () const;
    int GetOffset (int i) const;

    // assignment
    Lattice& operator= (const Lattice& rkLattice);

    // comparisons
    bool operator== (const Lattice& rkLattice) const;
    bool operator!= (const Lattice& rkLattice) const;

    // Conversions between n-dim and 1-dim structures.  The coordinate arrays
    // must have the same number of elements as the dimensions of the lattice.
    int GetIndex (const int* aiCoord) const;
    void GetCoordinates (int iIndex, int* aiCoord) const;

    // streaming
    bool Load (FILE* pkIFile);
    bool Save (FILE* pkOFile) const;

    static bool LoadRaw (const char* acFilename, int& riDimensions,
        int*& raiBound, int& riQuantity, int& riRTTI, int& riSizeOf,
        char*& racData);

protected:
    // Construction.  Lattice accepts responsibility for deleting the
    // bound array.
    Lattice (int iDimensions, int* aiBound);
    Lattice (const Lattice& rkLattice);
    Lattice ();

    // For deferred creation of bounds.  Lattice accepts responsibility
    // for deleting the bound array.
    Lattice (int iDimensions);
    void SetBounds (int* aiBound);
    void ComputeQuantityAndOffsets ();

    int m_iDimensions;
    int* m_aiBound;
    int m_iQuantity;
    int* m_aiOffset;

    // streaming
    static const char* ms_acHeader;
};

#include "Wm4Lattice.inl"

}

#endif
