#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "menusinfoCliente.hpp"
using namespace std;

class Prestamos: public MenusInfoCliente {
    public:
        Prestamos(long long int id);
        void procesarOpcionPrestamos();
        void menuPrestamos();
        int generarNuevoID();
        void procesarOpcion1();
        void menuPrincipal();
        void EscribirPrestamo(std::string tipo, std::string plazo, double interes, int cuotas, double monto, bool moneda);
        void nuevoPrestamo();
        bool verificarCuenta();
        void procesarOpcionSecun(Datos prestamo);
        bool procesarOpciontercearia();
        void prestamosAsociados();

    protected:
        long long int idPrestamo;
        long long int id;
        std::string nombreAsociado;
        std::string tipoPrestamo;
        double montoPrestamo;
        double interes;
        //int cuotas;
};
#endif