#include <stdio.h>

int main(){
    int a, b;
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);   
    printf("\nDigite o segundo numero: ");
    scanf("%d", &b);
    printf("\na =  %d  =  %d +  %d", a, a, b); 
    a = a + b;
    printf("\nb =  %d  =  %d -  %d", b, a, b);
    b = a - b;
    printf("\na =  %d  =  %d -  %d", a, a, b);
    a = a - b;
    printf("\nAgora a vale %d e b vale %d\n\n", a, b);
    return 0;
}