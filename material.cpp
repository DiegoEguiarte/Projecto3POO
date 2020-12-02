#include "material.h"

Material::Material()
{
    idMaterial = 0;
    titulo = "";
}

Material::Material(int id, string tit)
{
    idMaterial = id;
    titulo = tit;
}

Material::~Material()
{
}

void Material::setId(int id)
{
    idMaterial = id;
}

int Material::getId()
{
    return idMaterial;
}

void Material::setTitulo(string tit)
{
    titulo = tit;
}

string Material::getTitulo()
{
    return titulo;
}