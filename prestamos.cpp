#include "prestamos.hpp"
#include "cuentasAhorros.hpp"
#include <fstream>

/**
  * @file prestamos.cpp
 * @brief Implementación de la clase Prestamos y funciones relacionadas.
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
 * @brief Constructor de la clase Prestamos.
 * @param id Identificador asociado a la cuenta actual.
 */
Prestamos:: Prestamos(long long int id){
    this->id = id;
}

/**
 * Muestra el menú de gestión de préstamos.
 * Este menú presenta las opciones disponibles para la gestión de préstamos.
 */
void Prestamos::menuPrestamos()
{
    std::cout << "\n --- Gestión de préstamos ---\n";
    std::cout << " 1.Ver préstamos asociados a esa cuenta\n";
    std::cout << " 2.Crear préstamo\n";
    std::cout << " 3.Pagar cuota a un préstamo\n";
}

/**
 * Muestra el menú principal con los tipos de préstamos disponibles.
 * Este menú presenta las opciones de tipos de préstamos disponibles para el usuario.
 */
void Prestamos::menuPrincipal()
{
    std::cout << "\n --- Tipos de prestamos ---\n";
    std::cout << " 1.Prestamo Prendario\n";
    std::cout << " 2.Prestamo Personal\n";
    std::cout << " 3.Prestamo Hipotecario\n";
}

/**
 * Procesa la opción de tipo de moneda seleccionada.
 * Muestra un menú de opciones de tipo de moneda y procesa la opción seleccionada.
 * @return La opción de tipo de moneda seleccionada (1 para Colones, 2 para Dólares).
 */
int Prestamos::procesarOpciontercearia(){
    cout << "\n--Tipos de moneda--\n1.Colones\n2.Dolares\n";
    int opcion2 = verificarEntrada(2);
    if (opcion2 == 1){
            return 1;
    }
    else{
        return 2;
    }
}

/**
 * Genera un nuevo ID único para un préstamo.
 * Este método busca el último ID de préstamo registrado en un archivo y genera un nuevo ID único incrementando ese valor en 1.
 * @return El nuevo ID único generado para el préstamo.
 */
int Prestamos::generarNuevoID() {
    std::ifstream archivo("prestamos.txt");
    int contador = 1000;
    std::string linea;
    /// Contar el número de préstamos registrados
    while (std::getline(archivo, linea)) {
        contador++;
    }
    archivo.close();
    /// El nuevo ID único es el contador incrementado en 1
    return contador + 1;
}

/**
 * Procesa la opción secundaria del menú de gestión de préstamos.
 * Dependiendo de la opción seleccionada por el usuario, muestra información sobre el préstamo correspondiente,
 * solicita al usuario información adicional como el monto del préstamo y el tipo de moneda,
 * y escribe el préstamo en un archivo.
 * @param prestamo Estructura Datos con los datos del préstamo seleccionado.
 */
void Prestamos::procesarOpcionSecun(Datos prestamo){
    int opcion1 = MenusInfoCliente::verificarEntrada(3);
    if (opcion1 == 0){
        return;
    }
    double monto;
    int moneda;

    switch (opcion1){
        case 1:
            MenusInfoCliente::infoPrestamo(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0]);
            try{
                idPrestamo = generarNuevoID();
                moneda = procesarOpciontercearia();
                cout<<"Ingrese el monto del préstamo: ";
                cin>>monto;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }

            EscribirPrestamo(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0], monto, moneda);
            break;
        
        case 2:
            MenusInfoCliente::infoPrestamo(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1]);
            try{
                idPrestamo = generarNuevoID();
                moneda = procesarOpciontercearia();
                cout<<"Ingrese el monto del préstamo: ";
                cin>>monto;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }
            EscribirPrestamo(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1], monto, moneda);
            break;

        default:
            MenusInfoCliente::infoPrestamo(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2]);
            try{
                idPrestamo = generarNuevoID();
                moneda = procesarOpciontercearia();
                cout<<"Ingrese el monto del préstamo: ";
                cin>>monto;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }
            EscribirPrestamo(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2], monto, moneda);
            break;
    }

}

/**
 * Procesa la opción 1 del menú principal de gestión de préstamos.
 * Dependiendo de la opción seleccionada por el usuario, configura los datos del préstamo correspondiente
 * y llama a la función para procesar la opción secundaria del menú.
 */
