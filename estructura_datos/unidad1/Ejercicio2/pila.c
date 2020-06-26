#include <stdlib.h>
#include "pila.h"
#include <stdlib.h>

void crearPila(P_Pila p)
{
       RUT *aux;
       aux = (RUT *)malloc(50*sizeof(RUT));
       p->valores = aux;
       p->postope=0;
}

void apilar(P_Pila p, RUT dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

RUT desapilar(P_Pila p)
{
       RUT z = p->valores[p->postope -1];
       p->postope--;
       return z;
}

RUT tope(P_Pila p)
{
       return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
       return (p->postope == 0);
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %s ", p->valores[i]);
}


