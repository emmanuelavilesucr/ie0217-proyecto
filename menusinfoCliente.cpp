#include "menusInfoCliente.hpp"
#include "infoCliente.hpp"

void MenusInfoCliente::menuPrincipal()
{
    std::cout << "\n --- Tipos de prestamos ---\n";
    std::cout << " 1.Prestamo Prendario\n";
    std::cout << " 2.Prestamo Hipotecario\n";
    std::cout << " 3.Prestamo Personal\n";
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

int verificarEntrada(){
    try{
        int opcion;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        /// Verifica que la opción sea valida
        if (std::cin.fail() || (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4) ){
            throw std::runtime_error("No es una opción válida");
        }
        return opcion;

    }catch (const std::exception& e){
        /// Maneja el error lanzado
        std::cerr << "Error: " << e.what() << std::endl;
        return 0;
    }

}

void MenusInfoCliente::procesarOpcion1()
{
    int opcion = verificarEntrada();
    if (opcion == 0){
        return;
    }
    std::string plazo1;
    std::string plazo2;
    std::string plazo3;
    std::string tipo;
    float interes;
    int cuotas;
    float montoPrestamo;

    int opcion1;
    int opcion2;
    int opcion3;
    switch (opcion)
    {
        case 1:
            tipo = "Prendario";
            plazo1 = "Seis meses";
            plazo2 = "Un año";
            plazo3 = "Tres años";
            menuSecundario(plazo1, plazo2, plazo3);
            opcion1 = verificarEntrada();
            
            if (opcion1 == 1)
            {
                interes = 15;
                cuotas = 6;
                infoPrestamo(tipo, plazo1, interes, cuotas);
                menuTerceario();
                int opcion11 = verificarEntrada();

                if (opcion11 == 1)
                {
                    // Crear el objeto con los datos de esta opción
                    cout << "Ingrese el monto que desea consultar: ";
                    cin >> montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReportePrendario6meses.txt");
                    break;
                }
                else if (opcion11 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                    
                }
            }
            else if (opcion1 == 2)
            {
                interes = 12;
                cuotas = 12;
                infoPrestamo(tipo, plazo2, interes, cuotas);
                menuTerceario();
                int opcion12 = verificarEntrada();
                if (opcion12 == 1)
                {
                    // Crear el objeto con los datos de esta opción
                    cout << "Ingrese el monto que desea consultar: ";
                    cin >> montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReportePrendario1año.txt");
                    break;
                }
                else if (opcion12 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            else if (opcion1 == 3)
            {
                interes = 10;
                cuotas = 36;
                infoPrestamo(tipo, plazo3, interes, cuotas);
                menuTerceario();
                int opcion13 = verificarEntrada();
                if (opcion13 == 1)
                {
                    // Crear el objeto con los datos de esta opción
                    cout << "Ingrese el monto que desea consultar: ";
                    cin >> montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReportePrendario3años.txt");
                    break;
                }
                else if (opcion13 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            else{
                cout<<"Opción invalida";
                break;
            }

        case 2:
            tipo = "Personal";
            plazo1 = "Setenta y dos meses";
            plazo2 = "Ochenta meses";
            plazo3 = "Ochenta y cuatro meses";
            menuSecundario(plazo1, plazo2, plazo3);
            opcion2 = verificarEntrada();
            
            if (opcion2 == 1)
            {
                interes = 36;
                cuotas = 72;
                infoPrestamo(tipo, plazo1, interes, cuotas);
                menuTerceario();
                int opcion21 = verificarEntrada();
                
                if (opcion21 == 1)
                {
                    // Crear el objeto con los datos de esta opción
                    cout << "Ingrese el monto que desea consultar: ";
                    cin >> montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReportePersonal72meses.txt");
                    break;
                }
                else if (opcion21 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            else if (opcion2 == 2)
            {
                interes = 17;
                cuotas = 80;
                infoPrestamo(tipo, plazo2, interes, cuotas);
                menuTerceario();
                int opcion22 = verificarEntrada();
                
                if (opcion22 == 1)
                {
                    // Crear el objeto con los datos de esta opción
                    cout << "Ingrese el monto que desea consultar: ";
                    cin >> montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReportePersonal80meses.txt");
                    break;
                }
                else if (opcion22 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            else
            {
                interes = 5;
                cuotas = 84;
                infoPrestamo(tipo, plazo3, interes, cuotas);
                menuTerceario();
                int opcion23 = verificarEntrada();
                
                if (opcion23 == 1)
                {
                    //Crear el objeto con los datos de esta opción
                        cout<<"Ingrese el monto que desea consultar: ";
                        cin>>montoPrestamo;
                        InfoCliente informacion(montoPrestamo, interes, cuotas);
                        informacion.generarReporte("ReportePersonal84meses.txt");
                        break;
                }
                else if (opcion23 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            
            //break;

        case 3:
            tipo = "Hipotecario";
            plazo1 = "Diez años";
            plazo2 = "Veinte años";
            plazo3 = "Treinta años";
            menuSecundario(plazo1, plazo2, plazo3);
            opcion3 = verificarEntrada();
            
            if (opcion3 == 1)
            {
                interes = 5;
                cuotas = 120;
                infoPrestamo(tipo, plazo1, interes, cuotas);
                menuTerceario();
                int opcion31 = verificarEntrada();
        
                if (opcion31 == 1)
                {
                    //Crear el objeto con los datos de esta opción
                    cout<<"Ingrese el monto que desea consultar: ";
                    cin>>montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReporteHipotecario10años.txt");
                    break;
                }
                else if (opcion31 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            else if (opcion3 == 2)
            {
                interes = 4;
                cuotas = 240;
                infoPrestamo(tipo, plazo2, interes, cuotas);
                menuTerceario();
                int opcion32  = verificarEntrada();

                if (opcion32 == 1)
                {
                    //Crear el objeto con los datos de esta opción
                    cout<<"Ingrese el monto que desea consultar: ";
                    cin>>montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReporteHipotecario20ños.txt");
                    break;
                }
                else if (opcion32 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            else
            {
                interes = 3;
                cuotas = 360;
                infoPrestamo(tipo, plazo3, interes, cuotas);
                menuTerceario();
                int opcion33 = verificarEntrada() ;
                
                if (opcion33 == 1)
                {
                    //Crear el objeto con los datos de esta opción
                    cout<<"Ingrese el monto que desea consultar: ";
                    cin>>montoPrestamo;
                    InfoCliente informacion(montoPrestamo, interes, cuotas);
                    informacion.generarReporte("ReporteHipotecario30ños.txt");
                    break;
                }
                else if (opcion33 == 2)
                {
                    break;
                }
                else{
                    cout<<"Opción invalida";
                }
            }
            //break;

        case 4:
            try{
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
                /// Verifica que la opción sea valida
                //if (std::cin.fail()){
                //    throw std::runtime_error("Ha ingresado los datos de manera incorrecta.");
                //}

            }catch (const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
                break; //exit(EXIT_FAILURE); // Cambiar por un break
            }
            //break;
        default:
            std::cout << "Opcion invalida";
            break;
    }
}

int main(){
    MenusInfoCliente menus;
    menus.menuPrincipal();
    menus.procesarOpcion1();

    return 0;
}
