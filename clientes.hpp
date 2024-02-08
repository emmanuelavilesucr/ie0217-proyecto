#ifndef CLIENTES_HPP
#define CLIENTES_HPP
#include <string>

class Clientes {
private:
    long long int cliente_id;
    std::string nombre;

public:
    Clientes(long long int id, const std::string& nombre); 
    void GuardarInformacion() const;
};

#endif