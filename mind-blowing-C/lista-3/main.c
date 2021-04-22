#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef _WIN64
   void clear(){
      system("cls");
   }
#elif _WIN32
   void clear(){
      system("cls");
   }
#else
   void clear(){
      printf("\033c");
    }
#endif

#define RESET   "\033[0m"
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define EX05_ARRAY_LENGTH 3

int ex01();
int ex02();
int ex03();
int ex04();
int ex05();
int ex06();
int ex07();
int ex08();
int ex09();
int ex10();

int main(){
    int exec = 1, exercicio;
    while(exec == 1){
        clear();
        printf(BOLDWHITE"============Autor: Gabriel Victor Couto Martins de Paula===========\n"RESET);
        printf(BOLDWHITE"======================Selecione um exercício=======================\n"RESET);
        printf(BOLDWHITE"   [ 1 ] [ 2 ] [ 3 ] [ 14 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 10 ]\n" RESET);
        printf("                                  ");
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
            case 4:
                ex04();
            break;
            case 5:
                ex05();
            break;
            case 6:
                ex06();
            break;
            case 7:
                ex07();
            break;
            case 8:
                ex08();
            break;
            case 9:
                ex09();
            break;
            case 10:
                ex10();
            break;
            default:
                printf(BOLDWHITE"Exercício inexistente\n\n"RESET);
            break;
        }
        printf("\n\nDeseja continuar a execução?  [Sim = 1 / Não = 0]");
        scanf("%d", &exec);
        clear();
    }
}


int ex01(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex01=======================\n"RESET);
    printf("Faça um algoritmo que leia um conjunto de números [X] e imprima a quantidade de números pares [QPares] e a quantidade de números impares [QImpares] lidos. Admita que o valor 9999 é utilizado como sentinela (FLAG) para fim de leitura. Ex.: 1,2,3,4,5,9999 => Pares=2 Impares=3\n\n");
    
    
}
int ex02(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex02=======================\n"RESET);
    printf("Faça um programa que leia um conjunto indeterminado de números inteiros positivos e imprima o maior, o menor e a média aritmética desse conjunto de dados. [Flag -1].\nExecute este programa para os seguintes valores:\n\n1. 1,2,3,-1\n2. 3,2,1,-1\n3. 1,3,2,-1\n\n");


    printf("PARA INTERROMPER A LEITURA DIGITE -1;\nDigite os valores: ");

    
}
int ex03(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex03=======================\n"RESET);
    printf("Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um número lido do teclado.\nEx. Fatorial de 5! = 5x4x3x2x1=120\n");


    
}
int ex04(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex04=======================\n"RESET);
    printf("Calcule o valor da seguinte série lido a quantidade de termos:\n\nS = 1 - (1/3³) + (1/5³) - (1/3³) + (1/5³)...\n\n");

}

int ex05(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex05=======================\n"RESET);
    printf(" A série de fibonacci é formada pela seqüência:\n- 1, 2, 3, 5, 8, 13, 21, 34, ...\nEscreva um algoritmo que peça um número N maior que 2. Gere e imprima a série até este n-ésimotermo.\n");
   
}
int ex06(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex06=======================\n"RESET);
    printf("Fazer um algoritmo para calcular o valor de S, dado por, sendo o valor de N deverá se lido do teclado:\nS = + (1/N) - (2/(N-1)) + (3/(N-2)) - (4/(N-3))...(N/1)\n\n");
   
}
int ex07(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex07=======================\n"RESET);
    printf("Números palíndromos são aqueles que escritos da direita para esquerda ou da esquerda para direita tem o mesmo valor. Exemplo:929, 44, 97379. Faça um algoritmo que imprima todos os números palíndromos de 10000 a 99999.\n\n");
    
}
int ex08(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex08=======================\n"RESET);
    printf("O numero 3025 possui a seguinte característica:\n\n- 30 + 25 = 55\n- 55^2 = 3025\n\nQuantos e quais são os números de 4 dígitos possuem essa característica?\n\n");
    
}
int ex09(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex09=======================\n"RESET);
    printf("Faça um programa para um jogo de cara ou coroa. Neste caso, o jogador escolhe cara ou coroa (0 – cara e 1 – para coroa) mostre ao final de 10 tentativas, quantas foram certas e quantas erradas. (utilize o comando - para que o computador escolha o resultado).\n\n");
    
}
int ex10(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex10=======================\n"RESET);
    printf("Desenvolver um algoritmo para calcular a conta de água para a SANEAGO. O custo da água varia dependendo do tipo do consumidor -residencial, comercial ou industrial. A regra para calcular a conta é:\n\n•Residencial: R$ 75,00 de taxa mais R$ 3,50 por m3gastos;\n•Comercial: R$ 500,00 para os primeiros 80 m3gastos mais R$ 5,50 por m3gastos acima dos 80 m3;\n•Industrial: R$ 800,00 para os primeiros 100 m3gastos mas R$ 8,00 por m3gastos acima dos 100 m3;\n\n O algoritmo devera ler a conta do cliente,  seu tipo [residencial, comercial e industrial] e o seu consumo de água em metros cubos. Como resultado imprimir o valor a ser pago pelo mesmo.");
    
}