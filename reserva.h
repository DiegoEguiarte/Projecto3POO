#ifndef RESERVA_H
#define RESERVA_H

#include <ctime>
#include "fecha.h"
#include "material.h"

using namespace std;

class Reserva
{
private:
    int idMaterial;
    int idCliente;
    Fecha *fechaReservacion;
public:
    Reserva(); // Constructor default
    Reserva(int idm, int idc, Fecha *f); // Constructor parametrizado
    ~Reserva(); // Destructor
    
    // Funcion que devuelve la fecha luego de cantDias
    // a partir de la fecha de reserva
    Fecha calcularFechaFinReserva(int cantDias); 
    void setIdMaterial(int id); // Metodo modificador del id del material
    int getIdMaterial(); // Método de acceso al id del material
    void setIdCliente(int id); // Método modificador del id del cliente
    int getIdCliente(); // Método de acceso al id del cliente
    void setFecha(Fecha *f); // Método modificador de la fecha de reserva
    Fecha* getFecha(); // Método de acceso a la fecha de reserva
    void printReserva(); // Método utilizado para imprimir la informacion de la reserva
};



#endif