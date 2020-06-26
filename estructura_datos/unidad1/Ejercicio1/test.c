#include "supermercado.c"

int main()
{
    int carros_usados = 0;
    //Asignamos memoria a las cajas del supermercado
    Caja* caja[NUM_CAJAS];
    caja[0] = malloc(sizeof(Caja));
    caja[1] = malloc(sizeof(Caja));
    caja[2] = malloc(sizeof(Caja));

    //Declaramos los productos
    Producto productos[NUM_PRODUCTOS];

    //Creamos productos
    productos[0].id = 1111;
    productos[0].precio = 1.2;
    strcpy(productos[0].nombre , "Leche");
    productos[1].id = 1112;
    productos[1].precio = 0.8;
    strcpy(productos[1].nombre , "Azucar");
    productos[2].id = 1113;
    productos[2].precio = 2.5;
    strcpy(productos[2].nombre , "Chocolate");
   
    //Declaramos carros con un limite de 25
    CarritoDeCompra carros[NUM_CARROS];

    // Personas toman un carro
    carros[0].id = 1111;
    carros[0].cliente_id = 1111;
    carros[0].productos[0] = productos[0];
    carros[0].productos[1] = productos[1];
    carros[0].productos[2] = productos[2];
    carros_usados++;

    carros[1].id = 2;
    carros[1].cliente_id = 1112;
    carros[1].productos[0] = productos[0];
    carros[1].productos[1] = productos[1];
    carros_usados++;

    carros[2].id = 3;
    carros[2].cliente_id = 1113;
    carros[2].productos[0] = productos[0];
    carros_usados++;

    carros[3].id = 4;
    carros[3].cliente_id = 1114;
    carros[3].productos[0] = productos[0];
    carros[3].productos[1] = productos[1];
    carros[3].productos[2] = productos[2];
    carros_usados++;

    carros[4].id = 5;
    carros[4].cliente_id = 1115;
    carros[4].productos[0] = productos[0];
    carros[4].productos[1] = productos[1];
    carros_usados++;

    encola(&caja[0], carros[0]);
    encola(&caja[0], carros[1]);
    encola(&caja[1], carros[2]);

    //Imprime clientes que estan haciendo cola
    printf("Caja %d, los siguientes clientes estan haciendo cola:\n", 1);
    imprimirCola(caja[0]);

    printf("Caja %d, los siguientes clientes estan haciendo cola:\n", 2);
    imprimirCola(caja[1]);

    // Procesos para realizar pago y quitar cliente de la cola
    printf("\n\n ******* Pago Caja %d\n", 1);
    imprimirBoleta(caja[0]);
    printf("****\nFin Boleta\n\n");
    pago(&caja[0]);

    printf("Caja %d, los siguientes clientes estan haciendo cola:\n", 1);
    imprimirCola(caja[0]);

    return 0;
}