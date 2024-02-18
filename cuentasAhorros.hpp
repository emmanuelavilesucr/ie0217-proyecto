#ifndef CUENTASAHORROS_CPP
#define CUENTASAHORROS_CPP
#include <stdexcept>
#include <iostream>
#include <fstream>

class CuentasAhorros{
    public:
        
        CuentasAhorros(long long int cedula);
        bool crearCuenta();
    
    private:
        long long int cedula_cliente;
        double dinero_cuenta;
        bool tipo_moneda;

        bool verificarCuentaAhorrosRepetida();
};

#endif