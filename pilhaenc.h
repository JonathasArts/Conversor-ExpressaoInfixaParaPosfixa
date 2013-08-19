/* Criando o tipo Boolean. False possui valor zero (0) e true possui valor um (1) */
typedef enum{
	false,
	true
} boolean;

/* Pilha Simplismente Encadeada*/
typedef struct stnop{ 
  char dado; 							//Variavel para armazenar dado
  struct stnop *prox; 					//Ponteiro para o Proximo nó
} nopilha;

/* Criando o tipo pilha */ 
typedef nopilha* TPilha;

/* Operações primárias da Pilha */
void criapilha(TPilha *p);
boolean pilhavazia(TPilha p);
int tamanho(TPilha p);
boolean empilha(TPilha *p, char dado);
boolean desempilha(TPilha *p, char *dado);
boolean topo(TPilha p, char *dado);
void imprime(TPilha p);
