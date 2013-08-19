/* Includes necessários */
#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <stddef.h>

/* ------- Operações primárias da Pilha ------- */

/* Criando uma pilha vazia */ 
void criapilha(TPilha *p) { 
  *p = NULL; 
}


/* Verificar se a pilha esta vazia */ 
boolean pilhavazia(TPilha p) { 
  return (p == NULL); 
}


/* Obter o tamanho da pilha */ 
int tamanho(TPilha p) { 
  int contador = 0; 
  while( p != NULL) { 
    p = p->prox; 
    contador++; 
  } 
  return(contador); 
}


/* Inserir um elemento na pilha*/ 
boolean empilha(TPilha *p, char dado){ 
	nopilha *novo; 
	novo = (nopilha *) malloc(sizeof(nopilha)); 
	if (novo == NULL) 
		return( false );  // Erro de alocacao 
 
	novo->dado = dado; 
  	novo->prox = *p; 
  	*p = novo; 
  	return( true ); 
}


/* Retirar um elemnto do topo da pilha */
boolean desempilha(TPilha *p, char *dado){ 
	nopilha *aux; 
	if(pilhavazia(*p)) 
	    return( false ); 
	 
	aux = *p; 
	  *dado =  aux->dado; 
	  *p = (*p)->prox; 
	free(aux); 
	return( true ); 
}


/* Obter valor do elemnto no topo da pilha */
boolean topo(TPilha p, char *dado){ 
  if (pilhavazia(p)) 
    return( false ); 
  *dado = p->dado; 
  return( true ); 
}


/* Imprime a pilha */
void imprime(TPilha p){ 
  printf("[ ");
  textcolor(BROWN); 
  while(!pilhavazia(p)) { 
    printf("%c ",p->dado); 
    p = p->prox; 
  }
  textcolor(DARKGRAY); 
  printf("]"); 
} 
