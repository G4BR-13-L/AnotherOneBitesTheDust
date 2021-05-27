#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>
#include <ctype.h>

#define RESET "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDWHITE  "\033[1m\033[37m"      /* Bold White */

int main(){
    printf(BOLDGREEN"=====================================\nCódigo feito por Gabriel Victor Couto\nEngenharia de software - PUC Minas\n=====================================\n\n"RESET);
    
    printf(BOLDWHITE"Esse programa serve para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Ele também indica ao final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo usuário em no máximo 10 tentativas! Através de um número intermediário o programa pergunta ao usuário se o número é igual(=), maior(>) ou menor(<) que o que foi escolhido."RESET);

    int tentativas = 0, num = 512, aleatorio, resposta = 0, correto = 0;
    srand(time(NULL));

    do{
        if(correto == 0 && tentativas < 10){
            resposta = 0;
            while(resposta <= 0 || resposta > 3){
                printf("\nO numero que você está pensando é maior, menor ou igual a %d?", num)  ;
                printf("\n[ Maior: 1 | Menor: 2 | Igual: 3 ] : ");
                scanf("%d",&resposta);
                if(resposta <= 0 || resposta > 3){
                    printf(BOLDWHITE"\n\n===========Por favor digite valores válidos============\n"RESET);
                    resposta = 0;
                }
            }
            switch (resposta){
                case 1:
                    do{
                        aleatorio = rand() % 1023 + num;
                    }while( aleatorio < num || aleatorio > 1024 );
                    num = aleatorio;
                break;
                case 2:
                    do{
                        aleatorio = rand() % num + 1;
                    }while( aleatorio > num || aleatorio < 1 );
                    num = aleatorio;
                break;
                case 3:
                    correto = 1;
                break;
                
                default:
                printf(BOLDWHITE"\n=====ERRO DE PROGRAMAÇÃO====="RESET);
                    break;
            }
        }else if(correto == 1 && tentativas <= 10){
                printf(BOLDWHITE"\nO numero é: %d\nAcertei depois de %d tentativas"RESET, num, tentativas - 1);
                tentativas = 12;
        }else if(correto == 0 || tentativas > 10){
                printf(BOLDWHITE"\nNão consegui adivinhar o seu número com as tentativas programadas ;-;"RESET);
        }else{
                printf(BOLDWHITE"\n=====ERRO DE PROGRAMAÇÃO====="RESET);
        }
        tentativas++;   
        
    }while(tentativas <= 10);
    printf(BOLDWHITE"\n\n\nFIM!!\n\n\n"RESET);
    
}