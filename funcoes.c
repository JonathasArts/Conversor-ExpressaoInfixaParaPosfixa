/* Includes necessários */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio2.h>
#include <math.h>
#include <stddef.h>
//------------------
#include "funcoes.h"
#include "pilhaenc.h"

/* Constantes */
#define ESC 27													// Tecla ESC código 27 para saida do programa
#define MAX_EXPRESSAO 500 										// Tamanho maximo da expressão
#define VERDADEIRO 1
#define FALSO 0


/* FUNÇÃO PARA CAPTURAR A EXPRESSÃO NO FORMATO INFIXO
PARAMETROS: - String para receber expressão no formato infixo. (O Valor da string é modificado) 
RETORNO: - VERDADEIRO se o usuário não digitar ... e FALSO caso digite ... para sair do programa */
int pegaInfixo(char infixo[]){
	int i;
	int valida=FALSO, resultadoVerificacao=2;
	char saida[5] = "QUIT";
	
	while(valida == FALSO){										// Laço para validação da expressão
		cabecalho();											// Insere o cabeçalho
		
		printf("\n Digite uma expressao valida em formato INFIXO (quit: Sair):\n >> "); 
		fflush(stdin); 											// Limpa o buffer do teclado
		
		for ( i=0; i<MAX_EXPRESSAO; ){							// Laço para ler os caracteres digitados
			infixo[i]=getchar();								// Captura do teclado com 'getchar'
			if(infixo[i]=='\n'){ 								// Se digitar enter, retornar para o main
				infixo[i] = '\0';								// Substitui o '\n' por '\0' e Fecha a string com a expressao INFIXA
				break;											// Sai do laço
			}else if (!(isspace(infixo[i]))){ 					// Se é espaço, ignora e continua
				i++;											// Incremento do índice
			}
		}														// FIM laço para ler os caracteres digitados
		
		strcpy(strupr(infixo), infixo);							// Converte string para Maiusculo
		if(strncmp(infixo, saida,5)==0){						// Verifica saida do programa com 'QUIT'
			return FALSO;										// Caso 'QUIT' Retorna FALSO para sair do programa
		}
		
		resultadoVerificacao = expressaoInfixaValida(infixo);   // Chamada da função de validade da expressão
		if(infixo[0]=='\0'){
			resultadoVerificacao = FALSO;
		}
		if(resultadoVerificacao == VERDADEIRO){                 // Caso Expressão válida
	        textcolor(GREEN);
			printf("\n\n OK: Expressao Valida!");				// Mensagem de confirmação para o Usuário
			textcolor(LIGHTGRAY);               
	        valida = VERDADEIRO;                                // Atribuição que permite a saida do while
	    }
	    else if(resultadoVerificacao == FALSO){                	// Caso Expressão invalida continua no while
	        textcolor(RED);
			printf("\n Expressao Invalida! Digite Novamente.\a");	// Mensagem de negação para o Usuário
			textcolor(LIGHTGRAY); 
	        getch();											// Espera que o usuário veja a mensagem
	    }          
	}
	return VERDADEIRO;
}/* FIM FUNÇÃO */


