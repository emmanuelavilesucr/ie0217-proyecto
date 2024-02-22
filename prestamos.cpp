#include "prestamos.hpp"
#include "cuentasAhorros.hpp"
#include <fstream>

Prestamos:: Prestamos(long long int id){
    this->id = id;
}

void Prestamos::menuPrestamos()
{
    /// Muestra el menú principal con los tipos de préstamos disponibles
    std::cout << "\n --- Gestión de prestamos ---\n";
    std::cout << " 1.Ver préstamos asociados a esa cuenta\n";
    std::cout << " 2.Crear préstamo\n";
    std::cout << " 3.Abonar a un préstamo\n";
}

void Prestamos::menuPrincipal()
{
    /// Muestra el menú principal con los tipos de préstamos disponibles
    std::cout << "\n --- Tipos de prestamos ---\n";
    std::cout << " 1.Prestamo Prendario\n";
    std::cout << " 2.Prestamo Personal\n";
    std::cout << " 3.Prestamo Hipotecario\n";
}

bool Prestamos::procesarOpciontercearia(){
    cout << "\n--Tipos de moneda--\n1.Colones\n2.Dolares\n";
    int opcion2 = verificarEntrada(2);
    //if (opcion2 == 0){
     //   return;
    //}
    if (opcion2 == 1){
            return true;
    }
    else{
        return false;
    }

}

int Prestamos::generarNuevoID() {
    std::ifstream archivo("prestamos.txt");
    int contador = 1000;
    std::string linea;
    // Contar el número de préstamos registrados
    while (std::getline(archivo, linea)) {
        contador++;
    }
    archivo.close();
    // El nuevo ID único es el contador incrementado en 1
    return contador + 1;
}

void Prestamos::procesarOpcionSecun(Datos prestamo){
    int opcion1 = MenusInfoCliente::verificarEntrada(3);
    if (opcion1 == 0){
        return;
    }
    double monto;
    bool moneda;
    /// Maneja las opciones dle menú 2, llama las funciones necesarias.
    switch (opcion1){
        case 1:
            MenusInfoCliente::infoPrestamo(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0]);
            try{
                idPrestamo = generarNuevoID();
                moneda = procesarOpciontercearia();
                cout<<"Ingrese el monto que desea consultar: ";
                cin>>monto;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }

            EscribirPrestamo(prestamo.tipo, prestamo.plazos[0], prestamo.interes[0], prestamo.cuotas[0], monto, moneda);
            break;
        
        case 2:
            MenusInfoCliente::infoPrestamo(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1]);
            try{
                idPrestamo = generarNuevoID();
                moneda = procesarOpciontercearia();
                cout<<"Ingrese el monto que desea consultar: ";
                cin>>monto;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }
            EscribirPrestamo(prestamo.tipo, prestamo.plazos[1], prestamo.interes[1], prestamo.cuotas[1], monto, moneda);
            break;

        default:
            MenusInfoCliente::infoPrestamo(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2]);
            try{
                idPrestamo = generarNuevoID();
                moneda = procesarOpciontercearia();
                cout<<"Ingrese el monto que desea consultar: ";
                cin>>monto;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el monto");
                }
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }
            EscribirPrestamo(prestamo.tipo, prestamo.plazos[2], prestamo.interes[2], prestamo.cuotas[2], monto, moneda);
            break;
    }

}


