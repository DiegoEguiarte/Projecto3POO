#include <fstream>
#include <iostream>
#include <string>

// Librerias de estructuras
#include "disco.h"
#include "fecha.h"
#include "libro.h"
#include "material.h"
#include "reserva.h"
#include "software.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Material *materiales[30]; // Arreglo de materiales
    Reserva *reservas[60]; // Arreglo de reservas

    ifstream mat{"Material.txt"}; // Archivo de entrada de materiales
    ifstream res{"Reserva.txt"}; // Archivo de entrada de reservas

    if (!mat || !res) // Si alguno de los dos archivos generó un error
    {
        cout << "Error de archivos" <<endl;
        return 1; // Terminar la ejecucion con código de error 1
    }
    
    
    int mt = 0; // Contador de materiales

    while(mat) // Leer el archivo hasta el final
    {
        // Variables para la instanciacion de estructuras:
        string tit,tip,b;
        int id,a;
        // Ingresando los valores adecuados en las variables
        mat >> id >> tit >> tip >> a >> b;
        if (tip == "L") // Si el material es un libro
        {
            materiales[mt] = new Libro(a,b,id,tit); // Crear un nuevo libro y agregarlo al arreglo
            mt++;
        }
        else if (tip == "D") // Si el material es un disco
        {
            materiales[mt] = new Disco(a,b,id,tit); // Crear un nuevo disco y agregarlo al arreglo
            mt++;
        }
        else if (tip == "S") // Si el material es un software
        {
            materiales[mt] = new Software(a,b,id,tit); // Crear un nuevo software y agregarlo al arreglo
            mt++;
        }
    }
    mat.close(); // Closing the file

    int r = 0; // Contador de reservas

    while (res) // Leer el archivo hasta el final
    {
        int d,m,a,idm,idc; // Variables utilizadas para la instanciacion de nuevas reservas
        res >> d >> m >> a >> idm >> idc; // Asignando valores de la reserva a las variables
        Fecha *f = new Fecha(d,m,a); // Creando la nueva fecha
        reservas[r] = new Reserva(idm,idc,f); // Creando la nueva reserva y agregandola al arreglo
        r++;
    }
    res.close(); // Closing the file

    char opt = 'q'; // Variable que almacena la opcion del menu escogida

    int d,m,a,idm,idc; // Variables utilizadas en las distintas opciones del menu
            
    while (opt != 'f')
    {
        cout << endl << "Menu:" << endl;
        cout << "a) Consultar la lista de Materiales." << endl;
        cout << "b) Consultar la lista de reservaciones." << endl;
        cout << "c) Consultar las reservaciones de un material dado." << endl;
        cout << "d) Consultar las reservaciones de una fecha dada." << endl;
        cout << "e) Hacer una reservación." << endl;
        cout << "f) Terminar." << endl;
        cout << "Introduzca su opcion: ";
        cin >> opt;
        cout << endl;
    
        if (tolower(opt) == 'a')
        {
            for (int i = 0; i < mt; i++)
            {
                materiales[i]->muestraDatos();
            }
            
        }
        else if (tolower(opt) == 'b')
        {
            for (int i = 0; i < r; i++)
            {
                reservas[i]->printReserva();
            }
            
        }
        else if (tolower(opt) == 'c')
        {
            cout << endl << "Ingrese el ID del material a ser buscado: ";
            cin >> idm;
            cout << endl;
            for (int i = 0; i < r; i++)
            {
                if (idm == reservas[i]->getIdMaterial())
                {
                    reservas[i]->printReserva();
                }   
            }
        }
        else if (tolower(opt) == 'd')
        {
            cout << "Introduzca el dia: ";
            cin >> d;
            cout << "Introduzca el mes: ";
            cin >> m;
            cout << "Introduzca el año: ";
            cin >> a;
            Fecha f(d,m,a);
            for (int i = 0; i < r; i++)
            {
                if (*reservas[i]->getFecha() == f)
                {
                    reservas[i]->printReserva();
                }
            }
        }
        else if (tolower(opt) == 'e')
        {
            cout << "Introduzca el ID del material que sera reservado: ";
            cin >> idm;
            cout << "Introduzca el ID del cliente: ";
            cin >> idc;
            cout << "Introduzca el dia de la reserva: ";
            cin >> d;
            cout << "Introduzca el mes de la reserva: ";
            cin >> m;
            cout << "Introduzca el año de la reserva: ";
            cin >> a;
            Fecha *f = new Fecha(d,m,a);
            reservas[r] = new Reserva(idm,idc,f);
            r++;
            cout << "Listo" << endl << endl;
        }
    }

    for (int i = 0; i < mt; i++)
    {
        delete materiales[i];
    }
    
    for (int i = 0; i < r; i++)
    {
        delete reservas[i];
    }
    cout << "Finalizando el programa." << endl;

    return 0;
}
