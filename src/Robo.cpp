#include "../include/Robo.h"

Robo::Robo(int indiceRobo) {
  this->aliensEliminados = 0;
  this->recursosColetados = 0;
  this->filaDeComandos = FilaDeComandos();
  this->posicaoX = -1;
  this->posicaoY = -1;
  this->indiceRobo = indiceRobo;
}
void Robo::insereComando(string comando[4]) {
  string tipoComando = comando[0];
  if (comando[2] != "" && comando[3] != "") {
    int coordenadaX = stoi(comando[2]);
    int coordenadaY = stoi(comando[3]);
    filaDeComandos.insereComando(tipoComando, coordenadaX, coordenadaY);
    return;
  }
  filaDeComandos.insereComando(tipoComando);
}
void Robo::ativar() {
  if (posicaoX != -1) {
    cout << "BASE: ROBO " << indiceRobo << " JA ESTA EM MISSAO";
  } else {
    cout << "BASE: ROBO " << indiceRobo << " SAIU EM MISSAO";
    posicaoX = 0;
    posicaoY = 0;
  }
}

void Robo::executar() {
  if (posicaoX == -1) {
    cout << "BASE: ROBO " << indiceRobo << " NAO ESTA EM MISSAO";
  }
}

void Robo::retornar(){
  posicaoX = -1;
  posicaoY = -1;
  recursosColetados = 0;
  aliensEliminados = 0;
  filaDeComandos = FilaDeComandos();
}

int Robo::getRecursosColetados(){
  return recursosColetados;
}

int Robo::getAliensEliminados(){
  return aliensEliminados;
}