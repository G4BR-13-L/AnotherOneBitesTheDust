#include <stdio.h>

int oneNumber();
int tenNumber();
int main(){
    int option = 0;
    do{
        printf("O que voce deseja? \n\n");
        printf("1 –tabuada de um número \n2 –tabuada dos números de 1 a 9 \n9 –fim do programa\n\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            oneNumber();
        break;
        case 9:
            option = 9;
        break;
        case 2:
            tenNumber();
        break;
        default:
            option = 0;
        break;
        }
    }while(option != 9);
}

int oneNumber(){
    int num;
    printf("\nDigite o numero: ");
    scanf("%d", &num);
    for(int i = 1 ; i<=9 ; i++){
        printf("%i * %i = %i\n", num, i, num * i);
    }

}
int tenNumber(){
    printf("Tabuada de 1\n");
    for(int i = 1 ; i<=9 ; i++){
        for(int j = 1 ; j <=9 ; j++){
            printf("%i * %i = %i\n", i, j, i * j);
        }
        printf("Tabuada de %i\n", i++);
    }
}