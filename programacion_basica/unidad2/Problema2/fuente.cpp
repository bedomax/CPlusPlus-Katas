/**
PROGRAMA 2: Crea un array de números y otro de String de 4 posiciones donde insertarás
notas entre 0 y 10 (debes controlar que inserte una nota valida), pudiendo ser
decimal la nota en el array de números, en el de Strings guardarás los nombres de
los alumnos.
Después, crearás un array de String donde insertarás el resultado de la nota
con palabras

- Si la nota esta entre 0 y 4,99, será un suspenso.
- Si esta entre 5 y 6,99, será un bien.
- Si esta entre 7 y 8,99 será un notable. 
- Si esta entre 9 y 10 será un sobresaliente

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 30/09/2019
**/

#include <stdio.h>
#include <string.h>
// Declaramos constantes para el tamano del listado de alumnos
#define TAMANO 4
// Declaramos constantes con valores para la impresion
#define SUSPENSO "Suspenso"
#define BIEN "bien"
#define NOTABLE "Notable"
#define SOBRESALIENTE "Sobresaliente"

int main()
{
    // Declaramos variables
    char nombres[TAMANO][50];
    double notas[TAMANO];
    char resultado[TAMANO][20];
    bool error; /* Bandera para validar si hay errores */
    // Solicitamos datos de entrada
    for (int i = 0; i < TAMANO; i++)
    {
        printf("Alumno %d ***** \n", (i + 1));
        printf("Ingrese el nombre:");
        scanf("%s", nombres[i]);
        // Bucle para validar ingreso de nota de 0 a 10
        do
        {
            error = false;
            printf("Ingrese la nota(entre 0 a 10):");
            scanf("%lf", &notas[i]);
            if (!(notas[i] >= 0 && notas[i] <= 10))
            {
                // Activamos bucle en caso de existir error
                error = true;
                printf("* Error al ingresar la nota.\n");
            }
        } while (error);
    }

    // Recorremos las notas ingresadas y asignamos comentario
    for (int i = 0; i < TAMANO; i++)
    {
        switch ((int)notas[i])
        {
        case 0 ... 4: /* Rango de 0 a 4.99 */
            strncpy(resultado[i], SUSPENSO, sizeof(SUSPENSO));
            break;
        case 5 ... 6: /* Rango de 5 a 6.99 */
            strncpy(resultado[i], BIEN, sizeof(BIEN));
            break;
        case 7 ... 8: /* Rango de 7 a 8.99 */
            strncpy(resultado[i], NOTABLE, sizeof(NOTABLE));
            break;
        case 9 ... 10: /* Rango de 9 a 9.99 */
            strncpy(resultado[i], SOBRESALIENTE, sizeof(SOBRESALIENTE));
            break;
        }
    }

    // Imprimimos las notas
    for (int i = 0; i < TAMANO; i++)
    {
        printf("El alumno %s tiene una nota de %.2f, por lo que su resultado es %s \n", nombres[i], notas[i], resultado[i]);
    }

    printf("\n");
    return 0;
}