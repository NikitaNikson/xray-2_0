// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4SOFTUTILITYMCR_H
#define WM4SOFTUTILITYMCR_H

// TO DO.  Reimplement to manipulate float interpreted as an integer.

#define WM4_FLOAT_TO_INT(fFloat)\
    (int)(fFloat)

#define WM4_FLOAT_TO_UINT(fFloat)\
    (unsigned int)(fFloat)

#define WM4_UNIT_FLOAT_TO_INT(fFloat,iMaxValue)\
    (int)(fFloat*(float)iMaxValue)

#define WM4_UNIT_FLOAT_TO_UINT(fFloat,uiMaxValue)\
    (unsigned int)(fFloat*(float)uiMaxValue)

#endif
