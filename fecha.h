#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>

using namespace std;

class Fecha
{
private:
    int dd; // Dia
    int mm; // Mes
    int aa; // Año
    string nombreMes(); // Método que retorna el nombre del mes de la fecha
public:
    Fecha(); // Constructor por defecto
    Fecha(int d, int m , int a); // Constructor parametrizado
    ~Fecha(); // Destructor
    int getDia(); // Metodo de acceso al dia
    int getMes(); // Metodo de acceso al mes
    int getAnio();// Metodo de acceso al año
    void setFecha(int d, int m, int a); // Método modificador de la fecha
    Fecha operator +(int dias); // Operador de suma de fecha + dias
    bool operator >=(Fecha f); // Operador de comparacion >= entre fechas
    bool operator <=(Fecha f); // Operador de comparacion <= entre fechas
    bool operator >(Fecha f); // Operador de comparacion > entre fechas
    bool operator <(Fecha f); // Operador de comparacion < entre fechas
    bool operator ==(Fecha f); // Operador de comparacion == entre fechas
    istream& operator >>(istream& s); // Operador de entrada desde stream
    ostream& operator <<(ostream& s); // Operador de salida a stream
    void printFecha(); // Funcion utilizada para imprimir la informacion de la fecha
};

#endif