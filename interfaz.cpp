#include "interfaz.hpp" 

void Interfaz::menu_inicial(){
    int opcion;

    std::cout << "---Bienvenido al servicio administrativo del banco---" << std::endl;
    std::cout << "1. Información al cliente" << std::endl;
    std::cout << "2. Atención al cliente" << std::endl;
    std::cout << "Ingrese el número de la modalidad a elegir: ";
    
    try{
        std::cin >> opcion;
        
        switch (opcion)
        {
        case 1:
            std::cout << "Se ha elegido la opcion 1" << std::endl;
            break;
        case 2:
            std::cout << "Se ha elegido la opcion 2" << std::endl;
            break;
        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }
    }catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

