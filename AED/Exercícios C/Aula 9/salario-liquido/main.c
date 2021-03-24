#include <stdio.h>
#include <math.h>
/**2.Uma empresa contrata um encanador a R$ 20.00 por dia. Crie um programa que solicite o número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga, sabendo-se que são descontados 8% de impostos.**/

int main(){
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
