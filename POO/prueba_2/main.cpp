#include <iostream>
#include "persona.hpp"

#define endl '\n'

using std::cout;
using std::cin;
using std::string;

int main(){

    string cad1, cad2, cad3;
    cad1 = "Hello";
    cad2 = " world";
    cad3 = cad1 + cad2;
    cout<<cad3<<endl;

    cout << "Dime tu nombre: "<<endl;
    std::getline(cin, cad3);
    cin.ignore(0xff, '\n');
    cout << "Tu nombre es: " << cad3 << endl;

    return 0;
}