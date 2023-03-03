#include <iostream>
#include <string.h>
#include "persona.hpp"

using std::cout;
using std::endl;

persona::persona(int _edad, const char *_nombre){
    int size_nombre = strlen(_nombre)+1;
    edad = _edad;
    nombre = new char[size_nombre];
    strcpy_s(nombre, size_nombre, _nombre);
}

persona::~persona(){
    cout << "Ejecutando destructor de " << nombre << endl;
    delete nombre;
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