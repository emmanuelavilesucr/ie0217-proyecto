#ifndef CDP_HPP
#define CDP_HPP

#include <string>

// Se debe heredar de la clase Cuentas Bancarias
class CDP {
private:
    long long int idCuenta;
    double interes; 
    double montoCDP;
    std::string tipo;

public:
    
    void setIdCuenta(long long int id) { idCuenta = id; }
    void setInteres(double nuevoInteres) { interes = nuevoInteres; }
    void setMontoCDP(double monto) { montoCDP = monto; }
    void setTipo(const std::string& t) { tipo = t; }


    void ingresarCDP();
};

#endif