void Prestamos::procesarOpcion1()
{
    int opcion = MenusInfoCliente::verificarEntrada(3);
    if (opcion == 0){
        return;
    }

    /// Variable de tipo Datos (Struct)
    Datos prestamo1;

    /// Maneja las opciones del menú principal
    switch (opcion)
    {
        case 1:
            prestamo1.tipo = "Prendario";
            prestamo1.plazos = {"Seis meses", "Un año", "Tres años"};
            prestamo1.interes = {15, 12, 10};
            prestamo1.cuotas = {6, 12 ,36};

            MenusInfoCliente::menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcionSecun(prestamo1);
            break;

        case 2:
            prestamo1.tipo = "Personal";
            prestamo1.plazos = {"Doce meses", "Veinticuatro meses", "Treintaiséis meses"};
            prestamo1.interes = {35, 21, 9};
            prestamo1.cuotas = {12, 24 ,36};

            MenusInfoCliente::menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcionSecun(prestamo1);
            break;

        default:

            prestamo1.tipo = "Hipotecario";
            prestamo1.plazos = {"Diez años", "Veinte años", "Treinta años"};
            prestamo1.interes = {5, 4, 3};
            prestamo1.cuotas = {120, 240 ,360};

            MenusInfoCliente::menuSecundario(prestamo1.plazos[0], prestamo1.plazos[1], prestamo1.plazos[2]);
            procesarOpcionSecun(prestamo1);
            break;
    
    }
}


void Prestamos::EscribirPrestamo(std::string tipo, std::string plazo, double interes, int cuotas, double monto, bool moneda){

   // std::cout << "ID del Cliente: " << cliente_id << ", Nombre: " << nombre << std::endl;
    std::ofstream archivo("prestamos.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << idPrestamo << ","<< id << "," << tipo << "," << std::fixed << std::setprecision(15) << monto << "," << std::fixed << std::setprecision(15) << monto << "," << interes << "," << cuotas << "," << "0" <<  "," << moneda << std::endl;  // Escribe los datos del cliente en archivo txt
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
    }
}


void Prestamos::prestamosAsociados()
{
    // Abre el archivo para leer
    std::ifstream archivo("prestamos.txt");
    std::string linea;

    // Lee cada línea del archivo
    while (std::getline(archivo, linea)) {
        // Usa un stringstream para dividir la línea en partes usando la coma como delimitador
        std::stringstream ss(linea);
        std::string parte;
        int contador = 0;
        std::string moneda;

        // Recorre cada parte de la línea
        while (std::getline(ss, parte, ',')) {
            contador++;
            // Si es el segundo elemento (después de la coma), haz algo con él
            if (contador == 2) {
                //std::cout << "Segundo elemento de la línea: " << parte << std::endl;
                if (std::to_string(id) == parte){
                    std::stringstream ss(linea);
                    std::string parte;
                    std::vector<std::string> partes;

                    while (std::getline(ss, parte, ',')) {
                        partes.push_back(parte);
                    }
                    if (partes[8] == "1"){
                        moneda == "Colones";
                    }
                    else{
                        moneda == "Dolares";
                    }
                    cout << partes[0] << "\t" << partes[2]<< "\t" << partes[3]<< "\t" << partes[4]<< "\t" << partes[5]<< "\t\t" << partes[6]<< "\t" << partes[7]<< "\t" << moneda << std::endl;
                }
            }
        }
    }

    // Cierra el archivo
    archivo.close();
}

bool Prestamos::obtenerPagos(long long int idPrestamo, double pagar){
    std::ifstream archivo_entrada("prestamos.txt");
    std::string linea;
    while (archivo_entrada >> id && std::getline(archivo_entrada, linea)) {
        if (id == idPrestamo) {
            std::stringstream ss(linea);
            std::string parte;
            std::vector<std::string> partes;

            while (std::getline(ss, parte, ',')) {
                partes.push_back(parte);
            }
            tasaInteresMensual = std::stod(partes[5]) / 12 / 100;
            cuotaMensual = (tasaInteresMensual * std::stod(partes[3])) / (1 - pow((1 + tasaInteresMensual), -std::stod(partes[6])));
            interesPendiente = std::stod(partes[4]) * tasaInteresMensual;
            amortizacionPrincipal = cuotaMensual - interesPendiente;

            if (pagar == 0){
                saldoRestante = std::stod(partes[4]) - amortizacionPrincipal;
                cuotasPagadas = std::stoi(partes[7]) + 1;
            }
            else{
                saldoRestante = std::stod(partes[4]) - pagar;
            }

            if (std::stod(partes[4]) > 0){
                return true;
            }
            else{
                return false;
            }
            // Saldorestante =  Saldorestante -amortizacionPrincipal
            // cuotas pagadas +1
        }
        //float tasaInteresMensual = tasaInteresAnual / 12 / 100; // Calcula la tasa de interés mensual.
        //float cuotaMensual = (tasaInteresMensual * montoPrestamo) / (1 - pow((1 + tasaInteresMensual), -numCuotas));
    }

}

