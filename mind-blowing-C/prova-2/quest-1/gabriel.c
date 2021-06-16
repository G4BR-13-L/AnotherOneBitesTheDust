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