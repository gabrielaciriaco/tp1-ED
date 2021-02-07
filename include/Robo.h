#ifndef I_Robo_H
#define I_Robo_H
#include "FilaDeComandos.h"

class Robo{
    private:
        FilaDeComandos filaDeComandos;
        int posicaoX;
        int posicaoY;
        int aliensEliminados;
        int recursosColetados;
        int indiceRobo;
    public:
        Robo(){}
        Robo(int indiceRobo);
        void insereComando(string comando[4]);
        void ativar();
        void executar();
        void retornar ();
        int getRecursosColetados();
        int getAliensEliminados();
};

#endif