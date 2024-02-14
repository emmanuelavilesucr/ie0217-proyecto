#include "menusInfoCliente.hpp"
#include "infoCliente.hpp"

void MenusInfoCliente::menuPrincipal()
{
    std::cout << "\n --- Tipos de prestamos ---\n";
    std::cout << " 1.Prestamo Prendario\n";
    std::cout << " 2.Prestamo Personal\n";
    std::cout << " 3.Prestamo Hipotecario\n";
    std::cout << " 4.Reporte personalizado\n";
}

void MenusInfoCliente::menuSecundario(std::string plazo1, std::string plazo2, std::string plazo3)
{
    std::cout << "\n ---  Plazos preestablecidos ---\n";
    std::cout << " 1. " << plazo1 << "\n";
    std::cout << " 2. " << plazo2 << "\n";
    std::cout << " 3. " << plazo3 << "\n";
}

void MenusInfoCliente::menuTerceario()
{
    std::cout << "\n --- ¿Desea generar un reporte? ---\n";
    std::cout << " 1.Generar reporte\n";
    std::cout << " 2.Salir\n";
}

void MenusInfoCliente::infoPrestamo(std::string tipoPrestamo, std::string plazo, float interes, int cuotas)
{
    std::cout << "\n --- Infromación general ---\n";
    std::cout << " Tipo de prestamo: " << tipoPrestamo << std::endl;
    std::cout << " Plazo: " << plazo << std::endl;
    std::cout << " Tasa de interés anual: " << interes << std::endl;
    std::cout << " Número de cuotas: " << cuotas << std::endl;
}

int verificarEntrada(int numOpciones){
    try{
        int opcion;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        /// Verifica que la opción sea valida
        if (std::cin.fail() || opcion < 1 || opcion > numOpciones ){
            throw std::runtime_error("No es una opción válida");
        }
        return opcion;

    }catch (const std::exception& e){
        /// Maneja el error lanzado
        std::cerr << "Error: " << e.what() << std::endl;
        exit(0);
    }

}

void MenusInfoCliente::procesarOpcion3(std::string tipo, std::string plazo, float interes, int cuotas){
    int opcion2 = verificarEntrada(2);
    if (opcion2 == 0){
        return;
    }
    if (opcion2 == 1){
            float montoPrestamo;
            try{
                cout<<"Ingrese el monto que desea consultar: ";
                cin>>montoPrestamo;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
                InfoCliente informacion(montoPrestamo, interes, cuotas);
                informacion.generarReporte("Reporte" + tipo + plazo +".txt");
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }
    }
    else{
        cout<<"Saliendo del programa";
    }

}

void MenusInfoCliente::procesarOpcion2(Datos prestamo){
    int opcion1 = verificarEntrada(3);
    if (opcion1 == 0){
        return;
    }

    switch (opcion1){
        case 1:
            infoPrestamo(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0]);
            menuTerceario();
            procesarOpcion3(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0]);
            break;
        
        case 2:
            infoPrestamo(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1]);
            menuTerceario();
            procesarOpcion3(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1]);
            break;

        default:
            infoPrestamo(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2]);
            menuTerceario();
            procesarOpcion3(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2]);
            break;
    }

}
void MenusInfoCliente::procesarOpcion1()
{
    int opcion = verificarEntrada(4);
    if (opcion == 0){
        return;
    }

    Datos prestamo1;
    Datos prestamo2;
    Datos prestamo3;

    switch (opcion)
    {
        case 1:
            prestamo1.tipo = "Prendario";
            prestamo1.plazos = {"Seis meses", "Un año", "Tres años"};
            prestamo1.interes = {15, 12, 10};
            prestamo1.cuotas = {6, 12 ,36};

            menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcion2(prestamo1);
            break;

        case 2:
            prestamo1.tipo = "Personal";
            prestamo1.plazos = {"Setenta y dos meses", "Ochenta meses", "Ochenta y cuatro meses"};
            prestamo1.interes = {36, 17, 5};
            prestamo1.cuotas = {72, 80 ,84};

            menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcion2(prestamo1);
            break;

        case 3:

            prestamo1.tipo = "Hipotecario";
            prestamo1.plazos = {"Diez años", "Veinte años", "Treinta años"};
            prestamo1.interes = {5, 4, 3};
            prestamo1.cuotas = {120, 240 ,360};

            menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcion2(prestamo1);
            break;

        default:
            try{
                float montoPrestamo;
                float interes;
                int cuotas;

                cout<<"Ingrese el monto del prestamo: ";
                cin>>montoPrestamo;
                if (std::cin.fail()){
                    throw std::runtime_error("Ha ingresado los datos de manera incorrecta.");
                }

                cout<<"Ingrese la tasa de intéres anual: ";
                cin>>interes;
                if (std::cin.fail()){
                    throw std::runtime_error("Ha ingresado los datos de manera incorrecta.");
                }

                cout<<"Ingrese la cantidad de cuotas: ";
                cin>>cuotas;
                if (std::cin.fail()){
                    throw std::runtime_error("Ha ingresado los datos de manera incorrecta.");
                }

                InfoCliente informacion(montoPrestamo, interes, cuotas);
                informacion.generarReporte("ReportePersonalizado.txt");
                break;

            }catch (const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
                exit(0); 
            }
    }
}

int main(){
    MenusInfoCliente menus;
    menus.menuPrincipal();
    menus.procesarOpcion1();

    return 0;
}
