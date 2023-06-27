#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int matriz[LIN][COL], opcao1, opcao2;
  int valor, coluna, linha;
  while (1) {
    printf("1 - Digitar os valores da matriz manualmente\n");
    printf("2 - Preenchimento automático com números aleatórios\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao1);
    if (opcao1 == 1) {
      preencheMatrizManual(matriz, LIN, COL);
      break;
    } else if (opcao1 == 2) {
      preencheMatrizAleatorios(matriz, LIN, COL, LIMITE);
      break;
    } else
      printf("Opção inválida\n");
  }
  do {
    printf("Menu de opções\n");
    printf("1 - Exibir a matriz\n");
    printf("2 - Encontrar maior valor de uma coluna\n");
    printf("3 - Encontrar menor valor da matriz\n");
    printf("4 - Verificar se um valor existe na matriz\n");
    printf("5 - Realizar soma de coluna\n");
    printf("6 - Realizar soma de linha\n");
    printf("7 - Exibir elementos da diagonal principal\n");
    printf("8 - Verificar linhas em ordem crescente\n");
    printf("9 - Procurar sequência de valores na ordem fornecida\n");
    printf("10 - Finaliza\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao2);
    switch (opcao2) {
    case 1:
      apresentaMatriz(matriz, LIN, COL);
      break;
    case 2:
      while (1) {
        printf("Digite o número da coluna (0-%d): ", COL - 1);
        scanf("%d", &coluna);
        if (coluna < 0 || coluna > COL - 1) {
          printf("Número inválido\n");
        } else
          break;
      }
      printf("Maior valor da coluna %d: %d\n", coluna,
             encontraMaiorValorColuna(matriz, LIN, coluna));
      break;
    case 3:
      printf("Menor valor da matriz: %d\n",
             encontraMenorValor(matriz, LIN, COL));
      break;
    case 4:
      printf("Digite o valor a ser verificado: ");
      scanf("%d", &valor);
      verificaValor(matriz, LIN, COL, valor);
      break;
    case 5:
      while (1) {
        printf("Digite o número da coluna (0-%d): ", COL - 1);
        scanf("%d", &coluna);
        if (coluna < 0 || coluna > COL - 1) {
          printf("Número inválido\n");
        } else
          break;
      }
      printf("A soma dos elementos da coluna %d: %d\n", coluna,
             somaColuna(matriz, LIN, coluna));
      break;
    case 6:
      while (1) {
        printf("Digite o número da linha (0-%d): ", LIN - 1);
        scanf("%d", &linha);
        if (linha < 0 || linha > LIN - 1) {
          printf("Número inválido\n");
        } else
          break;
      }
      printf("A soma dos elementos da linha %d: %d\n", linha,
             somaLinha(matriz, COL, linha));
      break;
    case 7:
      apresentaDiagonalPrincipal(matriz, LIN, COL);
      break;
    case 8:
      verificaLinhaOrdemCrescente(matriz, LIN, COL);
      break;
    case 9:
      procuraSequencia(matriz, LIN, COL);
      break;
    case 10:
      printf("Programa finalizado\n");
      break;
    default:
      printf("Opção inválida\n");
    }
  } while (opcao2 != 10);

  return 0;
}