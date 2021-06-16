

//===== arquivo gabriel.c ======

#include <stdio.h>
#include <stdlib.h>
#include "gabriel.h"

int main(){
    int n_termos;
    printf("Digite o numero de termos da operação: ");
    scanf("%d", &n_termos);
    float resultado = operacao(n_termos);
    printf("\n\nH = %1.6f\n\n", resultado);
}
// ===== fim arquivo gabriel.c ======


// ====== biblioteca gabriel.c ======
#ifndef GABRIEL_H
#define GABRIEL_H

float operacao(int n_termos) {
  double soma = 0;
  float dividendo = 2, divisor = 1, aux = 0;

  for (int i = 0; i < n_termos; i++) {
    if (aux == 0) {
      soma -= dividendo / divisor;
      aux = 1;
    } else {
      soma += dividendo / divisor;
      aux = 0;
    }
    dividendo += 3;
    divisor += 2;
  }
  return soma;
}
#endif
// ====== fim biblioteca gabriel.h ======
