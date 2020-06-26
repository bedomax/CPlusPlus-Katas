/**
PROGRAMA 1:
Construir un programa que permita introducir dos horas, cada una incluyendo
horas, minutos y segundos, utilizando el formato hh:mm:ss y calcule la diferencia
en horas, minutos y segundos.
Se requiere que las horas sean válidas, es decir:
- HH,MM,SS positivos; hh entre 00 y 23, MM entre 0 y 59 y SS entre 0 y 59.
- Si se lee con error, debe avisar y volver a pedir la hora.
- Debe controlar que la segunda hora sea posterior a la primera. Si la primera 
hora es mayor a la segunda, debe avisar y volver a pedir la segunda hora.
Consideraciones:
- Se valorará que el programa permita la reutilización de código.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
**/

#include <stdio.h>
#include <string>    // Libreria para el uso de Strings
using namespace std; // Dependencia libreria String

// Declaramos constnates
#define TAMANO_HORA 3
#define HORA_MAX 24
#define MINUTO_SEGUNDO_MAX 60

// Funcion para obtener datos de entrada
void leerhora(string label, int *hora_txt)
{
    //decalaramos variables
    int hora, minuto, segundo;
    bool error = false;
    //Iniciamos ciclo para obtener un dato de entrada correcto
    do
    {
        error = false;
        printf("%s", label.c_str());
        scanf("%d:%d:%d", &hora, &minuto, &segundo);
        //Validamos si son datos correctos
        if (hora > HORA_MAX || minuto > MINUTO_SEGUNDO_MAX || segundo > MINUTO_SEGUNDO_MAX)
        {
            printf("Hora incorrecta !!! \n");
            error = true;
        }
    } while (error);
    hora_txt[0] = hora;
    hora_txt[1] = minuto;
    hora_txt[2] = segundo;
}

// Programa principal
int main()
{
    //Declaramos punteros
    int *hora_punt_1, *hora_punt_2;
    //Declaramos arreglos donde almacenamos los datos ingresados
    int hora_txt_1[TAMANO_HORA], hora_txt_2[TAMANO_HORA];
    //Declaramos variables que se usan en el programa
    int dif_segundo, dif_minuto, dif_hora;
    int hora_1, hora_2, minuto_1, minuto_2, segundo_1, segundo_2, total_1, total_2;
    bool error;
    //Igualamos los punteros con arreglos
    hora_punt_1 = hora_txt_1;
    hora_punt_2 = hora_txt_2;
    // Solicitamos al usuario mendiante una función, enviamos el puntero
    leerhora("Escribe la primera hora (formato hh:mm:ss): ", hora_punt_1);
    do
    {
        // Solicitamos el segundo dato
        error = false; // bandera para capturar el error
        leerhora("Escribe la segunda hora (formato hh:mm:ss): ", hora_punt_2);

        // Validamos si el dato ingresado no es menos al primer dato ingresado
        segundo_1 = hora_txt_1[2], segundo_2 = hora_txt_2[2];
        minuto_1 = hora_txt_1[1], minuto_2 = hora_txt_2[1];
        hora_1 = hora_txt_1[0], hora_2 = hora_txt_2[0];
        error = (hora_2 < hora_1) ? true : false;
        if (hora_2 == hora_1)
        {
            error = (minuto_2 < minuto_1) ? true : false;
            if (minuto_2 == minuto_1)
            {
                error = (segundo_2 < segundo_1) ? true : false;
            }
        }

    } while (error);

    //Calculamos la diferencia entre las dos horas
    if (segundo_1 > segundo_2)
    {
        minuto_2--;
        segundo_2 += 60;
    }
    dif_segundo = segundo_2 - segundo_1;

    if (minuto_1 > minuto_2)
    {
        hora_2--;
        minuto_2 += 60;
    }
    dif_minuto = minuto_2 - minuto_1;
    dif_hora = hora_2 - hora_1;

    //Imprimimos los resultados
    printf("%d:%d:%d\n", hora_txt_1[0], hora_txt_1[1], hora_txt_1[2]);
    printf("%d:%d:%d\n", hora_txt_2[0], hora_txt_2[1], hora_txt_2[2]);
    printf("La diferencia es %d hora(s), %d minuto(s), %d segundo(s).\n", dif_hora, dif_minuto, dif_segundo);
}