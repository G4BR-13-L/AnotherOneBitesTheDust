#include <stdio.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
int main(){

    int mat[5][5], a = 0, b = 0 , c = 0;
    printf("Digite uma valor para A: ");
    scanf("%d", &a);
    printf("\vDigite uma valor para B: ");
    scanf("%d", &b);
    printf("\vDigite uma valor para C: ");
    scanf("%d", &c);
    for( int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(j > i){
                mat[i][j] = a;
            }
        }
    }
    for( int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(j == i){
                mat[i][j] = c;
            }
        }
    }
    for( int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(j < i){
                mat[i][j] = b;
            }
        }
    }


    for( int i = 0 ; i < 5 ; i++){
        printf(BOLDGREEN"| ");
        for(int j = 0 ; j < 5 ; j++){
             printf(" [%d] ",mat[i][j]);
        }
        printf(" |\n"RESET);
    }

}

