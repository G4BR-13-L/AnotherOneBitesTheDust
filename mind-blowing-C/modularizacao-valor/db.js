var db = {
    initialCodeContent: `
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
#include <ctype.h>
#ifdef _WIN64
    #include <windows.h>
   void clear(){
      system("cls");
   }
#elif _WIN32
    #include <windows.h>
   void clear(){
      system("cls");
   }
#else
    #include <unistd.h>
   void clear(){
      printf("\\033c");
    }
#endif

#define RESET   "\\033[0m"
#define BLACK   "\\033[30m"      /* Black */
#define RED     "\\033[31m"      /* Red */
#define GREEN   "\\033[32m"      /* Green */
#define YELLOW  "\\033[33m"      /* Yellow */
#define BLUE    "\\033[34m"      /* Blue */
#define MAGENTA "\\033[35m"      /* Magenta */
#define CYAN    "\\033[36m"      /* Cyan */
#define WHITE   "\\033[37m"      /* White */
#define BOLDBLACK   "\\033[1m\\033[30m"      /* Bold Black */
#define BOLDRED     "\\033[1m\\033[31m"      /* Bold Red */
#define BOLDGREEN   "\\033[1m\\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\\033[1m\\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\\033[1m\\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\\033[1m\\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\\033[1m\\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\\033[1m\\033[37m"      /* Bold White */

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
        printf(BOLDWHITE"============Autor: Gabriel Victor Couto Martins de Paula===========\\n"RESET);
        printf(BOLDWHITE"======================Selecione um exercício=======================\\n"RESET);
        printf(BOLDWHITE"   [ 1 ] [ 2 ] [ 3 ] [ 14 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 10 ]\\n" RESET);
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
                printf(BOLDWHITE"Exercício inexistente\\n\\n"RESET);
            break;
        }
        printf("\\n\\nDeseja continuar a execução?  [Sim = 1 / Não = 0]");
        scanf("%d", &exec);
        clear();
    }
}`,
    questions: [
        `Elabore um procedimento para calcular o Fatorial de um número passado por parâmetro. A resposta deverá ser retornada em uma variável definida como global de nome FAT. Faça também um programa principal que chame esse procedimento.`,
        `Elabore um procedimento que receba um valor passado por parâmetro. Esse procedimento deverá devolver na variável global Fibo termo correspondente ao valor passado da serie de Fibonacci. Exemplo suponha que seja passado o valor 6, então deverá retorna o 6º termo da série ou seja 1,1,2,3,5,8, ou seja, deverá atribuir a variável Fibo valor 8.`,
        `Elabore um procedimento que receba um valor passado por parâmetro. Esse procedimento deverá devolver na variável global Fiba soma dos termos da serie de Fibonacci do primeiro termo até o termo passado. Exemplo suponha que seja passado o valor 6, então deverá atribuir a variável Fiba soma de 1+1+2+3+5+8, ou seja, Fib= 20.`,
        `Elabore um procedimento que receba dois valores passados por parâmetro. Esse procedimento  deverá atribuir a variável impar, a quantidade de números ímpares entre o intervalo fechado correspondente aos valores passados. Por exemplo, suponha que os valores passados seja, 3 e 6, deverá devolver impar=2, pois existem os números impares 3 e 5 no intervalo.`,
        `Elabore um procedimento que receba dois valores passados por parâmetro. Esse procedimento  deverá atribuir a variável impar, a soma dos números ímpares entre o intervalo fechado correspondente aos valores passados. Por exemplo, suponha que os valores passados seja, 3 e 6, deverá devolver impar=8, pois a soma dos números impares 3 e 5 no intervalo é 8.`,
    ],
}