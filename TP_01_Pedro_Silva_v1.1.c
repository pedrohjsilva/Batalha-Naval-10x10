#include <stdio.h>
#define alert printf
#define prompt scanf
#include <locale.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "batalha_naval_lib.h"
#include <windows.h>
#define L 10
#define C 10



/*
Centro Federal de Educa��o Tecnol�gica de Minas Gerais
Gradua��o em Engenharia Mec�nica
Gabriel Milagres
Pedro Henrique Silva
Rafael Freitas
*/



//fun��o que gera n�meros aleat�rios. a utilizaremos para definir as jogadas da m�quina
    int randomico(int LimI, int LimS)
    {
    int num;
    num=(rand() % (LimS-LimI + 1)) + LimI;
    }


//carregar tabuleiros - a fun��o nos gera um mapa a partir da leitura de um arquivo .txt
    int carregarTabuleiros(char arquivo1[], char arquivo2[],char tabuleiro1[NUM_LINHAS][NUM_COLUNAS], char tabuleiro2[NUM_LINHAS][NUM_COLUNAS]);


//mostrar tabuleiros - a fun��o nos exibe o mapa, caso precisemos imprimi-lo na tela do cmd
    void mostrarTabuleiros(char mapa_pc[10][11], char mapa_j[10][11], int jogadas[10][11]){
    alert("\n\nMAPA DO JOGADOR\t\t\t\tMAPA DA M�QUINA\n\n");

// na exibi��o dos mapas, foi decidido usar apenas n�meroa, e n�o caracteres, para tornar
// a experi�ncia do usu�rio mais simples. dessa maneira, ao ser solicitado uma coordenada
// ele precisar� inserir apenas os n�meros correspondentes
// al�m disso, nos simplifica de definirmos uma fun��o de convers�o
// ente (A-J) e (1-10)
    alert("\n    1 2 3 4 5 6 7 8 9 10\t\t  1 2 3 4 5 6 7 8 9 10\n");


    alert("  ________________________\t\t________________________\n");
    for (int i = 0; i < 10; i++)
    {
    if(i<9)
    {
    alert("%d ", i+1);} else
    alert("%d", i+1);

    alert("| ");
    for(int j = 0; j < 11-1; j++)
    {
    alert("%c ", mapa_j[i][j]);
    }
    alert(" |\t\t| ");
    for(int j = 0; j < 11-1; j++)
    {
    if(jogadas[i][j]!=0)
    {
    alert("%c ", mapa_pc[i][j]);
    }
    else
    {
    alert("~ ");
    }
    }
    alert(" |\n");
    }
    alert("  |______________________|\t\t|______________________|\n");
    alert("\n\n");
    }


// atirar - essa fun��o gera duas matrizes para manipular as jogadas.
// n�s a inicializamos apenas com 0's. ao atiras, substu�mos uma posi��o por 2
// e, ao acertarmos uma embarca��o, n�s substitu�mos a posi��o por 1
// no fim, utilizamos isso para verificar o status da vit�ria

// essa, armazena os disparos do jogador
    int atirar_j (char mapa_pc[10][11], int jogadas_pc[10][11] )
    {
    int linha,coluna;
    // para o jogador, solicitamos as coordenadas e lemos ela do teclado
    alert("VEZ DO JOGADOR\nDigite a linha:\n");
    prompt("%d", &linha);
    alert("\nInsira a coluna:\n");
    prompt("%d", &coluna);
    jogadas_pc[linha-1][coluna-1] = 2;
    if (mapa_pc[linha-1][coluna-1] != '~')
    {
    jogadas_pc[linha-1][coluna-1] = 1;
    }
    }


// j� essa, armazena disparos da m�quina
    int atirar_pc (char mapa_j[10][11], int jogadas_j[10][11] )
    {
    int linha,coluna;
    // para a m�quina geramos os valores de maneira randomica
    Sleep(1000);
    alert("\n\nA M�QUINA EST� JOGANDO...");
    linha = randomico (1,10);
    Sleep(1000);
    alert("\n\nA M�QUINA EST� JOGANDO...");
    coluna = randomico(1, 10);
    jogadas_j[linha-1][coluna-1] = 2;
    if (mapa_j[linha-1][coluna-1] != '~')
    {
    jogadas_j[linha-1][coluna-1] = 1;
    }
    }



//essa �a fun��o que definimos para verificar a matriz com o status da vit�ria da m�quina
    int verifica_pc (int jogadas_pc[10][11])
    {
    int acertos = 0;
    for (int i=0; i<10; i++)
    {
    for (int j=0; j>10; j++)
    {
    if(jogadas_pc[i][j]==1){acertos++;}
    }
    }
    if(acertos==21){system("cls"); alert("Vit�ria da m�quina!");
    }
    return verifica_pc;
    }



// e essa verifica o status da vit�ria para o jogador
    int verifica_j (int jogadas_j[10][11])
    {
    int acertos = 0;
    for (int i=0; i<10; i++)
    {
    for (int j=0; j>10; j++)
    {
    if(jogadas_j[i][j]==1){acertos++;
    }
    }
    }
    if(acertos==21){system("cls"); alert("Vit�ria do jogador!");
    }
    return verifica_j;
    }




