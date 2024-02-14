#ifndef MENUSINFO_HPP
#define MENUSINFO_HPP
#include <iostream>
#include <vector>
using namespace std;

struct Datos {
    std::string tipo;
    std::vector<std::string> plazos;
    std::string plazo;
    std::vector<float> interes;
    std::vector<int> cuotas;
    float montoPrestamo;
    std::string nombreReporte;
};

class MenusInfoCliente {
    public:
        void menuPrincipal();
        void procesarOpcion1();
        void menuSecundario(std::string plazo1, std::string plazo2, std::string plazo3);
        void procesarOpcion2(Datos prestamo);
        void menuTerceario();
        void procesarOpcion3(std::string tipo, std::string plazos, float interes, int cuotas);
        void infoPrestamo(std::string tipoPrestamo, std::string plazo, float interes, int cuotas);

};

#endif