/* FUNÇÂO PARA VERIFICAR SE A EXPRESSÃO DIGITADA É VALIDA
PARAMETROS: - string digitada na função pegaInfixo
RETORNO: - retorna 1 caso esteja digitada corretamente ou retorna 0 se estiver errada */
int expressaoInfixaValida(char infixo[]){
	int i, j, verificacao = VERDADEIRO, verificacao1 = VERDADEIRO;	// Variaveis utilizadas na função
	
	if(infixo[0]=='\0'){
		verificacao==FALSO;
	}
	
	for(i=0; infixo[i]!='\0'; i++){                       		// Laço para "varrer" toda a expressão
	/* ------- Verifica se é um caractere válido ['(',')', OPERADOR, LETRA] ------- */
		if(infixo[i]!='(' && infixo[i]!=')' && !(isalpha(infixo[i])) && !(eOperador(infixo[i])) && infixo[i]!='\0'){
			verificacao = FALSO;								// Se não é um caractere valido invalida a expressão
			break;												// Sai do laço
		}
	/* ------- Verifica se é o primeiro caractere é '(' ou LETRA ------- */
		if(i == 0){
			if(infixo[i]!='(' && !(isalpha(infixo[i]))){
				verificacao = FALSO;							// Se não é '(' ou LETRA invalida a expressão
				break;											// Sai do laço
			}
		}
		if(infixo[i] == '('){									// Se for '(' ver se esta fechado e se depois existe um '(' ou LETRA
			for(j=i; infixo[j]!='\0'; j++){						// Laço para verificar se cada parentese está sendo fechado
				if(infixo[j]==')'){								// Se estiver fechado...
					break;										// ...sai do laço
				}
				if(infixo[j+1]=='\0'){							// Se não estiver fechado...
					verificacao1 = FALSO;						// Invalida a expressão
				}
			}													// Fim laço de verificação dos parenteses
	/* ------- Verifica se depois de um '(' existe um '(' ou LETRA ------- */
			if(infixo[1+i] != '(' && !(isalpha(infixo[1+i]))){
				verificacao = FALSO;							// Se não é '(' ou LETRA invalida a expressão
				break;											// Sai do laço
			}
		}
	/* ------- Verifica se depois de um OPERADOR existe um '(' ou LETRA ------- */
		else if(eOperador(infixo[i])){
			if(infixo[1+i]!= '(' && !(isalpha(infixo[1+i]))){
				verificacao = FALSO;							// Se não é '(' ou LETRA invalida a expressão
				break;											// Sai do laço
			}
		}
	/* ------- Verifica se depois de uma LETRA existe um ')', '\0' ou OPERADOR ------- */
		else if(isalpha(infixo[i])){
			if(infixo[1+i] != ')' && !(eOperador(infixo[1+i])) && infixo[1+i]!='\0'){
				verificacao = FALSO;							// Se não é ')', '\0' ou OPERADOR invalida a expressão
				break;											// Sai do laço
			}
		}
	/* ------- Verifica se depois de um ')' existe um ')', '\0' ou OPERADOR ------- */
		else if(infixo[i] == ')'){
			if(infixo[1+i] != ')' && !(eOperador(infixo[1+i])) && infixo[1+i] != '\0'){
				verificacao = FALSO;							// Se não é ')', '\0' ou OPERADOR invalida a expressão
				break;											// Sai do laço
			}
		}	
	}															// FIM do laço
	
	
	/* ------- Verifica Se Foi Definida Como Expressão VÁLIDA ou INVÁLIDA ------- */
    if(verificacao==VERDADEIRO && verificacao1==VERDADEIRO){
    	return VERDADEIRO;										// Se for VÁLIDA retorna VERDADEIRO
	} 
    else{
		return FALSO;											// Se for INVÁLIDA retorna FALSO
	}
}/* FIM FUNÇÃO */


