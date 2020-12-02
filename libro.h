#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include "material.h"

using namespace std;

class Libro: public Material
{
private:
    int numPag;
    string Autor;
public:
    Libro(); // Constructor por defecto 
    Libro(int n, string a, int id, string tit); // Constructor parametrizado
    ~Libro(); // Destructor
    void setAutor(string a); // Método modificador del autor
    string getAutor(); // Método de acceso al autor
    void setNumpag(int n); // Método modificador del numero de paginas
    int getNumpag(); // Método de acceso al numero de paginas
    void muestraDatos(); // Método que muestra la información del libro
    int cantidadDiasPrestamo(); // Método que devuelve la cantidad de dias que puede ser prestado
};

#endif