
/* ===========Programa que cria o arquivo gabrielvictor.txt========*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randomNumber(int inicial, int final);
int *criarListaNumeros(int qtdNumeros);
void criarGabrielTxt(int qtdNumeros);
int main() {
  srand(time(NULL));
  int N;
  printf("Qual a quantidade de numeros a serem gerados?");
  scanf("%d", &N);
  criarGabrielTxt(N);
  return 0;
}

void criarGabrielTxt(int qtdNumeros) {
  int *listaNumeros = criarListaNumeros(qtdNumeros);
  FILE *fp;
  fp = fopen("gabrielvictor.txt", "w+");
  for (int i = 0; i < qtdNumeros; i++) {
    fprintf(fp, "%d\n", listaNumeros[i]);
  }
  fclose(fp);

  printf("\ngabrielvictor.txt Criado com SUCESSO\n");
}

int randomNumber(int inicial, int final) {
  int x;
  do {
    x = (rand() % (final - inicial + 1)) + inicial;
  } while (x < inicial);
  return x;
}

int *criarListaNumeros(int qtdNumeros) {
  int *lista;
  lista = (int *)malloc(qtdNumeros * sizeof(int));
  for (int i = 0; i < qtdNumeros; i++) {
    lista[i] = randomNumber(65, 75);
  }
  return lista;
}