/* CONVERTE UMA EXPRESSÃO NO FORMATO INFIXO PARA POSFIXO
PARAMETROS: - Expressão no formato infixo e inteiro para logar execução ou não logar
RETORNO: - Um ponteiro para a string no formato posfixo */
char* converteInfixParaPosfixa(char infixo[], int logarExecucao){
/* --- Declaração de Varáveis --- */
	int i, tamanho;
	int j=0, passo=1;
	char topo_ch;
	TPilha pilha;
/* - Fim declaração de Varáveis - */
	
	char *posfixo;												// Ponteiro para string posfixo
	posfixo = (char *) malloc(sizeof(char)*(strlen(infixo)+1));	// Alocação dinâmica da String posfixo
	posfixo[j] = '\0';											// Fechamento da string dimâmica posfixo
	
	criapilha(&pilha); 											// Inicializa a pilha
	tamanho = strlen(infixo);									// Verifica o tamanho da expressão digitada
	
	empilha(&pilha,'('); 										// Coloca na pilha
	strcat(infixo,")"); 										// Concatena um parentese direito para englobar toda a expressão 
	tamanho++;													// Incremento do TAMANHO
	
/* --------- Caso esteja logado ---------------- */
	if(logarExecucao){
		textcolor(BROWN);
		printf("\n\n PASSOS DA EXECUSSAO:\n");
		printf(" ------------------------------------------------------------------------------ ");
		textcolor(DARKGRAY);
		printf(" Passo\tChar\tSituacao da Pilha\t\tSaida\n =====\t===\t=[Topo|--->Base]=\t\t==========\n");
	}
/* --------------------------------------------- */
	
	for (i=0;i<tamanho;i++){									// Laço para Organização da Expressão

/* --------- Caso esteja logado ---------------- */
		if(logarExecucao == 1 && i == 0){
			printf(" %.2d-", passo);
			gotoxy(10,wherey());
			textcolor(BROWN);
			printf("%c", toupper(infixo[i]));
			textcolor(DARKGRAY);
			gotoxy(17,wherey());
			imprime(pilha);
			gotoxy(49,wherey());
			textcolor(BROWN);
			printf("%s\n", posfixo);
			textcolor(DARKGRAY);
			passo++;
		}
/* --------------------------------------------- */

		if (isalpha(infixo[i])){									// Se é LETRA
			posfixo[j++] = toupper(infixo[i]);						// Adiciona na expressão de saída
			posfixo[j] = '\0';										// Fechamento da string dimâmica posfixo
			
			/* --------- Caso esteja logado ---------------- */
				if(logarExecucao){
					printf(" %.2d-", passo);
					gotoxy(10,wherey());
					textcolor(BROWN);
					printf("%c", toupper(infixo[i]));
					textcolor(DARKGRAY);
					gotoxy(17,wherey());
					imprime(pilha);
					gotoxy(49,wherey());
					textcolor(BROWN);
					printf("%s\n", posfixo);
					textcolor(DARKGRAY);
					passo++;
				}
			/* --------------------------------------------- */					
		}
		else if (infixo[i]=='('){									// Se é parêntese esquerdo
			empilha(&pilha,'(');									// Sempre empilhar um parêntese esquerdo
		}
		else if (eOperador(infixo[i])){								// Se é operador
			while(VERDADEIRO){
				topo(pilha, &topo_ch);								// Pega o elemento no Topo da pilha para verificação
				if (eOperador(topo_ch)){
					if (precedenciaNivel(topo_ch) >= precedenciaNivel(infixo[i])){ // Se a precedencio do operador que está na pilha for maior do que a precedencia do operador atual...
						desempilha(&pilha, &posfixo[j++]);			// ...Desempilha o operador com maior precedencia e adiciona na expressão de saída (Posfixa)
						posfixo[j] = '\0';							// Fechamento da string dimâmica posfixo
						
						/* --------- Caso esteja logado ---------------- */
						if(logarExecucao){
							printf(" %.2d-", passo);
							gotoxy(10,wherey());
							textcolor(BROWN); 
							printf("%c", infixo[i]);
							textcolor(DARKGRAY); 
							gotoxy(17,wherey());
							imprime(pilha);
							gotoxy(49,wherey());
							textcolor(BROWN); 
							printf("%s\n", posfixo);
							textcolor(DARKGRAY); 
							passo++;
						}	
						/* --------------------------------------------- */
						
					}else
						break;								// Se a precedencia não for maior sair para empilhar o operador atual normalmente
				}else
					break;
				
			}
			empilha(&pilha, infixo[i]);						// Empilhar operador atual
		}
		else if (infixo[i]==')'){							// Se é parêntese direito
			while (VERDADEIRO){	
				topo(pilha, &topo_ch);						// Pega o elemento no Topo da pilha para verificação
				char aux;									// para receber o '(' retirado da pilha e descartar. Nem usa depois -_-
				if (topo_ch!='('){
					desempilha(&pilha, &posfixo[j++]);		// Desempilha os operadores para a expressão de saida até encontrar o '('
					posfixo[j] = '\0';						// Fechamento da string dimâmica posfixo
					
					/* --------- Caso esteja logado ---------------- */
							if(logarExecucao){
								printf(" %.2d-", passo);
								gotoxy(10,wherey());
								textcolor(BROWN); 
								printf("%c", infixo[i]);
								textcolor(DARKGRAY); 
								gotoxy(17,wherey());
								imprime(pilha);
								gotoxy(49,wherey());
								textcolor(BROWN); 
								printf("%s\n", posfixo);
								textcolor(DARKGRAY); 
								passo++;
							}
					/* --------------------------------------------- */
					
				}else{
					desempilha(&pilha, &aux);				// Desempilha o '('
					posfixo[j] = '\0';						// Fechamento da string dimâmica posfixo
					
					/* --------- Caso esteja logado ---------------- */
							if(logarExecucao){
								printf(" %.2d-", passo);
								gotoxy(10,wherey());
								textcolor(BROWN); 
								printf("%c", infixo[i]);
								textcolor(DARKGRAY); 
								gotoxy(17,wherey());
								imprime(pilha);
								gotoxy(49,wherey());
								textcolor(BROWN); 
								printf("%s\n", posfixo);
								textcolor(DARKGRAY); 
								passo++;
							}
					/* --------------------------------------------- */
										
					break;									// Sai do While ao encontar o '('
				}
			}
			continue;										// Reinicializa o While até encontrar o parentese esquerdo '('
		}
	}
	
	/* --------- Caso esteja logado ---------------- */
	if(logarExecucao){
		textcolor(BROWN);
		printf("\n ------------------------------------------------------------------------------ ");
	}
	/* --------------------------------------------- */
	
	posfixo[j] = '\0';										// Fecha a string da expressão de saída (Posfixa)
	textcolor(LIGHTGRAY);									// Volta a cor padrão do texto
	return posfixo; 										// Retornar o ponteiro para o main aqui
}/* FIM FUNÇÃO */


