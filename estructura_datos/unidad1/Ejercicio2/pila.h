#include <stdio.h>

#define Pila struct _Pila
#define P_Pila struct _Pila *

typedef char* RUT;

struct _Pila
{
    RUT *valores;
    int postope;
};

void crearPila(P_Pila p);
void apilar(P_Pila p, RUT dato);
RUT desapilar(P_Pila p);
RUT tope(P_Pila p);
int pilavacia(P_Pila p);
void mostrar(P_Pila p);

