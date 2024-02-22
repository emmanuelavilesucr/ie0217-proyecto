#ifndef CDP_HPP
#define CDP_HPP

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <unordered_map> // Nueva inclusión de biblioteca

using namespace std; // No recomendado en archivos de cabecera, pero lo mantendremos por simplicidad

/**
 * @file cdp.hpp
 * @brief Definicion de la clase CDP.
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

struct Cuenta {
    double colones;
    double dolares;
};

class CDP {

    public:
        CDP(long long int cedula);   // Constructor encargado de guardar cedula del usuario.
        void menuPrincipal();       // Muestra el menu principal 
        void menuSecundario();     // Muestra el menu secundario
        void menuPlazos();        // Muestra el menu con los plazos displonibles al usuario. 
        void monto();            // ingresa los montos del CDPs
        void menuDivisas();
        void menuTransferenciasPlazos();
        void menuTranferenciaDivisas();  

    private:

        /**
         * Atributos importantes para el cliente que realiza operaciones con los CDPs
         * Su atributos son los id o cedula del usuario, monto, interes, plaazos y  tipo de divisa (Colones o Dolares)
         */
        long long int cedula_cliente;
        double interes;
        double montoCDP;
        double plazo;
        string tipo;

        // Nuevas adiciones para manipulación de cuentas bancarias
        unordered_map<string, Cuenta> cuentas; // Estructura para almacenar cuentas bancarias
      
        void ingresarCDP();    // Ingresa nuevos CDPs
        void mostrarCDPs();   // Muestra los CDPs existentes a cada usuario.

        // Nuevas funciones para manipulación de cuentas bancarias
        void restarDinero(const string& numeroCuenta, double cantidad, int tipoMoneda, unordered_map<string, Cuenta>& cuentas);
        void elegirCuenta();
};

#endif