#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP

#include <iostream>
#include "menusinfoCliente.hpp"
using namespace std;

class Prestamos: public MenusInfoCliente {
    public:
        void EscribirPrestamo();
        void nuevoPrestamo();
        bool verificarCuenta();

    protected:
        long long int idCuenta;
        std::string nombreAsociado;
        std::string tipoPrestamo;
        double montoPrestamo;
        double interes;
        int cuotas;
};
#endif