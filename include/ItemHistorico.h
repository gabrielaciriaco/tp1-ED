#ifndef I_ItemHistorico_H
#define I_ItemHistorico_H
#include <iostream>

using namespace std;
class ItemHistorico
{
private:
    string acao;
    ItemHistorico* proximoHistorico;
    ItemHistorico* anteriorHistorico;
public:
    ItemHistorico(string acao);
    ItemHistorico* getProximoItemHistorico();
    ItemHistorico* getAnteriorItemHistorico();
    void setAnteriorItemHistorico(ItemHistorico* itemHistorico);
    void setProximoItemHistorico(ItemHistorico* itemHistorico);
    string getAcao();
};

#endif