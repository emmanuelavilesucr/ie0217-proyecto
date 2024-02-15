#include "infoCliente.hpp"

/**
 * @file infoCliente.cpp
 * @brief Implementación de la clase infoCliente y funciones relacionadas.
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
 * @brief Clase para manejar la información del cliente y generar reportes de amortización.
 */
InfoCliente::InfoCliente(float montoPrestamo, float tasaInteresAnual, int numCuotas){
    this->montoPrestamo = montoPrestamo; /**< Monto del préstamo. */
    this->tasaInteresAnual = tasaInteresAnual; /**< Tasa de interés anual. */
    this->numCuotas = numCuotas; /**< Número de cuotas. */
    amortizacion = calcularAmortizacion(); /**< Tabla de amortización. */
}

/**
 * @brief Calcula la tabla de amortización del préstamo.
 * @return Un vector de vectores que representa la tabla de amortización.
 * @throw std::runtime_error Si el número de cuotas es cero.
 */
std::vector<std::vector<float>> InfoCliente::calcularAmortizacion(){
    try{
        if (numCuotas == 0){
            throw runtime_error("Error: El número de cuotas no puede ser cero");
        }
        float tasaInteresMensual = tasaInteresAnual / 12 / 100; // Calcula la tasa de interés mensual.
        float cuotaMensual = (tasaInteresMensual * montoPrestamo) / (1 - pow((1 + tasaInteresMensual), -numCuotas)); // Calcula la cuota mensual de amortización.
        float saldoRestante = montoPrestamo; // Inicializa el saldo restante al monto del préstamo.
        std::vector<std::vector<float>> amortizacion; // Vector de vectores para almacenar la tabla de amortización.

        for (float cuota = 1; cuota < numCuotas + 1; cuota ++){ // Itera sobre cada cuota.
            float interesPendiente = saldoRestante * tasaInteresMensual; // Calcula el interés pendiente para esta cuota.
            float amortizacionPrincipal = cuotaMensual - interesPendiente; // Calcula la amortización principal para esta cuota.
            saldoRestante -= amortizacionPrincipal; // Actualiza el saldo restante.
            std::vector<float> vectorTemp = {cuota, interesPendiente, amortizacionPrincipal, saldoRestante}; // Crea un vector temporal con la información de la cuota.
            amortizacion.push_back(vectorTemp); // Agrega el vector temporal a la tabla de amortización.
        }

        return amortizacion; // Devuelve la tabla de amortización.
    }
    catch(const exception& e){ // Manejo de excepciones.
        cerr << e.what() << endl; // Imprime el mensaje de la excepción.
        // Devuelve la tabla de amortización (en este caso, vacía debido a la excepción).
        std::vector<float> vectorTemp = {};
        amortizacion.push_back(vectorTemp);
        return amortizacion;
    }
}

/**
 * @brief Genera un reporte de amortización y lo guarda en un archivo.
 * @param nombre El nombre del archivo donde se guardará el reporte.
 */
void InfoCliente::generarReporte(std::string nombre){
    ofstream archivo; // Objeto de flujo de salida para escribir en el archivo.
    archivo.open(nombre, ios::app); // Abre el archivo.
    if (archivo.fail()){
        // Muestra un mensaje de error si falla.
        cout << "No se pudo abrir el archivo"<< endl;
        exit(1);
    }
    // Primera linea del reporte.
    archivo << "Cuota  Interés pendiente  Amortización  Saldo restante"<< endl;
    for (int i = 0; i < amortizacion.size(); i++){ // Itera sobre cada elemento de la tabla de amortización.
        // Escribe los datos de cada cuota en el archivo.
        archivo << amortizacion[i][0] << "   " << amortizacion[i][1] << "   "<< amortizacion[i][2] << "   "<< amortizacion[i][3] << "   "<< endl;;
    }
    archivo.close(); // Cierra el archivo

}