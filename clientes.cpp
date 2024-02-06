#include <iostream>
#include <fstream> // Header encargado de la manipulacion de archivos .txt
#include <string>

// Se deben agregar manejos de excepciones de los datos float y strings

class Clientes {
    private:
        long long int id_cliente;
        std::string nombre;

    public:
        Clientes(long long int id,const std::string& nombre) : id_cliente(id), nombre(nombre) {} 
        
        
    void generar_txt() const {
        std::cout << "ID del Cliente: " << id_cliente << ", Nombre: " << nombre << std::endl;

        std::ofstream archivo("clientes.txt", std::ios::app);
        if (archivo.is_open()) {
            archivo << id_cliente << "," << nombre << std::endl;
            archivo.close();
        } else {
            std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
        }
    }

};


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
    cliente.generar_txt();
    return 0;

}