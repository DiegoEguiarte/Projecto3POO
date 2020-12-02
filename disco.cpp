#include "disco.h"

Disco::Disco()
{
    duracion = 0;
    Genero = "";
    idMaterial = 0;
    titulo = "";
    diasPrestamo = 3;
}

Disco::Disco(int d, string g, int id, string tit):Material(id,tit)
{
    duracion = d;
    Genero = g;
    diasPrestamo = 3;
}

Disco::~Disco()
{
}

void Disco::setDuracion(int d)
{
    duracion = d;
}

int Disco::getDuracion()
{
    return duracion;
}

string Disco::getGenero()
{
    return Genero;
}

void Disco::setGenero(string g)
{
    Genero = g;
}

void Disco::muestraDatos()
{
    cout << "ID: " << idMaterial << " - Titulo: " << titulo << " - Genero: " << Genero << " - Duración: " << duracion << endl;
}

int Disco::cantidadDiasPrestamo()
{
    return diasPrestamo;
}