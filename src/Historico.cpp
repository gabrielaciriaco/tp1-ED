#include "../include/Historico.h"
Historico::Historico() { this->primeiroItemHistorico = NULL; }

void Historico::insereItemHistorico(string acao) {
  bool historicoVazio = primeiroItemHistorico == NULL;
  ItemHistorico* novoItemHistorico = new ItemHistorico(acao);
  if (historicoVazio) {
    primeiroItemHistorico = novoItemHistorico;
    return;
  }
  ItemHistorico* itemHistoricoAtual = primeiroItemHistorico;
  while (itemHistoricoAtual->getProximoItemHistorico() != NULL) {
    itemHistoricoAtual = itemHistoricoAtual->getProximoItemHistorico();
  }
  novoItemHistorico->setAnteriorItemHistorico(itemHistoricoAtual);
  itemHistoricoAtual->setProximoItemHistorico(novoItemHistorico);
}

void Historico::imprimir() {
  ItemHistorico* itemHistoricoAtual = primeiroItemHistorico;
  while (itemHistoricoAtual != NULL) {
    cout << itemHistoricoAtual->getAcao() << endl;
    itemHistoricoAtual = itemHistoricoAtual->getProximoItemHistorico();
  }
}

void Historico::limpar() { this->primeiroItemHistorico = NULL; }