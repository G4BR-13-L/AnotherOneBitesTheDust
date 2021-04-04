#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FAlSE 0


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

int volume(float d){
    float v, r3;
    r3 = pow((d/2),2);
    v = (4*3.14*r3)/3;
    return v;
}
int ex01(){
    /*Escreva um programa que solicite ao usuário o diâmetro
     de uma esfera calcule e imprima:(a área da superfície 
     esférica e o volume da esfera.);*/
    
    //V = (4 · π · r³)/3
    //A = A = 4πr2
     
    double diameter;
    float Volume;
    printf("Digite o diâmetro da esfera(cm): ");
    scanf("%lf", &diameter);
    printf("\n");
    Volume = volume(diameter);
    printf("O volume da esfera é: %5.2fcm³ \n", Volume);
    return 0;
         

}
int ex02(){
    /*Escreva um algoritmo para mostrar na tela o resultado 
    das seguintes operações:
    a) 2>3
    b) 4=4
    c) ler os valores para (x e y) e mostrar o resultado para:
    x>y;
    y>x;
    x=y;
    d) Ler os valores de x, y, e A e mostre o resultado para:
        X² - Y³>X^(A+4) e A < 5
    e) Mostrar o resultado de:
        (-B+(B²-4AC)^0.5)/2A  e  não (A=0);
*/
    double x, y, a, b, c;
    bool logic;
    // a=========
    printf(BOLDGREEN "\na) 2 > 3: " RESET);
    printf("%d", 2 > 3);
    //b=========
    printf(BOLDGREEN "\nb) 4 = 4: " RESET); 
    printf("%d", 4 == 4);   
    //c=========
    printf(BOLDGREEN "\nc) - " ); 
    printf("\nDigite um valor para x: " RESET); 
    scanf("%lf", &x);
    printf(BOLDGREEN "\nDigite um valor para Y: " RESET);
    scanf("%lf", &y);
    printf(BOLDGREEN "\nResultado: " RESET);
    printf(BOLDGREEN "\n- x > y: " RESET); 
    printf("%d", x > y);
    printf(BOLDGREEN "\n- y > x: " RESET); 
    printf("%d", y > x);
    printf(BOLDGREEN "\n- x = y: " RESET); 
    printf("%d", x == y);
    printf("\n");
    // d==========
    printf(BOLDRED "d) X² - Y³>X^(A+4) e A < 5\n" RESET);
    printf("\nDigite um valor para X: ");
    scanf("%lf", &x);
    printf("\nDigite um valor para Y: ");
    scanf("%lf", &y);
    printf("\nDigite um valor para A: ");
    scanf("%lf", &a);
    printf(BOLDRED "\nResultado: \n" RESET);
    logic = ((pow(x,2)-pow(y,3)) > (pow(x,(a+4)))) && a<5;
    if(logic == 0){
        printf("X² - Y³>X^(A+4) e A < 5 = %d or true\n", logic);
    }else{
        printf("X² - Y³>X^(A+4) e A < 5 = %d or false\n", logic);
    }
    //e =============
    printf(BOLDRED "\ne) (-B+(B²-4AC)^0.5)/2A  e  não (A=0)\n" RESET);
    printf("\nDigite um valor para A: ");
    scanf("%lf", &a);
    printf("\nDigite um valor para B: ");
    scanf("%lf", &b);
    printf("\nDigite um valor para C: ");
    scanf("%lf", &c);
    logic = pow((-b+(pow(b,2)-4*a*c)),0.5)/2 && !(a==0);
    if(logic){
        printf("(-B+(B²-4AC)^0.5)/2A  e  não (A=0) resulta em %d ou true\n", logic);
    }else{
        printf("(-B+(B²-4AC)^0.5)/2A  e  não (A=0) resulta em %d ou false\n", logic);
    }
}

int ex03(){
    /*Escreva um algoritmo para ler dois valores (x,y) 
    escreva na tela o resultado da operação lógica que 
    verifica se a operação diferença entre eles, é igual 
    a zero.*/

    int x,y;
    bool logica;
    printf("Digite um valor para X: ");
    scanf("%d", &x);
    printf("\nDigite um valor para Y: ");
    scanf("%d", &y);
    logica = x != y;
    if(logica == 1){
        printf("X e Y são diferentes então a operação lógica resultou em 1 ou true");
    }else{
        printf("X e Y são iguais então a operação lógica resultou em 0 ou false");
    }

}
int main(){
    printf(BOLDCYAN "=============Ex01============\n" RESET);
    ex01();
    printf(BOLDCYAN "=============================\n \n");
    printf(BOLDCYAN "=============Ex02============\n" RESET);
    ex02();
    printf(BOLDCYAN "\n=============================\n \n");
    printf(BOLDCYAN "=============Ex03============\n" RESET);
    ex03();
    printf(BOLDCYAN "\n=============================\n \n");
    return 0;
}