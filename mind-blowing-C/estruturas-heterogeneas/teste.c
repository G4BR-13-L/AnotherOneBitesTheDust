
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int myRandom(int inicial, int final);
int funcaoA();
int funcaoB(int x, int z, int matriz[10][10]);

int main() {
  funcaoA();
  return 0;
}

int funcaoB(int x, int z, int matriz[10][10]) {
  int largest = 0, smallest = matriz[0][0], smallCoordI, smallCoordY, largeCoordI,
      largeCoordY;
  for (int i = 0; i < x; i++) {
    for (int y = 0; y < z; y++) {
      if (matriz[i][y] > largest) {
        largest = matriz[i][y];
        largeCoordI = i;
        largeCoordY = y;
      }
      if (matriz[i][y] < smallest) {
        smallest = matriz[i][y];
        smallCoordI = i;
        smallCoordY = y;
      }
    }
  }
  printf("\nO menor valor é %i, na posição [%i,%i]", smallest, smallCoordI,
         smallCoordY);
  printf("\nO maior valor é %i, na posição [%i,%i]\n\n", largest, largeCoordI,
         largeCoordY);
}

int funcaoA() {
  int matrixRand[10][10];
  int min, max;
  printf("       ");
  for (int i = 0; i < 10; i++) {
    printf("  %i.  |", i);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("\n");
    for (int y = 0; y < 10; y++) {
      if (y == 0) printf("  %i.  |", i);

      matrixRand[i][y] = myRandom(15, 50);

      printf("  %i  |", matrixRand[i][y]);
    }
  }
  funcaoB(10, 10, matrixRand);
}

int myRandom(int inicial, int final) {
  int x;
  do {
    x = (rand() % (final - inicial + 1)) + inicial;
  } while (x < inicial);
  return x;
}