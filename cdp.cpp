#include "cdp.hpp"
#include <iostream>
#include <fstream>


void CDP::ingresarCDP() {
    
 // std::cout << "ID de Cliente: " << cliente_id << ", Nombre: " << nombre << std::endl;

    std::ofstream archivo("CDP.txt", std::ios::app);
    if (archivo.is_open()) {        
        archivo << idCuenta << "," << montoCDP << "," << interes << "," << tipo <<  std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}


// main provisional

int main() {
    
    CDP miCDP;

    long long int idCuenta;
    std::cout << "Ingrese el ID de la cuenta: ";
    std::cin >> idCuenta;
    miCDP.setIdCuenta(idCuenta);


    double interes;
    std::cout << "Ingrese el interes: ";
    std::cin >> interes;
    miCDP.setInteres(interes);

    double monto;
    std::cout << "Ingrese el monto: ";
    std::cin >> monto;
    miCDP.setMontoCDP(monto);

    miCDP.setTipo("Colones");
    miCDP.ingresarCDP();

    std::cout << "Se ha ingresado el CDP en el archivo." << std::endl;

    return 0;
}


