

#include "menusInfoCliente.hpp"
#include "infoCliente.hpp"

/**
  * @file menusInfoCliente.cpp
 * @brief Implementación de la clase MenusInfoCliente y funciones relacionadas.
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

void MenusInfoCliente::menuPrincipal()
{
    /// Muestra el menú principal con los tipos de préstamos disponibles
    std::cout << "\n --- Tipos de prestamos ---\n";
    std::cout << " 1.Prestamo Prendario\n";
    std::cout << " 2.Prestamo Personal\n";
    std::cout << " 3.Prestamo Hipotecario\n";
    std::cout << " 4.Reporte personalizado\n";
}

void MenusInfoCliente::menuSecundario(std::string plazo1, std::string plazo2, std::string plazo3)
{
    /// Muestra un menú secundario con plazos preestablecidos para elegir
    std::cout << "\n ---  Plazos preestablecidos ---\n";
    std::cout << " 1. " << plazo1 << "\n";
    std::cout << " 2. " << plazo2 << "\n";
    std::cout << " 3. " << plazo3 << "\n";
}

void MenusInfoCliente::menuTerceario()
{
    /// Muestra un menú para preguntar al usuario si desea generar un reporte
    std::cout << "\n --- ¿Desea generar un reporte? ---\n";
    std::cout << " 1.Generar reporte\n";
    std::cout << " 2.Salir\n";
}

void MenusInfoCliente::infoPrestamo(std::string tipoPrestamo, std::string plazo, double interes, int cuotas)
{
    /// Muestra la información general de un préstamo
    std::cout << "\n --- Infromación general ---\n";
    std::cout << " Tipo de prestamo: " << tipoPrestamo << std::endl;
    std::cout << " Plazo: " << plazo << std::endl;
    std::cout << " Tasa de interés anual: " << interes << "%" << std::endl;
    std::cout << " Número de cuotas: " << cuotas << std::endl;
}

int MenusInfoCliente::verificarEntrada(int numOpciones){
    try{
        int opcion;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        /// Verifica que la opción sea valida
        if (std::cin.fail() || opcion < 1 || opcion > numOpciones ){
            throw std::runtime_error("No es una opción válida");
        }
        return opcion;

    }catch (const std::exception& e){
        /// Maneja el error lanzado
        std::cerr << "Error: " << e.what() << std::endl;
        exit(0);
    }

}

void MenusInfoCliente::procesarOpcion3(std::string tipo, std::string plazo, double interes, int cuotas){
    int opcion2 = verificarEntrada(2);
    if (opcion2 == 0){
        return;
    }
    /// Maneja las opciones del menú 3, llama las funciones necesarias.
    if (opcion2 == 1){
            double montoPrestamo;
            try{
                cout<<"Ingrese el monto que desea consultar: ";
                cin>>montoPrestamo;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
                InfoCliente informacion(montoPrestamo, interes, cuotas, 1);
                informacion.generarReporte("Reporte" + tipo + plazo +".txt");
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }
    }
    else{
        cout<<"Saliendo del programa";
    }

}

void MenusInfoCliente::procesarOpcion2(Datos prestamo){
    int opcion1 = verificarEntrada(3);
    if (opcion1 == 0){
        return;
    }

    /// Maneja las opciones dle menú 2, llama las funciones necesarias.
    switch (opcion1){
        case 1:
            infoPrestamo(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0]);
            menuTerceario();
            procesarOpcion3(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0]);
            break;
        
        case 2:
            infoPrestamo(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1]);
            menuTerceario();
            procesarOpcion3(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1]);
            break;

        default:
            infoPrestamo(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2]);
            menuTerceario();
            procesarOpcion3(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2]);
            break;
    }

}
void MenusInfoCliente::procesarOpcion1()
{
    int opcion = verificarEntrada(4);
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

            menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcion2(prestamo1);
            break;

        case 2:
            prestamo1.tipo = "Personal";
            prestamo1.plazos = {"Doce meses", "Veinticuatro meses", "Treintaiséis meses"};
            prestamo1.interes = {35, 21, 9};
            prestamo1.cuotas = {12, 24 ,36};

            menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcion2(prestamo1);
            break;

        case 3:

            prestamo1.tipo = "Hipotecario";
            prestamo1.plazos = {"Diez años", "Veinte años", "Treinta años"};
            prestamo1.interes = {5, 4, 3};
            prestamo1.cuotas = {120, 240 ,360};

            menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcion2(prestamo1);
            break;

        default:
            try{
                double montoPrestamo;
                double interes;
                int cuotas;

                cout<<"Ingrese el monto del prestamo: ";
                cin>>montoPrestamo;
                if (std::cin.fail()){
                    throw std::runtime_error("Ha ingresado los datos de manera incorrecta.");
                }

                cout<<"Ingrese la tasa de intéres anual: ";
                cin>>interes;
                if (std::cin.fail()){
                    throw std::runtime_error("Ha ingresado los datos de manera incorrecta.");
                }

                cout<<"Ingrese la cantidad de cuotas: ";
                cin>>cuotas;
                if (std::cin.fail()){
                    throw std::runtime_error("Ha ingresado los datos de manera incorrecta.");
                }

                InfoCliente informacion(montoPrestamo, interes, cuotas, 1);
                informacion.generarReporte("ReportePersonalizado.txt");
                break;

            }catch (const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
                exit(0); 
            }
    }
}