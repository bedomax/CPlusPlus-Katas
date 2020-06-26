/**
PROGRAMA 3: 
Escribe un programa en lenguaje c, que genere una lista circular, doblemente enlazada, 
con 10 cadenas de caracteres ingresadas, desde teclado por el usuario, 
ordénala descendentemente usando el método quick sort.
* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 2/09/2019
**/

#include <stdio.h>
#include <stdlib.h>
 
/* Declaramos estructura */
struct nodo
{
  char dato;
  struct nodo *siguiente;
};
 
/* funcion de ordenamiento con listado de cabecera */
void ordenamiento(struct nodo** cabecera_ref, struct nodo* nuevo_nodo)
{
  struct nodo* actual = *cabecera_ref;
  // Si es nulo
  if (actual == NULL)
  {
     nuevo_nodo->siguiente = nuevo_nodo;
     *cabecera_ref = nuevo_nodo;
  }
 
  // Comparamos si el datos es menos al nuevo nodo
  else if (actual->dato <= nuevo_nodo->dato)
  {
    /* Si el valor es mayor que el valor de la cabeza, entonces
       necesitamos cambiar el siguiente del último nodo */
    while(actual->siguiente != *cabecera_ref)
        actual = actual->siguiente;
    actual->siguiente = nuevo_nodo;
    nuevo_nodo->siguiente = *cabecera_ref;
    *cabecera_ref = nuevo_nodo;
  }
  else
  {
    /* Localiza el nodo antes del punto de insercion */
    while (actual->siguiente!= *cabecera_ref && 
           actual->siguiente->dato > nuevo_nodo->dato)
      actual = actual->siguiente;
 
    nuevo_nodo->siguiente = actual->siguiente;
    actual->siguiente = nuevo_nodo;
  }
}
 
/* Funcion para imprimir el listado */
void imprimirLista(struct nodo *inicio)
{
  struct nodo *temp;
 
  if(inicio != NULL)
  {
    temp = inicio;
    printf("\n");
    do {
      printf("%c ", temp->dato);
      temp = temp->siguiente;
    } while(temp != inicio);
  }
}
 
/* Programa Principal */
int main()
{
  int lista_tamano = 10, i;
  struct nodo *inicio = NULL;
  struct nodo *temp;

  for (i = 0; i< lista_tamano; i++)
  {
    temp = (struct nodo *)malloc(sizeof(struct nodo));
    printf("Ingrese un carácter [%d]:", i + 1);
    scanf("%s", &temp->dato);
    ordenamiento(&inicio, temp);
  }
 
  imprimirLista(inicio);
  return 0;
}