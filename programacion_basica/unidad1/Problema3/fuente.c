/**
PROGRAMA 3: Confeccionar un programa que calcule el volumen de un cilindro. Para ello se
debe leer el ‘Diámetro” y la “Altura”.
El volumen se calcula usando la siguiente fórmula:
Volumen = PI * Radio^2  * Altura
Cabe recordar que el Diámetro es el doble del radio
Es decir: Diámetro = 2Radio

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 2/09/2019
**/

#include <stdio.h>
#include <math.h>
int main()
{
    // Declaramos variables
    float PI = 3.141593;
    float diametro, altura, radio;
    double volumen;
    // Solicitamos información de lectura
    printf("Introduzca el diametro, en metros: ");
    scanf("%f", &diametro);
    printf("Introduzca la altura, en metros: ");
    scanf("%f", &altura);
    // Cálculos
    radio = diametro / 2;                  /* Calculamos radio */
    volumen = PI * pow(radio, 2) * altura; /* Formula para obtener el volumen, usamos función pow para elevar al cuadrado */
    // Imprimimos resultados
    printf("El volumen del cilindro es de %6lf metros cubicos", volumen);
    return 0;
}