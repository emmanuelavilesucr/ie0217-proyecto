#include "clientes.hpp"
#include <iostream>
#include <fstream> // Header encargado de la manipulacion de archivos .txt
#include <limits> // Header encargado de los limites numericos 

/**
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

Clientes::Clientes(long long int id, const std::string& nombre) : cliente_id(id), nombre(nombre) {}

/**
 * 
 * Esta funcion guarda el ID y el nombre del cliente. 
 * 
 * @brief Si el archivo no existe, el programa creara el archivo
 */
void Clientes::GuardarInformacion() const {

    std::cout << "ID del Cliente: " << cliente_id << ", Nombre: " << nombre << std::endl;
    std::ofstream archivo("clientes.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << cliente_id << "," << nombre << std::endl;  // Escribe los datos del cliente en archivo txt
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}
