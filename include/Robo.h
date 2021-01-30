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
};

#endif