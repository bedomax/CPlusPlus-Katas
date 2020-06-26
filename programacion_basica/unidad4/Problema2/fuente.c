/**
PROGRAMA 2:
A partir de las siguientes declaraciones de estructuras, realice un programa en C que llene el array 
“municipalidad” y devuelva los datos (nombre, coalición, posición) del candidato que ha obtenido 
mayor número de votos.

Se debe solicitar la cantidad de candidatos.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 21/11/2019
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estructura de Persona y Candidato
struct Persona
{
    char nombre[40];
    char coalision[25];
};

struct Candidato
{
    int posicion;
    int votos;
    struct Persona persona;
};

//Programa Principal
int main()
{
    //Declaramos variable
    int num_candidatos;
    char *aux = malloc(30 * sizeof *aux); /* variable auxiliar para almecenar string */
    //Solicitamos entrada para el num de candidatos
    do
    {
        printf("Ingrese número de candidatos:");
        scanf("%d", &num_candidatos);
    } while (num_candidatos <= 1);
    // Ingreso de datos de los candidatos
    struct Candidato candidato[num_candidatos]; /* Declaramos vector de  candidatos */
    printf("\n*** Ingresar datos de los candidatos ***\n");
    /* Ciclo repetitivo para capturar los eventos de los candidatos */
    for (int i = 0; i < num_candidatos; i++)
    {
        printf("Nombre[%d]:", i + 1);
        scanf("%s", aux);
        strcpy(candidato[i].persona.nombre, aux);
        printf("Coalisión[%d]:", i + 1);
        scanf("%s", aux);
        strcpy(candidato[i].persona.coalision, aux);
        printf("Posición[%d]:", i + 1);
        scanf("%i", &candidato[i].posicion);
        printf("Número de votos[%d]:", i + 1);
        scanf("%i", &candidato[i].votos);
    }
    //Revisa el candidato con más números
    int voto_max = 0, pos_max;
    for (int i = 0; i < num_candidatos; i++)
    {
        //Encuentre el valor máximo
        if ((candidato[i].votos > voto_max) || (voto_max == 0))
        {
            pos_max = i;
            voto_max = candidato[i].votos;
        }
    }
    // Imprimir resultados del campo mayor
    printf("\n\n***DATOS DEL CANDIDATO CON MAYOR NUMERO DE VOTOS***\n");
    printf("Nombre: %s\n", candidato[pos_max].persona.nombre);
    printf("Coalicion: %s\n", candidato[pos_max].persona.coalision);
    printf("Posición: %i\n", candidato[pos_max].posicion);
    printf("Número de Votos: %i\n", candidato[pos_max].votos);
    return 0;
}
