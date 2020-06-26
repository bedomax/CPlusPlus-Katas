/**
PROGRAMA 1:
Construir un programa tal que lea un archivo de texto llamado IntProg_U4.txt y cuente 
los espacios en blanco, dígitos, letras, cambios de línea (‘\n’) y otro tipo de caracteres que existan. 

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 21/11/2019
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Declaramos funciones
bool esNumero(char caracter);
bool esLetra(char caracter);
bool esVacio(char caracter);
bool esSaltoLinea(char caracter);
bool esOtro(char caracter);

//Definimos los valores de los caracteres de español áéíóúñÁÉÍÓÚÑ
 enum CARACTERES_ESPECIALES{
                a_tilde   = -95,
                e_tilde   = -87,
                i_tilde   = -83,
                o_tilde   = -77,
                u_tilde   = -70,
                n_tilde   = -79,
                A_tilde   = -127,
                E_tilde   = -119,
                I_tilde   = -115,
                O_tilde   = -109,
                U_tilde   = -102,
                N_tilde   = -111 };

//Constantes para la validación de caracteres
#define ESCAPAR_TILDE -61
#define VACIO ' '
#define SALTO_DE_LINEA '\n'
const int caracteres_especiales[12] = {a_tilde, e_tilde, i_tilde, o_tilde, u_tilde, n_tilde, A_tilde,E_tilde, I_tilde, O_tilde,U_tilde,N_tilde }; 

// Programa principal
int main()
{
    //Declaramos variables que contarán los caracteres
    int n_blancos = 0, n_digitos = 0;
    int n_letras = 0, n_lineas = 0, n_otros = 0, total = 0;
    char caracter;
    //Definimos el objeto para cargar archivo
    FILE *archivo;
    //Abrimos el archivo con fopen
    archivo = fopen("IntProg_U4.txt", "r");
    while ((caracter = fgetc(archivo)) != EOF) /* Ciclo repetitivo hasta llegar al final del archivo */
    {   

        n_digitos += esNumero(caracter) ? 1 : 0;    //Contamos los números
        n_letras += esLetra(caracter) ? 1 : 0;      //Contamos las letras
        n_blancos += esVacio(caracter) ? 1 : 0;     //Contamos espacion en blanco
        n_lineas += esSaltoLinea(caracter) ? 1 : 0; //Contamos las filas por medio \n
        //Si todos son falsos cuenta como otro carácter
        n_otros += esOtro(caracter) ? 1 : 0; //Contamos otros caracteres \n
    }
    total = n_digitos + n_letras + n_blancos + n_lineas + n_otros;
    printf("Resultado de Análisis\n");
    printf("Blancos\tDígitos\tLetras\tLíneas\tOtros\tTotal\n");
    printf("%d\t%d\t%d\t%d\t%d\t%d\t", n_blancos, n_digitos, n_letras, n_lineas, n_otros, total);
    return 0;
}

/**********************
Desarrollo de funciones
**********************/

bool esNumero(char caracter)
{
    //Validamos si existe un número
    return (caracter >= '0' && caracter <= '9') ? true : false;
}
bool esLetra(char caracter)
{
    //Validamos si existe un carácter de a - z y A - Z 
    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z'))
    {
        return true;
    }
    else
    {  
        //Escapamos el carácter de tílde
        if ((int)caracter != ESCAPAR_TILDE){
            //Obtenemos el tamaño del array de carácteres especiales
            int length = sizeof(caracteres_especiales)/sizeof(caracteres_especiales[0]);
            //iteramos el de carácteres especiales
            for(int i=0; i<=length; i++){
                //Si existe devuelve true
                if((int)caracter == caracteres_especiales[i]){
                    return true;
                }
            }
        }
        return false;
    }
}


bool esVacio(char caracter)
{
    // VALIDAMOS SI HAY CAMPOS EN BLANCO
    return (caracter == VACIO) ? true : false;
}

bool esSaltoLinea(char caracter)
{
    // VALIDAMOS SI HAY SALTO DE LINEA \n
    return (caracter == SALTO_DE_LINEA) ? true : false;
}

bool esOtro(char caracter)
{
    //Escapamos el carácter de tílde
    if ((int)caracter == ESCAPAR_TILDE){
        return false;
    }
    // SI NO ES NINGUNO DE LOS CASOS ES OTRO
    return !(esNumero(caracter) || esLetra(caracter) || esVacio(caracter) || esSaltoLinea(caracter)) ? true : false;
}