// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "Wm4GraphicsPCH.h"
#include "Wm4Catalog.h"

// Create catalogs for these graphics resources.
#include "Wm4Image.h"
#include "Wm4Texture.h"
#include "Wm4PixelProgram.h"
#include "Wm4VertexProgram.h"

namespace Wm4
{
//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template class Catalog<Image>;
template<> Catalog<Image>* Catalog<Image>::ms_pkActive = 0;
template<> std::vector<Catalog<Image>*>
    Catalog<Image>::ms_apkCatalogs =
    std::vector<Catalog<Image>*>();

template class Catalog<Texture>;
template<> Catalog<Texture>* Catalog<Texture>::ms_pkActive = 0;
template<> std::vector<Catalog<Texture>*>
    Catalog<Texture>::ms_apkCatalogs =
    std::vector<Catalog<Texture>*>();

template class Catalog<PixelProgram>;
template<> Catalog<PixelProgram>* Catalog<PixelProgram>::ms_pkActive = 0;
template<> std::vector<Catalog<PixelProgram>*>
    Catalog<PixelProgram>::ms_apkCatalogs =
    std::vector<Catalog<PixelProgram>*>();

template class Catalog<VertexProgram>;
template<> Catalog<VertexProgram>* Catalog<VertexProgram>::ms_pkActive = 0;
template<> std::vector<Catalog<VertexProgram>*>
    Catalog<VertexProgram>::ms_apkCatalogs =
    std::vector<Catalog<VertexProgram>*>();
//----------------------------------------------------------------------------
}
