/***********************************************
* Copyright (c) *** Corporation
* Author: panliang(divels@qq.com)
* Abstract: svg to pdf library
* Time: 2017.03.31
***********************************************/

#ifndef LIBSVG2PDF_H_
#define LIBSVG2PDF_H_

#include <locale.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DLL_EXPORTED 
# define DLL_EXPORTED __declspec(dllexport)
#endif

    DLL_EXPORTED bool libsvg2pdf(const char *insvgfile, const char *outpdffile, char *error);

#ifdef __cplusplus
}
#endif

#endif