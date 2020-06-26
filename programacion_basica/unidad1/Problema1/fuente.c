/**
PROGRAMA 1: Construir un programa tal que, dado el precio de un artículo vendido y la
cantidad de dinero pagado por un cliente, calcule e imprima el cambio que debe
entregarse entendiendo que se debe aplicar la regla de redondeo:
* Si la unidad es <=5 se redondea hacia abajo, y si es >5 entonces se redondea
hacia arriba, por ejemplo: 
* Si el artículo cuenta 14 y paga con 100, el vuelto sin redondeo es 86 y el
vuelto con redondeo serpa 90. 
* Si el artículo cuenta 19 y paga con 100, el vuelto sin redondeo es 81 y el
vuelto con redondeo serpa 80.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 2/09/2019
**/

#include <stdio.h>
int main(void)
{
    //Declaramos variables
    int precio, pago, vuelto, vuelto_redondeo, porcent;
    printf("Ingrese precio: ");
    scanf("%d", &precio); // Lee precio
    printf("Ingrese monto pago: ");
    scanf("%d", &pago);     // Lee pago
    vuelto = pago - precio; // Calculamos el vuelto
    porcent = vuelto % 10;  // Obtenemos el decimal del porcentaje
    if (porcent > 5)
        vuelto_redondeo = (vuelto - porcent) + 10; /* Si es mayor a 5 nos acercamos hacia arriba */
    else
        vuelto_redondeo = vuelto - porcent; /* Si es menor a 5 nos acercamos hacia abajo */
    printf("Vuelto con redondeo a entregar = %d \n", vuelto_redondeo);
    /* Finalizamos el programa */
    return 0; /* Sentencia return de terminación */
}
