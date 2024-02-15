#ifndef MENUSINFO_HPP
#define MENUSINFO_HPP
#include <iostream>
#include <vector>
using namespace std;

/**
 * @file menusInfoCliente.hpp
 * @brief Definición de la clase MenusInfoCliente y funciones relacionadas.
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

/**
 * @brief Estructura para almacenar los datos del préstamo.
 */
struct Datos {
    std::string tipo; /**< Tipo de préstamo. */
    std::vector<std::string> plazos; /**< Lista de plazos disponibles. */
    std::string plazo; /**< Plazo seleccionado. */
    std::vector<float> interes; /**< Lista de tasas de interés. */
    std::vector<int> cuotas; /**< Lista de cantidades de cuotas. */
    float montoPrestamo; /**< Monto del préstamo. */
    std::string nombreReporte; /**< Nombre del reporte. */
};

/**
 * @brief Clase para manejar los menús y la información del cliente.
 */
class MenusInfoCliente {
    public:

        /**
         * @brief Muestra el menú principal.
         */
        void menuPrincipal();

         /**
         * @brief Procesa la opción 1 del menú principal.
         */
        void procesarOpcion1();

        /**
         * @brief Muestra el menú secundario.
         * @param plazo1 El primer plazo disponible.
         * @param plazo2 El segundo plazo disponible.
         * @param plazo3 El tercer plazo disponible.
         */
        void menuSecundario(std::string plazo1, std::string plazo2, std::string plazo3);

        /**
         * @brief Procesa la opción 2 del menú secundario.
         * @param prestamo Los datos del préstamo seleccionado.
         */
        void procesarOpcion2(Datos prestamo);

        /**
         * @brief Muestra el menú terciario.
         */
        void menuTerceario();

        /**
         * @brief Procesa la opción 3 del menú terciario.
         * @param tipo Tipo de préstamo.
         * @param plazos Plazos disponibles.
         * @param interes Tasa de interés.
         * @param cuotas Cantidad de cuotas.
         */
        void procesarOpcion3(std::string tipo, std::string plazos, float interes, int cuotas);

        /**
         * @brief Muestra la información del préstamo.
         * @param tipoPrestamo Tipo de préstamo.
         * @param plazo Plazo del préstamo.
         * @param interes Tasa de interés.
         * @param cuotas Cantidad de cuotas.
         */
        void infoPrestamo(std::string tipoPrestamo, std::string plazo, float interes, int cuotas);

};

#endif /* MENUSINFO_HPP */