// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include <mach-o/dyld.h>
#include <cstdlib>
#include <cstring>

extern "C"
{

//----------------------------------------------------------------------------
void* GTGetFunctionPointer (const char* acFunction)
{
    NSSymbol kSymbol;
    char* acSymbolName;

    // Prepend a '_' for the Unix C symbol mangling convention.
    acSymbolName = (char*)malloc(strlen((const char*)acFunction) + 2);
    strcpy(acSymbolName+1,(const char*)acFunction);
    acSymbolName[0] = '_';

    kSymbol = 0;
    if (NSIsSymbolNameDefined(acSymbolName))
	{
        kSymbol = NSLookupAndBindSymbol(acSymbolName);
	}

    free(acSymbolName);
    return kSymbol ? NSAddressOfSymbol(kSymbol) : 0;
}
//----------------------------------------------------------------------------

} // extern "C"
