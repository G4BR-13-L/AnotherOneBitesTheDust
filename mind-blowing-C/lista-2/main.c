#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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
        printf(BOLDWHITE"======================Selecione um exercício=======================\n"RESET);
        printf(BOLDWHITE"   [ 1 ] [ 2 ] [ 3 ] [ 14 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 10 ]\n" RESET);
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
                printf(BOLDWHITE"Exercício inexistente\n\n"RESET);
            break;
        }
        printf("\n\nDeseja continuar a execução?  [Sim = 1 / Não = 0]");
        scanf("%d", &exec);
        clear();
    }
}


int ex01(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex01=======================\n"RESET);
    printf("Fazer um algoritmo que leia um numero inteiro e mostre uma mensagem indicando se este numero e par ou impar.\n\n");
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    if(num % 2 == 0){
        printf("\nÉ PAR.");
    }else{
        printf("\nÉ IMPAR");
    }
}
int ex02(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex02=======================\n"RESET);
    printf("Fazer um algoritmo peça o nome e as 3 notas de um aluno e mostre, além do nome e do valor da media do aluno, uma mensagem de 'Aprovado', caso a media seja igual ou superior a 6, ou a mensagem 'reprovado', caso contrario.\n\n");
    //Struct
    struct dadosAluno{
      char nome[25];
      float notas[3];
      float media;
      char status;
    };
    struct dadosAluno aluno;
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);
    fflush(stdin);
    printf("\nDigite a primeira nota:");
    scanf("%f", &aluno.notas[0]);
    printf("\nDigite a segunda nota:");
    scanf("%f", &aluno.notas[1]);
    printf("\nDigite a terceira nota:");
    scanf("%f", &aluno.notas[2]);
    printf("%s", aluno.nome);
    aluno.media = ( aluno.notas[0] + aluno.notas[1] + aluno.notas[2] ) / 3;
    if( aluno.media >= 6){
        printf(BOLDWHITE "\n\nNome: %s\nNota 1: %2.f\nNota 2: %2.f\nNota 3: %2.f\nMédia: %.2f\nSituação: APROVADO" RESET, aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
    }else{
        printf("\n\nNome: %s\nNota 1: %2.f\nNota 2: %2.f\nNota 3: %2.f\nMédia: %.2f\nSituação: REPROVADO", aluno.nome, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.media);
    }
    
}
int ex03(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex03=======================\n"RESET);
    printf("\nFazer um algoritmo que leia a temperatura da água e mostre se está no estado solido, líquido ou gasoso.\n");
    float temperatura;
    printf("Digite a temperatura da água: ");
    scanf("%f", &temperatura);
    if(temperatura <= 0){
        printf("A água está no estado sólido: %.2f°C\n\n", temperatura);
    }else{
        if(temperatura > 3 && temperatura < 100){
            printf("A água está no estado líquido: %.2f°C\n\n", temperatura);
        }else{
            if( temperatura >= 100 && temperatura < 5000){
                 printf("A água está no estado gasoso: %.2f°C\n\n", temperatura);
            }else{
                 printf("Não é mais água, é Plasma: %.2f°C\n\n", temperatura);
            }
        }
    }
}
int ex04(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex04=======================\n"RESET);
    printf("Leia um valor X e se ele for menor que 0 avalie Y = 2x + 4. Se ele for maior que 0 avalie x3-3 e se ele for igual a 0 de uma mensagem de erro.\n\n");
    float x, y;
    printf("Digite um valor para x: ");
    scanf("%f", &x);
    if( x == 0 ){
       printf("===========ERRO===========\n\n");
    }else{
        if(x < 0){
           y = 2 * x + 4;
           printf(" Y = 2x + 4\n");
           printf(" Y = %.2f\n\n", y);
        }else{
            y = 3 * x -3;
            printf(" Y = 3x - 3\n");
            printf(" Y = %.2f\n\n", y);

        }
    }
}

