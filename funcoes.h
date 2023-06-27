#define LIN 6
#define COL LIN
#define LIMITE 501

void preencheMatrizManual(int matriz[][COL], int lin, int col);
void preencheMatrizAleatorios(int matriz[][COL], int lin, int col, int limite);
void apresentaMatriz(int matriz[][COL], int lin, int col);
int encontraMaiorValorColuna(int matriz[][COL], int lin, int coluna);
int encontraMenorValor(int matriz[][COL], int lin, int col);
void verificaValor(int matriz[][COL], int lin, int col, int valor);
int somaColuna(int matriz[][COL], int lin, int coluna);
int somaLinha(int matriz[][COL], int col, int linha);
void apresentaDiagonalPrincipal(int matriz[][COL], int lin, int col);
void verificaLinhaOrdemCrescente(int matriz[][COL], int lin, int col);
void procuraSequencia(int matriz[][COL], int lin, int col);