/**
PROGRAMA 2: 
Escribe un programa en lenguaje c, que use una estructura de lista doblemente enlazada, con la 
información de un paciente de un hospital: nombre, dirección, Rut, fecha de nacimiento, sexo, día de 
visita y problema médico. Este programa debe tener una función para entrada de los datos de un paciente, 
guardar los diversos pacientes en la lista y mostrar todos cuyo día de visita sea determinado por el usuario.
* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 2/09/2019
**/

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

#define MAX 15 


typedef struct Pacientes
{
    char nombre[MAX]; 
    char direccion[MAX];
    char rut[MAX];
    char fecha_nacimiento[MAX];
    char sexo[MAX];
    char dia_visita[MAX];
    char problema_medico[MAX];
} Paciente;

struct Nodo {  
    Paciente paciente;
    struct Nodo* siguiente;  
    struct Nodo* anterior;  
};  
  
void agregar(struct Nodo** cabecera_ref, Paciente paciente)  
{  
    struct Nodo* nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));  
    nuevo_nodo->paciente = paciente;
    nuevo_nodo->siguiente = (*cabecera_ref);  
    nuevo_nodo->anterior = NULL;  
  
    if ((*cabecera_ref) != NULL)  
        (*cabecera_ref)->anterior = nuevo_nodo;  
  
    (*cabecera_ref) = nuevo_nodo;  
}  

void menu(){
        printf( "\n1. Agregar un paciente");
        printf( "\n2. Imprimir listado de pacientes");
        printf( "\n3. Salir. \n" );
}
void imprimirListado(struct Nodo* nodo)  
{  
    struct Nodo* last;  
    int flag = 0;
    while (nodo != NULL) {  
        printf("\n *** Detalle paciente *** \n");
        printf("1.1 Nombre: %s \n",  nodo->paciente.nombre);
        printf("1.2 Dirección: %s \n",  nodo->paciente.direccion);
        printf("1.3 Rut: %s \n",  nodo->paciente.rut);
        printf("1.3 Fecha de Nacimiento: %s \n",  nodo->paciente.fecha_nacimiento);
        printf("1.3 Sexo: %s \n",  nodo->paciente.sexo);
        printf("1.3 Día de Visita: %s \n",  nodo->paciente.dia_visita);
        printf("1.3 Problema Médico: %s \n",  nodo->paciente.problema_medico);
        last = nodo;  
        nodo = nodo->siguiente;  
    } 
}  
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
  
int main()  
{  
    struct Nodo* listado = NULL; 
    int opcion;
    Paciente paciente;
    char *aux = malloc(300 * sizeof *aux);
    printf( "\n*** Ingreso de Pacientes ***");
    do
    {
        menu();
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                 flush();
                 printf("\n*** Datos del Paciente ***\n");
                 printf( "1.1 Nombre:");
                 scanf("%s", aux);
                 strcpy(paciente.nombre, aux);
                 printf( "1.2 Dirección:");
                 scanf("%s", aux);
                 flush();
                 strcpy(paciente.direccion, aux);
                 printf( "1.3 RUT:");
                 scanf("%s", aux);
                 strcpy(paciente.rut, aux);
                 printf( "1.4 Fecha de Nacimiento(YYYYMMDD):");
                 scanf("%s", aux);
                 strcpy(paciente.fecha_nacimiento, aux);
                 flush();
                 printf( "1.5 Sexo:");
                 scanf("%s", aux);
                 strcpy(paciente.sexo, aux);
                 printf( "1.6 Día de Visita(YYYYMMDD):");
                 scanf("%s", aux);
                 strcpy(paciente.dia_visita, aux);
                 printf( "1.7 Problema médico:");
                 scanf("%s", aux);
                 strcpy(paciente.problema_medico, aux);
                 agregar(&listado, paciente);
            break;
            case 2:
                printf( "\n2.1 Listado de visitas:");
                imprimirListado(listado);      
            break;
        }
    }while ( opcion != 3 );
    return 0;  
} 