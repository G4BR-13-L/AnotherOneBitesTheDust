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

int gerarVetor(int N);

int main() {
  clear();
  printf(
      "6-Escrever um programa que leia um valor e chame a função e o "
      "procedimentos criados.(2,5)\n\n- Construa uma função que retorne um "
      "vetor do "
      "tipo real,com valores aleatórios entre 30 e 50 (intervalo fechado ),de "
      "tamanho N – passe o tamanho N por valor. \n\n- Construa um "
      "procedimento para imprimir umvetor real de tamanho N – passe o vetor "
      "por referência e o tamanho N por valor.\n\n");
  int valor;
  srand(time(NULL));
  printf("Digite um valor: ");
  scanf("%d", &valor);
  float *vetorFloat = gerarVetor(valor);
  for(int j = 0 ; j < 20 ; j++){
      printf("%f\n", vetorFloat[j]);
  }
  return 0;
}

/*Função qu retorna um numero aleatório*/
int gerarVetor(int N) {
  int inicial = 30, final = 50, aux;
  float *vetor;
vetor = (float *)malloc(N * sizeof(float));
  for (int i = 0; i < N; i++) {
    do {
      vetor[i] = (rand() % (final - inicial + 1)) + inicial;
    } while (vetor[i] < inicial);
  }
  return *vetor;
}
