#include <stdio.h>
#include <math.h>
/**
 *1.Escreva um programa que solicite ao usuário a altura e o raio de um cilindro circular e imprima o volume do cilindro. O volume de um cilindro circular é calculado por meio da seguinte fórmula:Vol= PI * raio2* altura **/
int main(){
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
