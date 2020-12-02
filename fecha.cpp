#include "fecha.h"

Fecha::Fecha()
{
    dd = 0;
    mm = 0;
    aa = 0;
}

Fecha::Fecha(int d, int m , int a)
{
    setFecha(d,m,a);
}

Fecha::~Fecha()
{
}

string Fecha::nombreMes()
{
    switch (mm)
    {
    case 1:
        return "Ene";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Abr";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "Jun";
        break;
    case 7:
        return "Jul";
        break;
    case 8:
        return "Ago";
        break;
    case 9:
        return "Sep";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    case 12:
        return "Dic";
        break;

    default:
        return "";
        break;
    }
}

int Fecha::getDia()
{
    return dd;
}

int Fecha::getMes()
{
    return mm;
}

int Fecha::getAnio()
{
    return 
    aa;
}

void Fecha::setFecha(int d, int m, int a)
{
    dd = d;
    mm = m;
    aa = a;
}

Fecha Fecha::operator +(int dias)
{
    // Variables utilizadas en los calculos
    int d = dd + dias;
    int m = mm;
    int a = aa;
    
    bool bisiesto = ((a % 4 == 0) && (a % 400 == 0) && (a % 100 == 0)); // Flag para saber si el año es bisiesto

    int aux; // Variable auxiliar utilizada para culminar la ejecución de la función

    while (true)
    {
        aux = d; 
        if (m == 2 && d > 28 && !bisiesto) // Si hay mas de 28 dias, el año no es bisiesto y el mes es febrero
        {
            m++; // Pasar al siguiente mes
            d = d - 28; // Restar los dias del mes de febrero
            if (d <= 31) // Si no hay mas de un mes restante en dias, termina la ejecucion
            {
                break;
            }
        }
        else if (m == 2 && d > 29 && bisiesto) // Si hay mas de 29 dias, el año es bisiesto y el mes es febrero
        {
            m++; // Pasar al siguiente mess
            d = d - 29; // Restar los dias de febrero bisiesto
            if (d <= 31) // Si no hay mas de un mes restante en dias, termina la ejecucion
            {
                break;
            }
        }
        else if (((m < 7 && m % 2 == 0) || (m > 8 && m % 2 != 0)) && d > 30) // Si es un mes de 30 dias y hay mas de 30 dias
        {
            d = d - 30; // Restar los dias del mes
            m++; // Pasar al siguiente mes
            if (d <= 31) // Si no hay mas de un mes restante en dias, termina la ejecucion
            {
                break;
            }
            
        }
        else if (((m <= 7 && m % 2 != 0) || (m >= 8 && m % 2 == 0)) && d > 31) // Si es un mes de 31 dias y hay mas de 31 dias
        {
            d = d - 31; // Restar los dias del mes
            m++; // Aumentar el mes
            if (m == 13) // Si se termina diciembre, comienza otro año
            {
                m = 1; // Año nuevo comienza en enero
                a++; // Avanzar al siguiente año
                if (d <= 31) // Si no hay mas de un mes restante en dias, termina la ejecucion
                {
                    break;
                }
                
            }
            
            if (d <= 30) // Si no hay mas de un mes restante en dias, termina la ejecucion
            {
                break;
            }
            
        }
        
        // Si la variable auxiliar es igual a la cantidad de dias al inicio y final del ciclo,
        // la cantidad de dias no fue modificada, el ciclo debe terminar.
        if (aux == d) 
        {
            break;
        }
    }

    Fecha out(d,m,a); // Instanciando la nueva fecha
    return out;
}

bool Fecha::operator >=(Fecha f)
{
    return *this > f || *this == f;
}

bool Fecha::operator <=(Fecha f)
{
    return *this < f || *this == f;
}

bool Fecha::operator >(Fecha f)
{
    if (*this == f) // Si las fechas son iguales
    {
        return false;
    }
    if (aa > f.aa) // Si el año de la fecha es mayor que el año de la otra fecha
    {
        return true;
    }
    else // Si no es mayor, es menor o igual:
    {
        if (aa == f.aa) // Si los años son iguales
        {
            if (mm > f.mm) // Se comparan los meses
            {
                return true;
            }
            else // Si el mes no es mayor, es menor o igual
            {
                if (mm == f.mm) // Si los meses son iguales
                {
                    return dd > f.dd; // Se comparan los dias
                }
                else // Si no es mayor ni igual, es menor
                {
                    return false;
                }
                
            }
        }
        else // Si no es mayor ni igual, es menor
        {
            return false;
        }
        
    }
    
}

bool Fecha::operator <(Fecha f)
{
    if (*this == f) // Si las fechas son iguales
    {
        return false;
    }    
    if (aa < f.aa) // Si el año de la fecha es menor al otro año
    {
        return true;
    }
    else // Si no es menor, es mayor o igual
    {
        if (aa == f.aa) // Si los años son iguales
        {
            if (mm < f.mm) // Se comparan los meses
            {
                return true;
            }
            else // Si el mes no es menor, es mayor o igual
            {
                if (mm == f.mm) // Si los meses son iguales
                {
                    return dd < f.dd; // se comparan los dias
                }
                else // Si no es menor ni igual, entonces es mayor
                {
                    return false;
                }
                
            }
        }
        else // Si el año no es menor ni igual, es mayor
        {
            return false;
        }
        
    }
    
}

bool Fecha::operator ==(Fecha f)
{
    return (dd == f.dd) && (mm == f.mm) && (aa == f.aa); // Si ambas fechas son iguales
}

istream& Fecha::operator >>(istream& s)
{
    int d,m,a;
    s >> d >> m >> a;
    setFecha(d,m,a);
    s.ignore();
    return s;
}

ostream& Fecha::operator <<(ostream& s)
{
    s << dd << "/" << nombreMes() << "/" << aa;
    return s;
}

void Fecha::printFecha()
{
    cout << dd << "/" << nombreMes() << "/" << aa;
}