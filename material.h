#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <string>

using namespace std;

class Material
{
protected:
    int idMaterial;
    string titulo;
    int diasPrestamo;
public:
    Material(); // Constructor default
    Material(int id, string tit); // Constructor parametrizado
    ~Material(); // Destructor
    virtual void muestraDatos() =0; // Funcion que muestra los datos del material
    virtual int cantidadDiasPrestamo() =0; // Funcion que devuelve la cantidad de dias que puede ser prestado el material
    void setId(int id); // Metodo modificador del id del material
    int getId(); // Método de acceso al id del material
    void setTitulo(string tit); // Método modificador del titulo
    string getTitulo(); // Método de acceso al titulo del material
};

#endif