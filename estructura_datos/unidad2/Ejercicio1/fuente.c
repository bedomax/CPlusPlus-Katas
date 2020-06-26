/**
PROGRAMA 1: 
Crea y ordena los elementos de una lista simplemente enlazada de manera descendente (de mayor a menor), 
usando cualquier método de ordenamiento.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 2/09/2019
**/

#include <stdio.h>
#include <stdlib.h>

/* Estructura de la lista */
struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

/* Funcion para el orden de a lista enlazada */
void ordenInsercion(struct Nodo **cabecera_ref, struct Nodo *nuevo_nodo)
{
    struct Nodo *actual;
    /* Validación si el campo es mayor al elemento de la cabecera */
    if (*cabecera_ref == NULL || (*cabecera_ref)->dato <= nuevo_nodo->dato)
    {
        nuevo_nodo->siguiente = *cabecera_ref;
        *cabecera_ref = nuevo_nodo;
    }
    else
    {
        /* Ubicamos el nodo antes de la inserción */
        actual = *cabecera_ref;
        while (actual->siguiente != NULL &&
               actual->siguiente->dato > nuevo_nodo->dato)
        {
            actual = actual->siguiente;
        }
        nuevo_nodo->siguiente = actual->siguiente;
        actual->siguiente = nuevo_nodo;
    }
}

/* funcion para crear el nodo*/
struct Nodo *nuevoNodo(int nuevo_dato)
{
    /* memoria para el nodo */
    struct Nodo *nuevo_nodo =
        (struct Nodo *)malloc(sizeof(struct Nodo));

    /* ingresa el nodo en la lista */
    nuevo_nodo->dato = nuevo_dato;
    nuevo_nodo->siguiente = NULL;

    return nuevo_nodo;
}

/* Función para imprimir el listado */
void imprimeLista(struct Nodo *cabecera)
{
    struct Nodo *temp = cabecera;
    while (temp != NULL)
    {
        printf("%d  ", temp->dato);
        temp = temp->siguiente;
    }
}

/* Manejador de programa */
int main()
{
    struct Nodo *cabecera = NULL;
    struct Nodo *nuevo_nodo = nuevoNodo(5);

    nuevo_nodo = nuevoNodo(10);
    ordenInsercion(&cabecera, nuevo_nodo);
    nuevo_nodo = nuevoNodo(3);
    ordenInsercion(&cabecera, nuevo_nodo);
    nuevo_nodo = nuevoNodo(2);
    ordenInsercion(&cabecera, nuevo_nodo);
    nuevo_nodo = nuevoNodo(1);
    ordenInsercion(&cabecera, nuevo_nodo);
    nuevo_nodo = nuevoNodo(9);
    ordenInsercion(&cabecera, nuevo_nodo);
    printf("Lista enlazada ordenada \n");
    imprimeLista(cabecera);

    return 0;
}