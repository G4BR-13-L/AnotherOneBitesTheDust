#include <stdio.h>

int main(){
    int a, b, c, d; 
    float media;
    printf("Digite um valor: ");
    scanf("%d", &a);
    printf("Digite outro valor: ");
    scanf("%d", &b);
    printf("Digite outro valor: ");
    scanf("%d", &c);
    printf("Digite mais um valor: ");
    scanf("%d", &d);
    media = (a + b + c + d ) / 4;
    printf("\nA média aritmética é: %.2f\n", media);
    return 0;
}