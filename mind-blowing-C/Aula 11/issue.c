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
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int teste(){
    printf("Olá mundo: ");
    char c;
    scanf("%c", &c);
    fflush(stdin);
    return 0;
}

//------

int main(){
    //printf(BOLDBLUE"Autor: Gabriel Victor Couto Martins de Paula\n"RESET);
    //printf(BOLDRED"As funções representam os exercícios.\n Para não ter que escrever muito mais código, as funções serão executadadas em sequencia. \n");
    //printf(BOLDRED"No códico fonte vc vai identificar cada questão com o prefixo 'Ex' e a respectiva letra do exercício.\n\n"RESET);
    //printf(BOLDWHITE"================================================\n"RESET);
    //printf(BOLDWHITE"======================Exa=======================\n"RESET);
    teste();
    char c;
    scanf("%c", &c);
    while( c != '\n'){
        printf("Pressione ENTER: ");
        scanf("%c", &c);
        fflush(stdin);
    }

    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Exb=======================\n"RESET);
    teste();
    clear();
    printf(BOLDWHITE"================================================\n"RESET);
    return 0;
}