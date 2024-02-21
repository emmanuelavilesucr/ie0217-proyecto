#include "cuentasAhorros.hpp"

CuentasAhorros::CuentasAhorros(long long int cedula) : cedula_cliente(cedula) {}

bool CuentasAhorros::crearCuenta(){
    try{
        int tipo;
        
        if (cantidad_cuentas == 2){
            std::cout << "Usted ya posee 2 cuentas" << std::endl;
            return false;
        }

        std::cout << "---Creando su cuenta de ahorros---" << std::endl;
        std::cout << std::endl;

        std::cout << "---Tipo de moneda---" << std::endl;
        std::cout << "1. Colones" << std::endl;
        std::cout << "2. Dolares" << std::endl;
        std::cout << "Elija un tipo de moneda para su cuenta: ";
        std::cin >> tipo;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("No ha colocado un numero para el tipo de moneda");
        }

        switch (tipo){
        case 1:
            tipo_moneda = 1;
            break;
        case 2:
            tipo_moneda = 2;
            break;
        default:
            throw std::runtime_error("El tipo de moneda elegida no existe.");
        }
        
        std::cout << std::endl;
        std::cout << "Ingrese la cantidad de dinero inicial de su cuenta: ";
        std::cin >> dinero_cuenta;
        if (std::cin.fail() || dinero_cuenta < 0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("La cantidad de dinero elegida no es valida");
            }
        
        bool verificando;

        verificando = verificarCuentaAhorrosRepetida();
        if (verificando == true){
            guardarDatos();
            return true;

        }else{
            return false;
        }
    }catch (std::exception& e){
        std::cerr << "Atencion: " << e.what() << std::endl;
        return false;
    }
}

bool CuentasAhorros::verificarCuentaAhorrosRepetida(){
    
    std::ifstream archivo_entrada("cuentasAhorros.txt");

    if (archivo_entrada.is_open()) {
        long long int id;
        int tipo_moneda_archivo;
        double dinero;
        std::string linea;

        while (std::getline(archivo_entrada, linea)) {
            std::istringstream ss(linea);

            if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                if (id == cedula_cliente) {
                    if (tipo_moneda_archivo == tipo_moneda){
                        std::cout << "Este usuario ya posee una cuenta de este tipo" <<  std::endl;
                        std::cout << "Intente otra vez..." << std::endl;
                        archivo_entrada.close();
                        return false;
                    }
                }else{
                    continue;
                }
            } else {
                // Hubo un problema al procesar la línea
                std::cerr << "Error al procesar la línea: " << linea << std::endl;
            }
        
        } 
        archivo_entrada.close();
        return true;
    } else{
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
        return false;
    }
}