//fun��o principal, onde nosso jogo � executado
    int main ( )
    {
    srand(time(0));
    system("start contra_nes.mp3");
    setlocale (LC_ALL,"");
    setlocale (LC_CTYPE,"pt_BR.UTF-8" );
    char caminho_j[] = "arquivo1.txt";
    char mapa_j[10][11];
    gera_mapa(caminho_j, mapa_j);
    char caminho_pc[] = "arquivo2.txt";
    char mapa_pc[10][11];
    gera_mapa(caminho_pc, mapa_pc);
    int jogadas[10][11];
    for (int i = 0; i < 10; i++)
    {
    for(int j = 0; j < 11-1; j++)
    {
    jogadas[i][j]=0;
    }
    }
    // esse char foi criado para imprimir durante a tela de carregamento
    // caso n�o o "cri�ssemos", a interface n�o imprimiria o s�mbolo de "%"
    // na interface do cmd
    char porcento = '%';

    // essas linhas do c�digo tentam simular a API de um jogo de Nintendo Entertainment System
    // utilizamos um front-end bem simples, uma vez que n�o podemos utilizar
    // bibliotecas de C++ para o desenvolvimento do jgo
    int campoJ1[L][C], campoJ2[L][C], op, game=1, campo=0;
    alert("\n\n\n\n\n\t\t\t  CEFET-MG - Gradua��o em Engenharia Mec�nica\n\n\n\n");
    alert("\t                                  .0.00                                     \n");
    alert("\t                                    0..00.0\n");
    alert("\t                                     0.00.\n");
    alert("\t                                          .0      | |----)\n");
    alert("\t                                          0.     _|_|_ _ _ \n");
    alert("\t                                            00  |[] [] []|\n");
    alert("\t                                            0   |[] [] []|\n");
    alert("\t       __          _____________________________|[] [] []|____________________ \n");
    alert("\t      |   |_______/                                                          /\n");
    alert("\t  ===>|                                           S.S. Engenharia Mec�nica  /\n");
    alert("\t      |    _______                                                         /\n");
    alert("\t      |__ /       |_______________________________________________________/\n");

    // utilizamos a fun��o Sleep diversas vezes para simular as intros e transi��es do jogo
    Sleep(4000);
    system("cls"); // ao limparmos a tela, conseguimos dar sequ�ncia nas transi��es, em vez de apenas imprimirmos mais conte�do na tela

    alert("\n\n\n\n\n\t\t\t  CENTRO FEDERAL DE EDUCA��O TECNOL�GICA DE MINAS GERAIS\n\n\n");
    alert("\t\t\t\t    Gradua��o em Engenharia Mec�nica\n\n\n");
    alert("\t\t\t\tTrabalho Pr�tico 01 - Batalha Naval 10x10\n\n\n\n\n");
    Sleep(4000);

    system("cls");

    alert("\n\n\n\n\n\n\n\t\t\t\t\   � 2022. SILVA, Pedro Henrique\n\n\n\n\n");
    alert("\t\t\t\t\tAll rights reserved\n\n\n\n\n\n");

    Sleep(4000);

    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[----------]  0%c\n\n\n", porcento);
    Sleep(800);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[=---------]  10%c\n\n\n", porcento);
    Sleep(800);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[==--------]  20%c\n\n\n", porcento);
    Sleep(850);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[===-------]  30%c\n\n\n", porcento);
    Sleep(600);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[====------]  40%c\n\n\n", porcento);
    Sleep(1300);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[=====-----]  50%c\n\n\n", porcento);
    Sleep(1000);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[======----]  60%c\n\n\n", porcento);
    Sleep(200);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[=======---]  70%c\n\n\n", porcento);
    Sleep(720);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[========--]  80%c\n\n\n", porcento);
    Sleep(2000);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[=========-]  90%c\n\n\n", porcento);
    Sleep(2300);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[=========-]  91%c\n\n\n", porcento);
    Sleep(2200);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[=========-]  94%c\n\n\n", porcento);
    Sleep(3500);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[=========-]  97%c\n\n\n", porcento);
    Sleep(4000);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[==========]  99%c\n\n\n", porcento);
    Sleep(4000);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  CARREGANDO...");
    alert("\n\n\t\t\t\t\t\t[==========]  100%c\n\n\n", porcento);
    Sleep(1000);
    system("cls");
    alert("\n\n\n\n\n\n\n\n\t\t\t\t\t  CARREGAMENTO CONCLU�DO...");
    alert("\n\n\t\t\t\tPressione qualquer tecla para continuar\n\n\n");
    prompt("");
    system("cls");
    mostrarTabuleiros(mapa_pc, mapa_j, jogadas);

    // jogadas - a partir daqui, o la�o de repeti��o garante que as jogadas sejam repetidas de maneira infinita
    // o �nico crit�rio para encerrar o jogo, � a vit�ria de um dos jogadores
    // n�o podemos fazer nada quanto ao velho "Alt + F4"
    atirar_j(mapa_pc, jogadas);
    verifica_j(jogadas);

    while (verifica_pc != 21)
    {
    system("cls");
    mostrarTabuleiros(mapa_pc, mapa_j, jogadas);
    atirar_pc(mapa_j, jogadas);
    verifica_j(jogadas);
    while (verifica_j !=21)
    {
    system("cls");
    mostrarTabuleiros(mapa_pc, mapa_j, jogadas);
    atirar_j(mapa_pc, jogadas);
    verifica_j(jogadas);
    };
    };
    }











