#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP
#include "clientes.hpp"
#include <iostream>
#include <stdexcept>
#include <regex>
#include <fstream>
#include <limits>

/**
 * Clase encargada de las acciones de la interfaz
 * 
 */
class Interfaz {
private:
      
      // Función encargada de imprimir las opciones para la atención al ciente
      void menuAtencionClientes();

      // Función encargada de de verificar las expresiones para crear una cuenta bancaria
      void crearCuentaVerificarExpresiones();

      // Verifica por medio de la cédula si existe una cuenta específica
      bool verificarCuenta();

      bool crearCuentaVerificarRepetidos(long long int cedula);

      // Posibles funciones futuras
      void solicitarCuenta();

      void solicitarPrestamo();

      void informacion();

      
public:
    // Función que imprime el primer menú del sistema bancario
    void menuInicial();
  
};

#endif