void CuentasAhorros::guardarDatos(){
    
    std::ofstream archivo("cuentasAhorros.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << this->cedula_cliente << "," << tipo_moneda << ","
        << std::fixed << std::setprecision(15) << this->dinero_cuenta << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}

void CuentasAhorros::menuAccionesCuenta(){
    int opcion;
    bool verificar;
    double cuenta_otro = 0;

    std::cout << std::endl;
    std::cout << "---Posibles Opciones a realizar---" << std::endl;
    std::cout << "1. Crear cuenta nueva" << std::endl;
    std::cout << "2. Ver tus cuentas actuales" << std::endl;
    std::cout << "3. Depositar dinero a una cuenta" << std::endl;
    std::cout << "4. Realizar un retiro" << std::endl;
    std::cout << "5. Transferir dinero a otra cuenta propia" << std::endl;
    std::cout << "6. Transferir dinero a cuenta de otro usuario" << std::endl;
    std::cout << "7. Salir" << std::endl;
    std::cout << "Elija una opcion para su cuenta de ahorros: ";
    std::cin >> opcion;

    switch (opcion){
    case 1:
        verficarCantidadCuentas();
        verificar = crearCuenta();
        if (verificar == true){
            std::cout << "Cuenta de ahorros creada" << std::endl;
            std::cout << std::endl;
        }else {
            std::cout << "Cuenta de ahorros no creada" << std::endl;
            std::cout << std::endl;
        }
        break;
    
    case 2:
        verMisCuentas();
        break;

    case 3:
        verficarCantidadCuentas();
        elegirCuenta();
        verificar = deposito();
        if (verificar == true){
            std::cout << "Depósito completado" << std::endl;
            actualizarDatos();
        }
        break;

    case 4:
        verficarCantidadCuentas();
        elegirCuenta();
        verificar = retiro(0);
        if (verificar == true){
            std::cout << "Retiro completado" << std::endl;
            actualizarDatos();
        }
        break;

    case 5:
        verficarCantidadCuentas();
        elegirCuenta();
        verificar = tranferirDineroPropia();
        if (verificar == true){
            std::cout << "Transferencia completa" << std::endl;
            actualizarDatos();
        }
        break;

    case 6:
        verficarCantidadCuentas();
        elegirCuenta();
        cuenta_otro = elegirOtroUsuario();
        if (cuenta_otro != 0){
            cedula_cliente_otro = cuenta_otro;
            verficarCantidadCuentas();
            elegirCuenta();
            verificar = tranferirDineroOtro();
            if (verificar == true){
                std::cout << "Transferencia completa" << std::endl;
            }
        }else{
            std::cout << "Tranferencia a otro usuario no realizada" << std::endl;
        }
        break;

    case 7:
        break;
  
    default:
        throw std::runtime_error("La opción elegida no esta disponible.");
    }
}

void CuentasAhorros::verMisCuentas(){
    std::ifstream archivo_entrada("cuentasAhorros.txt");

    if (archivo_entrada.is_open()) {
        long long int id;
        int tipo_moneda_archivo;
        double dinero;
        std::string linea;

        std::cout << std::endl;
        std::cout << "Cuentas del usuario: " << cedula_cliente << std::endl;
        std::cout << "--------------------" << std::endl;

        while (std::getline(archivo_entrada, linea)) {
            std::istringstream ss(linea);

            if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                if (id == cedula_cliente) {
                    std::cout << std::fixed << std::setprecision(15) << dinero << std::endl;
                    if (tipo_moneda_archivo == 1){
                       std::cout << "Tipo de moneda: colones"  << std::endl;
                       std::cout << "------------------------------" << std::endl;
                    }else{
                        std::cout << "Tipo de moneda: dolares"  << std::endl;
                        std::cout << "------------------------------" << std::endl;
                    }
                }else{
                    continue;
                }
            } else {
                // Hubo un problema al procesar la línea
                std::cerr << "Error al procesar la línea: " << linea << std::endl;
            }
        
        } 
        archivo_entrada.close();
        return;
    } else{
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
        return;
    }
}

void CuentasAhorros::verficarCantidadCuentas(){
    std::ifstream archivo_entrada("cuentasAhorros.txt");

    if (archivo_entrada.is_open()) {
        long long int id;
        int tipo_moneda_archivo;
        double dinero;
        std::string linea;

        while (std::getline(archivo_entrada, linea)) {
            std::istringstream ss(linea);

            if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                if (id == cedula_cliente  && cedula_cliente_otro == 0) {
                    cantidad_cuentas = cantidad_cuentas + 1;
                }else if (id == cedula_cliente_otro){
                    cantidad_cuentas_otro = cantidad_cuentas_otro + 1;
                }else{
                    continue;
                }
            } else {
                // Hubo un problema al procesar la línea
                std::cerr << "Error al procesar la línea: " << linea << std::endl;
            }
        
        } 
        archivo_entrada.close();
        return;
    } else{
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
        return;
    }
}

