/**
Ejercicio 18:
Confeccionar un programa que lea 6 números enteros. El programa debe determinar  el menor de ellos.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 17/12/2019
**/

#include <stdio.h>
#define TAMANO 6
int main(void)
{
    int listado[TAMANO], contador = 0, min = 0;
    do
    {
        // Solicitar números
        printf("Ingrese el número posicion [%d]: ", contador + 1);
        scanf("%d", &listado[contador]);
        // Asigna el número menor de acuerdo a los ingresados
        if ((listado[contador] < min) || (contador == 0))
            min = listado[contador];
        contador++;
    } while (contador < 6);
    // Imprime el número menor
    printf("El número menor es: %d\n", min);
}
