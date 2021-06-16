
/*
a) Faça uma função que receba uma matriz 10x10  e devolva essa matriz preenchida
com valores compreendidos entre 10 e 70.

b) Faça uma função que receba uma matriz 10x10  e imprima essa matriz

c) Faça uma função que receba uma matriz 10x10  e devolva a média dos elementos
que estão nas linhas impares (1,3,5,7,9) dessa matriz

d) Faça uma função que receba como parâmetros uma matriz 10x10 e escreva a
localização (linha e coluna) de todos os elementos da matriz que sejam PRIMOS ou
a mensagem que não existe valores com essa restrição.

e) Faça um programa que chame as funções criadas.*/
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
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

int randomNumber(int inicial,
                 int final);  // Função que retorna numero aleatório

/*Procedimento que informa os maiores e os menores numeros da matriz*/
int media(int mat[10][10]);
int primos(int mat[10][10]);
int verificaPrimo(int num);
int main() {
  clear();
  int x = 0;
  srand(time(NULL));
  int mat[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      mat[i][j] = randomNumber(10, 70);
    }
  }

  // Printar matriz ===========
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
  // Printar matriz =====================
  printf("\n\n" RESET);
  media(mat);
  printf("\n\n" RESET);
  primos(mat);
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

int media(int mat[10][10]) {
  printf("Media das linhas impares");
  int soma = 0;
  double media = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 != 0) {
      for (int j = 0; j < 10; j++) {
        soma += mat[i][j];
      }
      media = soma / 10;
      printf("\nLinha [%d] tem média: %.2f", i, media);
      soma = 0;
    }
  }
}
int verificaPrimo(int num) {
  int isPrimo = 0;
  for (int t = num - 1; t > 1; t--) {
    if (num % t == 0) {
      isPrimo = 0;
    }
  }
  return isPrimo;
}
int primos(int mat[10][10]) {
  int primosEncontrados = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int isPrimo = verificaPrimo(mat[i][j]);
      if (isPrimo == 1) {
        printf("\n[ %d, %d ] - %d é Primo", i, j, mat[i][j]);
        primosEncontrados++;
      }
    }
  }
  if (primosEncontrados == 0) {
    printf("\nNenhum numero primo foi encontrado\n");
  }
}
