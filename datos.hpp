#ifndef DATOS_HPP
#define DATOS_HPP
#include <string>

class Datos {

private:
    long long int transaccion_id;
    long long int cliente_id;
    double monto;
    std::string tipo;

public:
    
    Datos(long long int trans_id, long long int client_id, double amount, const std::string& t);
    void ingresarDatosColones() const;
    void ingresarDatosDolares() const;
};

#endif








   


