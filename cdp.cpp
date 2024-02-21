#include "cdp.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip> 
#include <vector>

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


CDP::CDP(long long int cedula) : cedula_cliente(cedula) {} // Constructo de la clase CDP

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
 * @brief Muestra al usuario un menu con el tipo de divisas al crear un CDP.
 */
void CDP::menuSecundario() {   
    int opcion_divisa;
    std::cout << "\n --- Tipo de Divisa: ---\n";
    std::cout << "1. Colones \n";
    std::cout << "2. Dólares\n";
    std::cout << "Ingrese una opción:\n";
    try {
        std::cin >> opcion_divisa;
        switch (opcion_divisa) {
            case 1:
                tipo = "Colones"; 
                menuPlazos(); 
                break;
            case 2:
                tipo = "Dólares"; 
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
    double monto;
    std::cout << "Ingrese el monto: ";
    std::cin >> monto;
    montoCDP = monto; 
    ingresarCDP();  // Almacena los datos ingresados por el usuario en el archivo txt
}

/**
 * @brief Muestra todos los CDPs activos de cada cliente.
 * Se abre y lee el archivo txt y muestra la información de los CDPs del cliente actual.
 */
void CDP::mostrarCDPs(){
    std::ifstream archivo_entrada("CDP.txt");
    if (archivo_entrada.is_open()) {
        long long int id;
        double dinero;
        std::string tipo_moneda;
        int plazo;
        int interes;

        std::cout << std::endl;
        std::cout << "CDPs activos: " << cedula_cliente << std::endl;
        std::cout << "--------------------" << std::endl;

        std::string linea;
        while (std::getline(archivo_entrada, linea)) {
            std::istringstream ss(linea);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            
            // Se realiza un verificacion de la cantidad de tokens para procesar una linea
            if (tokens.size() >= 5) {
                // Se realiza la conversion de tokens a los tipos
                id = std::stoll(tokens[0]);
                dinero = std::stod(tokens[1]);
                interes = std::stoi(tokens[2]);
                tipo_moneda = tokens[3];
                plazo = std::stoi(tokens[4]);

                // Se verifica si el ID coincide con el del cliente
                if (id == cedula_cliente) {
                    std::cout << "ID de cuenta: " << id << std::endl;
                    std::cout << "Saldo: " << std::fixed << std::setprecision(0) << dinero << std::endl;  
                    std::cout << "Tipo de moneda: " << tipo_moneda << std::endl;
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
