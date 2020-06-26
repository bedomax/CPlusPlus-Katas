/**
 *  Programa 2:
    Construir un programa llamado “bono Uniacc” que pregunte al encuestado:
    - si tiene hijos (‘S’,’N’)
    - si arrienda (‘S’,’N’)
    - tiene beca (‘S’, ‘N’)
    Si tiene beca, no recibe nada (bono = 0).
    Si no tiene beca:
    - Si tiene hijos: se suma al bono la cantidad de 50 mil.
    - Si arrienda: se suma al bono la cantidad de 80 mil.
    Se despliega el bono obtenido.
    Supuestos:
    Se leen sólo ‘S’ y ‘N’ en mayúsculas.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 2/09/2019
* */

#include <stdio.h>
int main(void)
{
    /* Declaramos variables */
    char beca, arrienda, hijos;
    int bono = 0;
    /* Solicitamos información de lectura */
    printf("¿Tiene Hijos?: ");
    scanf(" %c", &hijos);
    printf("¿Arrienda?: ");
    scanf(" %c", &arrienda);
    printf("¿Tiene Beca?: ");
    scanf(" %c", &beca);
    if (beca == 'N') /* Si No tiene beca realiza lo siguiente */
    {
        bono += (hijos == 'S') ? 50000 : 0;    /* Si tiene hijos sumamos 50.000 */
        bono += (arrienda == 'S') ? 80000 : 0; /* Si arrienda sumamos 80.000 */
    }
    /* Imprimimos resultados */
    printf("Bono= %d \n", bono);
    /* Finalizamos el programa */
    return 0; /* Sentencia return de terminación */
}