void CuentasAhorros::elegirCuenta(){
    std::ifstream archivo_entrada("cuentasAhorros.txt");

    if (archivo_entrada.is_open()) {
        long long int id;
        int tipo_moneda_archivo;
        double dinero;
        std::string linea;

        if (cantidad_cuentas == 1 && cantidad_cuentas_otro == 0){
            while (std::getline(archivo_entrada, linea)) {
                std::istringstream ss(linea);

                if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                    if (id == cedula_cliente) {
                        tipo_moneda = tipo_moneda_archivo;
                        dinero_cuenta = dinero;
                        if (tipo_moneda == 1){
                            std::cout << std::endl;
                            std::cout << "Usted posee una cuenta en colones" << std::endl;
                            std::cout << std::endl;
                            break;
                        }else if (tipo_moneda == 2){
                            std::cout << std::endl;
                            std::cout << "Usted posee una cuenta en dolares" << std::endl;
                            std::cout << std::endl;
                            break;
                        }
                    }else{
                        continue;
                    }
                } else {
                    // Hubo un problema al procesar la línea
                    std::cerr << "Error al procesar la línea: " << linea << std::endl;
                }
            
            }
        }else if (cantidad_cuentas == 2 && cantidad_cuentas_otro == 0){
            int eleccion;

            std::cout << "---Usted posee dos cuentas---" << std::endl;
            std::cout << "1. Cuenta en colones" << std::endl;
            std::cout << "2. Cuenta en dolares" << std::endl;
            std::cout << "Elija una de las dos cuentas con la que desea realizar el trámite: ";
            std::cin >> eleccion;

            if (std::cin.fail() || eleccion < 1 || eleccion > 2){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("No ha elegido una de las cuentas disponibles");
            }else {
                tipo_moneda = eleccion;
                
                while (std::getline(archivo_entrada, linea)) {
                    std::istringstream ss(linea);

                    if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                        if (id == cedula_cliente && tipo_moneda == tipo_moneda_archivo) {
                            dinero_cuenta = dinero;
                            if (tipo_moneda == 1){
                                std::cout << std::endl;
                                std::cout << "Cuenta en colones elegida" << std::endl;
                                std::cout << std::endl;
                                break;
                            }else {
                                std::cout << std::endl;
                                std::cout << "Cuenta en dolares elegida" << std::endl;
                                std::cout << std::endl;
                                break;
                            }
                        }else{
                            continue;
                        }
                    } else {
                        // Hubo un problema al procesar la línea
                        std::cerr << "Error al procesar la línea: " << linea << std::endl;
                    }
                }
            }
            
        }else if (cantidad_cuentas == 0 && cantidad_cuentas_otro == 0){
            while (std::getline(archivo_entrada, linea)) {
                std::istringstream ss(linea);

                if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                    if (id == cedula_cliente && tipo_moneda == tipo_moneda_archivo) {
                        dinero_cuenta = dinero;
                    }
                }
            }
        }else if (cantidad_cuentas_otro == 1){
            while (std::getline(archivo_entrada, linea)) {
                std::istringstream ss(linea);

                if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                    if (id == cedula_cliente_otro) {
                        tipo_moneda_otro = tipo_moneda_archivo;
                        dinero_cuenta_otro = dinero;
                        if (tipo_moneda_otro == 1){
                            std::cout << std::endl;
                            std::cout << "El otro usuario posee una cuenta en colones" << std::endl;
                            std::cout << std::endl;
                            break;
                        }else if (tipo_moneda_otro == 2){
                            std::cout << std::endl;
                            std::cout << "El otro usuario posee una cuenta en dolares" << std::endl;
                            std::cout << std::endl;
                            break;
                        }
                    }else{
                        continue;
                    }
                } else {
                    // Hubo un problema al procesar la línea
                    std::cerr << "Error al procesar la línea: " << linea << std::endl;
                }
            
            }
        }else if (cantidad_cuentas_otro == 2){
            int eleccion;

            std::cout << "---El otro usuario posee dos cuentas---" << std::endl;
            std::cout << "1. Cuenta en colones" << std::endl;
            std::cout << "2. Cuenta en dolares" << std::endl;
            std::cout << "Elija la cuenta del otro usuario a la que desea realizar el trámite: ";
            std::cin >> eleccion;

            if (std::cin.fail() || eleccion < 1 || eleccion > 2){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error("No ha elegido una de las cuentas del otro usuario disponibles");
            }else {
                tipo_moneda_otro = eleccion;
                
                while (std::getline(archivo_entrada, linea)) {
                    std::istringstream ss(linea);

                    if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                        if (id == cedula_cliente_otro && tipo_moneda_otro == tipo_moneda_archivo) {
                            dinero_cuenta_otro = dinero;
                            if (tipo_moneda_otro == 1){
                                std::cout << std::endl;
                                std::cout << "Cuenta en colones del otro usuario elegida" << std::endl;
                                std::cout << std::endl;
                                break;
                            }else {
                                std::cout << std::endl;
                                std::cout << "Cuenta en dolares del otro usuario elegida" << std::endl;
                                std::cout << std::endl;
                                break;
                            }
                        }else{
                            continue;
                        }
                    } else {
                        // Hubo un problema al procesar la línea
                        std::cerr << "Error al procesar la línea: " << linea << std::endl;
                    }
                }
            }
            
        }
        archivo_entrada.close();
        return;
    } else{
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
        return;
    }
}

