#ifndef CUENTASAHORROS_CPP
#define CUENTASAHORROS_CPP
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>

class CuentasAhorros{

    public:
        CuentasAhorros(long long int cedula);
        bool crearCuenta();
        void menuAccionesCuenta();
    
    private:
        long long int cedula_cliente;
        double dinero_cuenta;
        int tipo_moneda;

        bool verificarCuentaAhorrosRepetida();
        void guardarDatos();
};

#endif