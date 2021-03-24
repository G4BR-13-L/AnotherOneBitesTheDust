#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    double soma;
    float media;
    printf("Digite o primeiro numero: ");
    scanf("%i", &a);
    printf("\n");
    printf("Digite o segundo numero: ");
    scanf("%i", &b);
    printf("\n");
    soma = a+b;
    media = soma/2;
    printf("A média de %i e %i é %5.2f \n",a,b,media);
    return 0;
}
