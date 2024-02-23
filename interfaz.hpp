#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP
#include "clientes.hpp"
#include <iostream>
#include <stdexcept>
#include <regex>
#include <fstream>
#include <limits>
#include "prestamos.hpp"
#include "cdp.hpp"

/**
 * Clase encargada de las acciones de la interfaz
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
class Interfaz {
private:
      
      // Función encargada de imprimir las opciones para la atención al ciente
      void menuAtencionClientes();

      // Función encargada de de verificar las expresiones para crear una cuenta bancaria
      void crearCuentaVerificarExpresiones();

      // Verifica por medio de la cédula si existe una cuenta específica
      bool verificarCuenta();

      bool crearCuentaVerificarRepetidos(long long int cedula);

      void accionesCliente(long long int cedula);

      
public:
    // Función que imprime el primer menú del sistema bancario
    void menuInicial();
  
};

#endif