bool CuentasAhorros::deposito(){
    double dinero_depositado;
    
    std::cout << "Ingrese la cantidad de dinero que va a depositar a su cuenta: ";
    std::cin >> dinero_depositado;

    if (std::cin.fail() || dinero_depositado < 0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ha elegido una cantidad de dinero erronea a depositar" << std::endl;
        std::cout << std::endl;
        return false;
    }

    dinero_cuenta = dinero_cuenta + dinero_depositado;
    return true;
}

bool CuentasAhorros::retiro(double retirar){
    if (retirar == 0){    
        double dinero_retirado;
        
        std::cout << "Ingrese la cantidad de dinero a retirar a su cuenta: ";
        std::cin >> dinero_retirado;

        if (std::cin.fail() || dinero_retirado < 0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ha elegido una cantidad de dinero erronea a retirar" << std::endl;
            std::cout << std::endl;
            return false;
        }else if (dinero_retirado > dinero_cuenta){
            std::cout << "Su cuenta posee menos dinero del que pide retirar" << std::endl;
            std::cout << std::endl;
            return false;
        }
        dinero_cuenta = dinero_cuenta - dinero_retirado;
        return true;
    }else{
       dinero_cuenta = dinero_cuenta - retirar;
        return true; 
    }

    
}

void CuentasAhorros::actualizarDatos(){
    std::ifstream archivo_lectura("cuentasAhorros.txt");
    std::ofstream archivo_escritura("cuentasAhorros_temp.txt");


    if (archivo_lectura.is_open() && archivo_escritura.is_open()) {
        long long int id;
        int tipo_moneda_archivo;
        double dinero;
        bool cambio = false;
        std::string linea;


        while (std::getline(archivo_lectura, linea)) {
            std::istringstream ss(linea);

            if (ss >> id >> std::ws && ss.ignore() && ss >> tipo_moneda_archivo >> std::ws && ss.ignore() && ss >> dinero) {

                if (id == cedula_cliente && tipo_moneda_archivo == tipo_moneda) {
                    dinero = dinero_cuenta;
                    cambio = true;
                    archivo_escritura << id << "," << tipo_moneda_archivo << ","
                    << std::fixed << std::setprecision(15) << dinero << std::endl;
                }else if(id == cedula_cliente_otro && tipo_moneda_archivo == tipo_moneda_otro){
                    dinero = dinero_cuenta_otro;
                    cambio = true;
                    archivo_escritura << id << "," << tipo_moneda_archivo << ","
                    << std::fixed << std::setprecision(15) << dinero << std::endl;
                }else{
                    archivo_escritura << id << "," << tipo_moneda_archivo << ","
                    << std::fixed << std::setprecision(15) << dinero << std::endl;
                }
            } else {
                // Hubo un problema al procesar la línea
                std::cerr << "Error al procesar la línea: " << linea << std::endl;
            }
        
        } 
        archivo_lectura.close();
        archivo_escritura.close();

        if (cambio) {
            remove("cuentasAhorros.txt");
            rename("cuentasAhorros_temp.txt", "cuentasAhorros.txt");
        } else {
            remove("cuentasAhorros_temp.txt");
        }
        return;
    } else{
        std::cout << "No se pudieron abrir los archivos." << std::endl;
        return;
    }
}

