#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
/**
 * @file funciones.hpp
 * @brief Definición de algunas funciones variadas.
 * 
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

// Convierte de un tipo de moneda a otra
double conversionMoneda(double dinero, int tipo_moneda);

// Obtiene información sobre acciones realizadas por los clientes para guardaslas en una base de datos
void baseDatos(long long int cedula, std::string accion_realizada, double dinero_involucrado, int tipo_moneda);

#endif