#include <stdio.h>
#include <math.h>

int main(){
    int c;
    float f, verification;
    printf("Digite o valor em °C: ");
    scanf("%d", &c);
    f = ( (c * 9) / 5 ) + 32;
    verification = round(( f - 32 ) * 5 / 9);
    if( verification == c){
        printf("O valor em Fahrenheit é: %.f°\n\n", f);
        printf("\nverificação: %.2f°\n", verification);
    }else{
        printf("O programa flahou, e a formula não foi utilizada corretamente\n");
        printf("\nf: %.2f°", f);
        printf("\nverificação: %.2f°\n", verification);       
    }
    return 0;

}