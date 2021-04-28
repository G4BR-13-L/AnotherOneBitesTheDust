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
      printf("\033c");
    }
#endif

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
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
        printf(BOLDWHITE"============Autor: Gabriel Victor Couto Martins de Paula===========\n"RESET);
        printf(BOLDWHITE"======================Selecione um exercício=======================\n"RESET);
        printf(BOLDWHITE"   [ 1 ] [ 2 ] [ 3 ] [ 14 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 10 ]\n" RESET);
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
    printf("Faça um algoritmo que leia um conjunto de números [X] e imprima a quantidade de números pares [QPares] e a quantidade de números impares [QImpares] lidos. Admita que o valor 9999 é utilizado como sentinela (FLAG) para fim de leitura. Ex.: 1,2,3,4,5,9999 => Pares=2 Impares=3\n\n");
    int x, par = 0, impar = 0, zeros = 0;
    printf("PARA INTERROMPER A LEITURA DIGITE 9999;\nDigite os valores: ");
    do{
        printf(" - ");
        scanf("%d",&x);
        if( x % 2 == 0){
            par++;
        }else if( x % 2 == 1){
            impar++;
        }else{
            zeros++;
        }
    }while(x != 9999);
    printf("PARES: %d\nIMPARES: %d\nZEROS: %d", par, impar, zeros);
    
}
int ex02(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex02=======================\n"RESET);
    printf("Faça um programa que leia um conjunto indeterminado de números inteiros positivos e imprima o maior, o menor e a média aritmética desse conjunto de dados. [Flag -1].\nExecute este programa para os seguintes valores:\n\n1. 1,2,3,-1\n2. 3,2,1,-1\n3. 1,3,2,-1\n\n");
    int num = 0, totalNumbers = 0, maior = 0, menor = 1, soma = 0, zeros = 0;
    float media = 0;

    printf("PARA INTERROMPER A LEITURA DIGITE -1;\nDigite os valores: ");
    while( num != -1 ){
        printf("- ");
        scanf("%i", &num);
        if( num == -1 ){
            num = -1;
        }else{
            soma = soma + num;
            totalNumbers++;
            if( num > maior ){
                maior = num;
            }else if( num < menor && num != -1 ){
                menor = num;
            }else if( num == 0 ){
                zeros++;
            }
        }
        
    }
    media = soma / totalNumbers;

    printf("Números totais: %d\nMaior: %d\nMenor: %d\nSoma: %d\nZeros: %d\nMédia: %.2f",totalNumbers, maior,menor, soma, zeros, media);
    
}
int ex03(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex03=======================\n"RESET);
    printf("Escrever um algoritmo em Portugol, para calcular e imprimir o fatorial de um número lido do teclado.\nEx. Fatorial de 5! = 5x4x3x2x1=120\n");
    int num = 0;
    float fatorial;
    printf("Digite um número para que eu imprima seu fatorial: ");
    scanf("%i", &num);
    fatorial = num;
    for(int i = num - 1 ; i > 0 ; i--){
        printf("\n%.0f x %d = ", fatorial, num - 1);
        fatorial = fatorial * ( num - 1 );
        printf("%.0f", fatorial);
        num--;
    }
    printf("\nFatorial final: %.0f", fatorial);

    
}
int ex04(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex04=======================\n"RESET);
    printf("Calcule o valor da seguinte série lido a quantidade de termos:\n\nS = 1 - (1/3³) + (1/5³) - (1/3³) + (1/5³)...\n\n");
    int quantidade = 0, base = 3;
    float S = 0;
    printf("Digite a quantidade de termos: ");
    scanf("%d", &quantidade);
    S = 1 - ( 1 / pow(base,3));
    //printf("\n=====> %.5f\n", S);
    printf("S = 1 - ( 1 / %d³) ", base);
    for(int i = (quantidade - 1) ; i > 0 ; i--){
        S = S + ( 1 / pow( base+=2 , 3 ) );
        //printf("\n=====> %.5f\n", S);
        printf(" + ( 1 / %d³ )", base);
        S = S - ( 1 / pow( base+=2 , 3 ) );
        //printf("\n=====> %.5f\n", S);
        printf(" - ( 1 / %d³ )", base);
    }
    printf("\n\nResultado final de S: %.2f", S);

    
}

