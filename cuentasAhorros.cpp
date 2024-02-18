#include "cuentasAhorros.hpp"

CuentasAhorros::CuentasAhorros(long long int cedula) : cedula_cliente(cedula) {}

bool CuentasAhorros::crearCuenta(){
    int tipo;
    
    std::cout << "---Creando su cuenta de ahorros---" << std::endl;
    std::cout << std::endl;

    std::cout << "---Tipo de moneda---" << std::endl;
    std::cout << "1. Colones" << std::endl;
    std::cout << "2. Dolares" << std::endl;
    std::cout << "Elija un tipo de moneda para su cuenta: ";
    std::cin >> tipo;

    switch (tipo){
    case 1:
        this->tipo_moneda = true;
        break;
    case 2:
        this->tipo_moneda = false;
        break;
    default:
        throw std::runtime_error("El tipo de moneda elegida no existe.");
    }

    std::cout << "Ingrese la cantidad de dinero inicial de su cuenta: ";
    std::cin >> this->dinero_cuenta;
    if (std::cin.fail() || this->dinero_cuenta < 0){
            throw std::runtime_error("La cantidad de dinero elegida no es valida");
        }

    bool verificarCuentaAhorrosRepetida();
}