#pragma once
#include <string>

using std::string;

class persona
{
protected:
    int edad;
    string nombre;
public:
    persona();
    persona(int _edad, const char *_nombre);
    void reir();
    void comer();
    void hacerReir(int motivo);
    void saludar();

    //Getters
    int GetEdad(){ return edad;}
    string GetNombre(){ return nombre;}
    //Setters
    void SetNombre(const char *_nombre);
    void SetEdad(int edad);
};