// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#include "GTglExtensions.h"
#include <cassert>
#include <cstdio>

// Disable the MSVC8 warnings about deprecated functions.
#pragma warning( push )
#pragma warning( disable : 4996 )

//----------------------------------------------------------------------------
void ReportNullFunction (const char*)
{
    assert(false);
}
//----------------------------------------------------------------------------
void ReportGLError (const char* acFunction)
{
    GLenum code = glGetError();
    if (code != GL_NO_ERROR)
    {
        FILE* pkOFile = fopen("OpenGLErrors.txt","at");
        switch (code)
        {
        case GL_INVALID_ENUM:
            fprintf(pkOFile,"invalid enum, function %s\n",acFunction);
            break;
        case GL_INVALID_VALUE:
            fprintf(pkOFile,"invalid value, function %s\n",acFunction);
            break;
        case GL_INVALID_OPERATION:
            fprintf(pkOFile,"invalid operation, function %s\n",acFunction);
            break;
        case GL_STACK_OVERFLOW:
            fprintf(pkOFile,"stack overflow, function %s\n",acFunction);
            break;
        case GL_STACK_UNDERFLOW:
            fprintf(pkOFile,"stack underflow, function %s\n",acFunction);
            break;
        case GL_OUT_OF_MEMORY:
            fprintf(pkOFile,"out of memory, function %s\n",acFunction);
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION_EXT:
            fprintf(pkOFile,"invalid framebuffer operation, function %s\n",
                acFunction);
            break;
        default:
            fprintf(pkOFile,"unknown error, function %s\n",acFunction);
            break;
        }
        fclose(pkOFile);
    }
}
//----------------------------------------------------------------------------

#pragma warning( pop )
