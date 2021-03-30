#include <stdio.h>

int main(){
    int n1, n2, n3, p1, p2, p3; 
    double media;
    printf("Digite os valores das notas:: \n");
    printf("\nn1: ");
    scanf("%d", &n1);
    printf("\nn1: ");
    scanf("%d", &n2);
    printf("\nn1: ");
    scanf("%d", &n3);
    printf("\nDigite os valores dos pesos respectivamente:: \n");
    printf("\np1: ");
    scanf("%d", &p1);
    printf("\np2: ");
    scanf("%d", &p2);
    printf("\np3: ");
    scanf("%d", &p3);
    media = ( ( n1 * p1 ) + ( n2 * p2 ) + ( n3 * p3 ) ) / ( p1 + p2 + p3);
    printf("\nMédia ponderada: %.2f \n\n", media );
    return 0;
}