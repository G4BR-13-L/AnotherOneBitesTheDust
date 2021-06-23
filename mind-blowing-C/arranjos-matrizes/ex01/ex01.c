/* 
The MIT License (MIT)
    *Copyright © 2021 Gabriel Victor - PUC Minas
    *
    *Permission is hereby granted, free of charge, to any person obtaining a copy of
    *this software and associated documentation files (the “Software”), to deal in
    *the Software without restriction, including without limitation the rights to
    *use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    *the Software, and to permit persons to whom the Software is furnished to do so,
    *subject to the following conditions:
    *
    *The above copyright notice and this permission notice shall be included in all
    *copies or substantial portions of the Software.
    *
    *THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    *FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    *COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    *IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    *CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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

/**
 * Arranjos e matrizes, ex01
 * 04/05/2021
 * Engenharia de Software -  PUC Minas
 */
#include <stdio.h>
#include <stdlib.h>
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

int randomNumber(int inicial, int final); // Função que retorna numero aleatório

int main() {
  clear();
  printf(
      "1)Preencher uma matriz  de 10 x 10  posições com valores aleatórios "
      "de 15 a 50 (utilize para cada número a função rand–faça uma função "
      "que dados os valores inicial e final devolva um número aleatório "
      "dentro deste intervalo) Em seguida imprima os índices(i,j) da matriz "
      "e o valor correspondente, na forma de matriz, bem como chame os "
      "módulos abaixo(0,5)\n\n");
  int x = 0;
  srand(time(NULL));

  int mat[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      mat[i][j] = randomNumber(15, 50);
    }
  }
  printf("      ");
  for (int j = 0; j < 10; j++) {
    printf(BOLDWHITE "%d     " RESET, j);
  }
  printf("\n");
  for (int k = 0, i = 0; k < 10; k++, i++) {
    printf(BOLDWHITE "%d " RESET, i);
    printf(BOLDGREEN "| ");
    for (int l = 0; l < 10; l++) {
      printf(" [%d] ", mat[k][l]);
    }
    printf(" |\n" RESET);
  }

  return 0;
}

/*Função qu retorna um numero aleatório*/
int randomNumber(int inicial, int final) {
  int x;
  do {
    x = (rand() % (final - inicial + 1)) + inicial;
  } while (x < inicial);
  return x;
}