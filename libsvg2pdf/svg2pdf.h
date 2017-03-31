/***********************************************
* Copyright (c) *** Corporation
* Author: panliang(divels@qq.com)
* Abstract: svg to pdf
* Time: 2017.03.31
***********************************************/

#ifndef SVG2PDF_H_
#define SVG2PDF_H_

#include <stdbool.h>

bool svg2pdf(const char *infile, const char *outfile, char *errormsg);

#endif