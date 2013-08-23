/* Prototipação das Funções */
	// REQUERIDAS PELO PROJETO	
		char* converteInfixParaPosfixa(char infixo[], int logarExecucao);
		int expressaoInfixaValida(char infixo[]);
		float executaExpressao(char posfixo[], char operandos[], float valores[], float *valor);
		char* obterOperandos(char *posf);
	
	// FUNÇÕES QUE CRIAMOS
		int pegaInfixo(char infixo[]);
		int eOperador(char c);
		void cabecalho(void);
		void sairdoSistema(void);
		int precedenciaNivel(char ch);
		void imprimeResultado(char infixo[], char posfixo[]);
		int imprimeMensagem();
		float pegaValor(char *operand, float valores[]);

