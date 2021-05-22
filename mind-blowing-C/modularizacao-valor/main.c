

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
#include <ctype.h>
#ifdef _WIN64
#include <windows.h>
void clear()
{
    system("cls");
}
#elif _WIN32
#include <windows.h>
void clear()
{
    system("cls");
}
#else
#include <unistd.h>
void clear()
{
    printf("\033c");
}
#endif

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#define EX05_ARRAY_LENGTH 3

int ex01();
int ex02();
int ex03();
int ex04();
int ex05();

int main()
{
    int exec = 1, exercicio;
    while (exec == 1)
    {
        clear();
        printf(BOLDWHITE "============Autor: Gabriel Victor Couto Martins de Paula===========\n" RESET);
        printf(BOLDWHITE "======================Selecione um exercício=======================\n" RESET);
        printf(BOLDWHITE "                  [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] \n" RESET);
        printf("                                  ");
        scanf("%d", &exercicio);
        switch (exercicio)
        {
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
        default:
            printf(BOLDWHITE "Exercício inexistente\n\n" RESET);
            break;
        }
        printf("\n\nDeseja continuar a execução?  [Sim = 1 / Não = 0]");
        scanf("%d", &exec);
        clear();
    }
}

int somaImpar(int min, int max)
{
    int somaImpares = 0;
    if (min % 2 == 0)
    {
        min++;
    }
    if (max % 2 == 0)
    {
        max--;
    }
    somaImpares = min + max;
    return somaImpares;
}
int ex01()
{
    printf(BOLDWHITE "================================================\n" RESET);
    printf(BOLDWHITE "======================Ex01=======================\n" RESET);
    printf("Elabore um procedimento que receba dois valores passados por parâmetro. Esse procedimento  deverá atribuir a variável impar, a soma dos números ímpares entre o intervalo fechado correspondente aos valores passados. Por exemplo, suponha que os valores passados seja, 3 e 6, deverá devolver impar=8, pois a soma dos números impares 3 e 5 no intervalo é 8.\n\n");

    int min = 0, max = 0, soma = 0;
    do
    {
        printf("\nDigite um numero mínimo para o intervalo: ");
        scanf("%d", &min);
        printf("\nDigite um numero máximo para o intervalo: ");
        scanf("%d", &max);
        if (min >= max)
        {
            printf(BOLDRED "\n====ERRO====\nDigite valores válidos\n==========" RESET);
        }
        else
        {
            printf(BOLDGREEN "\n\nIntervalo: [ %d , %d ]" RESET, min, max);
        }
    } while (min >= max);

    soma = somaImpar(min, max);

    printf("\n A Soma do valores impares no intervalo é: [ %d ]", soma);
}
/*=======================================================================*/
int numerosDeImpares(int min, int max)
{
    int nImpares = 0;
    for (int i = min; i <= max; i++)
    {
        if (i % 2 == 1)
        {
            nImpares++;
        }
    }
    return nImpares;
}
int ex02()
{
    printf(BOLDWHITE "================================================\n" RESET);
    printf(BOLDWHITE "======================Ex02=======================\n" RESET);
    printf("Elabore um procedimento que receba dois valores passados por parâmetro. Esse procedimento  deverá atribuir a variável impar, a quantidade de números ímpares entre o intervalo fechado correspondente aos valores passados. Por exemplo, suponha que os valores passados seja, 3 e 6, deverá devolver impar=2, pois existem os números impares 3 e 5 no intervalo.\n\n");
    int min = 0, max = 0, nImpares = 0;
    do
    {
        printf("\nDigite um numero mínimo para o intervalo: ");
        scanf("%d", &min);
        printf("\nDigite um numero máximo para o intervalo: ");
        scanf("%d", &max);
        if (min >= max)
        {
            printf(BOLDRED "\n====ERRO====\nDigite valores válidos\n==========" RESET);
        }
        else
        {
            printf(BOLDGREEN "\n\nIntervalo: [ %d , %d ]" RESET, min, max);
        }
    } while (min >= max);

    nImpares = numerosDeImpares(min, max);
    printf("\n A quantidade de valores impares no intervalo é: [ %d ]", nImpares);
}
/*=======================================================================*/

int somaFibonacci(int nTermos)
{
    int num = 1, ultimo = 1, penultimo = 0;
    int soma = 0;
    printf(BOLDWHITE "[ ");
    for (int i = nTermos; i > 0; i--)
    {
        printf("%d, ", num);
        soma += num;
        num = ultimo + penultimo;
        penultimo = ultimo;
        ultimo = num;
    }
    printf("]");
    return soma;
}
int ex03()
{
    printf(BOLDWHITE "================================================\n" RESET);
    printf(BOLDWHITE "======================Ex03=======================\n" RESET);
    printf("Elabore um procedimento que receba um valor passado por parâmetro. Esse procedimento deverá devolver na variável global Fiba soma dos termos da serie de Fibonacci do primeiro termo até o termo passado. Exemplo suponha que seja passado o valor 6, então deverá atribuir a variável Fiba soma de 1+1+2+3+5+8, ou seja, Fib= 20.\n\n");

    int Fiba = 0, nFiba;
    printf("Digite o numero de termos da serie de fibonacci: ");
    scanf("%d", &nFiba);

    Fiba = somaFibonacci(nFiba);
    printf(BOLDGREEN "\nSoma dos termos: [ %d ]" RESET, Fiba);
}
/*==========================================================*/
int selecionaNumero(int nPosition)
{
    int num = 1, ultimo = 1, penultimo = 0;
    int soma = 0;
    printf(BOLDWHITE "[ ");
    for (int i = 0; i < nPosition-1; i++){
        printf("%d, ", num);
        num = ultimo + penultimo;
        penultimo = ultimo;
        ultimo = num;
    }
    printf("%d, ", num);
    printf("]");
    return num;
}
int ex04()
{
    printf(BOLDWHITE "================================================\n" RESET);
    printf(BOLDWHITE "======================Ex04=======================\n" RESET);
    printf("Elabore um procedimento que receba um valor passado por parâmetro. Esse procedimento deverá devolver na variável global Fibo termo correspondente ao valor passado da serie de Fibonacci. Exemplo suponha que seja passado o valor 6, então deverá retorna o 6º termo da série ou seja 1,1,2,3,5,8, ou seja, deverá atribuir a variável Fibo valor 8.\n\n");

    int Fibo = 0, nFibo;
    printf("Digite a posição do termo na serie de fibonacci: ");
    scanf("%d", &nFibo);

    Fibo = selecionaNumero(nFibo);
    printf(BOLDGREEN "\nNumero da posição %d de Fibonacci: [ %d ]" RESET, nFibo, Fibo);
}

/*========================================================================*/

int fatorial(int numero){
    int fatorial = 0;
    for(int i = numero; i > 0 ; i--){
        fatorial *= numero;
    }
    return fatorial;
}
int ex05(){
    printf(BOLDWHITE "================================================\n" RESET);
    printf(BOLDWHITE "======================Ex05=======================\n" RESET);
    printf("Elabore um procedimento para calcular o Fatorial de um número passado por parâmetro. A resposta deverá ser retornada em uma variável definida como global de nome FAT. Faça também um programa principal que chame esse procedimento.\n\n");
    int numero = 0;
    printf("Digite uma numero para que seja calculado seu fatorial: ");
    scanf("%d", &numero);
    int FAT = fatorial(numero);
    printf("\nO fatorial de %d é: [ %d ]", numero, FAT);
}