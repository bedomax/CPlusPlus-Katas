#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definir valores constantes de acuerdo a los parametros del supermercado
#define NUM_PRODUCTOS 5
#define NUM_CARROS 25
#define NUM_CAJAS 3

typedef struct Productos
{
    long id;
    char nombre[10];
    float precio;
} Producto;

typedef struct CarritoDeCompras
{
    int id;
    int cliente_id;
    Producto productos[NUM_PRODUCTOS];
} CarritoDeCompra;

typedef struct Cajas
{	
    CarritoDeCompra carro;
    struct Cajas *siguiente;
} Caja;


// Definir funciones a desarrollar
void encola(Caja* *caja, CarritoDeCompra carro);
void pago(Caja* *caja);
void imprimirCola(Caja* caja);
int contar(Caja* caja);
void imprimirBoleta(Caja* caja);
