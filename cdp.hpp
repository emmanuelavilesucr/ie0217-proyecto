#ifndef CDP_HPP
#define CDP_HPP
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>


class CDP {

    public:
        CDP(long long int cedula);
        void menuPrincipal();
        void menuSecundario();
        void menuPlazos();
        void monto();
    
    private:
        long long int cedula_cliente;
        double interes;
        double montoCDP;
        double plazo;
        std::string tipo;

      
        void ingresarCDP();
        void mostrarCDPs();
      
};

#endif