bool CuentasAhorros::tranferirDineroPropia(){
    double dinero_transferir = 0;
    
    if (cantidad_cuentas == 1){
        std::cout << "Usted solo posee una cuenta, no puede realizar este proceso" << std::endl;
    } else{
        if (tipo_moneda == 1){
           std::cout << "Digite la cantidad de dinero de su cuenta en colones que desea tranferir a su cuenta en dólares:  ";
           std::cin >> dinero_transferir;
           
           if (std::cin.fail() || dinero_transferir < 0){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ha elegido una cantidad de dinero erronea a retirar" << std::endl;
                std::cout << std::endl;
                return false;

            }else if (dinero_transferir > dinero_cuenta){
                std::cout << "Su cuenta posee menos dinero del que pide retirar" << std::endl;
                std::cout << std::endl;
                return false;

            }

            dinero_cuenta = dinero_cuenta - dinero_transferir;
            dinero_transferir = conversionMoneda(dinero_transferir, tipo_moneda);
            actualizarDatos();
            cantidad_cuentas = 0;
            tipo_moneda = 2;
            elegirCuenta();
            dinero_cuenta = dinero_cuenta + dinero_transferir;
            actualizarDatos();
            return true;
        }else{
            std::cout << "Digite la cantidad de dinero de su cuenta en dólares que desea tranferir a su cuenta en colones:  ";
            std::cin >> dinero_transferir;
            
            if (std::cin.fail() || dinero_transferir < 0){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ha elegido una cantidad de dinero erronea a retirar" << std::endl;
                std::cout << std::endl;
                return false;

            }else if (dinero_transferir > dinero_cuenta){
                std::cout << "Su cuenta posee menos dinero del que pide retirar" << std::endl;
                std::cout << std::endl;
                return false;

            }

            dinero_cuenta = dinero_cuenta - dinero_transferir;
            dinero_transferir = conversionMoneda(dinero_transferir, tipo_moneda);
            actualizarDatos();
            cantidad_cuentas = 0;
            tipo_moneda = 1;
            
            elegirCuenta();
            dinero_cuenta = dinero_cuenta + dinero_transferir;
            actualizarDatos();
            return true;
        }
    }
}

long long int CuentasAhorros::elegirOtroUsuario(){
    std::string nombre;
    std::string cedula_str;

    const std::regex regex_id("^[0-9]{9}$");

    do {
        std::cout << "Ingrese la cédula del otro usuario: ";
        std::cin >> cedula_str;

        if (!std::regex_match(cedula_str, regex_id)) {
            std::cout << "Cédula inválida. Debe contener 9 dígitos numericos." << std::endl;
        }
    } while (!std::regex_match(cedula_str, regex_id));

    long long int cedula = std::stoll(cedula_str);

    if (cedula == cedula_cliente){
        std::cout << "La cédula elegida es la suya." << std::endl;
        std::cout << "Si su objetivo es realizar una trasferencia entre sus cuentas, utilice la opción 5." << std::endl;
        return 0;
    }

    std::ifstream archivo_entrada("clientes.txt");

    if (!archivo_entrada.is_open()) {
        std::cout << "Sistema fuera de servicio. No se puede acceder a la base de datos" << std::endl;
        return 0;
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
                std::cout << std::endl;
                std::cout << "Nombre del usuario a tranferir dinero: " << nombre << std::endl;
                std:: cout << std::endl;
                return cedula;
            }
            return 0;
        }
    }

    archivo_entrada.close();

    if (!encontrado) {
        std::cout << "La cédula ingresada no pertenece a ningún usuario" << std::endl;
    }

    return 0;
}

bool CuentasAhorros::tranferirDineroOtro(){
    double dinero_transferir = 0;
    
    std::cout << "Digite la cantidad de dinero que quiere transferir de su cuenta a la cuenta del otro usuario:  ";
    std::cin >> dinero_transferir;
    
    if (std::cin.fail() || dinero_transferir < 0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ha elegido una cantidad de dinero erronea a retirar" << std::endl;
            std::cout << std::endl;
            return false;

        }else if (dinero_transferir > dinero_cuenta){
            std::cout << "Su cuenta posee menos dinero del que pide retirar" << std::endl;
            std::cout << std::endl;
            return false;

        }

        dinero_cuenta = dinero_cuenta - dinero_transferir;
        actualizarDatos();
        if (tipo_moneda != tipo_moneda_otro){
            dinero_transferir = conversionMoneda(dinero_transferir, tipo_moneda);
            dinero_cuenta_otro = dinero_cuenta_otro + dinero_transferir;
        }else {
            dinero_cuenta_otro = dinero_cuenta_otro + dinero_transferir;
        }
        actualizarDatos();
        return true;
}