int ex05(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex05=======================\n"RESET);
    printf(" A série de fibonacci é formada pela seqüência:\n- 1, 2, 3, 5, 8, 13, 21, 34, ...\nEscreva um algoritmo que peça um número N maior que 2. Gere e imprima a série até este n-ésimotermo.\n");
   int N = 0;
   float num = 0, ultimo = 1, penultimo = 0;
   do{
   printf("\nDigite a quantidade de termos: ");
   scanf("%d", &N);
   }while(N < 2);
   for(int i = N ; i > 0 ; i--){
       num = ultimo + penultimo;
       printf("%.0f + ", num);
       penultimo = ultimo;
       ultimo = num;
   }

}
int ex06(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex06=======================\n"RESET);
    printf("Fazer um algoritmo para calcular o valor de S, dado por, sendo o valor de N deverá se lido do teclado:\nS = + (1/N) - (2/(N-1)) + (3/(N-2)) - (4/(N-3))...(N/1)\n\n");
    float N = 0, i = 1, caso = 1;
    float S = 0;
    printf("Digite o valor de N: ");
    scanf("%f", &N);
    S = S + ( i / ( N ) );
    printf(" + ( %f / %f )",i,N);
    //printf("\n=====> %.5f\n", S);
    while(i < N){
        if(caso == 0){
            S -= ( i / ( N - i ) );
            printf(" + ( %f / %f - %f )",i,N,i);
            //printf("\n=====> %7.5f\n", S);
            caso = 1;
        }else{
            S += ( i / ( N - i ) );
            printf(" - ( %f / %f - %f )",i,N,i);
            //printf("\n=====> %7.7f\n", S);
            caso = 0;
        }
        i++;
    }
    if(caso == 0){
            S -=  N / 1 ;
            printf(" + ( %f / 1 )",N);
            //printf("\n=====> %7.5f\n", S);
            caso = 1;
    }else{
            S +=  N / 1 ;
            printf(" + ( %f / 1 )",N);
            //printf("\n=====> %7.5f\n", S);
            caso = 0;
    }
    printf("\n\nResultado final de S: %.8f", S);
}

void reverse(char str1[], int index, int size){
    char temp;

    temp = str1[index];
    str1[index] = str1[size - index];
    str1[size - index] = temp;

    if (index == size / 2)
    {
        return;
    }
    reverse(str1, index + 1, size);
}


