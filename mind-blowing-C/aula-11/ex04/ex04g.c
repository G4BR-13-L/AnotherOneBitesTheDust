#include <stdio.h>

int main(){
    int weight, portion;
    float rest;
    printf("Digite o peso do saco de ração(Kg): ");
    scanf("%d", &weight);
    printf("\nDigite a porção para cada gato(g): ");
    scanf("%d", &portion);
    weight = weight * 1000;
    rest = weight - portion * 2 * 5;
    rest = rest / 1000;
    if( ( rest > 0 ) || ( rest == 0 ) ){
        printf("\nRestarão %.0fKg de ração no saco após 5 dias\n\n", rest);
    }else{
        printf("\n%.0fKg é o que falta de ração para alimentar os gatos\n\n", rest * -1);
    }
    return 0;
}