#include <iostream>
#include <string.h>
#include "persona.hpp"

using std::cout;
using std::endl;

persona::persona(){
    nombre = "Juan";
    edad = 21;
}

persona::persona(int _edad, const char *_nombre){
    edad = _edad;
    nombre = _nombre;
}

void persona::reir(){
    cout << "Ja Ja Ja Ja Ja!..." << endl;
}

void persona::comer(){
    cout << "Ñam ñam ñam..." << endl;
}

void persona::hacerReir(int motivo){
    if(motivo % 3 == 0){
        reir();
    }else{
        cout << ":|"<<endl;
    }
}

void persona::saludar(){
    cout << "Hola soy "<< nombre << " y tengo " << edad << " anios" << endl;
}

void persona::SetNombre(const char *nombre){
    this->nombre = nombre;
}

void persona::SetEdad(int edad){
    if(edad >= 18){
        this->edad = edad;
    }
}