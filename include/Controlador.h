#ifndef I_Controlador_H
#define I_Controlador_H
#include "Robo.h"

class Controlador{
    private:
    Robo robos[50];
    char** mapa;

    public:
    Controlador(char** mapa);
};

#endif