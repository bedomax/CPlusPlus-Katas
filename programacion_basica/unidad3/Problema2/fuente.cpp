/**
 Programa 2:
 Construir un programa permita calcular la sumatoria de armónicos.
 Pero en vez de infinitos números, que lea la cantidad de elementos y entregue el resultado. 
 Debe permitirse solo valores entre 1 y 100.

 Como condición se desea que confeccione un método para la lectura de
 cantidad de datos y otro para el cálculo. Ambas funciones no pasarán parámetros.
 Deberá usar variables de ambientes adecuadas para obtener el resultado.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
 **/

#include <stdio.h>

//Declarar variables globales
int num;
double resultado = 0;
const int NUM_MAX(100);

//Declarar funciones
void entraDatos() /* función para ingresar datos */
{
    do
    {
        //Solicitar número para la sumatoria
        printf("Por favor introduzca un numero entre 1 y 100: ");
        scanf("%d", &num);
    } while (num < 0 || num > 100);
}

void calculo() /* función para calcular */
{
    for (double i = num; i > 0; i--)
    {
        resultado += (double)(1 / i);
    }
}

/* Programa Principal */
int main()
{
    /* Llamar de funciones */
    entraDatos();
    calculo();
    /* Impresion de resultado */
    printf("La suma armónica es: %lf\n\n ", resultado);
    return 0;
}
