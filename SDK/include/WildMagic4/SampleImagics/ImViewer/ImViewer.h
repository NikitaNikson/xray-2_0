// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef IMVIEWER_H
#define IMVIEWER_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class ImViewer : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    ImViewer ();

    virtual bool OnPrecreate ();
    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual bool OnSpecialKeyDown (int iKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);
    virtual void ScreenOverlay ();

protected:
    bool LoadImage ();
    void CopySliceToScreen ();
    void ReadPixelValue (int iX, int iY);
    void WritePixelString ();

    int m_iDimensions, m_iQuantity, m_iSliceQuantity;
    int* m_aiBound;
    float* m_afData;
    Color* m_akData;
    float m_fMin, m_fMax, m_fRange, m_fInvRange;
    int m_iZ;
    enum { PIXEL_STR_SIZE = 256 };
    char m_acPixelStr[PIXEL_STR_SIZE];
    bool m_bMouseDown;
};

WM4_REGISTER_INITIALIZE(ImViewer);

#endif