int ex05(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex05=======================\n"RESET);
    printf("Construa um algoritmo que receba como entrada três valores (A,B e C). Após o processamento o menor valor deverá estar em A e o maior valor em C, e o valor intermediário em B. Imprima A,B e C.\n");
    int A, B, C, sort[EX05_ARRAY_LENGTH], aux, contador, i;
    printf("\nDigite o primeiro valor:");
    scanf("%d", &A);
    printf("\nDigite o segundo valor:");
    scanf("%d", &B);
    printf("\nDigite o terceiro valor:");
    scanf("%d", &C);
    printf(BOLDWHITE"A B C \n");
    printf("%d %d %d"RESET, A, B, C);
    sort[0] = A;
    sort[1] = B;
    sort[2] = C;
    for(contador = 1 ; contador < EX05_ARRAY_LENGTH ; contador++){
        for(i = 0 ; i < EX05_ARRAY_LENGTH - 1 ; i++){
            if(sort[i] > sort[i+1]){
                aux = sort[i];
                sort[i] = sort[i+1];
                sort[i+1] = aux;
            }
        }
    }
    printf("\n\nA B C ----> A B C");
    printf("\n%d %d %d ----> %d %d %d", A,B,C, sort[0], sort[1], sort[2]);
    


}
int ex06(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex06=======================\n"RESET);
    printf("Desenvolver um algoritmo que leia três números inteiros: X, Y, Z  e verifique se o número X é divisível por Y e por Z. O algoritmo deverá mostrar as possíveis mensagens:\n- o número é divisível por Y e Z.\n- o número é divisível por Y mas não por Z.\n- o número é divisível por Z mas não por Y.\n- o número não é divisível nem Y nem por Z.\n\n");
    int x, y, z;
    printf("Digite um valor para X: ");
    scanf("%d",&x);
    printf("\nDigite um valor para Y: ");
    scanf("%d",&y);
    printf("\nDigite um valor para Z: ");
    scanf("%d",&z);
    if( x % y == 0){
        if( x % z == 0){
            printf("\n- o número é divisível por Y e Z.\n\n");
        }else{
            printf("\n- o número é divisível por Y mas não por Z.\n\n");
        }
    }else{
        if( x % z == 0){
            printf("\n- o número é divisível por Z mas não por Y.\n\n");
        }else{
            printf("\n- o número não é divisível nem Y nem por Z\n\n.");
        }
    }
}
int ex07(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex07=======================\n"RESET);
    printf("O numero 3025 possui a seguinte característica:\n\n30 + 25 = 55\n55²= 3025\n Faça um algoritmo que dado um numero de 4 dígitos (verifique se o número pertence a faixa) calcule e escreva se ele possui ou não esta característica.");
    int num,contador, aux, d1,d2, result;
    printf("Digite um numero de 4 digitos: ");
    scanf("%i", &num);
    aux = num;
    for(contador = 0; contador <= num ; contador++){
        num /= 10;
    }
    if(contador != 4 ){
        printf("O numero não tem o numero  certo de digitos");
    }else{
        d2 = aux % 100;
        if(d2 == 0){
            d1 = aux / 100;
        }else{
            if( d2 < 10){
                d1 = (aux - d2 ) / 100;
            }else{
                d1 = ( aux - d2 )/100;
            }
        }
        result = pow((d1+d2),2);
        if(result == aux){
            printf("\nO número tem a caracteristica exigida");
        }else{
            printf("\nO número não tem a caracteristica exigida");
        }
        
    }

}
int ex08(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex08=======================\n"RESET);
    printf("-ler um código do tecladoe  mostrar o nome correspondente, de acordo com a lista: \n221 Bernardo \n211 Eustáquio \n311 Luiz \n312 Mário \n332 Artur\n\n");
    int cod;
    printf("Digite um código: ");
    scanf("%d", &cod);
    switch (cod){
        case 221:
            printf("- 221 Bernardo \n");
        break;
        case 211:
            printf("- 211 Eustáquio \n");
        break;
        case 311:
            printf("- 311 Luiz \n");
        break;
        case 312:
            printf("- 312 Mário \n");
        break;
        case 332:
            printf("- 332 Artur\n");
        break;
        default:
            printf("Código inválido");
        break;
    }
}
int ex09(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex09=======================\n"RESET);
    printf("Números palíndromos são aqueles que escritos da direita para esquerda ou da esquerda para direita tem o mesmo valor. Exemplo:929, 44, 97379. Fazer um algoritmo que dado um numero de 5 dígitos; calcule e escreva se este e ou não palíndromo.");
    
}
int ex10(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex10=======================\n"RESET);
}