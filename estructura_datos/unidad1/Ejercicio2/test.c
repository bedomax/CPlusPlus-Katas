#include <stdlib.h>
#include <stdlib.h>
#include "pila.c"

int main(){
  Pila p, c_pila, aux;
  crearPila(&p);
  crearPila(&aux);

  apilar(&p, "17.151.821-5");
  apilar(&p, "24.098.397-4");
  apilar(&p, "15.257.336-7");
  apilar(&p, "18.065.062-8");

  mostrar(&p);

  c_pila = p;
  desapilar(&p);
  
  printf("\n\nCopiar\n");
  mostrar(&p);  
  mostrar(&c_pila);

  printf("\n\n\n");

  return 0;
}
