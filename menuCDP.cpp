#include <iostream>
#include "menuCDP.hpp"
#include "cdp.hpp"
#include <stdexcept>

void MenuCDP::menuPrincipal()
{   
    int opcion;

    std::cout << "\n --- Certificados de Depositos ---\n";
    std::cout << " 1.Crear CDP \n";
    std::cout << " 2.Ver CDPs\n";
    std::cout << " Ingrese una opción:\n";
    
    try{
        std::cin >> opcion;
        
        switch (opcion)
        {
        case 1: {
            CDP cdp; 
            menuSecundario(cdp); 
            break;
        }
        case 2:
            // Instacia para ver CDPs albergados en el archivo txt
            break;

        default:
            throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}

void MenuCDP::menuSecundario(CDP& cdp)
{   
    int opcion_divisa;

    std::cout << "\n --- Tipo de Divisa: ---\n";
    std::cout << " 1.Colones \n";
    std::cout << " 2.Dólares\n";
    std::cout << " Ingrese una opción:\n";
    
    try{
        std::cin >> opcion_divisa;
        
        switch (opcion_divisa)
        {
        case 1:
            cdp.setTipo("Colones");
            menuPlazos(cdp); 
            break;
        case 2:
            cdp.setTipo("Dólares");
            menuPlazos(cdp); 
            break;
 
        default:
            throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}

void MenuCDP::menuPlazos(CDP& cdp)
{
    int opcion_plazo;

    std::cout << "\n --- Plazos: ---\n";
    std::cout << " 1.Tres meses a 3% \n";
    std::cout << " 2.Seis meses a 4% \n";
    std::cout << " 3.Un año a 5% \n";
    std::cout << " Ingrese una opción:\n";
    
    try{
        std::cin >> opcion_plazo;
        
        switch (opcion_plazo)
        {
        case 1:
            cdp.setInteres(3);
            monto(cdp); 
            break;
        case 2:
            cdp.setInteres(4);
            monto(cdp); 
            break;
        case 3:
            cdp.setInteres(5);
            monto(cdp); 
            break;
        default:
            throw std::runtime_error("La opción elegida no está disponible.");
        }
    } catch (std::exception& e){
        std::cerr << "Error detectado: " << e.what() << std::endl;
        exit(0);
    }
}

void MenuCDP::monto(CDP& cdp)
{
    double monto;

    std::cout << "Ingrese el monto: ";
    std::cin >> monto;
    cdp.setMontoCDP(monto);
    cdp.ingresarCDP();
}


// Main de prueba

int main() {
    MenuCDP menu;
    menu.menuPrincipal();
    return 0;
}