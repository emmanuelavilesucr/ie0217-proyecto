#ifndef PRESTAMOS_HPP
#define PRESTAMOS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include "menusinfoCliente.hpp"
#include "cuentasAhorros.hpp"
#include "funciones.hpp"
#include "infoCliente.hpp"
//using namespace std;

/**
 * @file prestamos.hpp
 * @brief Definición de la clase Prestamos y funciones relacionadas.
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
 * @brief Clase para la gestión de préstamos.
 * Hereda de la clase MenusInfoCliente.
 */
class Prestamos: public MenusInfoCliente {
    public:
        Prestamos(long long int id); /// Constructor de la clase Prestamos.
        void procesarOpcionPrestamos(); /// Procesa la opción seleccionada del menú de gestión de préstamos.
        void menuPrestamos(); /// Muestra el menú principal de gestión de préstamos.
        int generarNuevoID(); /// Genera un nuevo ID único para un préstamo.
        void procesarOpcion1(); /// Procesa la opción seleccionada del menú principal de tipos de préstamos
        void menuPrincipal(); /// Muestra el menú principal con los tipos de préstamos disponibles.
        void EscribirPrestamo(std::string tipo, std::string plazo, double interes, int cuotas, double monto, int moneda); /// Escribe los datos de un nuevo préstamo en un archivo.
        void nuevoPrestamo(); /// Crea un nuevo préstamo.
        bool verificarCuenta(); /// Verifica si la cuenta asociada al préstamo existe.
        void procesarOpcionSecun(Datos prestamo); /// Procesa la opción seleccionada del menú secundario de tipos de plazos de préstamos.
        int procesarOpciontercearia(); /// Procesa la opción seleccionada del menú de tipos de moneda.
        void prestamosAsociados(); /// Muestra los préstamos asociados a una cuenta.
        void generarReporte(std::string nombre); /// Genera un reporte de préstamos.
        void menuReporte(); /// Muestra el menú para generar un reporte de préstamos.
        bool revisarIdPrestamo(); /// Revisa si el ID del préstamo es válido.
        void pagarCuota(long long int idPrestamo, CuentasAhorros& cuenta); /// Realiza el pago de una cuota de un préstamo.
        void abonarCapital(long long int idPrestamo, CuentasAhorros& cuenta); /// Realiza un abono al capital de un préstamo.
        bool obtenerPagos(long long int idPrestamo, double pagar); /// Obtiene los pagos asociados a un préstamo.
        void actualizarDatos(long long int idPrestamo, int opc); /// Actualiza los datos de un préstamo.

    protected:
        /// @brief Variables relacioandas con los datos del préstamo
        long long int idPrestamo;
        long long int id;
        std::string nombreAsociado;
        std::string tipoPrestamo;
        double montoPrestamo;
        double interes;

        double tasaInteresMensual; /// Tasa de interés mensual.
        double cuotaMensual; /// Cuota mensual del préstamo.
        double interesPendiente; /// Interés pendiente del préstamo.
        double amortizacionPrincipal; /// Amortización principal del préstamo.
        double saldoRestante; /// Saldo restante del préstamo.
        double cuotasPagadas; /// Cuotas pagadas del préstamo.
        int tipoMoneda; /// Tipo de moneda del préstamo.
        long long int idPrestamoTemp; /// ID temporal del préstamo.
        std::vector<std::vector<double>> amortizacion; /// Tabla de amortización del préstamo.
};
#endif