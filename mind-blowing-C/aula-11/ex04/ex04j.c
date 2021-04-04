#include <stdio.h>

int main(){
    float a1, a2, an, n, r, Sn;
    printf("Digite o primeiro termo: ");
    scanf("%f", &a1);
    printf("Digite o segundo termo: ");
    scanf("%f", &a2);
    printf("Quantos termos tem a progressão? ");
    scanf("%f", &n);  
    r = a2 - a1;
    an = a1 + ( n - 1 ) * r;
    Sn = n * ( ( a1 + an ) / 2 );
    printf("A soma de todos os termos da progressão é: %.2f\n\n", Sn);
    return 0;
}