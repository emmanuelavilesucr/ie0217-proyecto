#include "clientes.hpp"
#include <iostream>
#include <fstream> // Header encargado de la manipulacion de archivos .txt
#include <limits> // Header encargado de los limites numericos 

Clientes::Clientes(long long int id, const std::string& nombre) : cliente_id(id), nombre(nombre) {}

void Clientes::GuardarInformacion() const {

    std::cout << "ID del Cliente: " << cliente_id << ", Nombre: " << nombre << std::endl;
    std::ofstream archivo("clientes.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << cliente_id << "," << nombre << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}


// Funcion main provicional(testeo de la clase)
int main() {
    long long int id;
    std::string nombre;
    
    do {
        std::cout << "Ingrese el ID: ";
        std::cin >> id;

        if (id < 0 || id > 999999999) {
            std::cerr << "El ID debe tener un maximo de 9 digitos. Vuelva a intenterlo....." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            break; 
        }
    } while (true);

    std::cout << "Ingrese nombre: ";
    std::cin.ignore();  
    std::getline(std::cin, nombre);

    Clientes cliente(id, nombre);
    cliente.GuardarInformacion();

    return 0;
}