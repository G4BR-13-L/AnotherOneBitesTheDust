/*
The MIT License (MIT)
    *Copyright © 2021 Gabriel Victor - PUC Minas
    *
    *Permission is hereby granted, free of charge, to any person obtaining a
copy of *this software and associated documentation files (the “Software”), to
deal in *the Software without restriction, including without limitation the
rights to *use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of *the Software, and to permit persons to whom the Software is
furnished to do so, *subject to the following conditions:
    *
    *The above copyright notice and this permission notice shall be included in
all *copies or substantial portions of the Software.
    *
    *THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS *FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR *COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER *IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN *CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
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

void gravarFibonacci();
int exb();
int exc();
int main() {
  gravarFibonacci();
  exb();
  exc();
}

void gravarFibonacci() {
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

  printf("\nfibonacciLinear.txt Criado com SUCESSO\n");
}

int exb() {
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
}

int exc() {
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
    fprintf(fp,"%s\n", " ");
  }
  fclose(fp);
}

int randomNumber(int inicial, int final) {
  int x;
  do {
    x = (rand() % (final - inicial + 1)) + inicial;
  } while (x < inicial);
  return x;
}
