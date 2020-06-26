/**
Examen 2 - Oral:
Validar la ejecución del programa

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 17/12/2019
**/

#include <stdio.h>

void ff(double *d)
{
    double *p = d;
    double *b = p;
    //printf("%d\n", b);
    printf("%lf\n", *b);
}

int main()
{
    double d = 1024.77;
    ff(&d);
}
