// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4SoftRendererPCH.h"
#include "Wm4SoftRenderer.h"
using namespace Wm4;

//----------------------------------------------------------------------------
bool SoftRenderer::ComputeEdgeBuffers (const int aiX[3], const int aiY[3],
    const float* aafAttr[3], int& riYMin, int& riYMax)
{
    int iDx0, iDy0, iDx1, iDy1, iDet;

    if (aiY[0] < aiY[1])
    {
        if (aiY[0] < aiY[2])
        {
            if (aiY[1] < aiY[2])
            {
                // y0 < y1 < y2
                iDx0 = aiX[1] - aiX[0];
                iDy0 = aiY[1] - aiY[0];
                iDx1 = aiX[2] - aiX[0];
                iDy1 = aiY[2] - aiY[0];
                iDet = iDx0*iDy1 - iDx1*iDy0;

                if (iDet > 0)
                {
                    // midpoint to right
                    ThreeBuffers(0,1,2,aiX,aiY,aafAttr,m_aiXMax,m_aafXMaxAttr,
                        m_aiXMin,m_aafXMinAttr,riYMin,riYMax);
                    return true;
                }

                if (iDet < 0)
                {
                    // midpoint to left
                    ThreeBuffers(0,1,2,aiX,aiY,aafAttr,m_aiXMin,m_aafXMinAttr,
                        m_aiXMax,m_aafXMaxAttr,riYMin,riYMax);
                    return true;
                }

                // degenerate triangle
                return false;
            }
            else if (aiY[1] > aiY[2])
            {
                // y0 < y2 < y1
                iDx0 = aiX[2] - aiX[0];
                iDy0 = aiY[2] - aiY[0];
                iDx1 = aiX[1] - aiX[0];
                iDy1 = aiY[1] - aiY[0];
                iDet = iDx0*iDy1 - iDx1*iDy0;

                if (iDet > 0)
                {
                    // midpoint to right
                    ThreeBuffers(0,2,1,aiX,aiY,aafAttr,m_aiXMax,m_aafXMaxAttr,
                        m_aiXMin,m_aafXMinAttr,riYMin,riYMax);
                    return true;
                }

                if (iDet < 0)
                {
                    // midpoint to left
                    ThreeBuffers(0,2,1,aiX,aiY,aafAttr,m_aiXMin,m_aafXMinAttr,
                        m_aiXMax,m_aafXMaxAttr,riYMin,riYMax);
                    return true;
                }

                // degenerate triangle
                return false;
            }
            else
            {
                // y0 < y1 = y2
                if (aiX[1] < aiX[2])
                {
                    TwoBuffers(0,1,0,2,aiX,aiY,aafAttr,riYMin,riYMax);
                    return true;
                }

                if (aiX[1] > aiX[2])
                {
                    TwoBuffers(0,2,0,1,aiX,aiY,aafAttr,riYMin,riYMax);
                    return true;
                }

                // degenerate triangle
                return false;
            }
        }
        else if (aiY[0] > aiY[2])
        {
            // y2 < y0 < y1
            iDx0 = aiX[0] - aiX[2];
            iDy0 = aiY[0] - aiY[2];
            iDx1 = aiX[1] - aiX[2];
            iDy1 = aiY[1] - aiY[2];
            iDet = iDx0*iDy1 - iDx1*iDy0;
            
            if (iDet > 0)
            {
                // midpoint to right
                ThreeBuffers(2,0,1,aiX,aiY,aafAttr,m_aiXMax,m_aafXMaxAttr,
                    m_aiXMin,m_aafXMinAttr,riYMin,riYMax);
                return true;
            }
            
            if (iDet < 0)
            {
                // midpoint to left
                ThreeBuffers(2,0,1,aiX,aiY,aafAttr,m_aiXMin,m_aafXMinAttr,
                    m_aiXMax,m_aafXMaxAttr,riYMin,riYMax);
                return true;
            }

            // degenerate triangle
            return false;
        }
        else
        {
            // y2 = y0 < y1
            if (aiX[0] < aiX[2])
            {
                TwoBuffers(0,1,2,1,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }
            
            if (aiX[0] > aiX[2])
            {
                TwoBuffers(2,1,0,1,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }
            
            // degenerate triangle
            return false;
        }
    }
    else if (aiY[0] > aiY[1])
    {
        if (aiY[0] > aiY[2])
        {
            if (aiY[1] > aiY[2])
            {
                // y2 < y1 < y0
                iDx0 = aiX[1] - aiX[2];
                iDy0 = aiY[1] - aiY[2];
                iDx1 = aiX[0] - aiX[2];
                iDy1 = aiY[0] - aiY[2];
                iDet = iDx0*iDy1 - iDx1*iDy0;
                
                if (iDet > 0)
                {
                    // midpoint to right
                    ThreeBuffers(2,1,0,aiX,aiY,aafAttr,m_aiXMax,m_aafXMaxAttr,
                        m_aiXMin,m_aafXMinAttr,riYMin,riYMax);
                    return true;
                }
                
                if (iDet < 0)
                {
                    // midpoint to left
                    ThreeBuffers(2,1,0,aiX,aiY,aafAttr,m_aiXMin,m_aafXMinAttr,
                        m_aiXMax,m_aafXMaxAttr,riYMin,riYMax);
                    return true;
                }
                
                // degenerate triangle
                return false;
            }
            else if (aiY[1] < aiY[2])
            {
                // y1 < y2 < y0
                iDx0 = aiX[2] - aiX[1];
                iDy0 = aiY[2] - aiY[1];
                iDx1 = aiX[0] - aiX[1];
                iDy1 = aiY[0] - aiY[1];
                iDet = iDx0*iDy1 - iDx1*iDy0;
                
                if (iDet > 0)
                {
                    // midpoint to right
                    ThreeBuffers(1,2,0,aiX,aiY,aafAttr,m_aiXMax,m_aafXMaxAttr,
                        m_aiXMin,m_aafXMinAttr,riYMin,riYMax);
                    return true;
                }
                
                if (iDet < 0)
                {
                    // midpoint to left
                    ThreeBuffers(1,2,0,aiX,aiY,aafAttr,m_aiXMin,m_aafXMinAttr,
                        m_aiXMax,m_aafXMaxAttr,riYMin,riYMax);
                    return true;
                }
                
                // degenerate triangle
                return false;
            }
            else
            {
                // y1 = y2 < y0
                if (aiX[1] < aiX[2])
                {
                    TwoBuffers(1,0,2,0,aiX,aiY,aafAttr,riYMin,riYMax);
                    return true;
                }
                
                if (aiX[1] > aiX[2])
                {
                    TwoBuffers(2,0,1,0,aiX,aiY,aafAttr,riYMin,riYMax);
                    return true;
                }
                
                // degenerate triangle
                return false;
            }
        }
        else if (aiY[0] < aiY[2])
        {
            // y1 < y0 < y2
            iDx0 = aiX[0] - aiX[1];
            iDy0 = aiY[0] - aiY[1];
            iDx1 = aiX[2] - aiX[1];
            iDy1 = aiY[2] - aiY[1];
            iDet = iDx0*iDy1 - iDx1*iDy0;
            
            if (iDet > 0)
            {
                // midpoint to right
                ThreeBuffers(1,0,2,aiX,aiY,aafAttr,m_aiXMax,m_aafXMaxAttr,
                    m_aiXMin,m_aafXMinAttr,riYMin,riYMax);
                return true;
            }
            
            if (iDet < 0)
            {
                // midpoint to left
                ThreeBuffers(1,0,2,aiX,aiY,aafAttr,m_aiXMin,m_aafXMinAttr,
                    m_aiXMax,m_aafXMaxAttr,riYMin,riYMax);
                return true;
            }
            
            // degenerate triangle
            return false;
        }
        else
        {
            // y1 < y0 = y2
            if (aiX[0] < aiX[2])
            {
                TwoBuffers(1,0,1,2,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }
            
            if (aiX[0] > aiX[2])
            {
                TwoBuffers(1,2,1,0,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }
            
            // degenerate triangle
            return false;
        }
    }
    else
    {
        if (aiY[2] < aiY[0])
        {
            // y2 < y1 = y0
            if (aiX[0] < aiX[1])
            {
                TwoBuffers(2,0,2,1,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }
            
            if (aiX[0] > aiX[1])
            {
                TwoBuffers(2,1,2,0,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }
            
            // degenerate triangle
            return false;
        }
        else if (aiY[2] > aiY[0])
        {
            // y1 = y0 < y2
            if (aiX[0] < aiX[1])
            {
                TwoBuffers(0,2,1,2,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }
            
            if (aiX[0] > aiX[1])
            {
                TwoBuffers(1,2,0,2,aiX,aiY,aafAttr,riYMin,riYMax);
                return true;
            }

            // degenerate triangle
            return false;
        }
        else
        {
            // y0 = y1 = y2
            // degenerate triangle
            return false;
        }
    }
}
//----------------------------------------------------------------------------
void SoftRenderer::TwoBuffers (int i0, int i1, int j0, int j1,
    const int aiX[3], const int aiY[3], const float* aafAttr[3],
    int& riYMin, int& riYMax)
{
    riYMin = aiY[i0];
    riYMax = aiY[i1];

    ComputeEdgeBuffer(aiX[i0],aiY[i0],aafAttr[i0],aiX[i1],aiY[i1],aafAttr[i1],
        m_aiXMin,m_aafXMinAttr);

    ComputeEdgeBuffer(aiX[j0],aiY[j0],aafAttr[j0],aiX[j1],aiY[j1],aafAttr[j1],
        m_aiXMax,m_aafXMaxAttr);
}
//----------------------------------------------------------------------------
void SoftRenderer::ThreeBuffers (int i0, int i1, int i2, const int aiX[3],
    const int aiY[3], const float* aafAttr[3], int* aiXExt0,
    float (*aafXAttr0)[MAX_CHANNELS], int* aiXExt1,
    float (*aafXAttr1)[MAX_CHANNELS], int& riYMin, int& riYMax)
{
    riYMin = aiY[i0];
    riYMax = aiY[i2];

    ComputeEdgeBuffer(aiX[i0],aiY[i0],aafAttr[i0],aiX[i1],aiY[i1],aafAttr[i1],
        aiXExt0,aafXAttr0);

    ComputeEdgeBuffer(aiX[i1],aiY[i1],aafAttr[i1],aiX[i2],aiY[i2],aafAttr[i2],
        aiXExt0,aafXAttr0);

    ComputeEdgeBuffer(aiX[i0],aiY[i0],aafAttr[i0],aiX[i2],aiY[i2],aafAttr[i2],
        aiXExt1,aafXAttr1);
}
//----------------------------------------------------------------------------
void SoftRenderer::ComputeEdgeBuffer (int iX0, int iY0, const float* afAttr0,
    int iX1, int iY1, const float* afAttr1, int* aiXBuffer,
    float (*aafAttrBuffer)[MAX_CHANNELS])
{
    // Assign attributes to end points of the edge buffer.
    aiXBuffer[iY0] = iX0;
    aiXBuffer[iY1] = iX1;
    int i;
    for (i = 0; i < m_iNumOutputChannels; i++)
    {
        aafAttrBuffer[iY0][i] = afAttr0[i];
        aafAttrBuffer[iY1][i] = afAttr1[i];
    }

    int iDy = iY1 - iY0;
    assert(iDy > 0);
    if (iDy == 1)
    {
        // No scan lines between the minimum and maximum to process.
        return;
    }

    PerspectiveInterpolate(afAttr0,afAttr1,iY0,iY1,aafAttrBuffer);

    // Compute the x-values for the edge buffer.
    float fInvDy = 1.0f/(float)iDy;
    int iDx = iX1 - iX0;
    int iDet = iX0*iY1 - iX1*iY0;
    float fCoeffC = iDet*fInvDy;
    float fCoeffD = iDx*fInvDy;
    for (int iY = iY0 + 1; iY < iY1; iY++)
    {
        // The addition of 0.5 causes rounding to the nearest integer.
        int iX = (int)(fCoeffC + iY*fCoeffD + 0.5f);
        if (iX < 0)
        {
            iX = 0;
        }
        else if (iX > m_iWidth)
        {
            iX = m_iWidth;
        }
        aiXBuffer[iY] = iX;
    }
}
//----------------------------------------------------------------------------
