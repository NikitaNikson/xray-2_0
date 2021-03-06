// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4RASTERDRAWING_H
#define WM4RASTERDRAWING_H

#include "Wm4ImagicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

// Process the pixels visited by Bresenham's algorithm for the line segment
// with end points (x0,y0) and (x1,y1).  The callback is executed for each
// visited pixel (x,y).  The arguments to the callback are x and y.
WM4_IMAGICS_ITEM void Line2D (int iX0, int iY0, int iX1, int iY1,
    void (*oCallback)(int,int));

// Process the voxels visited by Bresenham's algorithm for the line segment
// with end points (x0,y0,z0) and (x1,y1,z1).  The callback is executed for
// each visited voxel (x,y,z).  The arguments to the callback are x, y, and z.
WM4_IMAGICS_ITEM void Line3D (int iX0, int iY0, int iZ0, int iX1, int iY1,
     int iZ1, void (*oCallback)(int,int,int));

// Process the hypervoxels visited by Bresenham's algorithm for the line
// segment with end points (x0,y0,z0,w0) and (x1,y1,z1,w1).  The callback is
// executed for each visited hypervoxel (x,y,z,w).  The arguments to the
// callback are x, y, z, and w.
WM4_IMAGICS_ITEM void Line4D (int iX0, int iY0, int iZ0, int iW0, int iX1,
     int iY1, int iZ1, int iW1, void (*oCallback)(int,int,int,int));

// Process the pixels visited by Bresenham's algorithm for the circle
// (x-xc)^2 + (y-yc)^2 = r^2.  The callback is executed for each visited
// pixel (x,y).  The arguments to the callback are x and y.
WM4_IMAGICS_ITEM void Circle2D (int iXC, int iYC, int iR,
     void (*oCallback)(int,int));

// Process the pixels visited by Bresenham's algorithm for the axis-aligned
// ellipse (x-xc)^2/a^2 + (y-yc)^2/b^2 = 1.  The callback is executed for each
// visited pixel (x,y).  The arguments to the callback are x and y.
WM4_IMAGICS_ITEM void Ellipse2D (int iXC, int iYC, int iA, int iB,
    void (*oCallback)(int,int));

// Process the pixels visited by Bresenham's algorithm for an arc of the
// axis-aligned ellipse (x-xc)^2/a^2 + (y-yc)^2/b^2 = 1.  The arc has end
// points (x0,fy0) and (x1,fy1) where (xi-xc)^2/a^2 + (yi-yc)/b^2 = 1 for
// i = 0,1.  The arc is traversed in clockwise order.  The callback is
// executed for each visited pixel (x,y).  The arguments to the callback are
// x and y.
WM4_IMAGICS_ITEM void EllipseArc2D (int iXC, int iYC, int iA, int iB,
    float fX0, float fY0, float fX1, float fY1, void (*oCallback)(int,int));

// Process the pixels visited by Bresenham's algorithm for an oriented
// ellipse.  The ellipse has shape and orientation determined by the bounding
// box with center (xc,yc) and axes (xa,ya) and (xb,yb), where theoretically
// Dot((xa,ya),(xb,yb)) = 0.  Rounding to the nearest integer will cause the
// dot product to be nonzero, yet small compared to the length of the
// cross product Cross((xa,ya,0),(xb,yb,0)) = (0,0,xa*yb-xb*ya).  This should
// not be a problem when drawing the ellipse.
WM4_IMAGICS_ITEM void GeneralEllipse2D (int iXC, int iYC, int iXA, int iYA,
    int iXB, int iYB, void (*oCallback)(int,int));

// The initial call must guarantee that the seed point (iX,iY) satisfies
// 0 <= iX < iXMax and 0 <= iY < iYMax and that aaiImage[iY][iX] is the
// background color (iBColor).  The fill color is specified by iFColor.
WM4_IMAGICS_ITEM void RecursiveFill (int iX, int iY, int iXMax, int iYMax,
    int** aaiImage, int iFColor, int iBColor);

WM4_IMAGICS_ITEM void NonrecursiveFill (int iX, int iY, int iXMax,
    int iYMax, int** aaiImage, int iFColor, int iBColor);

}

#endif
