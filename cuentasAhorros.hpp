#ifndef CUENTASAHORROS_CPP
#define CUENTASAHORROS_CPP
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "funciones.hpp"

class CuentasAhorros{

    public:
        CuentasAhorros(long long int cedula);
        bool crearCuenta();
        void menuAccionesCuenta();
    
    private:
        long long int cedula_cliente;
        double dinero_cuenta;
        int tipo_moneda;
        int cantidad_cuentas = 0;

        bool verificarCuentaAhorrosRepetida();
        void guardarDatos();
        void verMisCuentas();
        void verficarCantidadCuentas();
        void elegirCuenta();
        bool deposito();
        bool retiro(double retiro);
        void actualizarDatos();
        bool tranferirDineroPropia();
};

#endif