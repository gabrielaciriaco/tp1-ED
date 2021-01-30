#include <iostream>
#include "../include/Controlador.h"

Controlador::Controlador(char** mapa){
    for(int i=0;i<50;i++){
        robos[i] = Robo();
    }
    this->mapa = mapa;
}