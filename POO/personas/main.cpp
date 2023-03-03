#include <iostream>
#include <stdlib.h>
#include "persona.hpp"

#define endl "\n"

//char -> 1 byte -> 4 bits -> 0 0 0 0
// [20, 10, 40] -> 12 bytes + 3 bytes = 15 bytes [10100 0001, 1010 0010, 00101000 0011]

using std::cout;
using std::cin;

void foo(){
    persona myFoo(22, "Foo");
    myFoo.saludar();
}

void usarPersona(persona *persona_usar){
    cout << "Inicio de usar persona"<<endl;
    persona_usar->comer();
    persona_usar->hacerReir(rand() % 100);
    persona_usar->saludar();
    cout << "Fin de uso de persona"<<endl;
}

int main(){

    int x = 10;
    float pi = 3.1415;
    char n[] = "Nada";
    persona miPersona(21, "Roberto Isaac");
    persona *otraPersona = new persona(21, "Tilin");
    persona tercePersona(23, "Algun nombre muy largo pero no pondre el mismo que el profe asigno por que esta muy largo y es mas facil escribir algo diferente");

    /*cout << "Hello world!\n";
    cout << "Valor de x: "<< x << endl;
    cout << "Valor de pi: " << pi << endl;
    cout << "Valor de la cadena: " << n << endl;
    cin >> x;
    cout << "Valor de x: "<< x << endl;*/
    foo();
    usarPersona(&tercePersona);
    miPersona.saludar();
    otraPersona->saludar();
    tercePersona.saludar();

    delete otraPersona;

    return 0;
}