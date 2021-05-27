#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef _COLORS_
#define _COLORS_

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KWHT  "\x1B[37m"

#define FGRN(x) KGRN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif  /* _COLORS_ */

int main(){
    cout << BOLD(FGRN("=====================================\nCódigo feito por Gabriel Victor Couto\nEngenharia de software - PUC Minas\n=====================================\n\n"));
    
    cout << BOLD("Esse programa serve para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Ele também indica ao final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo usuário em no máximo 10 tentativas! Através de um número intermediário o programa pergunta ao usuário se o número é igual(=), maior(>) ou menor(<) que o que foi escolhido.\n\n");

    int tentativas = 0, num = 512, aleatorio = 0, resposta = 0, correto = 0;

    do{
        if(correto == 0 && tentativas < 10){
            resposta = 0;
            while(resposta <= 0 || resposta > 3){
                cout << "\nO numero que você está pensando é maior, menor ou igual a " << num << " ?" ;
                cout <<"\n[ Maior: 1 | Menor: 2 | Igual: 3 ] : ";
                cin >> resposta ;
                if(resposta <= 0 || resposta > 3){
                    cout << BOLD("\n\n===========Por favor digite valores válidos============\n");
                    resposta = 0;
                }
            }
            switch (resposta){
                case 1:
                    do{
                        aleatorio = num + rand() % 1023 ;
                    }while( aleatorio < num || aleatorio > 1024 );
                    num = aleatorio;
                break;
                case 2:
                    do{
                        aleatorio = 1 + rand() % num;
                    }while( aleatorio > num || aleatorio < 1 );
                    num = aleatorio;
                break;
                case 3:
                    correto = 1;
                break;
                default:
                    cout << "\n=====ERRO DE PROGRAMAÇÃO=====";
                break;
            }
        }else if(correto == 1 && tentativas <= 10){
                cout << BOLD("\nO numero é: " << num << "\nAcertei depois de " << tentativas -1 << " tentativas.");
                tentativas = 12;
        }else if(correto == 0 || tentativas > 10){
                cout << BOLD("\nNão consegui adivinhar o seu número com as tentativas programadas ;-;");
        }else{
                cout << BOLD("\n=====ERRO DE PROGRAMAÇÃO=====");
        }
        tentativas++;   
        
    }while(tentativas <= 10);
    cout << BOLD("\n\n\nFIM!!\n\n\n");
    
}