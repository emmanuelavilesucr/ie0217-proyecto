#include "funciones.hpp"
/**
 * @file funciones.cpp
 * @brief Lógica de las funciones variadas. 
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

/**
 * @brief Convierte un tipo de moneda en otra
 * 
 * @param dinero Dinero que se desea convertir
 * @param tipo_moneda Tipo de moneda del dinero antes de la conversión
 * 
 * La conversión se basó en el precio del dolar en el momento de la creación de este archivo
 * 
 * Retorna el dinero convertido
 * @return double 
 */
double conversionMoneda(double dinero, int tipo_moneda){
    if (tipo_moneda == 1){
        dinero = dinero/514.26;
        return dinero;
    }else if (tipo_moneda == 2) {
        dinero = dinero*514.26;
        return dinero;
    }
}