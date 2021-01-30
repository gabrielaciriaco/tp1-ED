#ifndef I_Comando_H
#define I_Comando_H

using namespace std;
class Comando
{
private:
    string tipo;
    int coordenadaX;
    int coordenadaY;
    Comando* proximoComando;
    Comando* anteriorComando;
public:
    Comando(string tipo);
    Comando(string tipo,int coordenadaX, int coordenadaY);
    Comando* getProximoComando();
    Comando* getAnteriorComando();
    void setAnteriorComando(Comando* comando);
    void setProximoComando(Comando* comando);
};

#endif