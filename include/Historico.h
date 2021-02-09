#ifndef I_Historico_H
#define I_Historico_H
#include <iostream>
#include <string>

#include "ItemHistorico.h"

using namespace std;
class Historico {
 private:
  ItemHistorico* primeiroItemHistorico;

 public:
  Historico();
  void insereItemHistorico(string acao);
  void imprimir();
  void limpar();
};

#endif