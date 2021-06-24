
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
 * 23/06/2021
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

void exa();
int exb();
int exc();
int exd();
int exe();

int main() {
    clear();
  /**Função para escrever a serie de fibonncai
   * No arquivo [ fibonacciLiner.txt ]
   */
  exa();

  /**Função para Ler o arquivo [ fibonacciLinear.txt ]
   * e escrever os numeros em forma de matriz na tela;
   */
  exb();

  /**Função para Ler o arquivo [ fibonacciLinear.txt ]
   * e grava-los em forma de matriz no arquivo
   * [ fibonacciMatriz.txt ];
   */
  exc();

  /**Função que lê o arquivo [ fibonacciLinear.txt ]
   * e ragistra os numeros impares no arquivo
   * [ fibonacci - Impares.tx] e os arquivos pares
   * no arquivo [ fibonacci - Pares.txt]
   */
  exd();

  /**Função para Ler o arquivo [ fibonacciLinear.txt ]
   * e escrever os numeros primos no arquivo
   * [ primos.txt ];
   */
  exe();
}

void exa() {
  printf(BOLDWHITE
         "a)-gravar em um arquivo os 64 primeiros valores da série: 1 1 2 3 5 "
         "8 13 21 34 . . .\n" RESET);
  FILE* fp;
  float num = 1, ultimo = 1, penultimo = 0;
  int i = 0;
  float fibonacci[64];
  printf("\nCriando Arquivo fibonacciLinear.txt\n");
  fp = fopen("fibonacciLinear.txt", "w+");
  for (int i = 0; i < 64; i++) {
    fibonacci[i] = num;
    num = ultimo + penultimo;
    penultimo = ultimo;
    ultimo = num;
    fprintf(fp, "%.0f\n", fibonacci[i]);
  }
  fclose(fp);

  printf(BOLDGREEN "\nfibonacciLinear.txt Criado com SUCESSO\n" RESET);
}

int exb() {
  printf(BOLDWHITE
         "\nb)-ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 "
         "imprima essa matriz na tela.\n\n" RESET);
  FILE* pFile;
  float fibonacci[64];
  if ((pFile = fopen("fibonacciLinear.txt", "r")) == NULL)  // Reading a file
  {
    printf("File could not be opened.\n");
  } else {
    char buffer[200];
    int i = 0;
    fgets(buffer, 200, pFile);
    while (!feof(pFile)) {
      sscanf(buffer, "%f", &fibonacci[i]);
      fgets(buffer, 200, pFile);
      i++;
    }
  }
  fclose(pFile);
  int width = 15;
  int p = 0;
  for (int j = 0; j < 8; j++) {
    for (int k = 0; k < 8; k++) {
      printf(BOLDGREEN "[%*.0f] " RESET, width, fibonacci[p]);
      p++;
    }
    printf("\n");
  }
  printf(BOLDGREEN "\nMatriz exibida com SUCESSO\n" RESET);
}

int exc() {
  printf(BOLDWHITE
         "\nc)-ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 "
         "armazene essa matriz em um arquivo.\n" RESET);
  FILE* fp;
  float fibonacci[64];
  if ((fp = fopen("fibonacciLinear.txt", "r")) == NULL)  // Reading a file
  {
    printf("File could not be opened.\n");
  } else {
    char buffer[200];
    int i = 0;
    fgets(buffer, 200, fp);
    while (!feof(fp)) {
      sscanf(buffer, "%f", &fibonacci[i]);
      fgets(buffer, 200, fp);
      i++;
    }
  }
  fclose(fp);

  int width = 15;
  int p = 0;

  fp = fopen("fibonacciMatriz.txt", "w+");

  for (int j = 0; j < 8; j++) {
    for (int k = 0; k < 8; k++) {
      fprintf(fp, "[%*.0f] ", width, fibonacci[p]);
      p++;
    }
    fprintf(fp, "%s\n", " ");
  }
  fclose(fp);

  printf(BOLDGREEN
         "\nArquivo [ fibonacciMatriz.txt ] criado com SUCESSO\n" RESET);
}

int exd() {
  printf(BOLDWHITE
         "\nd)-ler o arquivo letra ae armazenar os valores pares em um arquivo "
         "e os impares em outro arquivo.\n\n" RESET);
  FILE* fp;
  float fibonacci[64];
  if ((fp = fopen("fibonacciLinear.txt", "r")) == NULL)  // Reading a file
  {
    printf("File could not be opened.\n");
  } else {
    char buffer[200];
    int i = 0;
    fgets(buffer, 200, fp);
    while (!feof(fp)) {
      sscanf(buffer, "%f", &fibonacci[i]);
      fgets(buffer, 200, fp);
      i++;
    }
  }
  fclose(fp);

  fp = fopen("fibonacci - Impares.txt", "w+");
  int aux = 0;
  fprintf(fp, "%s\n ", "[ Numeros Impares ]");
  for (int j = 0; j < 64; j++) {
    aux = fibonacci[j];
    if (aux % 2 == 1) {
      fprintf(fp, "%.0f ", fibonacci[j]);
    }
  }
  fclose(fp);
  printf(BOLDGREEN
         "\nArquivo [ fibonacci - Impares.txt ] criado com SUCESSO" RESET);
  fp = fopen("fibonacci - Pares.txt", "w+");
  int aux1 = 0;
  fprintf(fp, "%s\n ", "[ Numeros Pares ]");
  for (int j = 0; j < 64; j++) {
    aux1 = fibonacci[j];
    if (aux1 % 2 == 0) {
      fprintf(fp, "%.0f ", fibonacci[j]);
    }
  }
  fclose(fp);
  printf(BOLDGREEN
         "\nArquivo [ fibonacci - Pares.txt ] criado com SUCESSO\n" RESET);
}

bool primo(int n) {
  bool primo = true;

  for (int i = 2; i < n / 2 && primo; i++) {
    if (n % i == 0) primo = false;
  }

  return primo;
}
int exe() {
  printf(BOLDWHITE
         "\ne)-ler o arquivo letra a e armazenar em um vetor apenas os primos, "
         "imprima esse vetor, e salve os dados desse vetor em um "
         "arquivo.\n\n" RESET);
  FILE* arq = fopen("fibonacciLinear.txt", "r");
  FILE* out = fopen("primos.txt", "w");
  int tamanho = 64;
  float primos[tamanho];
  int contador = 0;

  for (int i = 0; i < tamanho; i++) {
    float lido;
    fscanf(arq, "%f", &lido);

    if (primo(lido)) {
      primos[contador++] = lido;
      fprintf(out, "%.0f ", lido);
    }
  }
  fclose(arq);
  fclose(out);
  printf(BOLDGREEN "\nArquivo [ primos.txt ] criado com SUCESSO\n" RESET);
}
