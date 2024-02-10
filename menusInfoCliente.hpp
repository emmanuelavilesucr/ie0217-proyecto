#ifndef MENUSINFO_HPP
#define MENUSINFO_HPP
#include <iostream>
using namespace std;

class MenusInfoCliente {
    public:
        void menuPrincipal();
        void procesarOpcion1();
        void menuSecundario(std::string plazo1, std::string plazo2, std::string plazo3);
        void procesarOpcion2(std::string tipoPrestamo, std::string plazo);
        void menuTerceario();
        void procesarOpcion3();
        void infoPrestamo(std::string tipoPrestamo, std::string plazo, float interes, int cuotas);

};

#endif