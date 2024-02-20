#include "cdp.hpp"
#include <iostream>
#include <fstream>


void CDP::ingresarCDP() {

    std::ofstream archivo("CDP.txt", std::ios::app);
    if (archivo.is_open()) {        
        archivo << idCuenta << "," << montoCDP << "," << interes << "," << tipo << "," << plazo << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}




