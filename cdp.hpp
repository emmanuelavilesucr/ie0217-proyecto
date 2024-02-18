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

    void ingresarCDP() const;
};

#endif




