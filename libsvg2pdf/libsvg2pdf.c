/***********************************************
* Copyright (c) *** Corporation
* Author: panliang(divels@qq.com)
* Abstract: svg to pdf library
* Time: 2017.03.31
***********************************************/

#include "libsvg2pdf.h"
#include "svg2pdf.h"

DLL_EXPORTED bool libsvg2pdf(const char *insvgfile, const char *outpdffile, char *error)
{
    if (NULL == insvgfile || NULL == outpdffile)
    {
        return false;
    }

    return svg2pdf(insvgfile, outpdffile, error);
}

