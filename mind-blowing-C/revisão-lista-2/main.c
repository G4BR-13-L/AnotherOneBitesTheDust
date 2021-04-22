#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int ex;
    setlocale(LC_ALL, "portuguese");
    printf("[1]Exercício 01\n[2]Exercício 02\n[3]Exercício 03\n[4]Exercício 04\n[5]Exercício 05\n[6]Exercício 06\n[7]Exercício 07\n[8]Exercício 08\n[9]Exercício 09\n[10]Exercício 10\n");
    printf("Digite um número para escolher o exercício: \n");
    scanf("%d",&ex);
    printf("\n------------------------------------------------\n");
    switch(ex){
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
            printf("Por favor, selecione um número válido (1 a 10)");
    }
    printf("\n------------------------------------------------\n");
    return 0;
}

int ex01(){
    int num;
    int verify;
    printf("Digite um número para verificar se ele é par ou ímpar: \n");
    scanf("%d",&num);
    printf("O número %d é %s\n",num,num % 2  == 0 ? "Par" : "Ímpar");
    return 0;
}

int ex02(){
    char nome[20];
    int n1,n2,n3;
    float media;
    printf("Digite seu nome:\n");
    scanf("%s",nome);
    printf("Digite a nota 1 do aluno: \n");
    scanf("%d",&n1);
    printf("Digite a nota 2 do aluno: \n");
    scanf("%d",&n2);
    printf("Digite a nota 3 do aluno: \n");
    scanf("%d",&n3);

    media = (n1 + n2 + n3) / 3;
    printf("A média é %.1f, %s foi %s \n",media,nome,media >= 6 ? "Aprovado" : "Reprovado");
    return 0;
}

int ex03(){
    float temp;
    printf("Digite a temperatura da água:\n");
    scanf("%f",&temp);
    if(temp < 0){
        printf("Água em estado sólido\n");
    }
    if(temp == 0 || temp < 100){
        printf("Água em estado líquido\n");
    }
    else{
        printf("Água em estado gasoso\n");
    }
    return 0;
}

int ex04(){
    int x,y;
    printf("Digite o valor de x:\n");
    scanf("%d",&x);
    if(x < 0){
        x = pow(x,2);
        y = x + 4;
    }
    else{
        if(x>0){
            x = pow(x,3);
            y = x - 3;
        }
        else{
            printf("Erro,X deve ser diferente de 0\n");
        }
    }
    printf("y = %d\n",y);
    return 0;
}

int ex05(){
    int n1,n2,n3;
    printf("Digite um valor:\n");
    scanf("%d",&n1);
    printf("Digite outro valor:\n");
    scanf("%d",&n2);
    printf("Digite outro valor:\n");
    scanf("%d",&n3);
    if(n1 > n2 && n1 > n3 && n2 < n3)
    {
        printf("C = %d\n", n1);
        printf("B = %d\n", n3);
        printf("A = %d\n", n2);
    }else if (n1 > n2 && n1 > n3 && n3 < n2){
        printf("C = %d\n", n1);
        printf("B = %d\n", n2);
        printf("A = %d\n", n3);
    }else if (n2 > n1 && n2 > n3 && n1 < n3){
        printf("C = %d\n", n2);
        printf("B = %d\n", n3);
        printf("A = %d\n", n1);
    }else if (n2 > n1 && n2 > n3 && n3 < n1){
        printf("C = %d\n", n2);
        printf("B = %d\n", n1);
        printf("A = %d\n", n3);
    }else if (n3 > n1 && n3 > n2 && n2 < n1){
        printf("C = %d\n", n3);
        printf("B = %d\n", n1);
        printf("A = %d\n", n2);
    }else if (n3 > n1 && n3 > n2 && n1 < n2){
        printf("C = %d\n", n3);
        printf("B = %d\n", n2);
        printf("A = %d\n", n1);
    }

}

