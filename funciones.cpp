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

int main(){
    double dinero = 1000;
    int tipo_moneda = 2;
    dinero = conversionMoneda(dinero, tipo_moneda);
    std::cout << dinero;
    return 0;
}