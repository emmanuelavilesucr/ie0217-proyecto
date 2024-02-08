#include "infoCliente.hpp"

InfoCliente::InfoCliente(float montoPrestamo, float tasaInteresAnual, int numCuotas){
    this->montoPrestamo = montoPrestamo;
    this->tasaInteresAnual = tasaInteresAnual;
    this->numCuotas = numCuotas;
    cout << "xd";
    amortizacion = calcularAmortizacion();
}

std::vector<std::vector<float>> InfoCliente::calcularAmortizacion(){
    try{
        if (numCuotas == 0){
            throw runtime_error("Error: El número de cuotas no puede ser cero");
        }
        float tasaInteresMensual = tasaInteresAnual / 12 / 100;
        float cuotaMensual = (tasaInteresMensual * montoPrestamo) / (1 - pow((1 + tasaInteresMensual), -numCuotas));
        float saldoRestante = montoPrestamo;
        std::vector<std::vector<float>> amortizacion;

        for (float cuota = 1; cuota < numCuotas + 1; cuota ++){
            float interesPendiente = saldoRestante * tasaInteresMensual;
            float amortizacionPrincipal = cuotaMensual - interesPendiente;
            saldoRestante -= amortizacionPrincipal;
            std::vector<float> vectorTemp = {cuota, interesPendiente, amortizacionPrincipal, saldoRestante};
            amortizacion.push_back(vectorTemp);
        }

        return amortizacion;
    }
    catch(const exception& e){
        cerr << e.what() << endl;
        std::vector<float> vectorTemp = {};
        amortizacion.push_back(vectorTemp);
        return amortizacion;
    }
}

void InfoCliente::generarReporte(std::string nombre){
    ofstream archivo;
    archivo.open(nombre, ios::app);
    if (archivo.fail()){
        cout << "No se pudo abrir el archivo"<< endl;
        exit(1);
    }
    archivo << "Cuota  Interés pendiente  Amortización  Saldo restante"<< endl;
    for (int i = 0; i < amortizacion.size(); i++){
        archivo << amortizacion[i][0] << "   " << amortizacion[i][1] << "   "<< amortizacion[i][2] << "   "<< amortizacion[i][3] << "   "<< endl;;
    }
    archivo.close();

}

void InfoCliente::menuPrincipal(){
    std::cout << "\n --- Tipos de prestamos ---\n";
    std::cout << " 1.Prestamo Prendario\n";
    std::cout << " 2.Prestamo Hipotecario\n";
    std::cout << " 3.Prestamo Personal\n";
    std::cout << " 4.Reporte personalizado\n";
}

void InfoCliente::menuSecundario(std::string plazo1, std::string plazo2, std::string plazo3){
    std::cout << "\n ---  Plazos preestablecidos ---\n";
    std::cout << " 1. "<< plazo1 << "\n";
    std::cout << " 2. "<< plazo2 << "\n";
    std::cout << " 3. "<< plazo3 << "\n";
}

void InfoCliente::menuTerceario(){
    std::cout << "\n --- ¿Desea generar un reporte? ---\n";
    std::cout << " 1.Generar reporte\n";
    std::cout << " 2.Salir\n";
}

void InfoCliente::procesarOpcion1(){

}

void InfoCliente::procesarOpcion2(){

}

void InfoCliente::procesarOpcion3(){

}