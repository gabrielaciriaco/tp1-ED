#include "../include/ItemHistorico.h"

ItemHistorico::ItemHistorico(string acao){
  this->acao = acao;
  this->proximoHistorico = NULL;
  this->anteriorHistorico = NULL;
}
ItemHistorico* ItemHistorico::getProximoItemHistorico(){
  return this->proximoHistorico;
}

ItemHistorico* ItemHistorico::getAnteriorItemHistorico(){
  return this->anteriorHistorico;
}

void ItemHistorico::setAnteriorItemHistorico(ItemHistorico* itemHistorico){
  this->anteriorHistorico = itemHistorico;
}

void ItemHistorico::setProximoItemHistorico(ItemHistorico* itemHistorico){
  this->proximoHistorico = itemHistorico;
}

string ItemHistorico::getAcao(){
  return this->acao;
}