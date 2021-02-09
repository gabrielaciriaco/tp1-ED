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
  void executarComandos(int indiceRobo);
  void executarComando(Comando comando,int indiceRobo);
  void moverRobo(int indiceRobo,int coordenadaX,int coordenadaY);
  void coletarRecursos(int indiceRobo);
  void eliminarAlien(int indiceRobo);
 public:
  Base(char **mapa, string **comandos, int numeroDeComandos);
  void inicializaRobos(string **comandos, int numeroDeComandos);
  void retornarRobo(int indiceRobo);
  void imprimeRelatorio();
};

#endif