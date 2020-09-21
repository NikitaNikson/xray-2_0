// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4MAIN_H
#define WM4MAIN_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"
#include "Wm4MainMCR.h"
#include "Wm4Catalog.h"

namespace Wm4
{

class Image;
class Texture;
class VertexProgram;
class PixelProgram;

class WM4_GRAPHICS_ITEM Main
{
public:
    typedef void (*Initializer)(void);
    typedef std::vector<Initializer> InitializerArray;
    static void AddInitializer (Initializer oInitialize);
    static void Initialize ();

    typedef void (*Terminator)(void);
    typedef std::vector<Terminator> TerminatorArray;
    static void AddTerminator (Terminator oTerminate);
    static void Terminate ();

private:
    static InitializerArray* ms_pkInitializers;
    static TerminatorArray* ms_pkTerminators;
    static int ms_iStartObjects;
    static int ms_iFinalObjects;

    static Catalog<Image>* ms_pkImageCatalog;
    static Catalog<Texture>* ms_pkTextureCatalog;
    static Catalog<VertexProgram>* ms_pkVertexProgramCatalog;
    static Catalog<PixelProgram>* ms_pkPixelProgramCatalog;
};

}

#endif
