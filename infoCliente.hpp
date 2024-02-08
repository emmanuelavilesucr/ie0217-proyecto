#ifndef INFORMACION_HPP
#define INFORMACION_HPP
#include <vector>

#include <iostream>
using namespace std;

class InfoCliente {
    public:
        InfoCliente(float montoPrestamo, float tasaInteresAnual, int cuotas);
        std::vector<float> calcularAmortizacion();
        void generarReporte();
        void menuPrincipal();
        void procesarOpcion1();
        void menuSecundario();
        void procesarOpcion2();
        void menuTerceario();
        void procesarOpcion3();


    protected:
        float montoPrestamo;
        float tasaInteresAnual;
        int numCuotas;
};

#endif