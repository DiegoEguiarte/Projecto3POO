#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <string>
#include "material.h"

using namespace std;

class Software: public Material
{
private:
    int Version;
    string SO;
public:
    Software(); // Constructor por defecto
    Software(int v, string s, int id, string tit); // Constructor parametrizado
    ~Software(); // Destructor de la clase
    void setSO(string s); // Método modificador del SO
    string getSO(); // Método de acceso al nombre del SO
    void setVersion(int v); // Método modificador de la version
    int getVersion(); // Método de acceso a la version
    void muestraDatos(); // Método que muestra la información de la estructura
    int cantidadDiasPrestamo(); // Método que devuelve la cantidad de dias que puede ser prestado
};

#endif