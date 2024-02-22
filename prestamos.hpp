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
using namespace std;

class Prestamos: public MenusInfoCliente {
    public:
        Prestamos(long long int id);
        void procesarOpcionPrestamos();
        void menuPrestamos();
        int generarNuevoID();
        void procesarOpcion1();
        void menuPrincipal();
        void EscribirPrestamo(std::string tipo, std::string plazo, double interes, int cuotas, double monto, bool moneda);
        void nuevoPrestamo();
        bool verificarCuenta();
        void procesarOpcionSecun(Datos prestamo);
        bool procesarOpciontercearia();
        void prestamosAsociados();
        void pagarCuota(long long int idPrestamo);
        void abonarCapital(long long int idPrestamo);
        bool obtenerPagos(long long int idPrestamo, double pagar);
        void actualizarDatos(long long int idPrestamo, int opc);

    protected:
        long long int idPrestamo;
        long long int id;
        std::string nombreAsociado;
        std::string tipoPrestamo;
        double montoPrestamo;
        double interes;

        double tasaInteresMensual;
        double cuotaMensual;
        double interesPendiente;
        double amortizacionPrincipal;
        double saldoRestante;
        double cuotasPagadas;
        //int cuotas;
};
#endif