/*
 * tclGLMWFWInit.c --
 *
 * This file contains the C-implemented startup part of a
 * a Tcl interface to the GLMWFW OpenGL multi window frame work
 *
 * Copyright (c) 2007 by Arnulf P. Wiedemann
 *
 * See the file "license.terms" for information on usage and redistribution of
 * this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * This work is derived from/based on GLFW - An OpenGL framework version 2.6
 * by Camilla Berglund http://glmwfw.sourceforge.net
 *
 * It is adapted for use in Tcl environment. Instead of one window
 * this version supports multiple windows and has a stubs interface for the
 * different platforms. The platform dependent code parts are loadable packages
 * and package require command has to look for the right one dependent on the
 * platform
 *
 * RCS: @(#) $Id: tclGLMWFWInit.c,v 1.1.2.1 2007/11/01 20:42:44 wiede Exp $
 */

#include "tclGLMWFWInt.h"
#include "tclGLMWFWPlatform.h"

/*
 ************************************************************************
 ****                    GLMWFW user functions                       ****
 ************************************************************************
 */

/*
 *========================================================================
 * glmwfwInit() - Initialize various GLMWFW state
 *========================================================================
 */

int
glmwfwInit(
    void)
{
    /* Platform specific initialization */
    if (!_glmwfwPlatformInit()) {
        return GL_FALSE;
    }
    return GL_TRUE;
}

/*
 *========================================================================
 * glmwfwTerminate() - Close window and kill all threads.
 *========================================================================
 */

int
glmwfwTerminate(
    TclGLMWFWInfo *infoPtr)
{
    /* Platform specific termination */
    if (!_glmwfwPlatformTerminate(infoPtr)) {
        return TCL_ERROR;
    }
    return TCL_OK;
}