#include "software.h"


Software::Software()
{
    Version = 0;
    SO = "";
    idMaterial = 0;
    titulo = "";
    diasPrestamo = 1;
}

Software::Software(int v, string s, int id, string tit):Material(id,tit)
{
    Version = v;
    SO = s;
    diasPrestamo = 1;
}

Software::~Software()
{
}

string Software::getSO()
{
    return SO;
}

int Software::getVersion()
{
    return Version;
}

void Software::muestraDatos()
{
    cout << "ID: " << idMaterial << " - Titulo: " << titulo << " - SO: " << SO << " - Versión: " << Version << endl;
}

int Software::cantidadDiasPrestamo()
{
    return diasPrestamo;
}