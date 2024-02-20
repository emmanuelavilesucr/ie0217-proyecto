#ifndef MENUCDP_HPP
#define MENUCDP_HPP

#include "cdp.hpp"
#include <vector>

class MenuCDP {
    public:

        void menuPrincipal();
        void menuSecundario(CDP& cdp);
        void menuPlazos(CDP& cdp);
        void monto(CDP& cdp);
        
        void mostrarCDPs();

};

#endif