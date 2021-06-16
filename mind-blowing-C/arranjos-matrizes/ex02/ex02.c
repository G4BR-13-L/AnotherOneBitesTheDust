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

int randomNumber(int inicial,
                 int final);  // Função que retorna numero aleatório

int somaDiagonal(int mat[10][10]);  // Função que retorna a soma dos valores da
                                    // diagona da matriz

/*Procedimento que informa os maiores e os menores numeros da matriz*/
void maiorMenorNumero(int mat[10][10]) {
  printf(
      "2)Escreva um procedimento que receba uma matriz 10x10 (passagem de "
      "parâmetro), imprimir o maior e o menor elemento da matriz bem como a "
      "posição de cada um.(0,5)\n\n");
  int maior = mat[0][0], menor = mat[0][0];
  int maior_i = 0, maior_j = 0, menor_i = 0, menor_j = 0;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (mat[i][j] > maior) {
        maior = mat[i][j];
        maior_i = i;
        maior_j = j;
      } else if (mat[i][j] < menor) {
        menor = mat[i][j];
        menor_i = i;
        menor_j = j;
      }
    }
  }

  printf(BOLDWHITE "Maior numero:" RESET);
  printf(BOLDBLUE "%d\n" RESET, mat[maior_i][maior_j]);
  printf(BOLDWHITE "Posição:" RESET);
  printf(BOLDMAGENTA "[ %d, %d ]\n" RESET, maior_i, maior_j);
  printf(BOLDWHITE "Menor numero:" RESET);
  printf(BOLDBLUE "%d\n" RESET, mat[menor_i][menor_j]);
  printf(BOLDWHITE "Posição:" RESET);
  printf(BOLDMAGENTA "[ %d, %d ]\n\n" RESET, menor_i, menor_j);
}

// Procedimento que busca uma valor na matriz com base nas posições de linha e
// coluna
void buscaPorValor(int mat[10][10]) {
  printf(
      "4)Escreva um procedimento que receba uma matriz 10x10, peça ao usuário "
      "a posição [i,j] da matriz , e em seguida exiba o valor que esta na "
      "matriz nesta posição. FLAG -1(0,5)\n\n");
  int i = 0, j = 0;
  printf("Digite o numero da linha: ");
  scanf("%d", &i);
  printf("Digite o numero da Coluna: ");
  scanf("%d", &j);
  if (i < 0 || j < 0) {
    printf(BOLDRED "FLAG\n\n" RESET);
  } else {
    printf(BOLDWHITE "Valor da posição [ %d, %d ] é: " RESET, i, j);
    printf(BOLDMAGENTA "%d\n\n"RESET, mat[i][j]);
  }
}

/*
    ========Procedimento que busca um valor na matriz e 
    mostra a sua posição================================;
*/
void buscaPorPosicao(int mat[10][10]) {
  printf(
      "5)Escreva um procedimento que receba uma matriz 10x10, e um número. O "
      "procedimento deverá verificar se o número está ou não na matriz. Se "
      "estiver imprima a(s) posição(ões) desse número e se não estiver imprima "
      "a mensagem valor não encontrado.(0,5)\n\n");
  int n = 0, posicao_i = 0, posicao_j = 0, encontrado = 0;
  printf("Digite o valor a ser encontrado: ");
  scanf("%d", &n);
  if (n < 0) {
    printf(BOLDRED "FLAG -1\n\n" RESET);
  } else {
      for(int i = 0; i < 10; i++){
          for(int j = 0 ; j < 10 ; j++){
              if(mat[i][j] == n ){
                  posicao_i = i, posicao_j = j;
                  encontrado = 1;
                  break;
              }
          }
      }
      if(encontrado == 1){
          printf(BOLDWHITE "O Valor %d está na posição [ %d, %d ]\n\n" RESET, n, posicao_i, posicao_j);
      }else{
          printf(BOLDRED"Valor não encontrado\n\n"RESET);
      }
  }
}


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
  maiorMenorNumero(mat);
  somaDiagonal(mat);
  buscaPorValor(mat);
  buscaPorPosicao(mat);
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

// procedimento para escrever a matriz com diagonal destacada
void diagonal(int mat[10][10]) {
  printf("      ");
  for (int j = 0; j < 10; j++) {
    printf(BOLDWHITE "%d     " RESET, j);
  }
  printf("\n");
  for (int k = 0, i = 0; k < 10; k++, i++) {
    printf(BOLDWHITE "%d " RESET, i);
    printf(BOLDGREEN "| ");
    for (int l = 0; l < 10; l++) {
      if (k == l) {
        printf(BOLDRED " [%d] " RESET, mat[k][l]);
      } else {
        printf(BOLDGREEN " [%d] ", mat[k][l]);
      }
    }
    printf(" |\n" RESET);
  }
}
// Função que soma os valores da diagonal da matriz
int somaDiagonal(int mat[10][10]) {
  printf(
      "3)Escreva uma função que receba uma matriz 10x10 e retorne a soma dos "
      "elementos da diagonal principal.(0,5)\n\n");
  int soma = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == j) {
        soma += mat[i][j];
      }
    }
  }
  diagonal(mat);

  printf(BOLDWHITE "\n\nSoma dos valores na diagonal: ");
  printf(BOLDCYAN "%d\n\n" RESET, soma);
}
