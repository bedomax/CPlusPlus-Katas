/**
Ejercicio 19:
Confecciona un programa que pida dos números y muestre todos los números que van desde el primero al segundo. 
Se debe controlar que los valores sean correctos.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 17/12/2019
**/

#include <stdio.h>

//Declarar funciones
int entraNumero(int min = 0) /* función para ingresar datos */
{
    int num;
    bool pasa = false;
    do
    {
        //Solicitar número para la sumatoria
        printf("Por favor introduzca un numero: ");
        scanf("%d", &num);
        // Valida que sea un numero correcto
        if (num > 0 && min == 0)
            pasa = true;
        // Valida que sea mayor al primer número
        if ((num > min) && (pasa == false))
            pasa = true;

    } while (!pasa);
    return num;
}

int main(void)
{
    //Declaramos variables
    int min, max;
    // Leer datos
    min = entraNumero();
    max = entraNumero(min);
    //Bucle y imprime los número que se encuentran entre los dos números
    for (int i = min; i <= max; i++)
    {
        printf("%d,", i);
    }
    return 0;
}