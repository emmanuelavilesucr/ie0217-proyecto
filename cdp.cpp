#include "cdp.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip> 

CDP::CDP(long long int cedula) : cedula_cliente(cedula) {}

void CDP::ingresarCDP(){
    std::ofstream archivo("CDP.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << cedula_cliente << "," << std::fixed << std::setprecision(0) << montoCDP << "," << interes << "," << tipo << "," << plazo << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}

void CDP::menuPrincipal(){
    int opcion;
    std::cout << "\n --- Certificados de Depósitos ---\n";
    std::cout << "1. Crear CDP\n";
    std::cout << "2. Ver CDPs\n";
    std::cout << "3. Salir\n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                menuSecundario(); 
                break;
            }
            case 2:
                mostrarCDPs();
                break;
            case 3:
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

void CDP::menuSecundario() {   
    int opcion_divisa;
    std::cout << "\n --- Tipo de Divisa: ---\n";
    std::cout << "1. Colones \n";
    std::cout << "2. Dólares\n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_divisa;
        switch (opcion_divisa) {
            case 1:
                tipo = "Colones"; 
                menuPlazos(); 
                break;
            case 2:
                tipo = "Dólares"; 
                menuPlazos(); 
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

void CDP::menuPlazos() {
    int opcion_plazo;
    std::cout << "\n --- Plazos: ---\n";
    std::cout << "1. Tres meses a 3% \n";
    std::cout << "2. Seis meses a 4% \n";
    std::cout << "3. Doce meses a 5% \n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_plazo;
        switch (opcion_plazo) {
            case 1:
                plazo = 3;
                interes = 3;
                monto(); 
                break;
            case 2:
                plazo = 6;
                interes = 4;
                monto(); 
                break;
            case 3:
                plazo = 12;
                interes = 5;
                monto(); 
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

void CDP::monto() {
    double monto;
    std::cout << "Ingrese el monto: ";
    std::cin >> monto;
    montoCDP = monto; 
    ingresarCDP(); 
}

void CDP::mostrarCDPs(){
    std::ifstream archivo("CDP.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string idCuentaStr, montoStr, interesStr, tipoStr, plazoStr; 
            if (std::getline(ss, idCuentaStr, ',') &&
                std::getline(ss, montoStr, ',') &&
                std::getline(ss, interesStr, ',') &&
                std::getline(ss, tipoStr, ',') && 
                std::getline(ss, plazoStr)) { 
                long long int idCuenta = std::stoll(idCuentaStr);
                double monto = std::stod(montoStr);
                double interes = std::stod(interesStr);
                int plazo = std::stoi(plazoStr); 
                
                std::cout << "ID de Cuenta: " << idCuenta << std::endl;
                std::cout << "Tipo de Divisa: " << tipoStr << std::endl;
                std::cout << "Interés: " << interes << "%" << std::endl;
                std::cout << "Monto: " << monto << std::endl;
                std::cout << "Plazo: " << plazo << " meses" << std::endl; 
                std::cout << std::endl;
            }
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo CDP.txt." << std::endl;
    }
}
