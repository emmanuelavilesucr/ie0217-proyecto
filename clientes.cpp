#include "clientes.hpp"
#include <iostream>
#include <fstream> // Header encargado de la manipulacion de archivos .txt
#include <limits> // Header encargado de los limites numericos 

Clientes::Clientes(long long int id, const std::string& nombre) : cliente_id(id), nombre(nombre) {}

/**
 * 
 * Esta funcion guarda el ID y el nombre del cliente. 
 * 
 * @brief Si el archivo no existe, el programa creara el archivo
 */
void Clientes::GuardarInformacion() const {

    std::cout << "ID del Cliente: " << cliente_id << ", Nombre: " << nombre << std::endl;
    std::ofstream archivo("clientes.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << cliente_id << "," << nombre << std::endl;  // Escribe los datos del cliente en archivo txt
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}
