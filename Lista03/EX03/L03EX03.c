/* ================================================================== *
    Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 
    Disciplina: Algoritmos e Programação 2
 
    Lista 03 - Exercício 03 - Imagem em Escala de Cinza
 
    Instrucoes
    ----------
 
    Este arquivo contem o codigo que auxiliara no desenvolvimento do
    exercicio. Voce precisara completar as partes requisitadas.
 
* ================================================================== *
    Dados do aluno:
 
    RA: 
    Nome: 
 
* ================================================================== */

#include <stdio.h>
#include <math.h>

/* Ordem máxima da matriz */
#define MAX 100

/* Variaveis globais */
int *maior, *menor;

/* Opcoes do menu */
enum opcoes {SAIR = 0, CLAREAR, ESCURECER, DIAGONAL, TRANSPOSTA, BINARIA, MAIOR_MENOR};

/* ------------------------------ */
/*    FUNCOES JÁ IMPLEMENTADAS   */
/* ------------------------------ */

/* Exibe os elementos da matriz */
void exibe_matriz(int *comeco_matriz, int dimensao);

/* Exibe o maior e o menor numero da matriz ja sendo apontados pelas variaveis global maior e menor */
void exibe_maior_menor();


/* ------------------------------ */
/*    FUNCOES NAO IMPLEMENTADAS   */
/* ------------------------------ */

/* Recebe os elementos da matriz */
void popula_matriz(int *comeco_matriz, int dimensao);

/* Recebe os valores de uma outra matriz e soma a matriz principal com a matriz informada */
void clareia(int *comeco_matriz, int dimensao);

/* Recebe os valores de uma outra matriz e subtrai a matriz principal pela matriz informada */
void escurece(int *comeco_matriz, int dimensao);

/* Retorna 1 se for uma matriz diagonal e 0 caso contrário */
int diagonal(int *comeco_matriz, int dimensao);

/* A matriz passa a ser sua matriz transposta */
void transposta(int *comeco_matriz, int dimensao);

/* Todos os numeros maiores ou iguais que num_binariza passam a ser 255
	Os outros numeros passam a ser 0 */
void binariza(int *comeco_matriz, int dimensao, int num_binariza);


/* ------------------------------ */
/* ROTINA PRINCIPAL - NAO ALTERAR */
/* ------------------------------ */

int main(){
	int dimensao, opcao, num_binariza;
	int matriz[MAX][MAX];
	int *comeco_matriz = &matriz[0][0]; // Aponta para o primeiro elemento da matriz

	scanf("%d", &dimensao);
	popula_matriz(comeco_matriz, dimensao);	
	exibe_matriz(comeco_matriz, dimensao);

	while(1){
		scanf("%d", &opcao);

		switch (opcao){
			case SAIR:
				return 0;
				break;			

			case CLAREAR:
				clareia(comeco_matriz, dimensao);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case ESCURECER:
				escurece(comeco_matriz, dimensao);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case DIAGONAL:
				if (diagonal(comeco_matriz, dimensao))
					printf("SIM\n\n");
				else
					printf("NAO\n\n");
				break;

			case TRANSPOSTA:
				transposta(comeco_matriz, dimensao);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case BINARIA:
				scanf("%d", &num_binariza);
				binariza(comeco_matriz, dimensao, num_binariza);
				exibe_matriz(comeco_matriz, dimensao);
				break;

			case MAIOR_MENOR:
				exibe_maior_menor();
				break;

		};
	}
	return 0;
	
}


/* ------------------------------ */
/*    FUNCOES JÁ IMPLEMENTADAS   */
/* ------------------------------ */

/* Exibe os elementos da matriz */
void exibe_matriz(int *comeco_matriz, int dimensao){
	int i;
	for (i = 0; i < pow(dimensao, 2); i++){		
		printf("%03d ", *(comeco_matriz+i));
		if ((i + 1) % dimensao == 0)
			printf("\n");
	}
	printf("\n");
}

/* Exibe o maior e o menor numero da matriz ja sendo apontados pelas variaveis global maior e menor */
void exibe_maior_menor(){
	printf("Maior -> %d\nMenor -> %d\n\n", *maior, *menor);
}



/* ------------------------------ */
/*    FUNCOES NAO IMPLEMENTADAS   */
/* ------------------------------ */

/* Recebe os elementos da matriz */
void popula_matriz(int *comeco_matriz, int dimensao);

/* Recebe os valores de uma outra matriz e soma a matriz principal com a matriz informada */
void clareia(int *comeco_matriz, int dimensao);

/* Recebe os valores de uma outra matriz e subtrai a matriz principal pela matriz informada */
void escurece(int *comeco_matriz, int dimensao);

/* Retorna 1 se for uma matriz diagonal e 0 caso contrário */
int diagonal(int *comeco_matriz, int dimensao);

/* A matriz passa a ser sua matriz transposta */
void transposta(int *comeco_matriz, int dimensao);

/* Todos os numeros maiores ou iguais que num_binariza passam a ser 255
	Os outros numeros passam a ser 0 */
void binariza(int *comeco_matriz, int dimensao, int num_binariza);


