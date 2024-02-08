#include "clientes.hpp"
#include <iostream>
#include <fstream> // Header encargado de la manipulacion de archivos .txt

// Se deben agregar manejos de excepciones de los datos float y strings

Clientes::Clientes(long long int id, const std::string& nombre) : cliente_id(id), nombre(nombre) {}

void Clientes::mostrarYGuardarInformacion() const {
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
int main(){

    long long int id;
    std::string nombre;
    std::cout << "Ingrese el ID: ";
    std::cin >> id;

    std::cout << "Ingrese nombre: ";
    std::cin.ignore();  
    std::getline(std::cin, nombre);

    Clientes cliente(id, nombre);
    cliente.mostrarYGuardarInformacion();
    return 0;

}