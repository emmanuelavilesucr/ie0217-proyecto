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
    
}

void InfoCliente::menuPrincipal(){


}

void InfoCliente::menuSecundario(){

}

void InfoCliente::menuTerceario(){

}

void InfoCliente::procesarOpcion1(){

}

void InfoCliente::procesarOpcion2(){

}

void InfoCliente::procesarOpcion3(){

}