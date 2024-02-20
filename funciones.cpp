#include "funciones.hpp"

double conversionMoneda(double dinero, int tipo_moneda){
    if (tipo_moneda == 1){
        dinero = dinero/514.26;
        return dinero;
    }else if (tipo_moneda == 2) {
        dinero = dinero*514.26;
        return dinero;
    }
}
