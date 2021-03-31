#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

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

int Exa();
int Exb();
int Exc();
int Exd();
int Exe();
int Exf();
int Exg();
int Exh();
int Exi();
int Exj();

void enterFunction(){
    printf("Pressione [ ENTER ] para continuar.\n");
    while(getchar()!='\n'); // option TWO to clean stdin
    getchar(); // wait for ENTER
}

int main(){
    clear();
    printf(BOLDBLUE"Autor: Gabriel Victor Couto Martins de Paula\n"RESET);
    printf(BOLDRED"As funções representam os exercícios.\n Para não ter que escrever muito mais código, as funções serão executadadas em sequencia. \n");
    printf(BOLDRED"No códico fonte vc vai identificar cada questão com o prefixo 'Ex' e a respectiva letra do exercício.\n\n"RESET);
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exa=======================\n"RESET);
    Exa();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exb=======================\n"RESET);
    Exb();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exc=======================\n"RESET);
    Exc();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exd=======================\n"RESET);
    Exd();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exe=======================\n"RESET);
    Exe();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exf=======================\n"RESET);
    Exf();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exg=======================\n"RESET);
    Exg();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exh=======================\n"RESET);
    Exh();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exi=======================\n"RESET);
    Exi();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exj=======================\n"RESET);
    Exj();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
}



int Exa(){
    printf("a. Leia um número e imprima seu sucessor.\n");
    int a;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("\n %d \n \n", a+1);
}
int Exb(){
    printf("b. Calcule a média aritmética de quatro números inteiros dados.\n");
    int a, b, c, d; 
    float media;
    printf("Digite um valor: ");
    scanf("%d", &a);
    printf("Digite outro valor: ");
    scanf("%d", &b);
    printf("Digite outro valor: ");
    scanf("%d", &c);
    printf("Digite mais um valor: ");
    scanf("%d", &d);
    media = (a + b + c + d ) / 4;
    printf("\nA média aritmética é: %.2f\n", media);
}
int Exc(){
    printf("c. Faça um algoritmo que receba 3 (três) notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas.\n");
    int n1, n2, n3, p1, p2, p3; 
    double media;
    printf("Digite os valores das notas:: \n");
    printf("\nn1: ");
    scanf("%d", &n1);
    printf("\nn1: ");
    scanf("%d", &n2);
    printf("\nn1: ");
    scanf("%d", &n3);
    printf("\nDigite os valores dos pesos respectivamente:: \n");
    printf("\np1: ");
    scanf("%d", &p1);
    printf("\np2: ");
    scanf("%d", &p2);
    printf("\np3: ");
    scanf("%d", &p3);
    media = ( ( n1 * p1 ) + ( n2 * p2 ) + ( n3 * p3 ) ) / ( p1 + p2 + p3);
    printf("\nMédia ponderada: %.2f \n\n", media );
}
int Exd(){
    printf("d. Leia uma temperatura dada na escala Celsius (C) e imprima o equivalente em Fahrenheit (F).\n");
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
}
int Exe(){
    printf("e. Faça um algoritmo que receba o salário de um funcionário e o percentual de aumento, calcule e mostre o novo salário.\n");
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
}
int Exf(){
    printf("f. Faça um algoritmo que peça ao usuário a base e a altura e calcule a área de um triangulo.\n");
    int base, altura;
    float area;
    printf("Digite a base do triangulo: ");
    scanf("%d", &base);
    printf("\nDigite a altura do triangulo: ");
    scanf("%d", &altura);
    area = ( base * altura ) / 2;
    printf("\nÁrea: %.2f\n\n", area);
}
int Exg(){
    printf("g. Pedro comprou um saco de Ração com peso em quilos. Pedro possui 2 (dois) gatos para os quais fornece a quantidade de ração em gramas. Faça um algoritmo que receba o peso do Saco de ração e a quantidade de ração fornecida para cada gato. Calcule e mostre quanto restará de ração no saco após 5 (cinco) dias. \n");
    int weight, portion;
    float rest;
    printf("Digite o peso do saco de ração(Kg): ");
    scanf("%d", &weight);
    printf("\nDigite a porção para cada gato(g): ");
    scanf("%d", &portion);
    weight = weight * 1000;
    rest = weight - portion * 2 * 5;
    rest = rest / 1000;
    if( ( rest > 0 ) || ( rest == 0 ) ){
        printf("\nRestarão %.0fKg de ração no saco após 5 dias\n\n", rest);
    }else{
        printf("\n%.0fKg é o que falta de ração para alimentar os gatos\n\n", rest * -1);
    }
}
int Exh(){
    printf("h. Ler dois números inteiros para variáveis A e B. Trocar o valor de b com o de a, e imprimi-los.\n");
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
}
int Exi(){
    printf("i. Leia um número e imprima o resto da divisão por 7. Utilize o comando resto (a,b) na linguagem C (a %% b).\n");
    int num;
    double rest;
    printf("Digite um numero: ");
    scanf("%d", &num);
    rest = num % 7;
    printf("O resto da divisão de %d por 7 é: %.2f\n\n", num, rest);
}
int Exj(){
    printf("j. Calcular a soma dos termos de uma P.A. lendo os valores do primeiro termo, do segundo termo e do número de termos.\n");
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
}