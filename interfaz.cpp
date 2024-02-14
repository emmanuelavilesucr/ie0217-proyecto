#include "interfaz.hpp"
#include "menusInfoCliente.hpp"
// #include "CuentasBancarias.hpp"
// #include "Prestamos.hpp"

/**
 * @brief Verificca que la cédula ingresada por el usuario, no pertezca a otro usuario
 * 
 * Recibe la cédula dingresada y retorna un booleano dependiendo del resultado
 * @param cedula 
 * @return true 
 * @return false 
 */
bool Interfaz::crearCuentaVerificarRepetidos(long long int cedula){
    
    std::ifstream archivo_entrada("clientes.txt");

    if (archivo_entrada.is_open()) {
        long long int id;
        std::string nombre_usuario;

        while (archivo_entrada >> id >> std::ws && std::getline(archivo_entrada, nombre_usuario)) {
            if (id == cedula){
                std::cout << "La cédula indicada ya pertenece a otra persona" <<  std::endl;
                std::cout << "Intente otra vez..." << std::endl;
                return false;
            }
        }
        archivo_entrada.close();
        return true;
    } else {
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
    }

    return false;
}

/**
 * Por medio de expresiones regulares se encarga de obtener los datos del nombre y cécula que tendrá el usuario.
 * Este proceso lo realizará hasta que el usuario agregue datos correctos.
 * Una vez agrega todos los datos correctos, invoca un método encargado de que la cédula no se encuentre en el sistema.
 * Si no se encuentra, agrega el usuario a la base de datos.
 */
void Interfaz::crearCuentaVerificarExpresiones(){
    try{
        std::string nombre;
        std::string cedula_expresion;
        auto const regex_nombre = std::regex("^[A-ZÑÁ-Ú][a-zñá-ú]{1,20}(( )([A-ZÑÁ-Ú][a-zñá-ú]{1,20})){0,3}$");
        auto const regex_id = std::regex("^[0-9]{9}$");
        std::cin.ignore();

        while(true){
            std::cout << "Ingrese su nombre: ";
            getline(std::cin, nombre);

            std::cout << "Ingrese su cédula: ";
            getline(std::cin, cedula_expresion);;

            bool verificar_nombre = std::regex_match(nombre, regex_nombre);
            bool verificar_cedula = std::regex_match(cedula_expresion, regex_id);

            if (verificar_nombre == true && verificar_cedula == true){
                long long int cedula = std::stoll(cedula_expresion);
                bool verificado = crearCuentaVerificarRepetidos(cedula);
                if  (verificado == true){

                    Clientes clientes(cedula, nombre);
                    clientes.GuardarInformacion();
                    std::cout << "Su cuenta ha sido creada" << std::endl;
                    break;
                }

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

/**
 * @brief Primero verifica por medio de una expresión regular que la cédula sea correcta y después verifica que exista en el sistema
 * 
 * @return true 
 * @return false 
 */
bool Interfaz::verificarCuenta() {
    std::string nombre;
    std::string cedula_str;

    const std::regex regex_id("^[0-9]{9}$");

    do {
        std::cout << "Ingrese su cédula: ";
        std::cin >> cedula_str;

        if (!std::regex_match(cedula_str, regex_id)) {
            std::cout << "Cédula inválida. Debe contener 9 dígitos numericos." << std::endl;
        }
    } while (!std::regex_match(cedula_str, regex_id));

    long long int cedula = std::stoll(cedula_str);

    std::ifstream archivo_entrada("clientes.txt");

    if (!archivo_entrada.is_open()) {
        std::cout << "Sistema fuera de servicio. No se puede acceder a la base de datos" << std::endl;
        return false;
    }

    long long int id;
    std::string nombre_usuario;
    bool encontrado = false;

    while (archivo_entrada >> id && std::getline(archivo_entrada, nombre_usuario)) {
        if (id == cedula) {
            encontrado = true;
            archivo_entrada.close();

            size_t pos = nombre_usuario.find(',');
            if (pos != std::string::npos) {
                std::string nombre = nombre_usuario.substr(pos + 1);
                std::cout << "La cédula ingresada pertenece a: " << nombre << std::endl;
            }
            return false;
        }
    }

    archivo_entrada.close();

    if (!encontrado) {
        std::cout << "La cédula ingresada no pertenece a ningún usuario" << std::endl;
    }

    return !encontrado;
}

/**
 * @brief Menú encargado de la atención al cliente. Procesa la opción e invoca la función correspondiente.
 * 
 */
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
            verificarCuenta();
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

/**
 * @brief Procesa la primera opción del pragrama para invocar funciones, crear instancias o salir
 * 
 */
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
            MenusInfoCliente menus;
            menus.menuPrincipal();
            menus.procesarOpcion1();
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
        exit(0);
    }
}
