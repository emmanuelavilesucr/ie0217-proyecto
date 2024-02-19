#include "menuCDP.hpp"

void MenuCDP::menuPrincipal()
{   
    int opcion;

    std::cout << "\n --- Certificados de Depositos ---\n";
    std::cout << " 1.Crear CDP \n";
    std::cout << " 2.Ver CDPs\n";
    std::cout << " Ingrese un plazo:\n";
    
    try{
        std::cin >> opcion;
        
        switch (opcion)
        {
        case 1:
            menuSecundario();
            break;
        case 2:
            // Instacia para ver CDPs albergados en el archivo txt
            break;

        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }
    }catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}


void MenuCDP::menuSecundario()
{   
    int opcion_divisa;

    std::cout << "\n --- Tipo de Divisa: ---\n";
    std::cout << " 1.Colones \n";
    std::cout << " 2.Dolares\n";
    std::cout << " Ingrese un plazo:\n";
    
    try{
        std::cin >> opcion_divisa;
        
        switch (opcion_divisa)
        {
        case 1:
            // CDP en dolares
            break;
        case 2:
            // CDP en colones 
            break;
 
        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }
    }catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}

void MenuCDP::menuPlazos()
{

    int opcion_plazo;
    std::cout << "\n --- Plazo: ---\n";
    std::cout << " 1.Tres meses \n";
    std::cout << " 2.Seis meses\n";
    std::cout << " 3.Un año\n";
    std::cout << " Ingrese un plazo:\n";
    
    try{
        std::cin >> opcion_plazo;
        
        switch (opcion_plazo)
        {
        case 1:
            std::cout << "Se ha elegido la opcion 1" << std::endl;
            primerPlazo();
            break;
        case 2:
            segundoPlazo();
            break;
        case 3:
            tercerPlazo();
            break;
        default:
            throw std::runtime_error("La opción elegida no esta disponible.");
        }
    }catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}





void  MenuCDP::primerPlazo()
{
    
}


void  MenuCDP::segundoPlazo()
{
    
}

void  MenuCDP::tercerPlazo()
{

}



// Main de prueba

int main() {
    MenuCDP menu;
    menu.menuPrincipal();
    return 0;
}