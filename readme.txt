Este código é parte de um trabalho desenvolvido no Laboratório de Programação de Computadores 1, durante a minha graduação em Engenharia Mecânica, no CEFET/MG.

Considere me enviar suas ideias, sugestões ou tirar alguma dúvida pelo pedrohjsilva@ufmg.br

Se quiser, me pague um café: pedrohjsilva@ufmg.br


1.	Comandos de definição no código do programa

	#define alert printf
	#define prompt scanf

Os comandos do tipo #define foram utilizados para permitir fácil entendimento tanto para usuários de Javascript quando de C.
Apesar de alert e prompt substituírem printf e scanf no corpo do código, a sintaxe da linguagem C não foi alterada.


2.	Bibliotecas utilizadas no código do programa

	As bibliotecas <stdio.h>, <locale.h>, <math.h>, <string.h>, <stdlib.h>, <time.h>, “batalha_naval_lib.h” e <windows.h> foram adicionadas ao código, de maneira que, respectivamente, o código pudessse:

	-Utilizar os comandos de entrada e saída padrão;
	-Imprimir caracteres da do idioma brasileiro no prompt de comando;
	-Operar utilizando atribuições e termos matemáticos;
	-Manipular vetores de caracteres (strings);
	-Gerar a randomização de um número;
	-Utilizar a biblioteca de leitura de arquivo criada pelo Professor;
	-Trabalhar no prompt de comando executando programas do Windows (foi utilizada para reproduzir a trilha sonora do jogo);
