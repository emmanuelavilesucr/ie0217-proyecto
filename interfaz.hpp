#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP

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

      bool crearCuentaVerificarRepetidos(long long int cedula);

      void solicitarCuenta();
        // Primero terminar codigo de la clase clientes

      void solicitarPrestamo();

      void informacion();

      bool verificarCuenta();
public:

    void menuInicial();
  
};

#endif