void Prestamos::actualizarDatos(long long int idPrestamo, int opc){
    std::ifstream archivo_lectura("prestamos.txt");
    std::ofstream archivo_escritura("prestamos_temp.txt");


    if (archivo_lectura.is_open() && archivo_escritura.is_open()) {
        long long int id;
        long long int idCuenta;
        std::string tipo;
        double monto;
        double saldo;
        int interes, cuotas, pagadas, tipoMoneda;
        bool cambio = false;
        std::string linea;


        while (archivo_lectura >> id && std::getline(archivo_lectura, linea)) {
            if (id == idPrestamo){
                std::istringstream ss(linea);
                std::string parte;
                std::vector<std::string> partes;

                while (std::getline(ss, parte, ',')) {
                    partes.push_back(parte);
                }

                if (saldoRestante > 0){
                    partes[4] = std::to_string(saldoRestante);
                }
                else{
                    partes[4] = "0";
                }


                if (opc == 0){
                    partes[7] = std::to_string(cuotasPagadas);
                }
                cambio = true;
                archivo_escritura << id << "," << partes[1] << "," << partes[2] << "," << std::fixed << std::setprecision(15) << partes[3] << ","
                << std::fixed << std::setprecision(15) << partes[4] << ","<< partes[5] << ","<< partes[6] << ","<< partes[7] << ","<< partes[8] << std::endl;
            }
            else{
                std::istringstream ss(linea);
                std::string parte;
                std::vector<std::string> partes;

                while (std::getline(ss, parte, ',')) {
                    partes.push_back(parte);
                }
                archivo_escritura << id << "," << partes[1] << "," << partes[2] << "," << std::fixed << std::setprecision(15) << partes[3] << ","
                << std::fixed << std::setprecision(15) << partes[4] << ","<< partes[5] << ","<< partes[6] << ","<< partes[7] << ","<< partes[8] << std::endl;
            }
        
        } 
        archivo_lectura.close();
        archivo_escritura.close();

        if (cambio) {
            remove("prestamos.txt");
            rename("prestamos_temp.txt", "prestamos.txt");
        } else {
            remove("prestamos_temp.txt");
        }
        return;
    } else{
        std::cout << "No se pudieron abrir los archivos." << std::endl;
        return;
    }
}

void Prestamos::pagarCuota(long long int idPrestamo)
{
    CuentasAhorros cuenta(id);
    cout << "\n-- Eliga el método de pago --" << endl;
    cout << "1.Efectivo\n2.Transferencia" << endl;
    int opcion = MenusInfoCliente::verificarEntrada(2);
    bool verificar;
    switch (opcion)
    {
        case 1:
            if (obtenerPagos(idPrestamo, 0)){
                actualizarDatos(idPrestamo, 0);
            }
            else{
                cout << "El préstamo ya fue cancelado";
            }
            break;

        default:
            if (obtenerPagos(idPrestamo, 0)){
                if (saldoRestante > 0){
                    // Hacer retiro con cuotamensual
                    cuenta.verficarCantidadCuentas();
                    cuenta.elegirCuenta();
                    verificar = cuenta.retiro(cuotaMensual);
                    if (verificar == true){
                        cuenta.actualizarDatos();
                        std::cout << "Retiro completado" << std::endl;
                        actualizarDatos(idPrestamo, 0);
                    }
                }
                else{
                    // Hacer el retiro co
                    cuotaMensual = cuotaMensual + saldoRestante;
                    cuenta.verficarCantidadCuentas();
                    cuenta.elegirCuenta();
                    verificar = cuenta.retiro(cuotaMensual);
                    if (verificar == true){
                        cuenta.actualizarDatos();
                        std::cout << "Retiro completado" << std::endl;
                        actualizarDatos(idPrestamo, 0);
                    }
                }
            }
            else{
                cout << "El préstamo ya fue cancelado";
            }

            // Restarle al archivo de cuentas la cuota mensual
            break;
    }
}

