/**
Ejericio 17:
Confecciona un programa que permita determinar la diferencia en minutos de dos horas leídas.
Se pide que:
1. Se lea la hora en formado hh:mm
2. Se cree una función que lea la hora y devuelva la cantidad de minutos equivalente a la hora ingresada

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 17/12/2019
**/

#include <stdio.h>
#include <string>    // Libreria para el uso de Strings
using namespace std; // Dependencia libreria String

#define TAMANO_HORA 2
#define HORA_MAX 24
#define MINUTO_MAX 60

// Funcion para obtener datos de entrada
void leerhora(string label, int *hora_txt)
{
    //declaramos variables
    int hora, minuto;
    bool error = false;
    //Iniciamos ciclo para obtener un dato de entrada correcto
    do
    {
        error = false;
        printf("%s", label.c_str());
        scanf("%d:%d", &hora, &minuto);
        //Validamos si son datos correctos
        if (hora > HORA_MAX || minuto > MINUTO_MAX)
        {
            printf("Hora incorrecta !!! \n");
            error = true;
        }
    } while (error);
    hora_txt[0] = hora;
    hora_txt[1] = minuto;
}

int main(void)
{
    //Declaramos punteros
    int *hora_punt_1, *hora_punt_2;
    //Declaramos arreglos donde almacenamos los datos ingresados
    int hora_txt_1[TAMANO_HORA], hora_txt_2[TAMANO_HORA];
    int dif_minuto, dif_hora;
    int hora_1, hora_2, minuto_1, minuto_2, total_minutos_1, total_minutos_2, diferencia;
    bool error;
    //Igualamos los punteros con arreglos
    hora_punt_1 = hora_txt_1;
    hora_punt_2 = hora_txt_2;

    // Solicitamos al usuario mendiante una función, enviamos el puntero
    leerhora("Escribe la primera hora (formato hh:mm): ", hora_punt_1);
    leerhora("Escribe la segunda hora (formato hh:mm): ", hora_punt_2);

    // Asignaciones
    hora_1 = hora_txt_1[0], hora_2 = hora_txt_2[0];
    minuto_1 = hora_txt_1[1], minuto_2 = hora_txt_2[1];

    // Calculo: Convierto la hora en minutos
    total_minutos_1 = hora_1 * MINUTO_MAX + minuto_1;
    total_minutos_2 = hora_2 * MINUTO_MAX + minuto_2;
    if (total_minutos_1 > total_minutos_2)
        diferencia = total_minutos_1 - total_minutos_2;
    else
        diferencia = total_minutos_2 - total_minutos_1;
    // Imprimo
    printf("Primera hora(%d:%d) en minutos %d\n", hora_1, minuto_1, total_minutos_1);
    printf("Segunda hora(%d:%d) en minutos %d\n", hora_2, minuto_2, total_minutos_2);
    printf("Diferencia en minutos es: %d \n", diferencia);
    return 0; /* Sentencia return de terminación */
}
