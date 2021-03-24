#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


int salarioLiquido(){
    int dias;
	float salarioLiquido, salarioBruto;
	printf("Quantos dias o encanador trabalhou? ");
	scanf("%i", &dias);
	printf("\n");
	salarioBruto = 20*dias;
	printf("Salário bruto: %5.2f \n", salarioBruto);
	salarioLiquido = salarioBruto*0.92;
	printf("O salário líquido do encanador será de: %5.2f \n", salarioLiquido);
	return 0;
}
int media(){
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
int volumeDoCilindro(){
    float r,h,volume,y,areaBase;
	printf("Digite o valor da altura: ");
	scanf("%f", &h);
	printf("\n");
	printf("Digite o raio da base: ");
        scanf("%f", &r);
        printf("\n");
	y = r*r;
	areaBase = y*3.14195;
	volume = areaBase*h;
	printf("O volume do cilindro é igual a %5.4f \n",volume);
	return 0;

}

int lanchonete(){
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

int main(){
    printf(BOLDCYAN "============MÉDIA============\n" RESET);
    media();
    printf(BOLDCYAN "=============================\n \n");
    printf(BOLDCYAN "======VOLUME DO CILINDRO======\n" RESET);
    volumeDoCilindro();
    printf(BOLDCYAN "=============================\n \n");
    printf(BOLDCYAN "======SALÁRIO LIQUIDO======\n" RESET);
    salarioLiquido();
    printf(BOLDCYAN "=============================\n \n");
    printf(BOLDCYAN "==========LANCHONETE=========\n" RESET);
    lanchonete();
    printf(BOLDCYAN "=============================\n \n");

}