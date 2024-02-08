#include "interfaz.hpp" 

void Interfaz::crearCuentaVerificarExpresiones(){
    try{
        std::string nombre;
        std::string cedula;
        auto const regex_nombre = std::regex("^[A-ZÑÁ-Ú][a-zñá-ú]{1,20}(( )([A-ZÑÁ-Ú][a-zñá-ú]{1,20})){0,3}$");
        auto const regex_id = std::regex("^[0-9]{9}$");
        std::cin.ignore();

        while(true){
            std::cout << "Ingrese su nombre: ";
            getline(std::cin, nombre);

            std::cout << "Ingrese su cédula: ";
            getline(std::cin, cedula);;

            bool verificar_nombre = std::regex_match(nombre, regex_nombre);
            bool verificar_cedula = std::regex_match(cedula, regex_id);

            if (verificar_nombre == true && verificar_cedula == true){
                std::cout << "El nombre y cedula se pueden usar" << std::endl;
                break;

            }else if (verificar_nombre == false && verificar_cedula == false) {
                std::cout << "Lo sentimos, su nombre y cédula no cumplen con las normas establecidas:" << std::endl;
                std::cout << "1. El nombre debe estar compuesto de 1 a 4 palabras, compuesta de solo letras" << std::endl;
                std::cout << "2. Cada palabra del nombre de poseer mayúscula al inicio y solo en esa posición" << std::endl;
                std::cout << "3. La cédula debe estar compuesta por 9 números" << std::endl;
                std::cout << "Intente otra vez..." << std::endl;

            }else if (verificar_nombre == false) {
                //En caso de ser erroneo el nombre, recordamos las reglas a seguir para que sea válido
                std::cout << "Lo sentimos, su nombre no cumple con las normas establecidas:" << std::endl;
                std::cout << "1. El nombre debe estar compuesto de 1 a 4 palabras, compuesta de solo letras" << std::endl;
                std::cout << "2. Cada palabra de poseer mayúscula al inicio y solo en esa posición" << std::endl;
                std::cout << "Intente otra vez..." << std::endl;

            }else{
                //En caso de ser erroneo la cédula, recordamos las reglas a seguir para que sea válido
                std::cout << "Lo sentimos, su cédula no cumple con las normas establecidas:" << std::endl;
                std::cout << "1. Debe estar compuesta por 9 números" << std::endl;
                std::cout << "Intente otra vez..." << std::endl;
            }
        }
        
    }catch (...){
        std::cout << "Error inesperado a la hora de crear la cuenta" << std::endl;
    }
}


void Interfaz::menuAtencionClientes(){
    int opcion_cliente;
    
    std::cout << "---Opciones para la atención al cliente---" << std::endl;
    std::cout << "1. Acceder a una cuenta creada" << std::endl;
    std::cout << "2. Crear una cuenta" << std::endl;
    std::cout << "3. Salir de las opciones de atención" << std::endl;
    std::cout << "Ingrese el número de una opción: ";

    std::cin >> opcion_cliente;
        
        switch (opcion_cliente)
        {
        case 1:
            std::cout << "Se ha elegido la opcion 1" << std::endl;
            //Invocar funcionalidad para crear cuenta
            break;
        case 2:
            crearCuentaVerificarExpresiones();
            break;
        case 3:
            break;
        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }

}

void Interfaz::menuInicial(){
    int opcion;

    std::cout << "---Bienvenido al servicio administrativo del banco---" << std::endl;
    std::cout << "1. Información al cliente" << std::endl;
    std::cout << "2. Atención al cliente" << std::endl;
    std::cout << "3. Salir del prorgama" << std::endl;
    std::cout << "Ingrese el número de la modalidad a elegir: ";
    
    try{
        std::cin >> opcion;
        
        switch (opcion)
        {
        case 1:
            std::cout << "Se ha elegido la opcion 1" << std::endl;
            break;
        case 2:
            menuAtencionClientes();
            break;
        case 3:
            std::cout << "Saliendo del prorgama..." << std::endl;
            exit(0);
        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }
    }catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

