/**
PROGRAMA Item 2:
Explica cómo crear un árbol binario (a través de un video) que contenga una expresión aritmética, 
debes llenarlo de tal forma que al recorrerlo de manera in-orden aparezca la expresión correctamente.
* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
**/

// Importamos librerias que usaremos
#include <stdio.h>
#include <stdlib.h>

// Estructura nodo a utilizar
struct nodo
{
    char caracter;
    struct nodo *izq;
    struct nodo *der;
};

// Metodo para agregar nodo
struct nodo *nuevonodo(char caracter)
{
    struct nodo *nodo = (struct nodo *)
        malloc(sizeof(struct nodo));
    nodo->caracter = caracter;
    nodo->izq = NULL;
    nodo->der = NULL;
    return (nodo);
}
// Metodo para imprimir por orden "InOrder"
void imprimeInOrder(struct nodo *nodo)
{
    if (nodo == NULL)
        return;

    imprimeInOrder(nodo->izq);
    printf("%c ", nodo->caracter);
    imprimeInOrder(nodo->der);
}

// Principal
int main()
{
    // Crear nodo y ingresamos de acuerdo al nodo
    struct nodo *listado = nuevonodo('+');
    listado->izq = nuevonodo('*');
    listado->der = nuevonodo('4');
    listado->izq->izq = nuevonodo('3');
    listado->izq->der = nuevonodo('4');
    // Imprimimos el arbol binario en in-order
    printf("Arbol binario in-orden: \n");
    imprimeInOrder(listado);
    getchar();
    return 0;
}