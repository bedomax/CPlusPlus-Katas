/**
PROGRAMA 1:
Crea un árbol binario, con números enteros ingresados desde teclado. Una vez creado, escribe funciones que calculen:
a) La suma de sus elementos.
b) La suma de sus elementos que son múltiplos de 3.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
**/

#include <iostream>
using namespace std;

struct Nodo
{
    int valor;
    Nodo *izq, *der;
};

Nodo *crearNodo(int valor)
{
    Nodo *nodo = new Nodo;
    nodo->valor = valor;
    nodo->izq = nodo->der = NULL;
    return (nodo);
}

int suma(Nodo *nodo)
{
    if (nodo == NULL)
        return 0;
    return (nodo->valor + suma(nodo->izq) + suma(nodo->der));
}

int sumaMultiplo3(Nodo *nodo)
{
    if (nodo == NULL)
        return 0;
    if ((nodo->valor % 3) == 0)
        return (nodo->valor + sumaMultiplo3(nodo->izq) + sumaMultiplo3(nodo->der));
    else
        return 0;
}

void menu()
{
    printf("\n1. Agregar un valor árbol");
    printf("\n4. Salir \n");
}

struct Nodo *insertar(struct Nodo *nodo, int valor)
{
    if (nodo == NULL)
        return crearNodo(valor);
    if (valor < nodo->valor)
        nodo->izq = insertar(nodo->izq, valor);
    else if (valor > nodo->valor)
        nodo->der = insertar(nodo->der, valor);
    return nodo;
}

int main()
{
    int opcion, valor, puntero;
    Nodo *nodo = NULL;
    puntero = 0;
    printf("\n*** Programa ***\n");
    do
    {
        menu();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("- Ingrese un número:");
            scanf("%d", &valor);
            if (puntero == 0)
                nodo = insertar(nodo, valor);
            else
                insertar(nodo, valor);
            break;
        }
    } while (opcion != 4);
    int sum = suma(nodo);
    int sumMul3 = sumaMultiplo3(nodo);
    cout << "Suma total del árbol binario: " << sum << endl;
    cout << "Suma de multiplos de 3 total del árbol binario: " << sumMul3 << endl;
    return 0;
}