/* FUNÇÃO VERIFICAR SE É OPERADOR E É VÁLIDO
PARAMETROS: - Caractere da String 
RETORNO: - VERDADEIRO se for operador válido e FALSO caso não seja */
int eOperador(char o){
	if (o=='+'||o=='-'||o=='*'||o=='/'||o=='^'){
		return VERDADEIRO;									// retorna VERDADEIRO se for operador
	}else
		return FALSO;										// retorna FALSO se não for operador
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA DEFINIR O NIVEL DE PRECEDÊNCIA DO OPERADOR
PARAMETROS: - Caractere da String (OPERADOR)
RETORNO: - O Nivel de precedência do OPERADOR recebido [3 maior --- 1 menor] */
int precedenciaNivel(char o){
	if (o=='+'||o=='-')										// caso seja '+' ou '-' nível 1
		return 1;
	else if (o=='^')										// caso seja '^' nível 3
		return 3;
	else													// caso seja '*' ou '/' nível 2
		return 2;
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA MOSTRAR/IMPRIMIR O RESULTADO DA CONVERSÃO DA EXPRESSÃO NO FORMATO POSFIXO
PARAMETROS: - Expressão no formato INFIXO e expressão no formato POSFIXO
RETORNO: - void */
void imprimeResultado(char infixo[], char posfixo[]){
	textcolor(BROWN);
	printf("\n\n RESULTADO CONVERSAO:");
	printf("\n ------------------------------------------------------------------------------ ");
	textcolor(DARKGRAY);
	printf(" Expressao Original: %s\n", infixo);			// Imprime expressão INFIXA
	textcolor(YELLOW);
	printf(" Expressao Pos-fixa: %s\n", posfixo);			// Imprime expressão POSFIXA
	textcolor(BROWN);
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA EXECUTAR A EXPRESSÃO POSFIXADA, DE ACORDO COM SEUS RESPECTIVOS VOLARES.
PARAMETROS: - Expressão no formato POSFIXO; String contendo os operandos existentes na expressão; Array de float com os respectivos valores
de cada operando.
RETORNO: - void (O valor com o resultado da expressão é armazenado         vvAQUIvv   no float VALOR*/
float executaExpressao(char posfixo[], char operandos[], float valores[], float *valor){
	int i,j,h,k=1;
	char calculo[2];
	float numero[2], aux[MAX_EXPRESSAO/2];
	TPilha p;
	
	criapilha(&p);								// Cria a pilha
	
	aux[k-1] = valores[0];						// Caso digite apenas uma letra sem operador
	
	for(i=0; posfixo[i]!='\0'; i++){			// Laço para calcular o valor da expressão
		if(isalpha(posfixo[i])){				// Se for operando(letra)
			empilha(&p, posfixo[i]);				// Empilha
		}
		else{									// Se não for operando(letra) será operador
			switch(posfixo[i]){					// Para verificar qual é o operador
			/* ------------------------- Se for '+' ------------------------ */	
				case '+':
					desempilha(&p, &calculo[1]);					// Desempilha o ultimo operando
					desempilha(&p, &calculo[0]);					// Desempilha o primeiro operando
					for(h=0; h<2; h++){								// Laço para adicionar o valor numérico do operando
						for(j=0; operandos[j]!='\0'; j++){
							if(calculo[h]==operandos[j]){			// Se encontrar a posição do operando
								numero[h] = valores[j];				// Adiciona o valor do operando
								break;								// Sai do for
							}
							else if(calculo[h]=='>'){				// Se for um resultado já calculado
								numero[h] = aux[k-1];				// Adicionar Valor já calculado
								k--;								// Decremento do k para o aux
								break;								// Sai do for
							}
						}
					}
					aux[k] = numero[0] + numero[1];				// Calcula a soma
					k++;										// Incremento do k para aux que armazena valores já calculados
					empilha(&p, '>');							// Empilha para representar um valor já calculado
					break;										// Sai do switch
			/* ------------------------- Se for '-' ------------------------ */						
				case '-':
					desempilha(&p, &calculo[1]);					// Desempilha o ultimo operando
					desempilha(&p, &calculo[0]);					// Desempilha o primeiro operando
					for(h=0; h<2; h++){								// Laço para adicionar o valor numérico do operando
						for(j=0; operandos[j]!='\0'; j++){
							if(calculo[h]==operandos[j]){			// Se encontrar a posição do operando
								numero[h] = valores[j];				// Adiciona o valor do operando
								break;								// Sai do for
							}
							else if(calculo[h]=='>'){				// Se for um resultado já calculado
								numero[h] = aux[k-1];				// Adicionar Valor já calculado
								k--;								// Decremento do k para o aux
								break;								// Sai do for
							}
						}
					}
					aux[k] = numero[0] - numero[1];				// Calcula a subtração
					k++;										// Incremento do k para aux que armazena valores já calculados
					empilha(&p, '>');							// Empilha para representar um valor já calculado
					break;										// Sai do switch
			/* ------------------------- Se for '*' ------------------------ */					
				case '*':
					desempilha(&p, &calculo[1]);					// Desempilha o ultimo operando
					desempilha(&p, &calculo[0]);					// Desempilha o primeiro operando
					for(h=0; h<2; h++){								// Laço para adicionar o valor numérico do operando
						for(j=0; operandos[j]!='\0'; j++){
							if(calculo[h]==operandos[j]){			// Se encontrar a posição do operando
								numero[h] = valores[j];				// Adiciona o valor do operando
								break;								// Sai do for
							}
							else if(calculo[h]=='>'){				// Se for um resultado já calculado
								numero[h] = aux[k-1];				// Adicionar Valor já calculado
								k--;								// Decremento do k para o aux
								break;								// Sai do for
							}
						}
					}
					aux[k] = numero[0] * numero[1];				// Calcula a multiplicação
					k++;										// Incremento do k para aux que armazena valores já calculados
					empilha(&p, '>');							// Empilha para representar um valor já calculado
					break;										// Sai do switch
			/* ------------------------- Se for '/' ------------------------ */					
				case '/':
					desempilha(&p, &calculo[1]);					// Desempilha o ultimo operando
					desempilha(&p, &calculo[0]);					// Desempilha o primeiro operando
					for(h=0; h<2; h++){								// Laço para adicionar o valor numérico do operando
						for(j=0; operandos[j]!='\0'; j++){
							if(calculo[h]==operandos[j]){			// Se encontrar a posição do operando
								numero[h] = valores[j];				// Adiciona o valor do operando
								break;								// Sai do for
							}
							else if(calculo[h]=='>'){				// Se for um resultado já calculado
								numero[h] = aux[k-1];				// Adicionar Valor já calculado
								k--;								// Decremento do k para o aux
								break;								// Sai do for
							}
						}
					}
					aux[k] = numero[0] / numero[1];				// Calcula a divisão
					k++;										// Incremento do k para aux que armazena valores já calculados
					empilha(&p, '>');							// Empilha para representar um valor já calculado
					break;										// Sai do switch
			/* ------------------------- Se for '^' ------------------------ */				
				case '^': 
					desempilha(&p, &calculo[1]);					// Desempilha o ultimo operando
					desempilha(&p, &calculo[0]);					// Desempilha o primeiro operando
					for(h=0; h<2; h++){								// Laço para adicionar o valor numérico do operando
						for(j=0; operandos[j]!='\0'; j++){
							if(calculo[h]==operandos[j]){			// Se encontrar a posição do operando
								numero[h] = valores[j];				// Adiciona o valor do operando
								break;								// Sai do for
							}
							else if(calculo[h]=='>'){				// Se for um resultado já calculado
								numero[h] = aux[k-1];				// Adicionar Valor já calculado
								k--;								// Decremento do k para o aux
								break;								// Sai do for
							}
						}
					}
					aux[k] = pow(numero[0], numero[1]);			// Calcula a potência
					k++;										// Incremento do k para aux que armazena valores já calculados
					empilha(&p, '>');							// Empilha para representar um valor já calculado
					break;										// Sai do switch
			}
		}
	}										// Fim Laço para calcular o valor da expressão
	*valor = aux[k-1];						// Envia o valor final da expressão para valor no main
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA IDENTIFICAR OPERADOS EXISTENTES NA EXPRESSÃO POSFIXA
PARAMETROS: - A expressão no formato POSFIXO
RETORNO: - Um ponteiro para string contendo os operandos identificados, sem duplicidade */
char* obterOperandos(char *posf){
 	int j=0, i, k;															// Variáveis para os laços
 	int jaExiste=FALSO;														// Caso ja exista recebe VERDADEIRO
 	
	char *operandos;														// Ponteiro para string
	operandos = (char *) malloc(sizeof(char)*(strlen(posf)+1));				// Alocação dinâmica da String
	operandos[j]= '\0';														// Fechamento da string dinamica "operandos
	
	for(i=0; posf[i]!='\0' ;i++){											// Laço para "varrer" a expressão POSFIXADA toda
		if(isalpha(posf[i])){												// Se for operando entrar no próximo laço
			for(k=0;operandos[k]!='\0';k++){								// Laço para verificar se o operando ja existe
				if(posf[i]==operandos[k]){									// Se ja existe sair do laço...
					jaExiste = VERDADEIRO;									// ...jaExiste Recebe VERDADEIRO e...
					break;													// ...Sai do laço
				}
				else{				
					jaExiste = FALSO;										// Se não Existe recebe FALSO
				}
			}																// Fim laço para verificar se o operando ja existe
			if(jaExiste==FALSO){											// Se não existir...
				operandos[j++] = posf[i];									// Inserir operando na string "operandos"
				operandos[j] = '\0';										// Fechamento da string dinamica "operandos"
			}
		}
	}																		// Fim laço para "varrer" a expressão POSFIXADA toda
 	return operandos;														// Retorna o ponteiro para operandos
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA CAPTURAR O VALORES DOS OPERANDOS EXISTENTES NA EXPRESSÃO POSFIXA
PARAMETROS: - String com os operandos da expressão POSFIXADA, e stringo para receber os valores
RETORNO: - void (Os valores são colocados na strig valores[]) */
float pegaValor(char *operand, float valores[]){
	int i, j, k=0;												// Variáveis para os laços
	int cont=0, valida=FALSO;									// Variáveis para tratamento de erros
	char teste[10];												// String para tratamento de erros
	float val;													// Variavel para armazenar temporariamente o valor
	
	/* ------- Tela para exibição do programa ------- */
	textcolor(BROWN);
	gotoxy(1,wherey());
	printf("\n OPERANDOS IDENTIFICADOS: %s \n", operand);
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
	printf(" Digite os Valores Para os Operandos Identificados:\n\n\n");
	textcolor(DARKGRAY);
	for(i=0; operand[i]!='\0'; i++){
		printf("     %c = \n\n", operand[i]);
		cont++;											// Conta o numero de Operandos encontrados
	}
	textcolor(BROWN);
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
	gotoxy(10,wherey()-(2*cont+2));
	/* ------- Fim tela para exibição do programa ------- */
	
	for(i=0; i<cont; i++){								// Laço para recepção dos valores dos operandos
		gotoxy(10,wherey()+1);
		do{												// Laço para tratamento de erros
			gotoxy(10,wherey());
			printf("\t\t\t\t\t\t");						// Apaga a mensagem de erro
			gotoxy(10,wherey());
			fflush(stdin);								// Limpa o buffer do teclado
			gets(teste);								// Captura do valor digitado pelo usuário
			
			for(j=0;j<strlen(teste);j++){				// Laço para verificação se o valor é válido
				if(isdigit(teste[j]) || teste[j] == '.'){	// Se for digito ou ponto, ou seja, não for letra
					valida = VERDADEIRO;
					if(teste[j]=='.'){						// Se for ponto '.' ...
						if(!isdigit(teste[j+1]) && !isdigit(teste[j-1])){// ...Verifica se antes ou depois do ponto existe um digito...
							valida = FALSO;					// se não existir um digito invalida o valor e...
							break;							// ... sai do laço
						}
					}
				}
				else if(isalpha(teste[j])){
					valida = FALSO;
					break;
				}
				else{									// Se não for digito...
					valida = FALSO;						// ... invalida o valor e...
					break;								// ... sai do laço
				}
			}
			/* ------- Mensagem para o Usuário ------- */
			if(valida==FALSO){							// Se o valor digitado for inválido
				gotoxy(10,(wherey()-1));
				textcolor(RED);
				printf("\t Valor Invalido! Digite Novamente!\a");// Mensagem de negação
				textcolor(LIGHTGRAY);
				getch();								// Espera que o usuário veja a mensagem
			}
			else{										// Se o valor digitado for válido
				gotoxy(20,(wherey()-1));
				textcolor(GREEN);
				printf(" OK: Valor Valido!");			// Mensagem de confirmação
				textcolor(LIGHTGRAY);
				printf("\n");
			}
			/* ------- Fim mensagem para o Usuário ------- */
		}while(valida==FALSO);							// Fim laço para tratamento de erros
		
		val = atof(teste);								// Converte a string em float
		valores[i] = val;								// Salva o valor da variável	
	}													// Fim laço para recepção dos valores dos operandos
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA VERIFICAR SE O PROGRAMA DEVE REINICIAR
PARAMETROS: - void
RETORNO: - VERDAEIRO caso o usuário deseje reiniciar e FALSO caso contrário */
int imprimeMensagem(){
	char x;													// Char para receber a resposta do usuário
	
	printf(" Executar Outra Conversao <S/N>? (ESC: Sair) [ ]");// Pergunta para o Usuário
	do{														// Laço para tratamento de erros
		fflush(stdin);
		gotoxy(47,wherey());
		x = toupper(getch());								// Tratamento de erros
		textcolor(YELLOW);
		putchar(toupper(x));								// Captura do valor
		textcolor(LIGHTGRAY);
		if(x!='N' && x!='S' && x!=ESC){						// Frescurinha
			printf("\a");
		}
	}while(x!='N' && x!='S' && x!=ESC);						// Saida do laço apenas com 'S', ESC ou 'N'
	if(x=='S')
		return VERDADEIRO;									// Se 'S'(sim) retorna VERDADEIRO
	else
		return FALSO;										// Se 'N' (não) retorna FALSO
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA EXIBIR/IMPRIMIR O CABEÇALHO DO PROGRAMA
PARAMETROS: - void
RETORNO: - void */
void cabecalho(void){
	normvideo();system("CLS");		//  Limpa e Normaliza a tela
	textbackground(DARKGRAY);
	textcolor(BLACK);
	printf(" ------------------------------------------------------------------------------ ");
	printf("\tV1.0 - CONVERSOR DE EXPRESSOES INFIXAS PARA POSFIXAS\t\t\t");
	printf("\tAlunos: JONATHAS ART'S e NATACHA TARGINO\t\t\t\t");
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA EXIBIR/IMPRIMIR TELA DE DESPEDIDA DO PROGRAMA
PARAMETROS: - void
RETORNO: - void */
void sairdoSistema(void){
    fflush(stdin);normvideo();
	system("CLS");											//  Limpa e Normaliza a tela
	textcolor(BROWN);
	printf(" ------------------------------------------------------------------------------ ");
	printf(" ------------------------------------------------------------------------------ ");
    gotoxy(28,wherey()+4);
    printf("OBRIGADO PELA PREFERENCIA!!!");					// Imprime mensagem para o usuario
    gotoxy(22,12);
    printf(" BY JONATHAS ALMEIDA E NATACHA TARGINO");		// Direitos autorais =P #ÉNóis \0/\õ/
    gotoxy(54,22);
    textcolor(YELLOW);
	printf("ELES MERECEM NOTA 10,0 !!!");					// SUGESTÃO (vai que cola) kkkkkk...
    gotoxy(1,20);
	textcolor(BROWN);
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
	gotoxy(80,22);
}/* FIM FUNÇÃO */
