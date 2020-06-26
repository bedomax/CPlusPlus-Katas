/**
PROGRAMA 1:
Crea un árbol binario, con números enteros ingresados desde teclado. Una vez creado, escribe funciones que calculen:
a) La suma de sus elementos.
b) La suma de sus elementos que son múltiplos de 3.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
**/

// Importamos librerias que usaremos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos constantes
#define MAX 10

// Estructura  del tipo de dato Cliente
typedef struct Clientes
{
    char nombre[MAX];
    int tiempo_promedio;
} Cliente;

// Estructura del Listado ordenado
struct Nodo
{
    Cliente cliente;
    struct Nodo *siguiente;
};

//Método para agregar elementos al listado
void agregar(struct Nodo **lista_ref, Cliente nuevo_cliente)
{
    // Asignamos espacio de memoria
    struct Nodo *nuevo_Nodo =
        (struct Nodo *)malloc(sizeof(struct Nodo));

    // Asignamos al nodo los datos del nuevo cliente
    nuevo_Nodo->cliente = nuevo_cliente;
    nuevo_Nodo->siguiente = (*lista_ref);
    (*lista_ref) = nuevo_Nodo;
}

//Método para conocer el tamaño del listado
int tamanoListado(struct Nodo *listado)
{
    int count = 0;
    struct Nodo *current = listado;
    // Recorremos el listado
    while (current != NULL)
    {
        count++;
        current = current->siguiente;
    }
    return count;
}

//Método para calcular el promedio de tiempos
float promedioTiempo(struct Nodo *listado)
{
    int tamano = tamanoListado(listado);
    int total_minutos = 0;
    struct Nodo *current = listado;
    //Recorremos y realizamos una sumatoria
    while (current != NULL)
    {
        total_minutos += current->cliente.tiempo_promedio;
        current = current->siguiente;
    }
    //Dividimos con el total del listado
    return total_minutos / tamano;
}

//Método para mostrar en el menú
void menu()
{
    printf("\n1. Agregar Cliente");
    printf("\n2. Calcular promedio de tiempo");
    printf("\n3. Salir \n");
}

//Principal
int main()
{
    //Creamos el nodo
    struct Nodo *listado = NULL;
    //Creamos char auxiliar para almacenar strings de entrada
    char *aux = malloc(30 * sizeof *aux);
    int opcion;
    Cliente cliente;
    printf("\n*** Programa ***\n");
    // Ciclo repetitivo para solicitar datos de entrada
    do
    {
        // Mostramos menú
        menu();
        // Capturamos opción a desplegar
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            // Ingresa datos del cliente
            printf("- Ingrese el nombre:");
            scanf("%s", aux);
            strcpy(cliente.nombre, aux);
            printf("- Ingrese promedio de atención en minutos:");
            scanf("%d", &cliente.tiempo_promedio);
            agregar(&listado, cliente);
            break;
        case 2:
            // Despliega tiempo promedio de atención
            printf("Promedio de minutos usado para todo los clientes: %.2f\n", promedioTiempo(listado));
            break;
        }
    } while (opcion != 3);

    return 0;
}