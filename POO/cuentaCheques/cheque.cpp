#include "cheque.hpp"
#include <iostream>

cheque::cheque(int numeroDeCuenta, persona p){
    saldo = 0;
    this->numeroDeCuenta = numeroDeCuenta;
    this->Propietario = p.GetNombre();
    this->UltimoAcceso = "Sin historial";
}

void cheque::consultarDatos(){
    std::cout << "Nombre del propietario: " << this->Propietario << " Numero de cuenta: " << this->numeroDeCuenta << std::endl;
    std::cout << "Saldo total: $" << this->saldo << std::endl;
    std::cout << "ultimo acceso: " << this->UltimoAcceso << std::endl;
}

void cheque::enviar(Tsaldo saldo, cheque *destino){
    destino.
}