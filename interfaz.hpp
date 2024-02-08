#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP
// #include "Clientes.hpp"
// #include "CuentasBancarias.hpp"
// #include "Prestamos.hpp"
// #include "informacionClientes.hpp"
#include <iostream>
#include <stdexcept>
#include <regex>

class Interfaz {
private:
    // Atributos futuros
    // Clientes clientes;
    // CuentasBancarias cuentas_bancarias;
    // Prestamos prestamos;
    // InformacionClientes informacion_clientes;

      void menuAtencionClientes();

      void crearCuentaVerificarExpresiones();
        // Primero terminar codigo de la clase clientes

      void solicitarCuenta();
        // Primero terminar codigo de la clase clientes

      void solicitarPrestamo();

      void informacion();
public:

    void menuInicial();
  
};

#endif