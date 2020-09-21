// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "ScenePrinter.h"

WM4_WINDOW_APPLICATION(ScenePrinter);

// Usage:  ScenePrinter myfile.wmof
// Output:  myfile.txt

//----------------------------------------------------------------------------
ScenePrinter::ScenePrinter ()
    :
    WindowApplication3("ScenePrinter",0,0,640,480,ColorRGBA::WHITE)
{
}
//----------------------------------------------------------------------------
bool ScenePrinter::OnInitialize ()
{
    if (WindowApplication3::OnInitialize())
    {
        char* acFilename = 0;
        if (!TheCommand->Filename(acFilename))
        {
            // There must be an input WMOF file.
            return false;
        }

        int iLength = (int)strlen(acFilename);
        if (iLength <= 5)
        {
            // The input file name is not large enough to contain the .wmof
            // extension.
            WM4_DELETE[] acFilename;
            return false;
        }

        if (acFilename[iLength-5] != '.'
        ||  acFilename[iLength-4] != 'w'
        ||  acFilename[iLength-3] != 'm'
        ||  acFilename[iLength-2] != 'o'
        ||  acFilename[iLength-1] != 'f')
        {
            // The input file does not end in the .wmof extension.
            WM4_DELETE[] acFilename;
            return false;
        }

        // Load the scene graphs.
        Stream kStream;
        if (!kStream.Load(acFilename))
        {
            // Failed to load the file.
            WM4_DELETE[] acFilename;
            return false;
        }

        // Replace the .wmof extension by the .txt extension.
        acFilename[iLength-4] = 't';
        acFilename[iLength-3] = 'x';
        acFilename[iLength-2] = 't';
        acFilename[iLength-1] = 0;

        // Update the scenes to ensure all the world data and render state
        // is current.
        for (int i = 0; i < kStream.GetObjectCount(); i++)
        {
            Spatial* pkSpatial = DynamicCast<Spatial>(kStream.GetObjectAt(i));
            if (pkSpatial)
            {
                pkSpatial->UpdateGS();
                pkSpatial->UpdateRS();
            }
        }

        if (!kStream.SaveText(acFilename))
        {
            // Failed to save the file.
            WM4_DELETE[] acFilename;
            return false;
        }
    }

    // The window is not needed, so just inform the application layer to
    // terminate.  We need to do things this way because the renderer must
    // be created in order to load shader programs.
    return false;
}
//----------------------------------------------------------------------------
