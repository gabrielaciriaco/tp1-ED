#ifndef I_FilaDeComandos_H
#define I_FilaDeComandos_H
#include <iostream>
#include <string>
#include "Comando.h"

using namespace std;
class FilaDeComandos{
    private:
    Comando* primeiroComando;
    
    public:

    FilaDeComandos();
    void insereComando(string tipo);
    void insereComando(string tipo, int coordenadaX, int coordenadaY);
    void insereComando(Comando* novoComando);
};


#endif