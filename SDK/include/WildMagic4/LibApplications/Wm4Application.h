// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4APPLICATION_H
#define WM4APPLICATION_H

#include "Wm4Foundation.h"
#include "Wm4Imagics.h"
#include "Wm4Graphics.h"
#include "Wm4Physics.h"

namespace Wm4
{

class Application
{
public:
    // abstract base class
    virtual ~Application ();

    // the unique application object
    static Application* TheApplication;

    // the unique command-line arguments object
    static Command* TheCommand;

    // Derived classes must set this function pointer.  The int parameter is
    // the number of command line arguments.  The char** parameter is the
    // array of argument strings.
    typedef int (*EntryPoint)(int, char**);
    static EntryPoint Run;

    // Extra data storage to be used for platform-specific implementations.
    void SetExtraData (int iIndex, int iSize, const void* pvData);
    void GetExtraData (int iIndex, int iSize, void* pvData) const;

    bool LaunchFileDialog () const;

    // TO DO:  This feature is enabled only for Microsoft Windows.  Add the
    // feature to the other platforms.
    void LaunchTreeControl (Spatial* pkScene, int iXPos, int iYPos,
        int iXSize, int iYSize);
    void ShutdownTreeControl ();

    // For testing the disk-streaming and string-tree systems.  The input
    // object is streamed to disk and then loaded.  In a debug build, this
    // will allow 'assert' statements to trigger when there are mismatches
    // in saving and loading of data.  After loading, LaunchTreeControl is
    // called as a test of the string-tree system.  This function currently
    // is supported only on the Microsoft Windows platform.
    void TestStreaming (Spatial* pkScene, int iXPos, int iYPos, int iXSize,
        int iYSize, const char* acFilename);

protected:
    Application ();

    // extra data
    enum { APP_EXTRA_DATA_QUANTITY = 128 };
    char m_acExtraData[APP_EXTRA_DATA_QUANTITY];

    // support for file dialogs
    bool m_bLaunchFileDialog;
};

#include "Wm4ApplicationMCR.h"

}

#endif
