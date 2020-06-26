/**
PROGRAMA 1: Confecciona un programa que llene un arreglo de tamaño 20 con números
aleatorios en el rango entre 10 y 50, luego muestra el mayor número de todos
Nota: Debes comentar los ajustes e incorporaciones realizadas para el correcto
funcionamiento, así el cómo se obtienen los números aleatorios requeridos.
En el proceso no existen datos de entrada, solo de proceso (generación de los
números aleatorios) y de salida (el mayor).

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 30/09/2019
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    //Declaramos variables para utilizar en el ejercicio
    int arreglo[20];
    int max = 50;
    int min = 10;
    int range = max - min + 1; /* Determinamos el rango a calcular */
    int num, i, mayor = 0;
    srand(time(NULL)); /* reseteamos los números aleatorios */

    //Asignamos los valores al array
    for (i = 0; i < 20; i++)
        arreglo[i] = rand() % range + min;

    //Buscamos el número mayor
    for (i = 0; i < 20; i++)
        if (arreglo[i] > mayor)
            mayor = arreglo[i];

    //Imprimimos el array con los valores asignados
    for (i = 0; i < 20; i++)
        printf("%d\n", arreglo[i]);

    //Imprimimos el número mayor
    printf("El numero mayor es %d", mayor);

    printf("\n");
    return 0;
}