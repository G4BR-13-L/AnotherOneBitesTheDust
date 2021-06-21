/*
=====================================================
Código desenvolvido por:

 ██████╗  █████╗ ██████╗ ██████╗ ██╗███████╗██╗
██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██║██╔════╝██║
██║  ███╗███████║██████╔╝██████╔╝██║█████╗  ██║
██║   ██║██╔══██║██╔══██╗██╔══██╗██║██╔══╝  ██║
╚██████╔╝██║  ██║██████╔╝██║  ██║██║███████╗███████╗
 ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝
 =====================================================
*/

/*
 *Trabalho de Acesso sequecial de arquivos
 * 20/06/2021
 * Algoritmos e Estruturas de dados - PUC Minas
 * Engenharia de Software;
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN64
#include <windows.h>
void clear() { system("cls"); }
#elif _WIN32
#include <windows.h>
void clear() { system("cls"); }
#else
#include <unistd.h>
void clear() { printf("\033c"); }
#endif

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

int exA();
int exB();
int exC();
int exD();
int exE();

int fibonacciLen = 0;
int main() {
  int exec = 1, exercicio;
  while (exec == 1) {
    clear();
    printf(BOLDWHITE
           "============Autor: Gabriel Victor Couto Martins de "
           "Paula===========\n" RESET);
    printf(BOLDWHITE
           "\n= Exercícios:\n= A == 1\n= B == 2\n= C == 3\n= D == 4\n= E == "
           "5\n\n" RESET);
    printf(BOLDWHITE
           "======================Selecione um "
           "exercício=======================\n" RESET);
    printf(BOLDWHITE "                    [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ]" RESET);
    printf("\n                                  ");
    scanf("%d", &exercicio);
    switch (exercicio) {
      case 1:
        exA();
        break;
      case 2:
        exB();
        break;
      case 3:
        exC();
        break;
      case 4:
        exD();
        break;
      case 5:
        exE();
        break;
      default:
        printf(BOLDWHITE "Exercício inexistente\n\n" RESET);
        break;
    }
    printf("\n\nDeseja continuar a execução?  [Sim = 1 / Não = 0]");
    scanf("%d", &exec);
    clear();
  }
}

int exA() {
  printf(BOLDWHITE
         "a)-gravar em um arquivo os 64 primeiros valores da série: 1 1 2 3 5 "
         "8 13 21 34 . . ." RESET);
  int len = 0;
  printf("\n\nDigite o tamanho da sequencia de fibonacci: ");
  scanf("%d", &len);

  int fibonacci[len];
  char mensagem[255] = {};
  int num = 1, ultimo = 1, penultimo = 0;
  printf(BOLDWHITE "[ ");
  int i = 0;
  for (i = len; i > 0; i--) {
    fibonacci[i] = num;
    num = ultimo + penultimo;
    penultimo = ultimo;
    ultimo = num;
  }
  printf("]");
  for (int j = len; j > 0; j--) {
    sprintf(&mensagem[strlen(mensagem)], "%d ", fibonacci[j]);
  }
  FILE* arquivo;
  if ((arquivo = fopen("arquivo.txt", "w")) == NULL)  // modo de escrita ativo
  {
    printf("Erro de abertura!\n ");
  } else {
    fprintf(arquivo, "%s \n ", mensagem);
    fclose(arquivo);
  }
  printf("Fibonacci Gravado no arquivo: ");
  printf(BOLDBLUE "[ %s ]\n\n" RESET, mensagem);
}

int exB() {
  printf(BOLDWHITE
         "\nb)-ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 "
         "imprima essa matriz na tela.\n\n" RESET);
  int fibonacciLido[255];
  FILE* arquivoLeitura;

  int k = 0;
  if ((arquivoLeitura = fopen("arquivo.txt", "r")) == NULL) {
    printf("Erro de abertura! \n");
  } else {
    while (!feof(arquivoLeitura)) {
      fscanf(arquivoLeitura, "%d", &fibonacciLido[k]);
      k++;
    }
    fclose(arquivoLeitura);
  }
  int* fibonacciFormatado;
  fibonacciFormatado = (int*)malloc((k - 1) + sizeof(int));
  for (int g = 0; g < k - 1; g++) {
    fibonacciFormatado[g] = fibonacciLido[g];
  }
  fibonacciLen = k - 1;
  int mat[8][8];
  size_t f = k - 1;
  int fibo = 0;
  for (int y = 0; y < 8; y++) {
    for (int p = 0; p < 8; p++) {
      if (fibo >= f) {
        mat[y][p] = 0;
      } else {
        mat[y][p] = fibonacciFormatado[fibo];
        fibo++;
      }
    }
  }
  // Printar matriz ======================
  printf("      ");
  for (int j = 0; j < 8; j++) {
    printf(BOLDWHITE "%d     " RESET, j);
  }
  printf("\n");
  for (int k = 0, i = 0; k < 8; k++, i++) {
    printf(BOLDWHITE "%d " RESET, i);
    printf(BOLDGREEN "| ");
    for (int l = 0; l < 8; l++) {
      printf(" [%d] ", mat[k][l]);
    }
    printf(" |\n" RESET);
  }

  // Printar matriz =====================
}

int exC() {
  printf(BOLDWHITE
         "\nc)-ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 "
         "armazene essa matriz em um arquivo.\n" RESET);

  int fibonacciLido[255];
  FILE* arquivoLeitura;
  int k = 0;
  if ((arquivoLeitura = fopen("arquivo.txt", "r")) == NULL) {
    printf("Erro de abertura! \n");
  } else {
    while (!feof(arquivoLeitura)) {
      fscanf(arquivoLeitura, "%d", &fibonacciLido[k]);
      k++;
    }
    fclose(arquivoLeitura);
  }
  int fibonacciFormatado[k - 1];
  for (int g = 0; g < k - 1; g++) {
    fibonacciFormatado[g] = fibonacciLido[g];
  }
  fibonacciLen = k - 1;
  int mat[8][8];
  size_t f = k - 1;
  int fibo = 0;
  for (int y = 0; y < 8; y++) {
    for (int p = 0; p < 8; p++) {
      if (fibo >= f) {
        mat[y][p] = 0;
      } else {
        mat[y][p] = fibonacciFormatado[fibo];
        fibo++;
      }
    }
  }
  FILE* arquivo;
  if ((arquivo = fopen("arquivoMatriz.txt", "w")) == NULL) {
    printf("Erro de abertura!\n ");
  } else {
    int fibo = 0;
    for (int y = 0; y < 8; y++) {
      for (int p = 0; p < 8; p++) {
        if (fibo >= fibonacciLen) {
          mat[y][p] = 0;
          fprintf(arquivo, "[ %d ]", mat[y][p]);
        } else {
          fibo++;
          fprintf(arquivo, "[ %d ]", mat[y][p]);
        }
      }
      fprintf(arquivo, "\n");
    }
    fclose(arquivo);
  }
}

int pegarTamanhoFibonacci() {
  int fibonacciLido[255];
  FILE* arquivoLeitura;
  int k = 0;
  if ((arquivoLeitura = fopen("arquivo.txt", "r")) == NULL) {
    printf("Erro de abertura! \n");
  } else {
    while (!feof(arquivoLeitura)) {
      fscanf(arquivoLeitura, "%d", &fibonacciLido[k]);
      k++;
    }
    fclose(arquivoLeitura);
  }
  return k - 1;
}
int exD() {
  printf(BOLDWHITE
         "\nd)-ler o arquivo letra ae armazenar os valores pares em um arquivo "
         "e os impares em outro arquivo.\n\n" RESET);
  FILE* arq = fopen("arquivo.txt", "r");
  FILE* pares = fopen("pares.txt", "w");
  FILE* impares = fopen("impares.txt", "w");
  int tamanho = pegarTamanhoFibonacci();
  fibonacciLen = tamanho;
  for (int i = 0; i < tamanho; i++) {
    int lido;
    fscanf(arq, "%d", &lido);
    if (lido % 2 == 0)
      fprintf(pares, "%d ", lido);
    else
      fprintf(impares, "%d ", lido);
  }

  fclose(arq);
  fclose(pares);
  fclose(impares);
}
bool primo(int n) {
  bool primo = true;

  for (int i = 2; i < n / 2 && primo; i++) {
    if (n % i == 0) primo = false;
  }

  return primo;
}

int exE() {
  printf(BOLDWHITE
         "\ne)-ler o arquivo letra a e armazenar em um vetor apenas os primos, "
         "imprima esse vetor, e salve os dados desse vetor em um "
         "arquivo.\n\n" RESET);
  FILE* arq = fopen("arquivo.txt", "r");
  FILE* out = fopen("primos.txt", "w");
  int tamanho = pegarTamanhoFibonacci();
  fibonacciLen = tamanho;
  int primos[tamanho];
  int contador = 0;

  for (int i = 0; i < tamanho; i++) {
    int lido;
    fscanf(arq, "%d", &lido);

    if (primo(lido)) {
      primos[contador++] = lido;
      printf("%d ", lido);
      fprintf(out, "%d ", lido);
    }
  }
  fclose(arq);
  fclose(out);
}
