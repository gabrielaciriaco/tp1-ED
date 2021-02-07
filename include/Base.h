#ifndef I_Base_H
#define I_Base_H
#include <string>

#include "Robo.h"

using namespace std;
class Base {
 private:
  Robo robos[50];
  char **mapa;
  int quantidadeDeRecursos;
  int quantidadeDeAlienigenas;

 public:
  Base(char **mapa, string **comandos, int numeroDeComandos);
  void inicializaRobos(string **comandos, int numeroDeComandos);
  void recebeRecursosEAlienigenasColetados(int indiceRobo);
};

#endif