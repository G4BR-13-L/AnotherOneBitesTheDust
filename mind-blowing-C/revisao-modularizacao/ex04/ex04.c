#include <stdio.h>
#include <stdlib.h>

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
      printf("\033c");
    }
#endif

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/* ====================     VARIAVEIS GLOBAIS ===================== */
float auxiliar = 1;
float divisor = 2;
float operacao = 0;
int a = 0, b = 1, n = 0;
/* =============================================================== */
int fazerOperacao(); //Prototipação da função

int main(){
    clear();
    
    fazerOperacao();
    
    return 0;

}

int fazerOperacao(){
    
    printf(BOLDWHITE"Digite a quantidade de termos: "RESET);
    scanf("%d", &n);
    n++;
    printf(" [%1.0f/%1.0f] ", auxiliar, divisor);
    printf("+");
    operacao = auxiliar / divisor;
    auxiliar = a + b;
    a = b;
    b = auxiliar;
    divisor+=2;

    for (int i = 3; i <= n; i++){

        if( i % 2 == 1 ){
            printf(" [%1.0f/%1.0f] ", auxiliar, divisor);
            printf("-");
            operacao += auxiliar / divisor;
            auxiliar = a + b;
            a = b;
            b = auxiliar;
            divisor+=2;
        }else{
            printf(" [%1.0f/%1.0f] ", auxiliar, divisor);
            printf("+");
            operacao -= auxiliar / divisor;
            auxiliar = a + b;
            a = b;
            b = auxiliar;
            divisor+=2;
        }

    }
    printf( BOLDGREEN"\n\nResultado final da operação: %.5f\n\n" RESET, operacao);
}

