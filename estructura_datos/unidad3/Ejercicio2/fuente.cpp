/**
PROGRAMA 2:
Se necesita crear un archivo binario formado por registros que representan productos de perfumería. 
Los campos de cada registro son: código de producto, descripción, precio y número de unidades. 
La dirección de cada registro viene dada por una función hash que toma como campo clave el código del producto (tres dígitos):
hash(clave) = (clave modulo97) +1
El número máximo de productos distintos es 100. Las colisiones, de producirse, 
se situarán secuencialmente a partir del registro número 120.

* Autor: Bedo Cáceres
* Version 1.1
* Fecha: 28/10/2019
**/

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 3

/* Estructura de datos Producto */
struct Producto
{
    int codigo;
    string nombre;
    float precio;
};

int main()
{
    /* Abre el archivo binario */
    ofstream wfile("info.dat", ios::out | ios::binary);
    /* Revisa si al abrir el archivo tiene error */
    if (!wfile)
    {
        cout << "Cannot open file!" << endl;
        return 1;
    }
    // Listo de productos
    Producto listado[MAX];
    listado[0].codigo = 1;
    listado[0].nombre = "Perfume Adidas";
    listado[0].precio = 4200;
    listado[1].codigo = 2;
    listado[1].nombre = "Colonia Inglesa";
    listado[1].precio = 1500;
    listado[2].codigo = 3;
    listado[2].nombre = "Perfume Calvin Klein";
    listado[2].precio = 2000;
    /* Escribir en un archivo */
    for (int i = 0; i < MAX; i++)
        wfile.write((char *)&listado[i], sizeof(Producto));
    /* Cerrar archivo */
    wfile.close();
    /* Revisa si el archivo binario se encuentra en buen estado */
    if (!wfile.good())
    {
        cout << "Ocurrio un error al abrir el archivo!" << endl;
        return 1;
    }
    /* Abrimos archivo binario */
    ifstream rfile("info.dat", ios::in | ios::binary);
    /* Revisa si el archivo se pudo abrir */
    if (!rfile)
    {
        cout << "No puede abrir el archivo!" << endl;
        return 1;
    }
    Producto leer_listado[MAX];
    /* Leer el archivo */
    for (int i = 0; i < MAX; i++)
        rfile.read((char *)&leer_listado[i], sizeof(Producto));
    /* cierra el archivo */
    rfile.close();
    /* Verfica si el archivo esta correcto */
    if (!rfile.good())
    {
        cout << "Error al leer el archivo" << endl;
        return 1;
    }
    //Imprime el archivo
    for (int i = 0; i < MAX; i++)
    {
        cout << "Código: " << leer_listado[i].codigo << endl;
        cout << "Nombre del Producto: " << leer_listado[i].nombre << endl;
        cout << "Precios: " << leer_listado[i].precio << endl;
        cout << endl;
    }
    return 0;
}