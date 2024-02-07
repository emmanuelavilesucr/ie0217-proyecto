#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP
// #include "Clientes.hpp"
// #include "CuentasBancarias.hpp"
// #include "Prestamos.hpp"
// #include "informacionClientes.hpp"
#include <iostream>
#include <stdexcept>

class Interfaz {
private:
    // Atributos futuros
    // Clientes clientes;
    // CuentasBancarias cuentas_bancarias;
    // Prestamos prestamos;
    // InformacionClientes informacion_clientes;

      void menu_atencion_clientes();

      void crear_cuenta(int tipo_cuenta, int cliente_id);
        // Primero terminar codigo de la clase clientes

      void solicitar_cuenta();
        // Primero terminar codigo de la clase clientes

      void solicitar_prestamo();

      void informacion();
public:

    void menu_inicial();
  
};

#endif