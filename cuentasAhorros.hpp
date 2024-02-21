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
#include <regex>
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
        long long int cedula_cliente_otro = 0;
        double dinero_cuenta_otro;
        int tipo_moneda_otro;
        int cantidad_cuentas_otro = 0;

        bool verificarCuentaAhorrosRepetida();
        void guardarDatos();
        void verMisCuentas();
        void verficarCantidadCuentas();
        void elegirCuenta();
        bool deposito();
        bool retiro(double retiro);
        void actualizarDatos();
        bool tranferirDineroPropia();
        long long int elegirOtroUsuario();
};

#endif