void Prestamos::procesarOpcion1()
{
    int opcion = MenusInfoCliente::verificarEntrada(3);
    if (opcion == 0){
        return;
    }

    /// Variable de tipo Datos (Struct)
    Datos prestamo1;

    /// Maneja las opciones del menú principal
    switch (opcion)
    {
        case 1:
            prestamo1.tipo = "Prendario";
            prestamo1.plazos = {"Seis meses", "Un año", "Tres años"};
            prestamo1.interes = {15, 12, 10};
            prestamo1.cuotas = {6, 12 ,36};

            MenusInfoCliente::menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcionSecun(prestamo1);
            break;

        case 2:
            prestamo1.tipo = "Personal";
            prestamo1.plazos = {"Doce meses", "Veinticuatro meses", "Treintaiséis meses"};
            prestamo1.interes = {35, 21, 9};
            prestamo1.cuotas = {12, 24 ,36};

            MenusInfoCliente::menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcionSecun(prestamo1);
            break;

        default:

            prestamo1.tipo = "Hipotecario";
            prestamo1.plazos = {"Diez años", "Veinte años", "Treinta años"};
            prestamo1.interes = {5, 4, 3};
            prestamo1.cuotas = {120, 240 ,360};

            MenusInfoCliente::menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcionSecun(prestamo1);
            break;
    
    }
}

/**
 * Escribe los detalles de un nuevo préstamo en un archivo.
 * Este método toma los datos del préstamo (tipo, plazo, interés, cuotas, monto, moneda) y los escribe en un archivo de texto.
 * @param tipo El tipo de préstamo (Prendario, Personal, Hipotecario).
 * @param plazo El plazo del préstamo.
 * @param interes El interés del préstamo.
 * @param cuotas El número de cuotas del préstamo.
 * @param monto El monto del préstamo.
 * @param moneda El tipo de moneda del monto del préstamo (1 para Colones, 2 para Dólares).
 */
