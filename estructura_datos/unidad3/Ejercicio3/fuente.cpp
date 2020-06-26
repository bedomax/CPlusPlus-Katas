/**
PROGRAMA 3:
Crea un grafo con nodos que contengan: nombres, curso y rut de alumnos de un colegio. 
La relación entre estos nodos representa si son amigos.

Se pide:
Crear una función que recibe un Rut.
Escribir todos los amigos asociados a dicho Rut.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
**/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

using namespace std;

typedef struct Alumnos
{
    int id;
    char nombre[MAX];
    char rut[MAX];
    char curso[MAX];
} Alumno;

struct nodo
{
    Alumno alumno;
    struct nodo *izq;
    struct nodo *der;
};

bool imprimirAmigos(struct nodo *nodo_act, Alumno alumno)
{
    if (nodo_act == NULL)
        return false;

    if (nodo_act->alumno.id == alumno.id)
        return true;

    if (imprimirAmigos(nodo_act->izq, alumno) ||
        imprimirAmigos(nodo_act->der, alumno))
    {
        cout << nodo_act->alumno.nombre << " ";
        return true;
    }
    return false;
}

struct nodo *nuevoNodo(Alumno alumno)
{
    struct nodo *nodo = (struct nodo *)
        malloc(sizeof(struct nodo));
    nodo->alumno = alumno;
    nodo->izq = NULL;
    nodo->der = NULL;

    return (nodo);
}

int main()
{
    Alumno alumno_1;
    alumno_1.id = 1;
    strcpy(alumno_1.nombre, "Max");
    strcpy(alumno_1.rut, "18.158.853-5");
    strcpy(alumno_1.curso, "Arte");

    Alumno alumno_2;
    alumno_2.id = 2;
    strcpy(alumno_2.nombre, "Juan");
    strcpy(alumno_2.rut, "18.158.123-5");
    strcpy(alumno_2.curso, "Diseño");

    Alumno alumno_3;
    alumno_3.id = 3;
    strcpy(alumno_3.nombre, "David");
    strcpy(alumno_3.rut, "18.321.123-5");
    strcpy(alumno_3.curso, "Computación");

    Alumno alumno_4;
    alumno_4.id = 4;
    strcpy(alumno_4.nombre, "Pedro");
    strcpy(alumno_4.rut, "16.121.542-5");
    strcpy(alumno_4.curso, "Arte");

    Alumno alumno_5;
    alumno_5.id = 5;
    strcpy(alumno_4.nombre, "Ramiro");
    strcpy(alumno_4.rut, "17.211.242-5");
    strcpy(alumno_4.curso, "Diseño");

    Alumno alumno_6;
    alumno_6.id = 6;
    strcpy(alumno_6.nombre, "Joaquin");
    strcpy(alumno_6.rut, "16.531.212-5");
    strcpy(alumno_6.curso, "Arte");

    struct nodo *nodo_act = nuevoNodo(alumno_1);
    nodo_act->izq = nuevoNodo(alumno_2);
    nodo_act->der = nuevoNodo(alumno_3);
    nodo_act->izq->izq = nuevoNodo(alumno_4);
    nodo_act->izq->der = nuevoNodo(alumno_5);
    nodo_act->izq->izq->izq = nuevoNodo(alumno_6);

    cout << "Amigos de " << alumno_6.nombre << ":\n";
    imprimirAmigos(nodo_act, alumno_6);

    getchar();
    return 0;
}