int ex07(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex07=======================\n"RESET);
    printf("Números palíndromos são aqueles que escritos da direita para esquerda ou da esquerda para direita tem o mesmo valor. Exemplo:929, 44, 97379. Faça um algoritmo que imprima todos os números palíndromos de 10000 a 99999.\n\n");
    char numeroInvertido[5];
    char strContador[5];
    int i, j, countPalindromos = 0, palindromosList[1000];
    for(int contador = 10001 ; contador <= 99999 ; contador++ ){
        sprintf(strContador, "%d", contador);
        strcpy(numeroInvertido, strContador);
        j = strlen(numeroInvertido);
        reverse(numeroInvertido, 0,  j - 1);
        printf(BOLDWHITE"%s"RESET, numeroInvertido);
        i = atoi(numeroInvertido);
        //printf("\n- numeroInvertido:%d \n- strContador:%d \n",i, contador);
        if (i == contador){
            printf(BOLDGREEN"%d: Palindromo \n\n"RESET, contador);
            palindromosList[countPalindromos] = contador;
            countPalindromos++;
        }else{
            printf(BOLDRED"%d: não palindromo\n\n"RESET, contador);
        }
        strContador[0] = '\0';
        numeroInvertido[0] = '\0';
    }
    printf(BOLDGREEN"Total de palindromos: %d\n\n", countPalindromos);
    printf("Lista de Palindromos encontrados:\n\n"RESET);
    for(int k = 0; k <= 900 ; k++){
        printf(BOLDCYAN"%d, "RESET, palindromosList[k]);
    }
}
int ex08(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex08=======================\n"RESET);
    printf("O numero 3025 possui a seguinte característica:\n\n-> 30 + 25 = 55\n-> 55^2 = 3025\n\nQuantos e quais são os números de 4 dígitos possuem essa característica?\n\n");
    printf("O numeros que possuem a caracteristica estaão marcados de ");
    printf(BOLDGREEN"VERDE\n\n"RESET);
    int n1, n2;
    int resultado, countCaracteristica = 0, caracteristicaList[100];
    for(int contador = 1000 ; contador <= 9999 ; contador++ ){
        n2 = contador % 100;
        if(n2 == 0){
            n1 = contador / 100;
        }else{
            if( n2 < 10){
                n1 = ( contador - n2 ) / 100;
            }else{
                n1 = ( contador - n2 )/100;
            }
        }
        resultado = pow( ( n1 + n2 ) ,2);
        if (resultado == contador){
            printf(BOLDGREEN"[%d: Possui a característica], "RESET, contador);
            caracteristicaList[countCaracteristica] = contador;
            countCaracteristica++;
        }else{
            printf("%d, ", contador);
        }
    }
    printf(BOLDGREEN"\n\nTotal de números com a carcteristica: %d\n\n", countCaracteristica);
    printf("Lista de Caracteristicas encontrados:\n\n"RESET);
    for(int k = 0; k <= countCaracteristica ; k++){
        printf(BOLDCYAN"%d, "RESET, caracteristicaList[k]);
    }
    
}
int ex09(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex09=======================\n"RESET);
    printf("Faça um programa para um jogo de cara ou coroa. Neste caso, o jogador escolhe cara ou coroa (0 – cara e 1 – para coroa) mostre ao final de 10 tentativas, quantas foram certas e quantas erradas. (utilize o comando - para que o computador escolha o resultado).\n\n");
    /*printf("%d ", rand() % 100 +1);*/
    int contador = 0, acertos = 0, erros = 0;
    for(contador = 0 ; contador <=10 ; contador++){
        char barra[50] = "                                                  ";
        fflush(stderr);
        fflush(stdout);
        printf(BOLDBLUE"JOGANDO A MOEDA\n"RESET);
        fflush(stdout);
        for(int i = 0 ; i <50; i++){
            barra[i] = '=';
            printf("[%s]\b",barra);
            printf("\r");
            fflush(stdout);
            for(int j = 0 ; j < 10000000 ; j++){
                int x;
                x++;
            }
        }
        printf("\n");
        srand(time(NULL));
        int moeda, chute = 2;
        int aleatorio = 0;
        aleatorio = rand() % 100 + 1;
        if( aleatorio % 2 == 0 ){
            moeda = 0;
        }else{
            moeda = 1;
        }
        do{
            printf("Cara ou coroa? [0 / 1]: ");
            scanf("%d", &chute);
        }while( chute > 1 && chute < 0 );

        if(chute == moeda){
            acertos++;
            printf(BOLDGREEN"\nParabens você acertou!!!\n\n"RESET);
        }else{
            erros++;
            printf(BOLDRED"\nVocê errou dessa vez\n\n"RESET);
        }
    }
    printf(BOLDWHITE"=====Resultado=====\n"RESET);
    printf("Acertos: %d\nErros: %d\n", acertos,erros);
    printf(BOLDWHITE"==================\n\n"RESET);
}
int ex10(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex10=======================\n"RESET);
    printf("Faça um programa para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Indique ao final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo usuário em no máximo 10 tentativas! Utilize a seguinte proposta. Pegue o valor intermediário e pergunte ao usuário se o número é igual(=), maior(>) ou menor(<) que o que foi escolhido. Se for (=) implica que acertou! Se for maior escolha agora o número intermediário entre o que foi perguntado e o último, caso contrário escolha o intermediário entre o primeiro e o que foi perguntado, seguindo assim até acertar! Verifique que você conseguirá acertar qualquer número em no máximo 10 tentativas!!!");

    int tentativas, num = 512, aleatorio, resposta;
    srand(time(NULL));
    for(tentativas = 0 ; tentativas <= 10 ; tentativas++){
        printf("\nO numero que você está pensando é maior, menor ou igual a %d?", num)  ;
        printf("\n[ Maior: 1 | Menor: 2 | Igual: 3 ] : ");
        scanf("%d",&resposta);
        switch (resposta)
        {
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
            printf(BOLDWHITE"\nO numero é: %d\n"RESET, num);
            tentativas = 12;
        break;
        
        default:
            break;
        }
    }
    printf(BOLDWHITE"\n\n\nFIM!!"RESET);
    
}
