#include "supermercado.h"

void encola(Caja* *caja, CarritoDeCompra carro)
{
    Caja* nueva_caja = malloc(sizeof(Caja));
    if (nueva_caja == NULL)
    {
        printf("No hay memoria suficiente\n");
        return;
    }

    nueva_caja->carro = carro;
    nueva_caja->siguiente = NULL;
    
    Caja* actual_caja = *caja;

    while (actual_caja->siguiente != NULL)
    {
        actual_caja = actual_caja->siguiente;
    }
    actual_caja->siguiente = nueva_caja;
}


void imprimirCola(Caja* caja)
{
    Caja* actual_caja = caja;

    while (actual_caja != NULL)
    {
        if (actual_caja->carro.cliente_id != 0){
            printf("Cliente: %d -->", actual_caja->carro.cliente_id);
        }
        actual_caja = actual_caja->siguiente;
    }
    printf("\n");

}

int contar(Caja* caja){
    int num = 0;
    Caja* actual_caja = caja;
    while (actual_caja != NULL)
    {
        if (actual_caja->carro.cliente_id != 0){
            num++;
        }
        actual_caja = actual_caja->siguiente;
    }
    return num;
}


void pago(Caja* *caja)
{
    Caja* actual_caja = *caja;
    if (actual_caja == NULL || actual_caja->siguiente == NULL)
    {
        return;
    }
    Caja* p_caja = actual_caja->siguiente;
    Caja* s_caja = p_caja->siguiente;

    actual_caja->siguiente = s_caja;
    free(p_caja);
}

void imprimirBoleta(Caja* caja)
{
    int puntero = 0;
    float total_pagar = 0;
    Caja* actual_caja = caja;
    while (actual_caja != NULL)
    {
        if ((actual_caja->carro.cliente_id != 0)&&(puntero==0)){
             printf("Boleta Cliente: %d \n",actual_caja->carro.cliente_id);
            for(int i=0;i<NUM_PRODUCTOS;i++){
                int aux_precio =  actual_caja->carro.productos[i].precio * 100;
                if(aux_precio >  0){
                    printf("- %s : %.2f\n", actual_caja->carro.productos[i].nombre, actual_caja->carro.productos[i].precio);
                    total_pagar += (float) actual_caja->carro.productos[i].precio;
                }
            }
            puntero++;
        }
        actual_caja = actual_caja->siguiente;
    }
    printf("Total a pagar: %.2f", total_pagar);
    printf("\n");
}