#include "../include/Comando.h"

Comando::Comando(string tipo) {
  this->tipo = tipo;
  this->coordenadaX = -1;
  this->coordenadaY = -1;
  altaPrioridade = tipo.at(0) == '*';
  this->anteriorComando = NULL;
  this->proximoComando = NULL;
}

Comando::Comando(string tipo, int coordenadaX, int coordenadaY) {
  this->tipo = tipo;
  this->coordenadaX = coordenadaX;
  this->coordenadaY = coordenadaY;
  this->anteriorComando = NULL;
  this->proximoComando = NULL;
  altaPrioridade = tipo.at(0) == '*';
}

Comando* Comando::getProximoComando() { return proximoComando; }

Comando* Comando::getAnteriorComando() { return anteriorComando; }

void Comando::setProximoComando(Comando* proximoComando) {
  this->proximoComando = proximoComando;
}

void Comando::setAnteriorComando(Comando* anteriorComando) {
  this->anteriorComando = anteriorComando;
}

bool Comando::getAltaPrioridade() { return altaPrioridade; }

string Comando::getTipo() { return this->tipo; }

int Comando::getCoordenadaX() { return this->coordenadaX; }

int Comando::getCoordenadaY() { return this->coordenadaY; }

void Comando::setCoordenadaX(int coordenadaX) {
  this->coordenadaX = coordenadaX;
}

void Comando::setCoordenadaY(int coordenadaY) {
  this->coordenadaY = coordenadaY;
}