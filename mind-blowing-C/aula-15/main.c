#include <stdio.h>

#define RESET   "\033[0m"
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int ex01();
int ex02();
int ex03();

int main(){
    int exec = 1, exercicio;
    while(exec == 1){
        printf(BOLDWHITE"======================Selecione um exercício=======================\n"RESET);
        printf(BOLDWHITE"[ 1 ] [ 2 ] [ 3 ]\n" RESET);
        scanf("%d", &exercicio);
        switch (exercicio){
            case 1:
                ex01();
            break;
            case 2:
                ex02();
            break;
            case 3:
                ex03();
            break;
            default:
                printf(BOLDWHITE"Exercício inexistente\n\n"RESET);
            break;
        }
        printf("\n\nDeseja continuar a execução?  [Sim = 1 / Não = 0]");
        scanf("%d", &exec);
    }
    ex03();
}


int ex01(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex01=======================\n"RESET);
    printf("\nEscreva um programa para ler a idade de uma pessoa e mostrar se a pessoa é ou não maior de idade. A maioridade se estabelece ao alcançar 18  anos.\n\n");
    int idade;
    printf("Digite a idade da pessoa: ");
    scanf("%d", &idade);
    if(idade >= 18){
        printf("\nA pessoa é maior de idade.");
    }else{
        printf("\nA pessoa é maior de idade.");
    }
}
int ex02(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex02=======================\n"RESET);
    printf("Escreve um programa que leia um número e diga se esse número é par ou ímpar");
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    if(num % 2 == 0){
        printf("\nÉ PAR.");
    }else{
        printf("\nÉ IMPAR");
    }
}
int ex03(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex03=======================\n"RESET);
    printf("O cardápio de uma lanchonete é dado abaixo. Prepare um programa que o código correspondente ao item da lanchonete e mostre a descrição do item e seu valor. Caso for digitado um valor não existente mostre a mensagem código inválido\n\n");
    int item, cardapio = 1;
    while( cardapio == 1){
        printf(BOLDWHITE"----- itens do cardápio -----\n");
        printf("[ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] \n" RESET);
        printf("selecione um item: ");
        scanf("%d", &item);
        switch(item){
            case 1:
                printf(BOLDWHITE"1 - Hambúrguer...............R$ 30,00\n\n"RESET);
            break;
            case 2:
                printf(BOLDWHITE"2 - Cheeseburger.............. R$ 35,50\n\n"RESET);
            break;
            case 3:
                printf(BOLDWHITE"3 - Fritas.....................R$ 20,50\n\n"RESET);
            break;
            case 4:
                printf(BOLDWHITE"4 - Refrigerante...............R$ 10,00\n\n"RESET);
            break;
            case 5:
                printf(BOLDWHITE"5 - Milkshake..................R$ 30,00\n\n"RESET);
            break;
            default:
                printf(BOLDWHITE". – código inválido\n\n" RESET);
            break;
        }
        printf("Deseja ver outro item? [Sim = 1 / Não = 0]");
        scanf("%d", &cardapio);
    }
}