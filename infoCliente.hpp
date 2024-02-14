#ifndef INFORMACION_HPP
#define INFORMACION_HPP
#include <vector>
#include <stdexcept>
#include <cmath>
#include <fstream>

#include <iostream>
using namespace std;

class InfoCliente {
    public:
        InfoCliente(float montoPrestamo, float tasaInteresAnual, int cuotas);
        std::vector<std::vector<float>> calcularAmortizacion();
        void generarReporte(std::string nombre);

    protected:
        float montoPrestamo;
        float tasaInteresAnual;
        int numCuotas;
        std::vector<std::vector<float>> amortizacion;
};

#endif