#ifndef I_Robo_H
#define I_Robo_H
#include "FilaDeComandos.h"
#include "Historico.h"
class Robo{
    private:
        FilaDeComandos filaDeComandos;
        int posicaoX;
        int posicaoY;
        int aliensEliminados;
        int recursosColetados;
        int indiceRobo;
        Historico historico;
    public:
        Robo(){}
        Robo(int indiceRobo);
        void insereComando(string comando[4]);
        void ativar();
        void retornar();
        void coletar();
        void eliminar();
        void relatorio();
        int getRecursosColetados();
        int getAliensEliminados();
        Comando* desenfileiraComando();
        void mover(int posicaoX,int posicaoY);
        int getPosicaoX();
        int getPosicaoY();
        bool estaEmMissao();
        void insereItemHistorico(string acao);
};

#endif