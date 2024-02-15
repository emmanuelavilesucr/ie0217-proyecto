#ifndef CLIENTES_HPP
#define CLIENTES_HPP
#include <string>


/**
 * Clase encargada del registro de un nuevo usuario. Esta clase extrae el ID y su nombre del cliente y lo almacena en un archivo txt.
 * 
 */
class Clientes {

private:
    long long int cliente_id;
    std::string nombre;

public:


    Clientes(long long int id, const std::string& nombre); 

    void GuardarInformacion() const; // Esta funcion guarda los datos en un archivo llamado txt.  
};

#endif