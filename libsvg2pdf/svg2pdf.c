/***********************************************
* Copyright (c) *** Corporation
* Author: panliang(divels@qq.com)
* Abstract: svg to pdf
* Time: 2017.03.31
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <rsvg.h>
#include <rsvg-cairo.h>
#include <cairo.h>
#include <cairo-pdf.h>
#include <cairo-win32.h>
//#include <pango/pangocairo.h> 
//#include <glib.h>

#include "svg2pdf.h"

#define FAIL(msg)							\
    do { fprintf (stderr, "FAIL: %s\n", msg); exit (-1); } while (0)

bool svg2pdf(const char *infile, const char *outfile, char *errormsg)
{
    GError *error = NULL;
    RsvgHandle *handle;
    RsvgDimensionData dim;
    double width, height;
    const char *filename = infile;
    const char *output_filename = outfile;
    cairo_surface_t *surface;
    cairo_t *cr;
    cairo_status_t status;
    BOOL res = true;

    //g_type_init ();

    rsvg_set_default_dpi(72.0);
    handle = rsvg_handle_new_from_file(filename, &error);
    if (error != NULL)
    {
        res = false;
        FAIL(error->message);
        sprintf(errormsg, "Error : %s.", error->message);
    }
    rsvg_handle_get_dimensions(handle, &dim);
    width = dim.width;
    height = dim.height;

    surface = cairo_pdf_surface_create(output_filename, width, height);
    cairo_pdf_surface_set_size(surface, 350, 320);
    cr = cairo_create(surface);

    rsvg_handle_render_cairo(handle, cr);

    status = cairo_status(cr);
    if (status)
    {
        FAIL(cairo_status_to_string(status));
        res = false;
        sprintf(errormsg, "Error : %s", cairo_status_to_string(status));
    }
    else
    {
        sprintf(errormsg, "svg transfer pdf is successed.");
    }

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    return res;
}
