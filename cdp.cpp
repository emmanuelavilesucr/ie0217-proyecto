#include "cdp.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip> 
#include <vector>
#include "cuentasAhorros.hpp"


/**
 * @file cdp.cpp
 * @brief Funcionalidades del los diferentes métodos de la clase CDP.
 * 
 * @license 
 * Copyright 2024 [Brenda Natalia Castro Jiménez, Emanuel Avilés Ramírez, Luis José Brenes Campos]
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
*/

CDP::CDP(long long int cedula) : cedula_cliente(cedula) {} // Constructor de la clase CDP

/**
 * @brief Ingresar nuevos certificados de depositos.
 */
void CDP::ingresarCDP(){
    std::ofstream archivo("CDP.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << cedula_cliente << "," << std::fixed << std::setprecision(0) << montoCDP << "," << interes << "," << tipo << "," << plazo << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}

/**
 * @brief Muestra el menu principal al usuario 
 * Permite al usuario realizar operaciones respecto a los CDPs.
 */
void CDP::menuPrincipal(){

    int opcion;
    std::cout << "\n --- Certificados de Depósitos ---\n";
    std::cout << "1. Crear CDP\n";
    std::cout << "2. Ver CDPs\n";
    std::cout << "3. Salir\n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                menuSecundario(); 
                break;
            }
            case 2:
                mostrarCDPs();
                break;
            case 3:
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

/**
 * @brief Muestra el menu que incluye los metodos de pago.
 */
void CDP::menuSecundario(){
    int opcion_secundaria;
    std::cout << "\n --- Metodo de pago: ---\n";
    std::cout << "1. Efectivo\n";
    std::cout << "2. Transferencia\n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_secundaria;
        switch (opcion_secundaria) {
            case 1:
                menuDivisas(); 
                break;
            case 2:
                menuTransferenciasPlazos();
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

/**
 * @brief Muestra el menu de los plazos de CDPs en caso de haber escogido la opcion de transferencia en el menu secundario.
 */
void CDP::menuTransferenciasPlazos(){
    int opcion_transPlazo;
    std::cout << "\n --- Plazos: ---\n";
    std::cout << "1. Tres meses a 3% \n";
    std::cout << "2. Seis meses a 4% \n";
    std::cout << "3. Doce meses a 5% \n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_transPlazo;
        switch (opcion_transPlazo) {
            case 1:
                plazo = 3;
                interes = 3;
                menuTranferenciaDivisas();
                break;
            case 2:
                plazo = 6;
                interes = 4;
                menuTranferenciaDivisas(); 
                break;
            case 3:
                plazo = 12;
                interes = 5;
                menuTranferenciaDivisas();
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

/**
 * @brief Muestra el menu para seleccionar la divisa en caso de haber escogido pago por transferencia.
 */
void CDP::menuTranferenciaDivisas() {   
    int opcion_transDivisa;
    std::cout << "\n --- Tipo de Divisa: ---\n";
    std::cout << "1. Colones \n";
    std::cout << "2. Dólares\n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_transDivisa;
        switch (opcion_transDivisa) {
            case 1:
                tipo = 1; 
                elegirCuenta(); 
                break;
            case 2:
                tipo = 2; 
                elegirCuenta(); 
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

/**
 * @brief Realiza el cobro del CDP del saldo de la cuenta bancaria.
 * 
 * @param cantidad La cantidad a restar
 * @param tipoMoneda El tipo de Divisa
 */
void CDP::restarDinero(const string& numeroCuenta, double cantidad, int tipoMoneda, unordered_map<string, Cuenta>& cuentas) {
    ifstream archivoEntrada("cuentasAhorros.txt");
    ofstream archivoSalida("cuentasAhorros.tmp");

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        string cuenta, tipoMonedaStr, saldoStr;

        if (getline(ss, cuenta, ',') && getline(ss, tipoMonedaStr, ',') && getline(ss, saldoStr, ',')) {
            int tipoMonedaActual = stoi(tipoMonedaStr);
            if (cuenta == numeroCuenta && tipoMonedaActual == tipoMoneda) {
                double saldo = stod(saldoStr);
                if (cantidad <= 0) {
                    cout << "Error: La cantidad de retiro debe ser mayor que cero." << endl;
                    return;
                }
                if (cantidad > saldo) {
                    cout << "Error: No hay suficiente en la cuenta." << endl;
                    return;
                }
                saldo -= cantidad;
                archivoSalida << cuenta << "," << tipoMonedaActual << "," << fixed << setprecision(15) << saldo << "\n";
                if (tipoMonedaActual == 1) {
                    cuentas[numeroCuenta].colones = saldo;
                } else {
                    cuentas[numeroCuenta].dolares = saldo;
                }
            } else {
                archivoSalida << linea << "\n";
            }
        } else {
            cout << "Error al leer la línea del archivo: " << linea << endl;
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    remove("cuentasAhorros.txt");
    rename("cuentasAhorros.tmp", "cuentasAhorros.txt");
    remove("cuentasAhorros.tmp");
}


/**
 * @brief Solicita al usuario inicir sesion con la cuenta bancaria.
 */
void CDP::elegirCuenta() {
    ifstream archivo("cuentasAhorros.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    unordered_map<string, Cuenta> cuentas;

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        
        string numeroCuenta_str, tipoMoneda_str, saldo_str;

        if (getline(ss, numeroCuenta_str, ',') && getline(ss, tipoMoneda_str, ',') && getline(ss, saldo_str, ',')) {
            double saldo = stod(saldo_str);
            int tipoMoneda = stoi(tipoMoneda_str);
            
            if (cuentas.find(numeroCuenta_str) == cuentas.end()) {
                if (tipoMoneda == 1) {
                    cuentas[numeroCuenta_str] = Cuenta{saldo, 0};
                } else if (tipoMoneda == 2) {
                    cuentas[numeroCuenta_str] = Cuenta{0, saldo};
                }
            } else {
                if (tipoMoneda == 1) {
                    cuentas[numeroCuenta_str].colones = saldo;
                } else if (tipoMoneda == 2) {
                    cuentas[numeroCuenta_str].dolares = saldo;
                }
            }
        } else {
            cout << "Error al leer la línea del archivo: " << linea << endl;
        }
    }

    archivo.close();

    if (cuentas.find(to_string(cedula_cliente)) != cuentas.end()) {
        Cuenta& cuentaUsuario = cuentas[to_string(cedula_cliente)];

        cout << "--- Cuentas de ahorro activas: --- " << endl;
        if (cuentaUsuario.colones > 0) {
            cout << "1. Cuenta en colones" << endl;
        }
        if (cuentaUsuario.dolares > 0) {
            cout << "2. Cuenta en dolares" << endl;
        }

        int tipoCuenta;
        cout << "Elija la cuenta con la que desea adquirir el CDP: ";
        cin >> tipoCuenta;

        if ((tipoCuenta == 1 && cuentaUsuario.colones > 0) || (tipoCuenta == 2 && cuentaUsuario.dolares > 0)) {
            cout << "Ingrese monto del CDP: ";
            cin >> montoCDP;

            if (montoCDP > 0) {
                restarDinero(to_string(cedula_cliente), montoCDP, tipoCuenta, cuentas);
                cout << "--- CDP registrado ---" << endl;
                baseDatos(cedula_cliente, "Se ha realizado una compra via transferencia bancaria de un CDP", montoCDP, tipo);
                ingresarCDP();

            } else {
                cout << "La cantidad ingresada no es válida." << endl;
            }
        } else {
            cout << "Opción invalida." << endl;
        }
        
    } else {
        cout << "El número de cuenta ingresado no existe." << endl;
    }

    return;
}

/**
 * @brief Muestra al usuario un menu con el tipo de divisas al crear un CDP.
 */
void CDP::menuDivisas() {   
    int opcion_divisa;
    std::cout << "\n --- Tipo de Divisa: ---\n";
    std::cout << "1. Colones \n";
    std::cout << "2. Dólares\n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_divisa;
        switch (opcion_divisa) {
            case 1:
                tipo = 1; 
                menuPlazos(); 
                break;
            case 2:
                tipo = 2; 
                menuPlazos(); 
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

/**
 * @brief Muestra al usuario un menu con los plazos y intereses al crear un nuevo CDP.
 */
void CDP::menuPlazos() {
    int opcion_plazo;
    std::cout << "\n --- Plazos: ---\n";
    std::cout << "1. Tres meses a 3% \n";
    std::cout << "2. Seis meses a 4% \n";
    std::cout << "3. Doce meses a 5% \n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_plazo;
        switch (opcion_plazo) {
            case 1:
                plazo = 3;
                interes = 3;
                monto(); 
                break;
            case 2:
                plazo = 6;
                interes = 4;
                monto(); 
                break;
            case 3:
                plazo = 12;
                interes = 5;
                monto(); 
                break;
            default:
                throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e) {
        std::cerr << "Error detectado: " << e.what() << std::endl;
    }
}

/**
 * @brief El usuario ingresa el monto de los nuevos CDPs.
 */
void CDP::monto() {
    std::cout << "Ingrese el monto: ";
    std::cin >> montoCDP;
    std::cout << "--- CDP registrado ---\n";
    baseDatos(cedula_cliente, "Se ha realizado una compra en efectivo de un CDP", montoCDP, tipo);
    ingresarCDP();  // Almacena los datos ingresados por el usuario en el archivo txt
}

/**
 * @brief Muestra todos los CDPs activos de cada cliente.
 * Se abre y lee el archivo txt y muestra la información de los CDPs del cliente actual.
 */
void CDP::mostrarCDPs() {
    std::ifstream archivo_entrada("CDP.txt");
    if (archivo_entrada.is_open()) {
        long long int id;
        double dinero;
        int tipo; // Variable para almacenar el tipo de moneda (1 para colones, 2 para dólares)
        int plazo;
        int interes;

        std::cout << std::endl;
        std::cout << "Sus CDPs activos: " << std::endl;
        std::cout << "--------------------" << std::endl;

        std::string linea;
        while (std::getline(archivo_entrada, linea)) {
            std::istringstream ss(linea);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            // Se realiza un verificación de la cantidad de tokens para procesar una línea
            if (tokens.size() >= 5) {
                // Se realiza la conversión de tokens a los tipos
                id = std::stoll(tokens[0]);
                dinero = std::stod(tokens[1]);
                interes = std::stoi(tokens[2]);
                tipo = std::stoi(tokens[3]); // Se obtiene el tipo de moneda como entero
                plazo = std::stoi(tokens[4]);

                // Se verifica si el ID coincide con el del cliente
                if (id == cedula_cliente) {
                    std::cout << "Monto: " << std::fixed << std::setprecision(0) << dinero << std::endl;
                    // Se muestra el tipo de moneda según el valor numérico
                    std::cout << "Tipo de moneda: " << ((tipo == 1) ? "Colones" : "Dolares") << std::endl;
                    std::cout << "Interés: " << interes << "%" << std::endl;
                    std::cout << "Plazo: " << plazo << " meses" << std::endl;
                    std::cout << "------------------------------" << std::endl;
                }
            } else {
                std::cerr << "Error al procesar la línea: " << linea << std::endl;
            }
        }
        archivo_entrada.close();
    } else {
        std::cout << "No se pudo abrir el archivo para lectura." << std::endl;
    }
}
