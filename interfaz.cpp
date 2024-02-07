#include "interfaz.hpp" 

void Interfaz::menu_atencion_clientes(){
    int opcion_cliente;
    
    std::cout << "---Opciones para la atención al cliente---" << std::endl;
    std::cout << "1. Acceder a una cuenta creada" << std::endl;
    std::cout << "2. Crear una cuenta" << std::endl;
    std::cout << "Ingrese el número de una opción: ";

    std::cin >> opcion_cliente;
        
        switch (opcion_cliente)
        {
        case 1:
            std::cout << "Se ha elegido la opcion 1" << std::endl;
            //Invocar funcionalidad para crear cuenta
            break;
        case 2:
            std::cout << "Opcion 2";
            //Incoar la opcion de elegir un usuario y las acciones que puede realizar
            break;
        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }

}

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
            menu_atencion_clientes();
            break;
        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }
    }catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

