#include "interfaz.hpp"

int main(){
    while(1){
        try{
            Interfaz verificar;
            verificar.menu_inicial();
        }catch(...){
            std::cout << "Error: hubo un error inesperado en nuestra administración de servicios bancarios" << std::endl;
            exit(0);
        }
    }
    return 0;
}