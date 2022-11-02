#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_LINHAS 10
#define NUM_COLUNAS 11

/* Prot�tipos */
/* ========================================================================== */
int gera_mapa(char caminhoArquivo[], char mapa[NUM_LINHAS][NUM_COLUNAS]);
int retorna_numero_aleatorio(int limiteInferior, int limiteSuperior);
/* ========================================================================== */



/* Implementa��o */
/* ========================================================================== */
int gera_mapa(char caminhoArquivo[], char mapa[NUM_LINHAS][NUM_COLUNAS]){
    FILE *arquivo;
    char linha[12];

    arquivo = fopen(caminhoArquivo, "r");

    // Se o arquivo n�o existir
    if (arquivo == NULL)
    {
	   printf("\n\nO ARQUIVO N�O P�DE SER LIDO OU N�O EXISTE!\n\n");
        return 0;
    }
    else
    {
        for (int i = 0; i < NUM_LINHAS; i++){
          // L� uma linha (inclusive com o '\n')
          fgets(linha, 12, arquivo);
          // Percorre a linha e ignora o \n e o \0
          for(int j = 0; j < 10; j++){
                mapa[i][j] = linha[j];
          }

        }

      fclose(arquivo);

      return 1;

    }
}

int retorna_numero_aleatorio(int limiteInferior, int limiteSuperior){
	int valor;
    // Garante que o n�mero aleat�rio est� entre o limiteInferior e limiteSuperior
    valor = (rand() % (limiteSuperior - limiteInferior + 1)) + limiteInferior;

    return valor;
}
/* ========================================================================== */






