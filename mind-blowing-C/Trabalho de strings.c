/* 
The MIT License (MIT)
    *Copyright © 2021 Gabriel Victor - PUC Minas
    *
    *Permission is hereby granted, free of charge, to any person obtaining a copy of
    *this software and associated documentation files (the “Software”), to deal in
    *the Software without restriction, including without limitation the rights to
    *use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    *the Software, and to permit persons to whom the Software is furnished to do so,
    *subject to the following conditions:
    *
    *The above copyright notice and this permission notice shall be included in all
    *copies or substantial portions of the Software.
    *
    *THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    *FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    *COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    *IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    *CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ 
/*
=====================================================
Código desenvolvido por:

 ██████╗  █████╗ ██████╗ ██████╗ ██╗███████╗██╗
██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██║██╔════╝██║
██║  ███╗███████║██████╔╝██████╔╝██║█████╗  ██║
██║   ██║██╔══██║██╔══██╗██╔══██╗██║██╔══╝  ██║
╚██████╔╝██║  ██║██████╔╝██║  ██║██║███████╗███████╗
 ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝
 =====================================================
*/

/**
 * Trabalho de Strings
 * 04/05/2021
 * Engenharia de Software -  PUC Minas
 */
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
    printf("Leia um conjunto indeterminado de palavras e ao final (estipule você um flag) informe qual foi a maior palavra e a menor palavra digitada, em tamanho e lexicograficamente.\n\n");
    char maior[50] = "a", menor[50] = "..................................................", palavra[50];
    printf(BOLDBLUE"Para encerrar a leitura digite -1\n"RESET);

    do{
        printf("\nDigite uma palavra: ");
        scanf("%s", palavra);
        fflush(stdin);
        if(( palavra[0] == '-' ) && ( palavra[1]  == '1' )){
            break;
        }else{
            if( strlen(palavra) > strlen(maior) ){
                strcpy(maior, palavra);
            }else{
                if( strlen(palavra) < strlen(menor) ){
                    strcpy(menor, palavra);
                }
            }
        }
        
    }while( ( palavra[0] != '-' ) && ( palavra[1]  != '1' ));
    printf("\nMaior palavra: %s [%li caracteres]", maior, strlen(maior));
    printf("\nMenor palavra: %s [%li caracteres]", menor, strlen(menor));
    
}
int ex02(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex02=======================\n"RESET);
    printf("Ler um string de no máximo 50 caracteres e contar quantas letras A essa palavra possui.\n\n");
    char palavra[50];
    int totalA = 0;
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    for( int i = 0 ; i < strlen(palavra) ; i++){
        if(palavra[i] == 'A'){
            totalA++;
        }
    }
    printf("A palavra [%s] possui %d letras A", palavra, totalA);
    
}
int ex03(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex03=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres e indicar quais as posições da letra A nessa palavra.\n\n");
    char palavra[50];
    int totalA = 0, positions[50], j = 0;
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    for( int i = 0 ; i < strlen(palavra) ; i++){
        if(palavra[i] == 'A'){
            totalA++;
            positions[j] = i;
            j++;
        }
    }
    printf("A palavra [%s] possui um total de %d letras A nas posições: ", palavra, totalA);
    printf("[ ");
    for(int k = 0 ; k < j ; k++){
        printf("%d,", positions[k]);
    }
    printf("]");
    
}

int ex04(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex04=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres e em seguida um caractere, mostrar quais as posições esse caractere aparece na string lida e quantas vezes ele apareceu.\n\n");
    char palavra[50], caractere[1];
    int totalCaractere = 0, positions[50], j = 0;
    
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    printf("\nQual caractere deseja analisar? ");
    scanf("%s", caractere);
    
    for( int i = 0 ; i < strlen(palavra) ; i++){

        char temp1[2] = {palavra[i], '\0'}, temp2[2] = {caractere[0], '\0'};
        if( strcmp( temp1, temp2) == 0 ){
            totalCaractere++;
            positions[j] = i;
            j++;
        }
    }
    printf("A palavra [%s] possui um total de %d caracteres %c nas posições: ", palavra, totalCaractere, caractere[0] );
    printf("[ ");
    for(int k = 0 ; k < j ; k++){
        printf("%d,", positions[k]);
    }
    printf("]");
}

