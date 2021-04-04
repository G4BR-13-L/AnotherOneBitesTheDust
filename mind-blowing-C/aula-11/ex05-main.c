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
int ex11();
int ex12();
int ex13();
int ex14();
int ex15();

void enterFunction(){
    printf("Pressione [ ENTER ] para continuar.\n");
    while(getchar()!='\n'); // option TWO to clean stdin
    getchar(); // wait for ENTER
}

int main(){
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex01=======================\n"RESET);
    //ex01();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex02=======================\n"RESET);
    //ex02();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex03=======================\n"RESET);
    //ex03();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex04=======================\n"RESET);
    //ex04();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex05=======================\n"RESET);
    //ex05();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex06=======================\n"RESET);
    //ex06();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex07=======================\n"RESET);
    //ex07();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex08=======================\n"RESET);
    //ex08();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex09=======================\n"RESET);
    //ex09();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex10=======================\n"RESET);
    //ex10();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex11=======================\n"RESET);
    //ex11();
    //enterFunction();
    //clear();
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Ex12=======================\n"RESET);
    //ex12();
    //enterFunction();
    //clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex13=======================\n"RESET);
    ex13();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex14=======================\n"RESET);
    ex14();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex15=======================\n"RESET);
    ex15();
    enterFunction();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
}

