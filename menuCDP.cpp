#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "menuCDP.hpp"
#include "cdp.hpp"

void MenuCDP::mostrarCDPs() {
    std::vector<CDP> cdps;

    std::ifstream archivo("CDP.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string idCuentaStr, montoStr, interesStr, tipo;
            if (std::getline(ss, idCuentaStr, ',') &&
                std::getline(ss, montoStr, ',') &&
                std::getline(ss, interesStr, ',') &&
                std::getline(ss, tipo)) {
                long long int idCuenta = std::stoll(idCuentaStr);
                double monto = std::stod(montoStr);
                double interes = std::stod(interesStr);
                CDP cdp;
                cdp.setIdCuenta(idCuenta);
                cdp.setMontoCDP(monto);
                cdp.setInteres(interes);
                cdp.setTipo(tipo);
                cdps.push_back(cdp);
            }
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo CDP.txt." << std::endl;
        return;
    }

    std::cout << "Información de todos los CDPs:\n";
    for (const auto& cdp : cdps) {
        std::cout << "ID de Cuenta: " << cdp.getIdCuenta() << std::endl;
        std::cout << "Tipo de Divisa: " << cdp.getTipo() << std::endl;
        std::cout << "Interés: " << cdp.getInteres() << "%" << std::endl;
        std::cout << "Monto: " << cdp.getMontoCDP() << std::endl;
        std::cout << std::endl;
    }
}

void MenuCDP::menuPrincipal() {
    int opcion;

    std::cout << "\n --- Certificados de Depósitos ---\n";
    std::cout << " 1. Crear CDP \n";
    std::cout << " 2. Ver CDPs\n";
    std::cout << " Ingrese una opción:\n";
    
    try {
        std::cin >> opcion;
        
        switch (opcion) {
            case 1: {
                CDP cdp; 
                menuSecundario(cdp); 
                break;
            }
            case 2:
                mostrarCDPs();
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}

void MenuCDP::menuSecundario(CDP& cdp) {   
    int opcion_divisa;

    std::cout << "\n --- Tipo de Divisa: ---\n";
    std::cout << " 1. Colones \n";
    std::cout << " 2. Dólares\n";
    std::cout << " Ingrese una opción:\n";
    
    try {
        std::cin >> opcion_divisa;
        
        switch (opcion_divisa) {
            case 1:
                cdp.setTipo("Colones");
                menuPlazos(cdp); 
                break;
            case 2:
                cdp.setTipo("Dólares");
                menuPlazos(cdp); 
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}

void MenuCDP::menuPlazos(CDP& cdp) {
    int opcion_plazo;

    std::cout << "\n --- Plazos: ---\n";
    std::cout << " 1. Tres meses a 3% \n";
    std::cout << " 2. Seis meses a 4% \n";
    std::cout << " 3. Un año a 5% \n";
    std::cout << " Ingrese una opción:\n";
    
    try {
        std::cin >> opcion_plazo;
        
        switch (opcion_plazo) {
            case 1:
                cdp.setInteres(3);
                monto(cdp); 
                break;
            case 2:
                cdp.setInteres(4);
                monto(cdp); 
                break;
            case 3:
                cdp.setInteres(5);
                monto(cdp); 
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}

void MenuCDP::monto(CDP& cdp) {
    double monto;

    std::cout << "Ingrese el monto: ";
    std::cin >> monto;
    cdp.setMontoCDP(monto);
    cdp.ingresarCDP();
}




int main() {
    MenuCDP menu;
    menu.menuPrincipal();
    return 0;
}