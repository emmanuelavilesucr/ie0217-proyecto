#include "interfaz.hpp"

int main(){
    while(1){
        try{
            Interfaz verificar;
            verificar.menuInicial();
        }catch(...){
            std::cout << "Error: hubo un error inesperado en nuestra administración de servicios bancarios" << std::endl;
            exit(0);
        }
    }
    return 0;
}