void Prestamos::abonarCapital(long long int idPrestamo)
{
    CuentasAhorros cuenta(id);
    cout << "\n-- Eliga el método de pago --" << endl;
    cout << "1.Efectivo\n2.Transferencia" << endl;
    int opcion = MenusInfoCliente::verificarEntrada(2);
    double abono;
    bool verificar;
    cout << "\nDigite el monto que desea abonarle al capital: ";
    cin >> abono;
    switch (opcion)
    {
        case 1:
            if (obtenerPagos(idPrestamo, abono)){
                actualizarDatos(idPrestamo, 1);
            }
            else{
                cout << "El préstamo ya fue cancelado";
            }
            break;

        default:
            if (obtenerPagos(idPrestamo, abono)){
                if (saldoRestante > 0){
                    // Llamar retiro con abono
                    //CuentasAhorros cuenta(id);
                    cuenta.verficarCantidadCuentas();
                    cuenta.elegirCuenta();
                    verificar = cuenta.retiro(abono);
                    if (verificar == true){
                        cuenta.actualizarDatos();
                        std::cout << "Retiro completado" << std::endl;
                        actualizarDatos(idPrestamo, 1);
                    }
                }
                else{
                    // Llamar retiro con abono + saldo restante
                    //CuentasAhorros cuenta(id);
                    cuenta.verficarCantidadCuentas();
                    cuenta.elegirCuenta();
                    abono = abono + saldoRestante;
                    verificar = cuenta.retiro(abono);
                    if (verificar == true){
                        cuenta.actualizarDatos();
                        std::cout << "Retiro completado" << std::endl;
                        actualizarDatos(idPrestamo, 1);
                    }
                }
            }
            else{
                cout << "El préstamo ya fue cancelado";
            }
            break;
    }
}

void Prestamos::procesarOpcionPrestamos()
{
    int opcion = MenusInfoCliente::verificarEntrada(3);
    if (opcion == 0){
        return;
    }

    long long int idPrestamoPagar;
    switch (opcion)
    {
        case 1:
            cout << "\nPréstamos asociados a la cuenta " << id << endl;
            cout << "Id\tTipo\t\tMonto\tSaldo\tIntéres\tCuotas\tCuotas pagadas" << endl;
            prestamosAsociados();
            break;

        case 2:
            menuPrincipal();
            procesarOpcion1();
            break;
        default:
            try{
                cout<<"Ingrese el ID del préstamo que desea pagar: ";
                cin>>idPrestamoPagar;
                if (std::cin.fail()){
                    throw std::runtime_error("No es un dato válido para el ID");
                }
            }
            catch(const std::exception& e){
                /// Maneja el error lanzado
                std::cerr << "Error: " << e.what() << std::endl;
            }
            cout << "\n-- Tipo de pago --" << endl;
            cout << "1.Pagar cuota\n2.Abonar al capital" << endl;
            opcion = MenusInfoCliente::verificarEntrada(2);
            if (opcion == 1){
                pagarCuota(idPrestamoPagar);
            }
            else{
                abonarCapital(idPrestamoPagar);
            }
            break;

    }
}


int main(){
    Prestamos prestamo(123456789);
    prestamo.menuPrestamos();
    prestamo.procesarOpcionPrestamos();
    return 0;
}