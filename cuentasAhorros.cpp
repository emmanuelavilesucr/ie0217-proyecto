#include "cuentasAhorros.hpp"

CuentasAhorros::CuentasAhorros(long long int cedula) : cedula_cliente(cedula) {}

bool CuentasAhorros::crearCuenta(){
    try{
        int tipo;

        std::cout << "---Creando su cuenta de ahorros---" << std::endl;
        std::cout << std::endl;

        std::cout << "---Tipo de moneda---" << std::endl;
        std::cout << "1. Colones" << std::endl;
        std::cout << "2. Dolares" << std::endl;
        std::cout << "Elija un tipo de moneda para su cuenta: ";
        std::cin >> tipo;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("No ha colocado un numero para el tipo de moneda");
        }

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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("La cantidad de dinero elegida no es valida");
            }

        bool verificando;

        verificando = verificarCuentaAhorrosRepetida();
        if (verificando == true){
            guardarDatos();
            return true;

        }else{
            return false;
        }
    }catch (std::exception& e){
        std::cerr << "Atencion: " << e.what() << std::endl;
        return false;
    }
}

bool CuentasAhorros::verificarCuentaAhorrosRepetida(){
    
    std::ifstream archivo_entrada("cuentasAhorros.txt");

    if (archivo_entrada.is_open()) {
        long long int id;
        bool tipo_moneda;
        double dinero;

        while (archivo_entrada >> id >> std::ws && archivo_entrada >> tipo_moneda >> std::ws && archivo_entrada >> dinero) {
            if (id == this->cedula_cliente && tipo_moneda == this->tipo_moneda){
                std::cout << "Ya existe una cuenta de ahorros con este tipo de moneda para este usuario" <<  std::endl;
                std::cout << "Intente otra vez..." << std::endl;
                return false;
            }
        }
        archivo_entrada.close();
        return true;
    } else {
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
    }

    return false;
}

void CuentasAhorros::guardarDatos(){
    
    std::ofstream archivo("cuentasAhorros.txt", std::ios::app);
    if (archivo.is_open()) {
        if (tipo_moneda == true){
            archivo << this->cedula_cliente << "," << "true" << this->dinero_cuenta << std::endl;
            archivo.close();
        }else{
            archivo << this->cedula_cliente << "," << "false" << "," << this->dinero_cuenta << std::endl;
            archivo.close();
        }
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}
