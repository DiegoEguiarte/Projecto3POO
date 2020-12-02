#include "libro.h"

Libro::Libro()
{
    numPag = 0;
    Autor = "";
    idMaterial = 0;
    titulo = "";
    diasPrestamo = 5;
}

Libro::Libro(int n, string a, int id, string tit):Material(id,tit)
{
    numPag = n;
    Autor = a;
    diasPrestamo = 5;
}

Libro::~Libro()
{
}

void Libro::setAutor(string a)
{
    Autor = a;
}

string Libro::getAutor()
{
    return Autor;
}

void Libro::setNumpag(int n)
{
    numPag = n;
}

int Libro::getNumpag()
{
    return numPag;
}

void Libro::muestraDatos()
{
    cout << "ID: " << idMaterial << " - Titulo: " << titulo << " - Autor: " << Autor << " - Numero de Paginas: " << numPag << endl;
}

int Libro::cantidadDiasPrestamo()
{
    return diasPrestamo;
}