int ex05(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex05=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres e em seguida um caractere (entre A e z -consista se o caracter esta nesse intervalo), mostrar quais as posições esse caractere (maiúscula ou minúscula) na stringlida e quantas vezes ele apareceu.\n\n");
    char palavra[50], caractere[1];
    int totalCaractere = 0, positions[50], j = 0;
    
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    
    do{
        printf("\nQual caractere deseja analisar? ");
        scanf("%s", caractere);
    }while(!(caractere[0] >= 'A' && caractere[0] <= 'Z' || caractere[0] >= 'a' && caractere[0] <= 'z'));
    
    
    for( int i = 0 ; i < strlen(palavra) ; i++){

        char temp1[2] = {palavra[i], '\0'}, temp2[2] = {caractere[0], '\0'};
        if( strcmp( temp1, temp2) == 0 ){
            totalCaractere++;
            positions[j] = i;
            j++;
        }
    }
    printf("A palavra [%s] possui um total de %d caracteres %c nas posições: ", palavra, totalCaractere, caractere[0] );
    printf("[ ");
    for(int k = 0 ; k < j ; k++){
        printf("%d,", positions[k]);
    }
    printf("]");

}
int ex06(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex06=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres e mostrar quantas letras possui e quantos caracteres são números e quantos não são nem números nem letras.\n\n"); 
    char palavra[50];
    int nums = 0, words = 0, nothing = 0;
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    for( int i = 0 ; i < strlen(palavra) ; i++){
        if(palavra[i] >= '0' && palavra[i] <= '9'){
            //Se for numero
            nums++;
        } else if(palavra[i] >= 'A' && palavra[i] <= 'Z' || palavra[i] >= 'a' && palavra[i] <= 'z')  {
            //Se for letra
            words++;
            
        }else{
            nothing++;
        }
    }
    printf("A palavra [%s] possui %d letras e %d numeros e %d que não são nem numeros nem letras", palavra, words, nums, nothing);

}


int ex07(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex07=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres e criar uma nova string com seu inverso, isso é a ultima letra da primeira string será a primeira na nova stringe assim sucessivamente.\n\n");
    
    char palavra[50], palavraInversa[50];
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    for( int i = 0, j = strlen(palavra) - 1; i < strlen(palavra) ; i++){
        palavraInversa[i] = palavra[j];
        j--;
    }
    printf("A palavra [%s] inversa é [%s]", palavra, palavraInversa);

}
void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
int ex08(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex08=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Utilize uma string auxiliar\n\n");
    char string[50], stringNoSpaces[50];
    int i,k =0;
    printf("Forneca uma string com espacos em branco: ");
    scanf("%s", string);
     for(i=0;string[i];i++)
    {
     	string[i]=string[i+k];
 
     	
     	if(string[i]==' '|| string[i]=='\t')
     	{
		  k++;
		  i--;
	    }
     	
    }
    printf("String sem espaços em branco: %s\n", string);
}
int ex09(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex09=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Sem utilize string auxiliar.\n\n");
    char string[50], stringNoSpaces[50];
    int i,k =0;
    printf("Forneca uma string com espacos em branco: ");
    scanf("%s", string);
     for(i=0;string[i];i++)
    {
     	string[i]=string[i+k];
 
     	
     	if(string[i]==' '|| string[i]=='\t')
     	{
		  k++;
		  i--;
	    }
     	
    }
    printf("String sem espaços em branco: %s\n", string);
    
}
int ex10(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex10=======================\n"RESET);
    printf("Ler uma string de no máximo 50 caracteres em seguida leia outra string de no máximo 3 caracteres, informe quantas vezes a segunda string aparece na primeira string, e diga as posições iniciais em que ela aparece.\n\n");

    char palavra[50], caractere[3];
    int totalCaractere = 0, positions[50], j = 0;
    
    printf("\nDigite uma palavra: ");
    scanf("%s", palavra);
    printf("\nQual caractere deseja analisar? ");
    scanf("%s", caractere);
    
    for( int i = 0 ; i < strlen(palavra) ; i++){

        char temp1[4] = {palavra[i], palavra[i+1], palavra[i+2], '\0'}, temp2[4] = {caractere[0], caractere[1], caractere[2], '\0'};
        if( !(strcmp( temp1, temp2)) ){
            totalCaractere++;
            positions[j] = i;
            j++;
        }
    }
    printf("\n\nA palavra [%s] possui um total de %d caracteres %s nas posições: ", palavra, totalCaractere, caractere );
    printf("[ ");
    for(int k = 0 ; k < j ; k++){
        printf("%d,", positions[k]);
    }
    printf("]");
    
}
