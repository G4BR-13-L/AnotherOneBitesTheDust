#include <stdio.h>

int main(){
    int base, altura;
    float area;
    printf("Digite a base do triangulo: ");
    scanf("%d", &base);
    printf("\nDigite a altura do triangulo: ");
    scanf("%d", &altura);
    area = ( base * altura ) / 2;
    printf("\nÁrea: %.2f\n\n", area);
    return 0;
}