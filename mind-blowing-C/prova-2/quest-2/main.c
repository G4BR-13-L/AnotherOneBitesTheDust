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

int *gerarVetor(int vetor_len); // função que retorna o vetor como valor
int randomNumber(int inicial, int final); // função que gerea numeros aleatórios

int main() {
  srand(time(NULL));
  int vetor_len;
  printf("Digite o comprimento do vetor: ");
  scanf("%d", &vetor_len);
  int *vetor = gerarVetor(vetor_len);
  for (int j = 0; j < vetor_len; j++) {
    printf("[%d] ", *(vetor + j));
  }
  printf("\n");
  for (int k = 0; k < vetor_len; k++) {
    int frequencia = 0;

    int verificacao = 0;
    for (int h = k; h >= 0; h--) {
      if (*(vetor + k) != *(vetor + h)) {
        verificacao++;
      } else {
        verificacao = 0;
      }
    }
    if (verificacao == k) {
      for (int l = 0; l < vetor_len; l++) {
        if (*(vetor + k) == *(vetor + l)) {
          frequencia++;
        }
      }
        printf("[%d] - aparece %d vezes\n", *(vetor + k), frequencia);
    }
  }
}

// Função que retorna o vetor como valor
int *gerarVetor(int vetor_len) {
  int *vetor;
  vetor = (int *)malloc(vetor_len * sizeof(int));
  for (int i = 0; i < vetor_len; i++) {
    vetor[i] =  randomNumber(0, 10) ;
  }
  return vetor;
}

/*Função qu retorna um numero aleatório*/
int randomNumber(int inicial, int final) {
  int x;
  do {
    x = (rand() % (final - inicial + 1)) + inicial;
  } while (x < inicial);
  return x;
}