int ex01(){
    printf("1. Ler um valor inteiro do teclado e dizer se é par\n\n");
    int num, r;
    printf("Digite um número: ");
    scanf("%d", &num);
    r = num % 2 == 0;
    printf("\n é par: %d", r);
}
int ex02(){
    printf("2. Ler um valor inteiro do teclado e dizer se é ímpar\n\n");
    int num, r;
    printf("Digite um número: ");
    scanf("%d", &num);
    r = num % 2 == 1;
    printf("\n é ímpar: %d", r);
}
int ex03(){
    printf("3. ler um valor inteiro do teclado e dizer se ímpar e maior que 100.\n\n");
    int num, r;
    printf("Digte um número: ");
    scanf("%d", &num);
    r = num % 2 == 1;
    printf("\né ímpar: %d",r);
    r = num > 100;
    printf("\né maior que 100: %d",r);
}
int ex04(){
    printf("4. ler um valor inteiro do teclado e dizer se é par e menor que 100, ou ímpar e maior que 100.\n\n");
    int num, r;
    printf("Digte um número: ");
    scanf("%d", &num);
    r = num % 2 == 1;
    printf("\né ímpar: %d",r);
    r = num > 100;
    printf("\né maior que 100: %d",r);
    r = num % 2 == 0;
    printf("\né par: %d",r);
    r = num < 100;
    printf("\né menor que 100: %d",r);
}
int ex05(){
    printf("5. ler um valor inteiro do teclado e dizer se pertence ao intervalo aberto entre (25:75).\n\n");
    int num, r;
    printf("Digte um número: ");
    scanf("%d", &num);
    r = num >= 25;
    printf("\né igual ou maior a 25: %d",r);
    r = num <= 75;
    printf("\né igual ou meno a 75: %d",r);
    r = num >= 25 && num <= 75;
    printf("\nestá no intervalo: %d",r);
}
int ex06(){
    printf("6. ler um valor inteiro do teclado e dizer se pertence ao intervalo fechado entre [25:75].\n\n");
    int num, r;
    printf("Digte um número: ");
    scanf("%d", &num);
    r = num > 25;
    printf("\né maior a 25: %d",r);
    r = num <= 75;
    printf("\né igual ou menor a 75: %d",r);
    r = num > 25 && num <= 75;
    printf("\nestá no intervalo: %d",r);
}
int ex07(){
    printf("7. ler um valor inteiro do teclado e dizer se pertence aos intervalos fechados [15:45] ou [66:99]\n\n");
    int num, r;
    printf("Digte um número: ");
    scanf("%d", &num);
    r = num > 15;
    printf("\né maior a 15: %d",r);
    r = num <= 45;
    printf("\né igual ou menor a 75: %d",r);
    r = num > 15 && num <= 45;
    printf("\nestá no intervalo [15:45]: %d",r);
    r = num > 66;
    printf("\né maior a 66: %d",r);
    r = num <= 99;
    printf("\né igual ou menor a 99: %d",r);
    r = num > 66 && num <= 99;
    printf("\nestá no intervalo [66:99]: %d",r);
}
int ex08(){
    printf("8. ler dois valores inteiros do teclado e dizer se o primeiro é par e o segundo é ímpar.\n\n");
    int num1, num2,r;
    printf("Digte um número: ");
    scanf("%d", &num1);
    printf("\nDigte outro número: ");
    scanf("%d", &num2);
    r = num1 % 2 == 0;
    printf("\n%d é par: %d", num1, r);
    r = num2 % 2 == 1;
    printf("\n%d é ímpar: %d",num2, r);
}
int ex09(){
    printf("9. ler dois valores inteiros do teclado e dizer se o primeiro é par e positivo, e o segundo é ímpar e negativo.\n\n");
    int num1, num2, r;
    printf("Digte um número: ");
    scanf("%d", &num1);
    printf("\nDigte outro número: ");
    scanf("%d", &num2);
    r = num1 % 2 == 0 && num1 > 0;
    printf("\n%d é par e positivo: %d", num1, r);
    r = num2 % 2 == 1 && num2 < 0;
    printf("\n%d é ímpar e negativo: %d",num2, r);
}
int ex10(){
    printf("10. ler dois valores reais do teclado e dizer se o primeiro é maior, menor ou igual ao segundo.\n\n");
    double num1, num2;
    int r;
    printf("Digte um número: ");
    scanf("%lf", &num1);
    printf("\nDigte outro número: ");
    scanf("%lf", &num2);
    r = num1 > num2;
    printf("\n é maior: %d \n\n", r);
    r = num1 == num2;
    printf("\n é igual: %d \n\n", r);
    r = num1 < num2;
    printf("\n é menor: %d \n\n", r);
    
    
}
int ex11(){
    printf("11. ler três valores reais do teclado e dizer se o primeiro está entre os outros dois\n\n");
    double num1, num2, num3;
    int r;
    printf("Digte um número: ");
    scanf("%lf", &num1);
    printf("\nDigte outro número: ");
    scanf("%lf", &num2);
    printf("\nDigte mais um número: ");
    scanf("%lf", &num3);
    r = ( num1 > num2 && num1 < num3 ) || ( num1 > num3 && num1 < num2 );
    printf("%f está entre %f e %f: %d", num1, num2, num3, r);
}
int ex12(){
    printf("12. ler três valores reais do teclado e dizer se o primeiro não está entre os outros dois\n\n");
    double num1, num2, num3;
    int r;
    printf("Digte um número: ");
    scanf("%lf", &num1);
    printf("\nDigte outro número: ");
    scanf("%lf", &num2);
    printf("\nDigte mais um número: ");
    scanf("%lf", &num3);
    r = ( num1 < num2 && num1 < num3 ) || ( num1 > num2 && num1 > num3 );
    printf("%f não está entre %f e %f: %d", num1, num2, num3, r);
}
int ex13(){
    printf("13. ler três valores literais (caracteres) do teclado e dizer se o primeiro está entre os outros dois\n\n");
    char car1, car2, car3;
    int r;
    printf("Digte um caractere: ");
    scanf("%c%*c", &car1);
    printf("\nDigte outro caractere: ");
    scanf("%c%*c", &car2);
    printf("\nDigte mais um caractere: ");
    scanf("%c%*c", &car3);
    r = ( car1 > car2 && car1 < car3 ) || ( car1 > car3 && car1 < car2 );
    printf("\n%c está entre %c e %c: %d\n", car1, car2, car3, r);
}
int ex14(){
    printf("14. ler três valores literais (caracteres) do teclado e dizer se estão em ordem crescente lexicograficamente.\n\n");
}
int ex15(){
    printf("15. ler um valor literal (caractere) do teclado e dizer se é uma letra maiúscula.\n\n");
}