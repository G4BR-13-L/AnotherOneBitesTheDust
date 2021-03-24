#include <stdio.h>
#include <math.h>
/**
 *1.Escreva um programa que solicite ao usuário a altura e o raio de um cilindro circular e imprima o volume do cilindro. O volume de um cilindro circular é calculado por meio da seguinte fórmula:Vol= PI * raio2* altura **/
int main(){
	printf("============LANCHONETE=========== \n");
    printf("Hambúrguer...............R$ 30,00 \n");
    printf("Cheeseburger.............R$ 35,50 \n");
    printf("Fritas...................R$ 20,50 \n");
    printf("Refrigerante.............R$ 10,00 \n");
    printf("Milkshake................R$ 30,00 \n");
    int quantidade[5], i;
    float total;
    for(i = 0; i<5 ; i++){
        switch (i){
        case 0:
            printf("Quantos hamburgueres você consumiu? ");
            scanf("%d", &quantidade[i]);
            printf("\n");
            total = total + (quantidade[i]*30);
            break;
        case 1:
            printf("Quantos cheeseburgueres você consumiu? ");
            scanf("%d", &quantidade[i]);
            printf("\n");
            total = total + (quantidade[i]*35.5);
            break;
        case 2:
            printf("Quantos fritas você consumiu? ");
            scanf("%d", &quantidade[i]);
            printf("\n");
            total = total + (quantidade[i]*20.5);
            break;
        case 3:
            printf("Quantos refrigerantes você consumiu? ");
            scanf("%d", &quantidade[i]);
            printf("\n");
            total = total + (quantidade[i]*10);
            break;
        case 4:
            printf("Quantos milkshakes você consumiu? ");
            scanf("%d", &quantidade[i]);
            printf("\n");
            total = total + (quantidade[i]*30);
            break;
        
        default:
            i--;
            break;
        }
        
    }
    printf("R$%5.2f \n\n",total);
    return 0;

}