/// test svg2pdf

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "libsvg2pdf.h"

int main(void)
{
    char *svgfile = "G:\\panliang\\svg\\test1.svg";
    char *pdffile = "G:\\panliang\\svg\\test1.pdf";
    char error[1024] = { 0 };

    if (!libsvg2pdf(svgfile, pdffile, error))
    {
        printf("%s\n", error);
    }
    else
    {
        printf("successed.\n");
    }
    
    getchar();
    return 0;
}
