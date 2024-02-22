#ifndef CUENTASAHORROS_CPP
#define CUENTASAHORROS_CPP
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <regex>
#include "funciones.hpp"
#include <string>

/**
 * @file cuentasAhorros.hpp
 * @brief Definición de la clase CuentasAhorros.
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

class CuentasAhorros{

    public:
        // Constructor que guarda el id del usuario que realiza el trámite
        CuentasAhorros(long long int cedula);
        // Método para crear una cuenta de ahorros nueva
        bool crearCuenta();
        // Método para presentar las acciones que se pueden realizar con una cuenta de ahorros
        void menuAccionesCuenta();
        // Verifica la cantidad de cuentas que posee un usuario
        void verficarCantidadCuentas();
        // Se encarga de realizar un retiro
        bool retiro(double retiro);
        // Actualiza los datos en caso de que se realice un trámite
        void actualizarDatos();
        // Se encarga de elegir la cuenta con la que el usuario decide realizar un trámite
        void elegirCuenta();
        
        /**
         * Atributos importantes para el cliente que realiza el trámite
         * Entre ellos encontramos el id del usuario, la cantidad de dinero que posee en la cuenta elegida,
         * el tipo de moneda de esa cuenta (1 si es en colones o 2 si es en dólares), y la cantidad de cuentas
         * que posee el usuario.
         */
        long long int cedula_cliente;
        double dinero_cuenta;
        int tipo_moneda;
        int cantidad_cuentas = 0;
        
    private:
        
        /**
         * Mismos atributos pero utilizados para el usuario al que se le transfiere dinero
         * 
         */
        long long int cedula_cliente_otro = 0;
        double dinero_cuenta_otro;
        int tipo_moneda_otro;
        int cantidad_cuentas_otro = 0;

        // Verifica que no se cree una cuenta de ahorros del mismo tipo para un mismo usuario
        bool verificarCuentaAhorrosRepetida();
        //  Guarda los datos de las cuentas de ahorros del usuario
        void guardarDatos();
        // Imprime las cuentas de ahorros que posee el usuario
        void verMisCuentas();
        // Se encarga de realizar un depósito
        bool deposito();
        // Tranfiere dinero de una cuenta elegida a la otra cuenta que se posee en caso de poseer 2
        bool tranferirDineroPropia();
        // Elección del otro usuario para tranferirle dinero
        long long int elegirOtroUsuario();
        // Trasfiere dinero desde una cuenta elegida propia, a la cuenta del otro usuario elegida
        bool tranferirDineroOtro();
};

#endif