void Prestamos::EscribirPrestamo(std::string tipo, std::string plazo, double interes, int cuotas, double monto, int moneda){
    /// Abre el archivo para escribir, agregando datos al final del archivo
    std::ofstream archivo("prestamos.txt", std::ios::app);
    if (archivo.is_open()) {
        /// Escribe los datos
        archivo << idPrestamo << ","<< id << "," << tipo << "," << std::fixed << std::setprecision(15) << monto << "," << std::fixed << std::setprecision(15) << monto << "," << interes << "," << cuotas << "," << "0" <<  "," << moneda << std::endl;
        // Mnesaje de éxito
        cout << "\nEl nuevo préstamo se ha registrado" << endl;
        baseDatos(id, "Se creó un nuevo préstamo (ID: "+ std::to_string(idPrestamo) + ")", monto, moneda);
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}

/**
 * Genera un reporte de amortización y lo escribe en un archivo.
 * Este método toma los datos de amortización y los escribe en un archivo con el nombre especificado.
 * El reporte incluye detalles de las cuotas pendientes, como el número de cuota, el interés pendiente,
 * la amortización, y el saldo restante.
 * @param nombre El nombre del archivo en el que se escribirá el reporte.
 */
void Prestamos::generarReporte(std::string nombre){
    if (cuotasPagadas != 0)
    {
        if (std::ifstream(nombre)) {
            std::remove(nombre.c_str());
        }
        if (std::ifstream(nombre)) {
            if (std::remove(nombre.c_str()) != 0) {
                
            } else {
                std::cout << "Se eliminó el archivo existente con el mismo nombre" << std::endl;
            }
        }
        int cuotaActual = 0;
        ofstream archivo; // Objeto de flujo de salida para escribir en el archivo.
        archivo.open(nombre, ios::app); // Abre el archivo.
        if (archivo.fail()){
            // Muestra un mensaje de error si falla.
            cout << "No se pudo abrir el archivo"<< endl;
            exit(1);
        }
        
        // Primera linea del reporte.
        archivo << "Cuota\tInterés pendiente\tAmortización\tSaldo restante"<< endl;
        for (int i = 0; i < amortizacion.size(); i++){ // Itera sobre cada elemento de la tabla de amortización.
            if (cuotaActual >= cuotasPagadas){
                break;
            }
            // Escribe los datos de cada cuota en el archivo.
            if (amortizacion[i][3] < 0){
                amortizacion[i][3] = 0;
            }
            archivo << amortizacion[i][0] << "\t\t" << amortizacion[i][1] << "\t\t\t\t" << amortizacion[i][2] << "\t\t\t" << amortizacion[i][3] << "\t" << endl;
            cuotaActual = cuotaActual + 1;
        }
        cout << "\n¡El reporte se ha generado con éxito!" << endl;
        archivo.close(); // Cierra el archivo
    }
    else{
        cout << "No se ha hecho ningún pago a este préstamo";
    }

}

/**
 * Muestra un menú para generar un reporte actual de un préstamo.
 * Este método muestra las opciones disponibles y permite al usuario seleccionar la generación de un reporte actual de un préstamo.
 * Si se elige la opción de generar el reporte, se revisa la existencia del préstamo, se obtienen los datos relevantes
 * y se genera el reporte en un archivo de texto.
 */
void Prestamos::menuReporte()
{
    cout << "1. Generar reporte actual de un préstamo" << endl;
    cout << "2. Salir" << endl;
    int opcion = MenusInfoCliente::verificarEntrada(2);
    if (opcion == 1){
        if (revisarIdPrestamo()){
            std::ifstream archivo_entrada("prestamos.txt");
            std::string linea;
            while (archivo_entrada >> idPrestamoOtro && std::getline(archivo_entrada, linea)) {
                if (idPrestamoOtro == idPrestamoTemp) {
                    std::stringstream ss(linea);
                    std::string parte;
                    std::vector<std::string> partes;

                    while (std::getline(ss, parte, ',')) {
                        partes.push_back(parte);
                    }
                    InfoCliente informacion(std::stod(partes[3]), std::stod(partes[5]), std::stoi(partes[6]));
                    amortizacion = informacion.amortizacion;
                    cuotasPagadas = std::stoi(partes[7]);
                    generarReporte("ReporteActual" + std::to_string(idPrestamoTemp) + ".txt");

                }
            }
        }
        else{
            cout << "No se pudo encontrar un préstamo relacionado";
        }

    }

}

/**
 * Verifica la existencia de un préstamo basado en su ID.
 * Este método solicita al usuario que ingrese el ID del préstamo que desea pagar.
 * Luego busca este ID en el archivo de préstamos. Si se encuentra, devuelve verdadero; de lo contrario, devuelve falso.
 * Si el usuario ingresa un dato inválido para el ID, se lanza una excepción y se maneja el error.
 * @return Verdadero si se encuentra el préstamo con el ID especificado, falso de lo contrario.
 */
bool Prestamos::revisarIdPrestamo(){
    try
    {
        cout<<"\nIngrese el ID del préstamo: ";
        cin>>idPrestamoTemp;
        if (std::cin.fail()){
            throw std::runtime_error("No es un dato válido para el ID");
        }
        bool encontrado = false;
        std::ifstream archivo_entrada("prestamos.txt");
        std::string linea;
        while (archivo_entrada >> idPrestamoOtro && std::getline(archivo_entrada, linea)) {
            if (idPrestamoOtro == idPrestamoTemp) {
                return true;
            }
        }
    }
    catch(const std::exception& e){
        /// Maneja el error lanzado
        std::cerr << "Error: " << e.what() << std::endl;
        exit(0);
    }
}


/**
 * Muestra los préstamos asociados a una cuenta específica.
 * Este método abre el archivo de préstamos y busca aquellos préstamos asociados al ID de la cuenta actual.
 * Luego, muestra los detalles de los préstamos asociados en la consola.
 * Finalmente, muestra el menú de reportes para que el usuario pueda generar un reporte del préstamo.
 */
void Prestamos::prestamosAsociados()
{
    /// Abre el archivo para leer
    std::ifstream archivo("prestamos.txt");
    std::string linea;

    /// Lee cada línea del archivo
    while (std::getline(archivo, linea)) {
        /// Usa un stringstream para dividir la línea en partes usando la coma como delimitador
        std::stringstream ss(linea);
        std::string parte;
        int contador = 0;
        std::string monedad;

        /// Recorre cada parte de la línea
        while (std::getline(ss, parte, ',')) {
            contador++;
            /// Si es el segundo elemento
            if (contador == 2) {
                /// Verifica el ID
                if (std::to_string(id) == parte){
                    std::stringstream ss(linea);
                    std::string parte;
                    std::vector<std::string> partes;

                    while (std::getline(ss, parte, ',')) {
                        partes.push_back(parte);
                    }
                    if (std::stoi(partes[8]) == 1){
                        monedad = "Colones";
                    }
                    else{
                        monedad = "Dolares";
                    }
                    cout << partes[0] << "\t" << partes[2]<< "\t" << std::stof(partes[3])<< "\t" << std::stof(partes[4])<< "\t" << std::stof(partes[5])<< "\t\t" << partes[6]<< "\t" << std::stof(partes[7])<< "\t\t" << monedad << "\n";
                }
            }
        }
    }
    // Cierra el archivo
    archivo.close();
    menuReporte();
}


/**
 * Obtiene los detalles de los pagos asociados a un préstamo.
 * Este método busca un préstamo específico en el archivo de préstamos y calcula los detalles de los pagos asociados.
 * Si el parámetro 'pagar' es igual a 0, el método actualiza el saldo restante y el número de cuotas pagadas, sino solo el saldo.
 * Si el saldo restante del préstamo es mayor que 0, el método devuelve verdadero; de lo contrario, devuelve falso.
 * @param idPrestamo El ID del préstamo del que se desean obtener los pagos.
 * @param pagar El monto a pagar para abonar al capital (0 si no se desea pagar una cuota).
 * @return Verdadero si el préstamo no ha sido cancelado, falso de lo contrario.
 */
bool Prestamos::obtenerPagos(long long int idPrestamo, double pagar){
    std::ifstream archivo_entrada("prestamos.txt");
    std::string linea;
    while (archivo_entrada >> idPrestamoOtro && std::getline(archivo_entrada, linea)) {
        if (idPrestamoOtro == idPrestamo) {
            std::stringstream ss(linea);
            std::string parte;
            std::vector<std::string> partes;

            while (std::getline(ss, parte, ',')) {
                partes.push_back(parte);
            }
            tasaInteresMensual = std::stod(partes[5]) / 12 / 100;
            cuotaMensual = (tasaInteresMensual * std::stod(partes[3])) / (1 - pow((1 + tasaInteresMensual), -std::stod(partes[6])));
            interesPendiente = std::stod(partes[4]) * tasaInteresMensual;
            amortizacionPrincipal = cuotaMensual - interesPendiente;
            tipoMoneda = std::stoi(partes[8]);
            if (pagar == 0){
                saldoRestante = std::stod(partes[4]) - amortizacionPrincipal;
                cuotasPagadas = std::stoi(partes[7]) + 1;
            }
            else{
                saldoRestante = std::stod(partes[4]) - pagar;
            }

            if (std::stod(partes[4]) > 0){
                return true;
            }
            else{
                return false;
            }
        }

    }

}

/**
 * Actualiza los datos de un préstamo en el archivo de préstamos.
 * Este método toma el ID de un préstamo y la opción para actualizar el número de cuotas pagadas (Pagar una cuota, no abonar al capital).
 * Lee cada línea del archivo de préstamos, busca el préstamo con el ID especificado y actualiza su saldo restante y/o el número de cuotas pagadas según sea necesario.
 * Luego, escribe las líneas actualizadas en un archivo temporal.
 * Si se realizan cambios, elimina el archivo de préstamos original y renombra el archivo temporal como el archivo de préstamos original.
 * @param idPrestamo El ID del préstamo que se desea actualizar.
 * @param opc La opción para actualizar el número de cuotas pagadas o no (0 si no se desea actualizar).
 */
void Prestamos::actualizarDatos(long long int idPrestamo, int opc){
    std::ifstream archivo_lectura("prestamos.txt");
    std::ofstream archivo_escritura("prestamos_temp.txt");


    if (archivo_lectura.is_open() && archivo_escritura.is_open()) {
        long long int id;
        long long int idCuenta;
        std::string tipo;
        double monto;
        double saldo;
        int interes, cuotas, pagadas, tipoMoneda;
        bool cambio = false;
        std::string linea;


        while (archivo_lectura >> idPrestamoOtro && std::getline(archivo_lectura, linea)) {
            if (idPrestamoOtro == idPrestamo){
                std::istringstream ss(linea);
                std::string parte;
                std::vector<std::string> partes;

                while (std::getline(ss, parte, ',')) {
                    partes.push_back(parte);
                }

                if (saldoRestante > 0){
                    partes[4] = std::to_string(saldoRestante);
                }
                else{
                    partes[4] = "0";
                }


                if (opc == 0){
                    partes[7] = std::to_string(cuotasPagadas);
                }
                cambio = true;
                archivo_escritura << id << "," << partes[1] << "," << partes[2] << "," << std::fixed << std::setprecision(15) << partes[3] << ","
                << std::fixed << std::setprecision(15) << partes[4] << ","<< partes[5] << ","<< partes[6] << ","<< partes[7] << ","<< partes[8] << std::endl;
            }
            else{
                std::istringstream ss(linea);
                std::string parte;
                std::vector<std::string> partes;

                while (std::getline(ss, parte, ',')) {
                    partes.push_back(parte);
                }
                archivo_escritura << id << "," << partes[1] << "," << partes[2] << "," << std::fixed << std::setprecision(15) << partes[3] << ","
                << std::fixed << std::setprecision(15) << partes[4] << ","<< partes[5] << ","<< partes[6] << ","<< partes[7] << ","<< partes[8] << std::endl;
            }
        
        } 
        archivo_lectura.close();
        archivo_escritura.close();

        if (cambio) {
            cout << "\n¡Se realizó el pago correctamente!"<< endl;
            remove("prestamos.txt");
            rename("prestamos_temp.txt", "prestamos.txt");
        } else {
            remove("prestamos_temp.txt");
        }
        return;
    } else{
        std::cout << "No se pudieron abrir los archivos." << std::endl;
        return;
    }
}

/**
 * Realiza el pago de una cuota de un préstamo.
 * Este método permite al usuario elegir entre dos métodos de pago: efectivo o transferencia.
 * Si se elige efectivo, se actualizan los datos del préstamo.
 * Si se elige transferencia, se verifica si hay saldo suficiente en la cuenta y se realiza un retiro.
 * Si la moneda del préstamo y la cuenta no coinciden, se realiza una conversión de moneda antes del retiro.
 * @param idPrestamo El ID del préstamo para el cual se va a realizar el pago de la cuota.
 */
void Prestamos::pagarCuota(long long int idPrestamo, CuentasAhorros& cuenta)
{
    cout << "\n-- Eliga el método de pago --" << endl;
    cout << "1.Efectivo\n2.Transferencia" << endl;
    int opcion = MenusInfoCliente::verificarEntrada(2);
    bool verificar;
    switch (opcion)
    {
        case 1:
            if (obtenerPagos(idPrestamo, 0)){
                actualizarDatos(idPrestamo, 0);
            }
            else{
                cout << "El préstamo ya fue cancelado";
            }
            break;

        default:
            if (obtenerPagos(idPrestamo, 0)){
                if (saldoRestante > 0){
                    // Hacer retiro con cuotamensual
                    cuenta.verficarCantidadCuentas();
                    cuenta.elegirCuenta();
                    if (tipoMoneda != cuenta.tipo_moneda){
                        cuotaMensual = conversionMoneda(cuotaMensual, tipoMoneda);
                    }
                    verificar = cuenta.retiro(cuotaMensual);
                    if (verificar == true){
                        cuenta.actualizarDatos();
                        std::cout << "Retiro completado" << std::endl;
                        baseDatos(id, "Se pagó la cuota del préstamo " + std::to_string(idPrestamo), cuotaMensual, tipoMoneda);
                        actualizarDatos(idPrestamo, 0);
                    }
                }
                else{
                    // Hacer el retiro con:
                    cuotaMensual = cuotaMensual + saldoRestante;
                    cuenta.verficarCantidadCuentas();
                    cuenta.elegirCuenta();
                    if (tipoMoneda != cuenta.tipo_moneda){
                        cuotaMensual = conversionMoneda(cuotaMensual, tipoMoneda);
                    }
                    verificar = cuenta.retiro(cuotaMensual);
                    if (verificar == true){
                        cuenta.actualizarDatos();
                        std::cout << "Retiro completado" << std::endl;
                        baseDatos(id, "Se pagó la cuota del préstamo " + std::to_string(idPrestamo), cuotaMensual, tipoMoneda);
                        actualizarDatos(idPrestamo, 0);
                    }
                }
            }
            else{
                cout << "El préstamo ya fue cancelado";
            }
            break;
    }
}

/**
 * Procesa la opción seleccionada del menú de gestión de préstamos.
 * Dependiendo de la opción elegida, realiza diferentes acciones:
 * - Si se elige la opción 1, muestra los préstamos asociados a la cuenta.
 * - Si se elige la opción 2, muestra el menú principal para crear un nuevo préstamo.
 * - Si se elige una opción diferente, verifica si hay un préstamo relacionado y muestra las opciones para pagar una cuota o abonar al capital.
 */
void Prestamos::procesarOpcionPrestamos()
{
    int opcion = MenusInfoCliente::verificarEntrada(3);
    if (opcion == 0){
        return;
    }
    CuentasAhorros cuenta(id);
    long long int idPrestamoPagar;
    switch (opcion)
    {
        case 1:
            cout << "\nPréstamos asociados a la cuenta " << id << endl;
            cout << "Id\tTipo\t\tMonto\tSaldo\tIntéres\tCuotas\tCuotas pagadas\tMoneda" << endl;
            prestamosAsociados();
            break;

        case 2:
            menuPrincipal();
            procesarOpcion1();
            break;
        default:
            if(revisarIdPrestamo())
            { 
                pagarCuota(idPrestamoTemp, cuenta);
            }
            else{
                cout << "No se pudo encontrar un préstamo relacionado";
            }
            break;

    }
}
