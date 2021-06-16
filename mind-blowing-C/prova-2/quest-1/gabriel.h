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