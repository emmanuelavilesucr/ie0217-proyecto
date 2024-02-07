#include "interfaz.hpp"

int main(){
    try{
        Interfaz verificar;
        verificar.menu_inicial();
    }catch(...){
        std::cout << "Error: hubo un error inesperado en nuestra administración de servicios bancarios" << std::endl;
    }
    return 0;
}