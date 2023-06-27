#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheMatrizManual(int matriz[][COL], int lin, int col) {
  int i, j;
  for (i = 0; i < lin; i++)
    for (j = 0; j < col; j++) {
      printf("Digite o valor para a posição [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
}

void preencheMatrizAleatorios(int matriz[][COL], int lin, int col, int limite) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < lin; i++)
    for (j = 0; j < col; j++)
      matriz[i][j] = rand() % limite;
}

void apresentaMatriz(int matriz[][COL], int lin, int col) {
  int i, j;
  for (i = 0; i < lin; i++) {
    for (j = 0; j < col; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }
}

int encontraMaiorValorColuna(int matriz[][COL], int lin, int coluna) {
  int i;
  int maior = matriz[0][coluna];
  for (i = 0; i < lin; i++)
    if (matriz[i][coluna] > maior)
      maior = matriz[i][coluna];
  return maior;
}

int encontraMenorValor(int matriz[][COL], int lin, int col) {
  int i, j, menor = matriz[0][0];
  for (i = 0; i < lin; i++)
    for (j = 0; j < col; j++)
      if (matriz[i][j] < menor)
        menor = matriz[i][j];
  return menor;
}

void verificaValor(int matriz[][COL], int lin, int col, int valor) {
  int i, j, valorEncontrado = 0;
  for (i = 0; i < lin; i++) {
    if (valorEncontrado == 1)
      break;
    for (j = 0; j < col; j++)
      if (matriz[i][j] == valor) {
        printf("O valor %d existe na matriz\n", valor);
        valorEncontrado = 1;
        break;
      }
  }
  if (valorEncontrado == 0)
    printf("O valor %d não existe na matriz\n", valor);
}

int somaColuna(int matriz[][COL], int lin, int coluna) {
  int i, soma = 0;
  for (i = 0; i < lin; i++)
    soma = soma + matriz[i][coluna];
  return soma;
}

int somaLinha(int matriz[][COL], int col, int linha) {
  int j, soma = 0;
  for (j = 0; j < col; j++)
    soma = soma + matriz[linha][j];
  return soma;
}

void apresentaDiagonalPrincipal(int matriz[][COL], int lin, int col) {
  int i, j;
  for (i = 0; i < lin; i++)
    for (j = 0; j < col; j++)
      if (i == j) {
        printf("%d", matriz[i][j]);
        if (i != lin - 1)
          printf(", ");
      }
  printf("\n");
}

void verificaLinhaOrdemCrescente(int matriz[][COL], int lin, int col) {
  int i, j;
  int contadorCrescente = 0;
  int ordemCrescenteEncontrada = 0;
  for (i = 0; i < lin; i++) {
    contadorCrescente = 0;
    for (j = 1; j < col; j++) {
      if (matriz[i][j] > matriz[i][j - 1])
        contadorCrescente++;
      else
        break;
    }
    if (contadorCrescente == col - 1) {
      printf("A linha %d possui os elementos em ordem crescente: ", i);
      for (j = 0; j < col - 1; j++)
        printf("%d, ", matriz[i][j]);
      printf("%d ", matriz[i][col - 1]);
      printf("\n");
      ordemCrescenteEncontrada = 1;
    }
  }
  if (ordemCrescenteEncontrada == 0)
    printf("Não há linhas com elementos em ordem crescente\n");
}

void procuraSequencia(int matriz[][COL], int lin, int col) {
  int n, i, j, k;
  int contadorCrescente = 0;
  int sequenciaEncontrada = 0;
  while (1) {
    printf("Digite o valor de n (1 a %d): ", LIN);
    scanf("%d", &n);
    if (n < 0 || n > 6)
      printf("Número inválido\n");
    else
      break;
  }
  int sequencia[n];
  printf("Digite os %d valores da sequência\n", n);
  for (i = 0; i < n; i++) {
    printf("Digite o %dº valor: ", i + 1);
    scanf("%d", &sequencia[i]);
  }
  // LINHAS
  for (i = 0; i < LIN; i++) {
    contadorCrescente = 0;
    for (j = 0; j < COL; j++) {
      if (matriz[i][j] == sequencia[contadorCrescente])
        contadorCrescente++;
      else
        contadorCrescente = 0;
      if (contadorCrescente == n) {
        sequenciaEncontrada = 1;
        printf("A sequência ");
        for (k = 0; k < n; k++) {
          printf("%d", sequencia[k]);
          if (k < n - 1)
            printf(", ");
          else
            printf(" ");
        }
        printf("aparece na linha %d\n", i);
        break;
      }
    }
  }
  // COLUNAS
  for (i = 0; i < COL; i++) {
    contadorCrescente = 0;
    for (j = 0; j < LIN; j++) {
      if (matriz[j][i] == sequencia[contadorCrescente])
        contadorCrescente++;
      else
        contadorCrescente = 0;
      if (contadorCrescente == n) {
        sequenciaEncontrada = 1;
        printf("A sequência ");
        for (k = 0; k < n; k++) {
          printf("%d", sequencia[k]);
          if (k < n - 1)
            printf(", ");
          else
            printf(" ");
        }
        printf("aparece na coluna %d\n", i);
        break;
      }
    }
  }
  if (sequenciaEncontrada == 0) {
    printf("A sequência ");
    for (k = 0; k < n; k++) {
      printf("%d", sequencia[k]);
      if (k < n - 1)
        printf(", ");
      else
        printf(" ");
    }
    printf("não aparece em nenhuma linha ou coluna\n");
  }
}