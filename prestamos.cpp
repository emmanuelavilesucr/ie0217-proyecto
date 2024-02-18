#include "prestamos.hpp"
#include <fstream>


void Prestamos::nuevoPrestamo(){
    
}

void Prestamos::EscribirPrestamo(){

   // std::cout << "ID del Cliente: " << cliente_id << ", Nombre: " << nombre << std::endl;
    std::ofstream archivo("prestamos.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << idCuenta << "," << montoPrestamo << "," << interes << "," << cuotas <<  std::endl;  // Escribe los datos del cliente en archivo txt
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}