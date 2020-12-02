#include "reserva.h"

Reserva::Reserva()
{
    idMaterial = 0;
    idCliente = 0;
}

Reserva::Reserva(int idm, int idc, Fecha *f)
{
    idMaterial = idm;
    idCliente = idc;
    fechaReservacion = f;
}

Reserva::~Reserva()
{
    delete fechaReservacion;
}

Fecha Reserva::calcularFechaFinReserva(int cantDias)
{
    return *fechaReservacion + cantDias;
}

void Reserva::setIdMaterial(int id)
{
    idMaterial = id;
}

int Reserva::getIdMaterial()
{
    return idMaterial;
}

void Reserva::setIdCliente(int id)
{
    idCliente = id;
}

int Reserva::getIdCliente()
{
    return idCliente;
}

void Reserva::setFecha(Fecha *f)
{
    fechaReservacion = f;
}

Fecha* Reserva::getFecha()
{
    return fechaReservacion;
}

void Reserva::printReserva()
{
    cout << "Cliente: " << idCliente << " - Material: " << idMaterial << " - Fecha: ";
    fechaReservacion->printFecha();
    cout << endl;
}