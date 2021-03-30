#include <stdio.h>
#include <math.h>

int main(){
    int salario, percentual;
    double aumento, novoSalario;
    printf("Digite o valor do salário: ");
    scanf("%d", &salario); 
    printf("\nDigite o percentual de aumento: ");
    scanf("%d", &percentual);
    aumento = salario * percentual / 100;
    novoSalario = salario + aumento;
    printf("\nValor do aumento: %5.2f", aumento);
    printf("\nO salário com aumento: %5.2f\n", novoSalario);
    return 0;

}