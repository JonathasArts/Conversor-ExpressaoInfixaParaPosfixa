Conversor-ExpressaoInfixaParaPosfixa
====================================

Projeto Estrutura de Dados


Conversão e Avaliação de Expressões Pós-Fixadas 
(Semestre 2013.1) 
 
Introdução 
 
Uma representação para expressões aritméticas, que seja conveniente do ponto de vista computacional, é 
assunto de interesse, por exemplo, na área de compiladores. A notação tradicional é ambígua e, portanto, 
obriga  ao  preestabelecimento  de  regras  de  prioridade.  Isso,  naturalmente,  torna  a  tarefa  computacional 
menos  simples.  
 
Vimos que a representação posfixada é uma alternativa para transformação das expressões infixas. Deste 
modo,  neste  projeto,  você  deve  implementar  uma  estrutura  de  dados  ou  conjunto  de  operações  que  dê 
suporte  à  análise,  verificação  e  execução  de  expressões  pós-fixadas  (use  a  lista09  para  obter  toda  a 
fundamentação necessária sobre esse tipo de transformação). 
 
Operações: 
 
A  implementação é  livre,  entretanto,  não  deve  quebrar  o  encapsulamento  da  estrutura  de  dados,  o  que 
implicaria em desclassificação do projeto. Basicamente, a estrutura de dados para conversão de expressões 
deve conter as seguintes operações: 
 
-#define LOGAR 1 /* Sinaliza que a execução da expressão será logada */ 
-#define NAO_LOGAR 0 /* Sinaliza que a execução da expressão não será logada */ 
 
/* Converte uma expressão infixa para posfixa. 
   PARAMETROS: 
   expressao – A expressão no formato infixo digitada. 
   logarExecucao – Um inteiro que informa se o passo-a-passo da expressão será logado 
   RETORNO: 
   Um ponteiro para a string no formato posfixo */ 
char* converteInfixParaPosfixa(char *expressao, int logarExecucao); 
 
/* Verifica se uma expressão infixa é válida ou não. 
   PARAMETROS: 
   expressao – A expressão no formato infixo. 
   RETORNO: 
   1 caso a expressão seja válida, 0 caso contrário */ 
int expressaoInfixaValida( char *expressao); 
 
 
 
Estrutura de Dados I    Prof: Alex Sandro C. Rêgo 
/* Executa a expressão posfixada, de acordo com seus respectivos valores. 
   PARAMETROS: 
   expressao – A expressão no formato posfixo. 
   operandos – Um string contendo a sequência dos operandos existentes na expressão 
   valor – Um array de float com os respectivos valores de cada operando 
   RETORNO: 
   Um float com o resultado da avaliação da expressão */ 
float executaExpressao( char *expressao, char *operandos, float *valor); 
 
/* Identifica os operandos existentes na expressão infixa ou posfixa. 
   PARAMETROS: 
   expressao – A expressão no formato infixo ou posfixo. 
   RETORNO: 
   Um string contendo a lista de operandos identificados, sem duplicidade*/ 
char* obterOperandos( char *expressao); 
 
OBSERVAÇÃO:  outras  operações  podem  surgir,  de  acordo  com  o  planejamento  da  estrutura. Não 
necessariamente,  as  soluções  devam  obedecer  rigorosamente  o  protótipo  e  funcionalidades  listadas. 
Entretanto, qualquer alteração deve ser dialogada com o professor. 
 
Simulação: 
 
Digite a expressão na forma infixa (quit: sair) 
> A+B*C 
  Deseja ver o processo de transformação passo-a-passo (S/N)? S 
 
 OK: expressao valida! 
 
  [1] A   Pilha (topo):[ ]   Saída: A 
  [2] +  Pilha (topo):[+]   Saída: A 
  [3] B  Pilha (topo):[+]   Saída: AB 
  [4] *  Pilha (topo):[*+]   Saída: AB 
  [5] C  Pilha (topo):[*+]   Saída: ABC 
      Esvaziando a pilha... 
  [6] expressao final: ABC*+  
 
  Digite os valores dos operandos identificados: 
  A = 3.0 
  B = 2.0 
  C = 4.0 
 
  O resultado da expressao eh: 
  11.0 
 
Digite a expressão na forma infixa (quit: sair) 
> quit 
 
 
 
Estrutura de Dados I    Prof: Alex Sandro C. Rêgo 
REQUISITOS FUNCIONAIS 
 
  Cada operando é representado por uma única letra do alfabeto. 
  A  operação  converteInfixParaPosfixa()  deve  alocar  dinamicamente  a  string  posfixada, 
internamente, e devolver um ponteiro para a mesma; 
  A operação expressaoInfixaValida() deve verificar se uma expressão infixa é válida em termos 
do  uso correto  dos  parênteses  e uso  operadores/operandos,  considerando  que  os  operadores  são 
binários; 
  A expressão pode conter operandos repetidos; 
  O layout da apresentação é de livre escolha da equipe. Entretanto, deve ser observada as seguintes 
situações: 
1.  O usuário deve digitar a expressão no formato infixo; 
2.  O usuário deve informar se  deseja visualizar o passo-a-passo da transformação; 
3.  Antes de executar a transformação, deve ser verificado se a expressão infixa é válida ou não. 
Se  for  válida,  executa  a  transformação.  Se  não  for,  o  usuário  deve  digitar  novamente  a 
expressão; 
4.  Após a conversão da expressão, o usuário deve digitar o valor de cada operando identificado. 
Cada  operando  deve  ser  identificado  automaticamente,  de  modo  que  o  usuário  associe 
apenas o seu valor; 
5.  Por fim, a expressão posfixada é executada e o valor final (float) é exibido ao usuário. 
6.  O usuário pode executar o mesmo processo quantas vezes desejar. 
 
Considerações Gerais 
 
  Máximo de 2 alunos por equipe; 
  Quebra de encapsulamento no código ocasionará perda total da nota; 
  Código  deve  estar  bem  documentado,  principalmente  no  que  diz  respeito à  apresentação  das 
operações (ver exemplo utilizado neste projeto) 
  Interface funcional, que atenda às considerações descritas na simulação; 
  Programação estruturada, com uso de bibliotecas .h 
  O código deve ser reutilizável, com o mínimo de acoplamento possível.
