#include <stdio.h>

int main(){
    int num;
    double rest;
    printf("Digite um numero: ");
    scanf("%d", &num);
    rest = num % 7;
    printf("O resto da divisão de %d por 7 é: %.2f\n\n", num, rest);
    return 0;
}