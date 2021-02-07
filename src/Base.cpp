#include "../include/Base.h"

#include <iostream>

Base::Base(char **mapa, string **comandos, int numeroDeComandos) {
  for (int i = 0; i < 50; i++) {
    robos[i] = Robo(i);
  }
  this->mapa = mapa;
  inicializaRobos(comandos, numeroDeComandos);
}

void Base::inicializaRobos(string **comandos, int numeroDeComandos) {
  for (int i = 0; i < numeroDeComandos; i++) {
    string tipoComando = comandos[i][0];
    int indiceRobo = stoi(comandos[i][1]);

    if (tipoComando == "ATIVAR") {
      robos[indiceRobo].ativar();
    } else if (tipoComando == "EXECUTAR") {
      robos[indiceRobo].executar();
    } else if (tipoComando == "RETORNAR") {
      recebeRecursosEAlienigenasColetados(indiceRobo);
      robos[indiceRobo].retornar();
    } else {
      robos[indiceRobo].insereComando(comandos[i]);
    }
  }
}

void Base::recebeRecursosEAlienigenasColetados(int indiceRobo) {
  this->quantidadeDeRecursos += robos[indiceRobo].getRecursosColetados();
  this->quantidadeDeAlienigenas += robos[indiceRobo].getAliensEliminados();
}