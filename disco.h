#ifndef DISCO_H
#define DISCO_H

#include <string>
#include "material.h"

using namespace std;

class Disco: public Material
{
private:
    int duracion;
    string Genero;
public:
    Disco(); // Constructor por defecto
    Disco(int d, string g, int id, string tit); // Constructor parametrizado
    ~Disco(); // Destructor
    void setDuracion(int d); // Método modificador de la duracion
    int getDuracion(); // Método de acceso a la duracion del disco.
    void setGenero(string g); // Método modificador del genero
    string getGenero(); // Método de acceso al genero
    void muestraDatos(); // Método que muestra los datos del disco
    int cantidadDiasPrestamo(); // Método que devuelve la cantidad de dias que puede ser prestado
};

#endif