/**
PROGRAMA 2:
Una empresa de servicios en diferentes partes del país necesita realizar una aplicación en lenguaje C, 
que estructure las distancias que existen entre los lugares que debe visitar, además es necesario considerar 
el consumo de combustible. Para ello debes ingresar una ciudad de salida y una ciudad de llegada 
escribiendo la distancia y el gasto en combustible (no se necesita saber el camino más corto, 
ya que ellos planifican la ruta).

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
**/

// Importamos librerias que usaremos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos constantes
#define MAX 100

// Estructura de datos para ingreso de rutas
typedef struct Rutas
{
    char inicio[MAX];
    char final[MAX];
    float combustible;
    float distancia;
    int tiempo_promedio;
} Ruta;

// Estructura del Listado ordenado
struct Nodo
{
    Ruta ruta;
    struct Nodo *siguiente;
};

//Método para agregar elementos al listado
void agregar(struct Nodo **lista_ref, Ruta nueva_ruta)
{
    // Asignamos espacio de memoria
    struct Nodo *nuevo_Nodo =
        (struct Nodo *)malloc(sizeof(struct Nodo));

    // Asignamos al nodo los datos del nuevo cliente
    nuevo_Nodo->ruta = nueva_ruta;
    nuevo_Nodo->siguiente = (*lista_ref);
    (*lista_ref) = nuevo_Nodo;
}

// Método para imprimir rutas ingresadas
void ImprimirListadoRutas(struct Nodo *listado)
{
    int cont = 0;
    struct Nodo *current = listado;
    // Recorremos el listado
    while (current != NULL)
    {
        cont++;
        printf("%d) Inicio: %s Fin: %s Combustible: %.2f Distancia: %.2f\n", cont, current->ruta.inicio, current->ruta.final, current->ruta.combustible, current->ruta.distancia);
        current = current->siguiente;
    }
}

// Método para imprimir menú
void menu()
{
    printf("\n1.Ingresar ruta");
    printf("\n2.Imprimir");
    printf("\n3. Salir \n");
}

//Principal
int main()
{
    //Creamos el nodo
    struct Nodo *rutas = NULL;
    char *aux = malloc(100 * sizeof *aux);
    int opcion;
    Ruta ruta;
    printf("\n*** Programa ***\n");
    do
    {
        // Mostramos menú
        menu();
        // Capturamos opción a desplegar
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            // Entrada de destino de ida
            printf("- Ingrese el destino de inicio:\n");
            scanf("%s", aux);
            strcpy(ruta.inicio, aux);
            // Entrada de vuelta
            printf("- Ingrese el destino de final:\n");
            scanf("%s", aux);
            strcpy(ruta.final, aux);
            // Entrada de valor destino
            printf("- Ingrese distancia(km):\n");
            scanf("%f", &ruta.distancia);
            // Entrada de valor destino
            printf("- Ingrese gasto combustible(litros):\n");
            scanf("%f", &ruta.combustible);
            // Agrego ruta al listado
            agregar(&rutas, ruta);
            break;
        case 2:
            // imprimir
            ImprimirListadoRutas(rutas);
            break;
        }
    } while (opcion != 3);
    return 0;
}
