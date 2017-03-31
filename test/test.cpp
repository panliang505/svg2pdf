/// test svg2pdf

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "libsvg2pdf.h"

int main(void)
{
    char *svgfile = "d:\\cairotest\\11.svg";
    char *pdffile = "d:\\cairotest\\11.pdf";
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
