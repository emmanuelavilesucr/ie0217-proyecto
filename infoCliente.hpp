#ifndef INFORMACION_HPP
#define INFORMACION_HPP
#include <vector>
#include <stdexcept>
#include <cmath>
#include <fstream>

#include <iostream>
using namespace std;

/**
 * @file infoCliente.hpp
 * @brief Definición de la clase infoCliente y funciones relacionadas.
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
 * @brief Clase que se encarga de calcular la amortización y
 * demás datos necesarios para generar un reporte.
 * 
 * Esta clase proporciona funcionalidades básicas para realizar reportes.
 */
class InfoCliente {
    public:

        /**
         * @brief Constructor de la clase InfoCliente.
         * 
         * @param montoPrestamo Valor del monto del préstamo.
         * @param tasaInteresAnual Valor de la tasa de interés anual del préstamo.
         * @param cuotas Número de cuotas del préstamo.
         */
        InfoCliente(double montoPrestamo, double tasaInteresAnual, int cuotas, double tipo);

        /**
         * @brief Calcula la amortización del préstamo.
         * 
         * @return Lista de amortizaciones para cada cuota.
         */
        std::vector<std::vector<double>> calcularAmortizacion(double tipo);

        /**
         * @brief Método para imprimir el reporte en un archivo csv.
         * 
         * @param nombre Nombre con el cual se va a guardar el archivo csv.
         */
        void generarReporte(std::string nombre);

        std::vector<std::vector<double>> amortizacion; ///< Lista de amortizaciones para cada cuota.

    protected:
        double montoPrestamo; ///< Valor del monto del préstamo.
        double tasaInteresAnual; ///< Valor de la tasa de interés anual del préstamo.
        int numCuotas; ///< Número de cuotas del préstamo.
        int tipo;
};

#endif /* INFORMACION_HPP */