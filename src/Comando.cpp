#include "../include/Comando.h"

Comando::Comando(string tipo) {
  this->tipo = tipo;
  this->coordenadaX = -1;
  this->coordenadaY = -1;
  altaPrioridade = tipo.at(0) == '*';
}
Comando::Comando(string tipo, int coordenadaX, int coordenadaY) {
  this->tipo = tipo;
  this->coordenadaX = coordenadaX;
  this->coordenadaY = coordenadaY;
  altaPrioridade = tipo.at(0) == '*';
}
Comando* Comando::getProximoComando() { return proximoComando; }
Comando* Comando::getAnteriorComando() { return anteriorComando; }
void Comando::setProximoComando(Comando* comando) { proximoComando = comando; }
void Comando::setAnteriorComando(Comando* comando) {
  anteriorComando = comando;
}

bool Comando::getAltaPrioridade(){
  return altaPrioridade;
}