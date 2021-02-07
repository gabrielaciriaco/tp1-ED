#include "../include/FilaDeComandos.h"

FilaDeComandos::FilaDeComandos(){
    primeiroComando = NULL;
}
void FilaDeComandos::insereComando(string tipo){
    Comando* novoComando = new Comando(tipo);
    insereComando(novoComando);
}
void FilaDeComandos::insereComando(string tipo, int coordenadaX, int coordenadaY){
    Comando* novoComando = new Comando(tipo, coordenadaX, coordenadaY);
    insereComando(novoComando);
}
void FilaDeComandos::insereComando(Comando* novoComando){
    bool primeiroComandoVazio = primeiroComando==NULL;
    if(primeiroComandoVazio){
        primeiroComando =  novoComando;
        return;
    }
    bool altaPrioridade = novoComando->getAltaPrioridade();
    if(altaPrioridade){
        novoComando->setProximoComando(primeiroComando);
        primeiroComando->setAnteriorComando(novoComando);
        primeiroComando = novoComando;
        return;
    }
    Comando* comandoAtual =  primeiroComando;
    while(comandoAtual->getProximoComando()!=NULL){
        comandoAtual = comandoAtual->getProximoComando();
    }
    novoComando->setAnteriorComando(comandoAtual);
    comandoAtual->setProximoComando(novoComando);
}