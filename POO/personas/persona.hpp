#pragma once

class persona
{
protected:
    int edad;
    char *nombre;
public:
    persona(int _edad, const char *_nombre);
    ~persona();
    void reir();
    void comer();
    void hacerReir(int motivo);
    void saludar();
};