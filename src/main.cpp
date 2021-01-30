#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char *nomeArquivo = argv[1];    
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Arquivo no encontrado, verifique se o arquivo esta na pasta");
        exit(1);
    }
    
    int quantidadeDeLinhasDoMapa;
    int quantidadeDeColunasDoMapa;
    fscanf(arquivo, "%d", &quantidadeDeLinhasDoMapa);
    fscanf(arquivo, "%d", &quantidadeDeColunasDoMapa);
    fscanf(arquivo, "%*[\n]");

    cout << quantidadeDeLinhasDoMapa << endl;
    cout << quantidadeDeColunasDoMapa;

    char mapa[quantidadeDeLinhasDoMapa][quantidadeDeColunasDoMapa];

    for (int i = 0; i < quantidadeDeLinhasDoMapa; i++)
    {
        for (int j = 0; j < quantidadeDeColunasDoMapa; j++)
        {
            fscanf(arquivo, "%c ", &mapa[i][j]);
        }
        fscanf(arquivo, "%*[\n]");
    }
    return 0;
}