int ex06(){
    int x,y,z;
    printf("Digite um valor:\n");
    scanf("%d",&x);
    printf("Digite outro valor:\n");
    scanf("%d",&y);
    printf("Digite outro valor:\n");
    scanf("%d",&z);

    if(x % y == 0 && x % z == 0){
        printf("O número %d é divísivel por %d e %d\n",x,y,z);
    }
    else if(x % y == 0 && x % z != 0){
        printf("O número %d é divísivel por %d e não por %d\n",x,y,z);
    }
    else if(x % y != 0 && x % z == 0){
        printf("O número %d é divísivel por %d e não por %d\n",x,z,y);
    }
    else{
        printf("O número %d não é divísivel nem por %d e nem por %d\n",x,y,z);
    }
    return 0;
}

int ex07(){
    int num,n1,n2,n3,n4,aux,sum,result;
    printf("Digite um número para verificar se ele possui esta característica:\n");
    scanf("%d",&num);
    if(num < 999){
        printf("O número %d é menor do que 1000.\n",num);
        return 0;
    }

    n1 = num / 1000;  
    aux = num % 1000; 
    n2 = aux / 100; 
    aux = num % 100; 
    n3 = aux / 10; 
    n4 = num % 10;

    sum = (n1 * 10 + n2) + (n3 * 10 + n4);
    result = pow(sum,2);
    if(num != result) {
        printf("O número %d não possui esta característica.\n",num);
    }
    else{
        printf("O número %d possui esta característica.\n",num);
    }
    return 0;
}

int ex08(){
    int id;
    printf("221 Bernardo\n 211 Eustáquio\n 311 Luiz\n 312 Mário\n 332 Artur\n");
    printf("Digite um código para mostrar o nome correspondente\n");
    scanf("%d",&id);
    switch(id){
        case 221:
            printf("221 Bernardo\n");
            break;
        case 211:
            printf("211 Eustáquio\n");
            break;
        case 311:
            printf("311 Luiz\n");
            break;
        case 312:
            printf("312 Mário\n");
            break;
        case 332:
            printf("332 Artur\n");
            break;
        default:
            printf("Código de pessoa inválido.\n");
    }
    return 0;
}

int ex09(){
    int num,n1,n2,n3,n4,n5,aux;
    printf("Digite um número para verificar se ele é palíndromo\n");
    scanf("%d",&num);
    if(num < 9999){
        printf("O número precisa ser maior do que 9999\n");
        return 0; 
    }

    n1 = num / 10000; 
    aux = num % 10000; 
    n2 = aux / 1000;  
    aux = num % 1000; 
    n3 = aux / 100; 
    aux = num % 100; 
    n4 = aux / 10; 
    n5 = num % 10;

    if(n1 == n5 && n2 == n4){
        printf("O número %d é palíndromo\n",num);
    }else{
        printf("O número %d não é palíndromo\n",num);
    }

    return 0;
}

int ex10(){
    int meters,type,tax,difference;
    float bill,perMeter;
    printf("Digite o tipo de consumidor:\n[1]Residencial\n[2]Comercial\n[3]Industrial\n");
    scanf("%d",&type);
    printf("Digite o tamanho em m3 do seu terreno:\n");
    scanf("%d",&meters);
    switch(type){
        case 1:
            tax = 75;
            perMeter = 3.5 * meters;
            bill = tax + perMeter;
            printf("O valor da conta é igual a %.2f\n",bill);
            break;
        case 2:
            tax = 500;
            if(meters > 80){
                difference = meters - 80;
                perMeter = 5.5 * difference;
                bill = tax + perMeter; 
            }else{
                bill = tax;
            }
            printf("O valor da conta é igual a %.2f\n",bill);
            break;

        case 3:
            tax = 800;
            if(meters > 100){
                difference = meters - 100;
                perMeter = 8 * difference;
                bill = tax + perMeter; 
            }else{
                bill = tax;
            }
            printf("O valor da conta é igual a %.2f\n",bill);
            break;

        default:
            printf("Número inválido\n");
    }
}