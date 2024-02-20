#ifndef CDP_HPP
#define CDP_HPP

#include <string>


class CDP {
private:
    long long int idCuenta;
    double interes; 
    double montoCDP;
    std::string tipo;

public:
    
    // Acceso a atributos 
    long long int getIdCuenta() const { return idCuenta; }
    double getInteres() const { return interes; }
    double getMontoCDP() const { return montoCDP; }
    std::string getTipo() const { return tipo; }
    
    void setIdCuenta(long long int id) { idCuenta = id; }
    void setInteres(double nuevoInteres) { interes = nuevoInteres; }
    void setMontoCDP(double monto) { montoCDP = monto; }
    void setTipo(const std::string& t) { tipo = t; }


    void ingresarCDP();
};

#endif
