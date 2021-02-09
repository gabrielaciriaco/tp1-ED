#ifndef I_Comando_H
#define I_Comando_H
#include <iostream>

using namespace std;
class Comando
{
private:
    string tipo;
    int coordenadaX;
    int coordenadaY;
    Comando* proximoComando;
    Comando* anteriorComando;
    bool altaPrioridade;
public:
    Comando(string tipo);
    Comando(string tipo,int coordenadaX, int coordenadaY);
    Comando* getProximoComando();
    Comando* getAnteriorComando();
    void setAnteriorComando(Comando* comando);
    void setProximoComando(Comando* comando);
    bool getAltaPrioridade();
    string getTipo();
    int getCoordenadaX();
    int getCoordenadaY();
    void setCoordenadaX(int coordenadaX);
    void setCoordenadaY(int coordenadaY);
};

#endif