#include <string>
#include "persona.hpp"

typedef double Tsaldo;

class cheque
{
protected:
    Tsaldo saldo;
    int numeroDeCuenta;
    std::string Propietario;
    std::string UltimoAcceso;

public:
    cheque(int numeroDeCuenta, persona p);
    void consultarDatos();
    void enviar(Tsaldo saldo, cheque *destino);
    Tsaldo retirar(Tsaldo saldo);
    void setSaldo(Tsaldo saldo){this->saldo = saldo;}
};