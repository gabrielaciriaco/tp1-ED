#include <fstream>
#include <iostream>

#include "../include/Base.h"

using namespace std;

int contaQuantidadeDeComandos(char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Arquivo no encontrado, verifique se o arquivo esta na pasta");
    exit(1);
  }
  int quantidadeDeComandos = 0;
  char ch;
  char chAnterior;
  while ((ch = fgetc(arquivo)) != EOF) {
    if (ch == '\n') {
      quantidadeDeComandos++;
    }
    chAnterior = ch;
  }
  if (chAnterior != '\n') {
    quantidadeDeComandos++;
  }
  fclose(arquivo);
  return quantidadeDeComandos;
}
string **lerComandos(char *nomeArquivo, int quantidadeDeComandos) {
  string **comandos = new string *[quantidadeDeComandos];
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Arquivo no encontrado, verifique se o arquivo esta na pasta");
    exit(1);
  }
  char aux;
  for (int i = 0; i < quantidadeDeComandos; i++) {
    comandos[i] = new string[4];

    for (int j = 0; j < 2; j++) {
      string trechoComando = "";
      do {
        aux = fgetc(arquivo);
        while (aux != ' ' && aux != '\n' && aux != EOF) {
          trechoComando += aux;
          aux = fgetc(arquivo);
        }
      } while (trechoComando == "");

      comandos[i][j] = trechoComando;
    }
    aux = fgetc(arquivo);

    if (aux != '(') {
      fseek(arquivo, -1, SEEK_CUR);
      fscanf(arquivo, "%*[\n]");
      continue;
    }
    do
    {
      aux = fgetc(arquivo);
      comandos[i][2] += aux;
    } while (aux!=',');
    
    do
    {
      aux = fgetc(arquivo);
      comandos[i][3] += aux;
    } while (aux!=')');

    do {
      aux = fgetc(arquivo);
    } while (aux != '\n' && aux != EOF);
  }
  fclose(arquivo);
  return comandos;
}

int main(int argc, char *argv[]) {
  char *nomeArquivo = argv[1];
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Arquivo no encontrado, verifique se o arquivo esta na pasta");
    exit(1);
  }

  int quantidadeDeLinhasDoMapa;
  int quantidadeDeColunasDoMapa;
  fscanf(arquivo, "%d", &quantidadeDeLinhasDoMapa);
  fscanf(arquivo, "%d", &quantidadeDeColunasDoMapa);
  fscanf(arquivo, "%*[\n]");

  char **mapa = new char *[quantidadeDeLinhasDoMapa];

  for (int i = 0; i < quantidadeDeLinhasDoMapa; i++) {
    mapa[i] = new char[quantidadeDeColunasDoMapa];

    for (int j = 0; j < quantidadeDeColunasDoMapa; j++) {
      fscanf(arquivo, "%c ", &mapa[i][j]);
    }
    fscanf(arquivo, "%*[\n]");
  }
  fclose(arquivo);
  int quantidadeDeComandos = contaQuantidadeDeComandos(argv[2]);
  string **comandos = lerComandos(argv[2], quantidadeDeComandos);
  Base base = Base(mapa, comandos, quantidadeDeComandos);
  base.imprimeRelatorio();
  return 0;
}
