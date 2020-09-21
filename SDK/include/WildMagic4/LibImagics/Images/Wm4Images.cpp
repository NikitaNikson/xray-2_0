// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4ImagicsPCH.h"
#include "Wm4Images.h"
using namespace Wm4;

// VC6 incorrectly complains that the template-class specialization for
// TImage<Eint>, TImage2D<Eint>, and TImage3D<Eint> are already instantiated.
#ifdef WM4_USING_VC6
#pragma warning(disable : 4660 )
#endif


//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wm4
{
template class WM4_IMAGICS_ITEM TImage<Echar>;
template class WM4_IMAGICS_ITEM TImage<Euchar>;
template class WM4_IMAGICS_ITEM TImage<Eshort>;
template class WM4_IMAGICS_ITEM TImage<Eushort>;
template class WM4_IMAGICS_ITEM TImage<Eint>;
template class WM4_IMAGICS_ITEM TImage<Euint>;
template class WM4_IMAGICS_ITEM TImage<Elong>;
template class WM4_IMAGICS_ITEM TImage<Eulong>;
template class WM4_IMAGICS_ITEM TImage<Efloat>;
template class WM4_IMAGICS_ITEM TImage<Edouble>;
template class WM4_IMAGICS_ITEM TImage<Ergb5>;
template class WM4_IMAGICS_ITEM TImage<Ergb8>;

template class WM4_IMAGICS_ITEM TImage2D<Echar>;
template class WM4_IMAGICS_ITEM TImage2D<Euchar>;
template class WM4_IMAGICS_ITEM TImage2D<Eshort>;
template class WM4_IMAGICS_ITEM TImage2D<Eushort>;
template class WM4_IMAGICS_ITEM TImage2D<Eint>;
template class WM4_IMAGICS_ITEM TImage2D<Euint>;
template class WM4_IMAGICS_ITEM TImage2D<Elong>;
template class WM4_IMAGICS_ITEM TImage2D<Eulong>;
template class WM4_IMAGICS_ITEM TImage2D<Efloat>;
template class WM4_IMAGICS_ITEM TImage2D<Edouble>;
template class WM4_IMAGICS_ITEM TImage2D<Ergb5>;
template class WM4_IMAGICS_ITEM TImage2D<Ergb8>;

template class WM4_IMAGICS_ITEM TImage3D<Echar>;
template class WM4_IMAGICS_ITEM TImage3D<Euchar>;
template class WM4_IMAGICS_ITEM TImage3D<Eshort>;
template class WM4_IMAGICS_ITEM TImage3D<Eushort>;
template class WM4_IMAGICS_ITEM TImage3D<Eint>;
template class WM4_IMAGICS_ITEM TImage3D<Euint>;
template class WM4_IMAGICS_ITEM TImage3D<Elong>;
template class WM4_IMAGICS_ITEM TImage3D<Eulong>;
template class WM4_IMAGICS_ITEM TImage3D<Efloat>;
template class WM4_IMAGICS_ITEM TImage3D<Edouble>;
template class WM4_IMAGICS_ITEM TImage3D<Ergb5>;
template class WM4_IMAGICS_ITEM TImage3D<Ergb8>;
}
//----------------------------------------------------------------------------
