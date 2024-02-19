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
            tipo_moneda = 1;
            break;
        case 2:
            tipo_moneda = 2;
            break;
        default:
            throw std::runtime_error("El tipo de moneda elegida no existe.");
        }

        std::cout << "Ingrese la cantidad de dinero inicial de su cuenta: ";
        std::cin >> dinero_cuenta;
        if (std::cin.fail() || dinero_cuenta < 0){
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
        int tipo_moneda_archivo;
        double dinero;
        std::string linea;

        while (std::getline(archivo_entrada, linea)) {
            std::istringstream ss(linea);

            if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                if (id == cedula_cliente) {
                    if (tipo_moneda_archivo == tipo_moneda){
                        std::cout << "Este usuario ya posee una cuenta de este tipo" <<  std::endl;
                        std::cout << "Intente otra vez..." << std::endl;
                        archivo_entrada.close();
                        return false;
                    }
                }else{
                    continue;
                }
            } else {
                // Hubo un problema al procesar la línea
                std::cerr << "Error al procesar la línea: " << linea << std::endl;
            }
        
        } 
        archivo_entrada.close();
        return true;
    } else{
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
        return false;
    }
}

void CuentasAhorros::guardarDatos(){
    
    std::ofstream archivo("cuentasAhorros.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << this->cedula_cliente << "," << tipo_moneda << "," << this->dinero_cuenta << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}
