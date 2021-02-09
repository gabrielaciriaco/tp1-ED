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
      executarComandos(indiceRobo);
    } else if (tipoComando == "RETORNAR") {
      retornarRobo(indiceRobo);
    } else if (tipoComando == "RELATORIO") {
      robos[indiceRobo].relatorio();
    } else {
      robos[indiceRobo].insereComando(comandos[i]);
    }
  }
}

void Base::retornarRobo(int indiceRobo) {
  Robo robo = robos[indiceRobo];
  int recursosColetados = robos[indiceRobo].getRecursosColetados();
  int aliensEliminados = robos[indiceRobo].getAliensEliminados();
  if (robo.getPosicaoX() != -1 || robo.getPosicaoY() != -1) {
    cout << "BASE: ROBO " << indiceRobo << " RETORNOU ALIENS "
         << aliensEliminados << " RECURSOS " << recursosColetados << endl;
    this->quantidadeDeRecursos += recursosColetados;
    this->quantidadeDeAlienigenas += aliensEliminados;
    robos[indiceRobo].retornar();
  } else {
    cout << "BASE: ROBO " << indiceRobo << " NAO ESTA EM MISSAO" << endl;
  }
}

void Base::executarComandos(int indiceRobo) {
  if (robos[indiceRobo].estaEmMissao()) {
    Comando *comando = robos[indiceRobo].desenfileiraComando();
    while (comando != NULL) {
      executarComando(*comando, indiceRobo);
      comando = robos[indiceRobo].desenfileiraComando();
    }
  } else {
    string acao =
        "BASE: ROBO " + to_string(indiceRobo) + ": NAO ESTA EM MISSAO";
    robos[indiceRobo].insereItemHistorico(acao);
  }
}

void Base::executarComando(Comando comando, int indiceRobo) {
  if (comando.getTipo() == "MOVER" || comando.getTipo() == "*MOVER") {
    moverRobo(indiceRobo, comando.getCoordenadaX(), comando.getCoordenadaY());
  } else if (comando.getTipo() == "COLETAR" ||
             comando.getTipo() == "*COLETAR") {
    coletarRecursos(indiceRobo);
  } else if (comando.getTipo() == "ELIMINAR" ||
             comando.getTipo() == "*ELIMINAR") {
    eliminarAlien(indiceRobo);
  }
}

void Base::moverRobo(int indiceRobo, int coordenadaX, int coordenadaY) {
  string acao;
  if (mapa[coordenadaX][coordenadaY] == 'O') {
    acao = "ROBO " + to_string(indiceRobo) + ": IMPOSSIVEL MOVER PARA (" +
           to_string(coordenadaX) + "," + to_string(coordenadaY) + ")";
  } else {
    acao = "ROBO " + to_string(indiceRobo) + ": MOVEU PARA (" +
           to_string(coordenadaX) + "," + to_string(coordenadaY) + ")";
    robos[indiceRobo].mover(coordenadaX, coordenadaY);
  }
  robos[indiceRobo].insereItemHistorico(acao);
}

void Base::coletarRecursos(int indiceRobo) {
  Robo robo = robos[indiceRobo];
  int coordenadaX = robo.getPosicaoX();
  int coordenadaY = robo.getPosicaoY();
  string acao;
  if (mapa[coordenadaX][coordenadaY] == 'R') {
    acao = "ROBO " + to_string(indiceRobo) + ": RECURSOS COLETADOS EM (" +
           to_string(coordenadaX) + "," + to_string(coordenadaY) + ")";
    robos[indiceRobo].coletar();
    mapa[coordenadaX][coordenadaY] = '.';
  } else {
    acao = "ROBO " + to_string(indiceRobo) +
           ": IMPOSSIVEL COLETAR RECURSOS EM (" + to_string(coordenadaX) + "," +
           to_string(coordenadaY) + ")";
  }
  robos[indiceRobo].insereItemHistorico(acao);
}

void Base::eliminarAlien(int indiceRobo) {
  Robo robo = robos[indiceRobo];
  int coordenadaX = robo.getPosicaoX();
  int coordenadaY = robo.getPosicaoY();
  string acao;
  if (mapa[coordenadaX][coordenadaY] == 'H') {
    acao = "ROBO " + to_string(indiceRobo) + ": ALIEN ELIMINADO EM (" +
           to_string(coordenadaX) + "," + to_string(coordenadaY) + ")";
    robos[indiceRobo].eliminar();
    mapa[coordenadaX][coordenadaY] = '.';
  } else {
    acao = "ROBO " + to_string(indiceRobo) +
           ": IMPOSSIVEL ELIMINAR ALIEN EM (" + to_string(coordenadaX) + "," +
           to_string(coordenadaY) + ")";
  }
  robos[indiceRobo].insereItemHistorico(acao);
}

void Base::imprimeRelatorio() {
  cout << "BASE: TOTAL DE ALIENS " << quantidadeDeAlienigenas << " RECURSOS "
       << quantidadeDeRecursos << endl;
}