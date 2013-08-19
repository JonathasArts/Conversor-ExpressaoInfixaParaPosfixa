/*	|-----------------------------------------------------------------------------------------------|
	|			PROJETO REFERENTE A PARTE DA 2ª NOTA DA DISCIPLINA "ESTRUTURAS DE DADOS"    		|
	|                       		Professores: Alex Sandro	                  		            |
	|      			CONVERSOR DE EXPRESSÃO NO FORMATO INFIXO PARA POSFIXO: InfPosf!                 |
	|                        Alunos: Jonathas Almeida e Natacha Targino                             |
	|                                                                                               |
	|                          Data da última modificação: 18/08/2013                               |
	|																								|
	|	Este Programa é protegido por leis internacionais de software e pela LEI DE DEUS.			|
	|	Afinal de contas, só Deus sabe como ele Funciona... =P										|
	|-----------------------------------------------------------------------------------------------|
	Não alterar desta linha para baixo
*/

/* Includes necessários */
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
//----------------
#include "pilhaenc.h"												// Estrutura Pilha Simplemente Encadeada
#include "funcoes.h"												// Funções criadas

/* Constantes */
#define LOGAR 1														// Cumprir tabela no projeto
#define NAO_LOGAR 0													// Cumprir tabela no projeto
#define MAX_EXPRESSAO 500 											// Tamanho maximo da expressão digitada (exageramos mesmo =P)


int main(int argc, char *argv[]) {
	char infixo[MAX_EXPRESSAO];										// String para receber expressão digitada
	char x;															// Char para tratamento de erro
	int logarExecucao;												// Variavel para Verificar "Logar" Execução
	char *posf, *operand;											// Ponteiros para expressão POSFIXA e string dos OPERANDOS
	float valor=0, valores[MAX_EXPRESSAO];							// Variáveis para receber valores numericos da expressão
	
	for(;;){										// Laço infinito para repetição do programa
		logarExecucao = NAO_LOGAR;									// Logar execução, por default é NAO_LOGAR ('0')
		if(pegaInfixo(infixo)==0){									// Chama a funão que captura os caracteres da expressão
			break;													// Caso retorne 0 Sair do programa
		}			
	/* --------------------------- Verificação se deseja logar a Execução ----------------------------- */
		printf("\n\n Deseja Ver o Processo de Transformacao da Expressao Passo-a-Passo (S/N)? [ ]");
		do{
			fflush(stdin);											// Limpa o buffer do teclado
			gotoxy(76,wherey());									// Reposiciona o cursor para receber a resposta (S/N)
			x = toupper(getch());									// Recebe a Resposta do Usuário
			textcolor(YELLOW);
			putchar(toupper(x));									// Mostra o que foi digitado pelo usuário
			textcolor(LIGHTGRAY);
			if(x!='N' && x!='S'){									// Frescurinha
				printf("\a");
			}
		}while(x!='N' && x!='S');									// Se for diferente de 'S' e 'N' permanece no laço
		if(x=='S')													// se sim 'S' LOGAR
			logarExecucao = LOGAR;									// 1 = Logar
		else														// se não 'N' NÂO LOGAR
			logarExecucao = NAO_LOGAR;								// 0 = Não Logar
	/* ----- FIM Verificação se deseja logar a Execução - colocar isso  numa função separada ---------- */
	
		posf = converteInfixParaPosfixa(infixo, logarExecucao); 	// Chama a função que converte de infixo para posfixo devolvendo um ponteiro
		infixo[strlen(infixo)-1]='\0';								// Fecha a string da expressão no formato infixo
		imprimeResultado(infixo, posf);								// Chama a Função que Imprime o resultado da expressão posfixada
	
	
	/* -------------- Verificação se Definir Valores Para as Variáveis da Expressao ------------------- */
		printf("\n\n Deseja Definir Valores Para as Variaveis da Expressao(S/N)? [ ]");
		do{
			fflush(stdin);											// Limpa o buffer do teclado
			gotoxy(63,wherey());
			x = toupper(getch());									// Recebe a Resposta do Usuário
			textcolor(YELLOW);
			putchar(toupper(x));									// Mostra o que foi digitado pelo usuário
			textcolor(LIGHTGRAY);
			if(x!='N' && x!='S'){									// Frescurinha
				printf("\a");
			}
		}while(x!='N' && x!='S');									// Se for diferente de 'S' e 'N' permanece no laço
		
		if(x=='S'){												// Caso 'S' (sim)...
			operand = obterOperandos(posf);							// Chama função que identifica Operandos existentes na expressão POSFIXADA e retorna...
																	// ...ponteiro para a string com os operandos identificados
		/* ------- Segunda tela do programa ------- */
			fflush(stdin);											// Limpa o buffer do teclado
			normvideo();system("CLS");								// Limpa e Normaliza a tela
			cabecalho();											// Imprime o cabeçalho
			textcolor(YELLOW);
			printf("\n EXPRESSAO POSFIXADA: %s", posf);				// Mostra expressão no formato posfixo para conferência
			textcolor(LIGHTGRAY);
			
			pegaValor(operand, valores);							// Chama função para capturar os valores numéricos
			
			executaExpressao(posf, operand, valores, &valor);		// Chama função para Executar a expressão
			textcolor(BROWN);
			printf("\n\n  O RESULTADO DA EXPRESSAO EH: ");
			textcolor(YELLOW);
			printf(" %.2f\n\n\n\n", valor);							// Imprime o resultado final da expressão
			textcolor(LIGHTGRAY);
		}															
		else													// Caso 'N' (não)...
			printf("\n\n\n\n");										// ...Prossegue o programa
			
	/* ------------- FIM Verificação se Definir Valores Para as Variáveis da Expressao --------------- */


		if(imprimeMensagem())										// Chamada da função para saber se deseja fazer uma nova verificação
			continue;											// Caso verdadeiro continuar/reiniciar
		else
			break;												// Caso Falso sair do programa
			
		free(posf);													// Libera o ponteiro 'posf'											
		free(operand);												// Libera o ponteiro 'operand'
	}												// Fim laço infinito de repetição do programa
	
	sairdoSistema();
													// Chamada da função com tela de despedida
	return EXIT_SUCCESS;							// Encerrar o programa
}// FIM DO MAIN =P
