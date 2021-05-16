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

void ex02();
void ex03();
void ex01();
void ex04();
void ex06();
void ex07();
void ex05();
void ex08();
void ex09();
void ex10();

void executeAll();
int main(){
    /*=================================================================================*/
    /*=================================================================================
    VARIAVEIS GLOBAIS DO EXERCÍCIO 6*/
    int minimo = 42;
    
    int maximo = 2021;
    
    /*=================================================================================*/
    /*=================================================================================*/

    //executeAll();
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


void executeAll(){
    ex01();
    ex02();
    ex03();
    ex04();
    ex05();
    ex06();
    ex07();
    ex08();
    ex09();
    ex10();
}
void ex01(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex01=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler uma palavra do teclado;\n-mostrar todas as letras maiúsculas que estão na palavra digitada.\nDICA: Definir um teste para determinar se um caractere é letra maiúscula.\n\n");
    char palavra[50], caracteres[50];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    for(int g = 0; g < strlen(palavra) ; g++){
        if(palavra[g] == ' '){
            palavra[g] = '-';
        }
    }
    for(int i = 0, j = 0 ; i < strlen(palavra) ; i++){
        if(palavra[i] >= 'A' && palavra[i] <= 'Z'){
            caracteres[j] = palavra[i];
            j++;
        }
    }
    printf("\nString: [ %s ]", palavra);
    printf("\nCaracteres Maiúsculos: [");
    for(int k = 0; k < strlen(caracteres) ; k++){
        printf("%c ,", caracteres[k]);
    }
    printf("] \n");
}


void ex02(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex02=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler uma palavra do teclado;\n-ler um caractere do teclado-transforme toda a palavra em maiúscula;\n-contar e mostrar as letras maiúsculas menores que o caractere, e quantas letras são maiores que o caractere, e quantas são iguais ao caractere lido\n\n");
    char palavra[50], palavraUpr[50], caractere;
    int totalMenor = 0, totalMaior = 0, totalIgual = 0, len = 0;

    //Criação da struct
    struct metadadosCaracteres{
      int posicao;
      char glifo;
      int equivalencia; // Maior == 2; igual == 1; menor == 0
    };

    //Leitura da string
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    fflush(stdin);
    printf("Digite um caractere: ");
    scanf("%s", &caractere);

    //Tratamento da string
    len = strlen(palavra);
    for(int h = 0 ; h < len ; h++){
        palavraUpr[h] = toupper(palavra[h]);
    }
    struct metadadosCaracteres dadosCaracteres[len];
    for(int i = 0 ; i < len ; i++){
        if(palavraUpr[i] > caractere){
            totalMaior++;
            dadosCaracteres[i].posicao = i;
            dadosCaracteres[i].glifo = palavraUpr[i];
            dadosCaracteres[i].equivalencia = 2;
        } else if(palavraUpr[i] == caractere){
            totalIgual++;
            dadosCaracteres[i].posicao = i;
            dadosCaracteres[i].glifo = palavraUpr[i];
            dadosCaracteres[i].equivalencia = 1;
        }else if(palavraUpr[i] < caractere){
            totalMenor++;
            dadosCaracteres[i].posicao = i;
            dadosCaracteres[i].glifo = palavraUpr[i];
            dadosCaracteres[i].equivalencia = 0;
        }
    }

    printf("\nString Lida: [ %s ]", palavra);
    printf("\nString Maiúscula: [ %s ]", palavraUpr);
    printf("\nCaractere Lido: [ %c ]", caractere);
    printf("\nResumo:\n  Total de caracteres maiores: [ %d ]\n  Total de caracteres iguais: [ %d ]\n  Total de caracteres menores: [ %d ]", totalMaior, totalIgual, totalMenor);
    printf("\n\nDados Analisados: [\n");
    for(int j = 0 ; j < len ; j++){
        printf("     { posição: %d, caractere: %c, equivalencia: ", dadosCaracteres[j].posicao, dadosCaracteres[j].glifo);
        switch(dadosCaracteres[j].equivalencia){
            case 0:
                printf("'Menor' },\n");
            break;
            case 1:
                printf("'igual' },\n");
            break;
            case 2:
                printf("'Maior' },\n");
            break;
            default:
                printf("'none' },\n");
            break;
        }
    }
    printf("]\n\n");   
}

void ex03(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex03=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler uma cadeia de caracteres do teclado;\n-contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas.\n");
    char cadeia[50];
    int len = 0, totalMaiusculas = 0, totalMinusculas = 0, totalNaoLetra = 0;
    typedef struct Carateres{
        int posicao;
        char glifo;
        int situacao; //maiusculo == 2 ;  minusculo == 1 ; não-letra == 0;
    } Caracteres;

    

    // leitura
    printf("\nDigite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    //tratamento da string 
    len = strlen(cadeia);
    Caracteres caracteres[len];

    for(int i = 0 ; i < len ; i++){
        if( ( cadeia[i] >= 'A' && cadeia[i] <= 'Z') || ( cadeia[i] >= 'a' && cadeia[i] <= 'z' ) ){
            if( cadeia[i] >= 'A' && cadeia[i] <= 'Z'){
                totalMaiusculas++;
                caracteres[i].posicao = i;
                caracteres[i].glifo = cadeia[i];
                caracteres[i].situacao = 2;
            }else if ( cadeia[i] >= 'a' && cadeia[i] <= 'z' ){
                totalMinusculas++;
                caracteres[i].posicao = i;
                caracteres[i].glifo = cadeia[i];
                caracteres[i].situacao = 1;
            }
        }else{
            totalNaoLetra++;
            caracteres[i].posicao = i;
            caracteres[i].glifo = cadeia[i];
            caracteres[i].situacao = 0;
        }
    }
    printf("\nTotal de Maiusculas: [ %d ]\nTotal de Minusculas: [ %d ]\n Não letras: [ %d ]", totalMaiusculas, totalMinusculas,totalNaoLetra);
    printf("\n\nDados Analisados: [\n");
    for(int j = 0 ; j < len ; j++){
        printf("     { posição: %d, caractere: %c, situação: ", caracteres[j].posicao, caracteres[j].glifo);
        switch(caracteres[j].situacao){
            case 0:
                printf("'Não letra' },\n");
            break;
            case 1:
                printf("'Minúsculo' },\n");
            break;
            case 2:
                printf("'Maiúsculo' },\n");
            break;
            default:
                printf("'none' },\n");
            break;
        }
    }
    printf("]\n\n");   


    
}

void ex04(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex04=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler uma cadeia de caracteres do teclado;\n-contar e mostrar todos os dígitos, percorrendo desde o fim até o início da cadeia de caracteres.\n\n");
    char cadeia[50];
    int len = 0;
    // leitura
    printf("\nDigite uma cadeia de caracteres: ");
    scanf("%s", cadeia);
    len = strlen(cadeia);
    printf("Cadeia do início ao fim = [ ");
    for( int i = len ; i >= 0 ; i--){
        printf("%c, ", cadeia[i]);
    }
    printf("]\nTotal de caracteres = [ %d ]", len);


}


void ex05(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex05=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler uma cadeia de caracteres do teclado;\n-contar e mostrar tudo o que não for dígito e também não for letra minúscula.\n\n");
    char cadeia[50], selecionados[50];
    int len = 0;

    printf("\nDigite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    //tratamento da string 
    len = strlen(cadeia);

    for(int i = 0 ; i < len ; i++){
        if( ( cadeia[i] < 'a' || cadeia[i] > 'z') && ( cadeia[i] < '0' || cadeia[i] > '9' ) ){
            selecionados[i] = cadeia[i];
        }
    }
    printf("Não digitos e não minusculos: [");
    for(int j = 0 ; j < strlen(selecionados) ; j++){
        printf("%c, ", selecionados[j]);
    }
    printf("]\nTotal de Caracteres: %ld", strlen(selecionados));

}

void ex06(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex06=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler dois valores inteiros positivos, limites para definirem um intervalo;( esses valores deverão ser globais\n-ler uma quantidade de valores inteiros a serem testados –FLAG -1; um por vez;\n-contar e mostrar dentre esses valores lidos os que forem múltiplos de 2 e de 3, ao mesmo tempo, e pertençam ao intervalo.\n\n");
    //A variaveis globais ja foram declaradas no inicio do método principal
    
    int numeros[100], numControle = 0, fimDaLista = 0;

    typedef struct numerosValidos{
        int num;
        
    }
    for(int i = 0; i < 100 ; i++){
        printf("Digite um numero: ");
        scanf("%d", &numControle);
        if (numControle != -1){
            numeros[i] = numControle;
        }else{
            i++;
            fimDaLista = i;
            i = 100;
        }
    }
    

    
    for(int j = 0 ; j < 50 ; j++){
        printf("%d, ", numeros[j]);
    }
    /*int a[17];
    size_t n = sizeof(a)/sizeof(a[0]);*/





}


void ex07(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex07=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler dois valores inteiros positivos, limites para definirem um intervalo ( esses valores deverão ser globais)\n-ler uma quantidade de valores inteiros a serem testados;-Flag-1, um por vez;\n-contar e mostrar dentre esses valores lidos os que forem múltiplos de 3, que não forem também múltiplos de 5, e pertençam ao intervalo.\n\n");
   
}

void ex08(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex08=======================\n"RESET);
    printf("Crie um procedimento para: \n- ler dois valores reais, o primeiro menor que o segundo, caso não seja emita uma mensagem  de erro e peça novamente, para definirem um intervalo; ( esses valores deverão ser globais) \n- Crie outro procedimento para: \n  - ler a quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade; \n  - contar e mostrar todos os valores lidos, pertencentes ao do intervalo, cujas partes inteiras forem números ímpares. \nDICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int), antes de testar se é impar\n\n");
    
}

void ex09(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex09=======================\n"RESET);
    printf("Crie um procedimento para: \n- ler dois valores reais, maiores que 0 e menores que 1, caso não seja emita uma mensagem de erro e peça novamente, para definirem um intervalo de precisão; ; ( esses valores deverão ser globais) Crie um procedimento para: \n - ler uma quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade; contar e mostrar todos os valores lidos que tenham suas partes fracionárias maiores que o intervalo de precisão. \nDICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int), e obter a parte fracionária mediante a subtração da parte inteira, antes de testar.\n\n");
    
}

void ex10(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex10=======================\n"RESET);
    printf("Crie um procedimento para: \nler uma linha do teclado; defina essa linha como global ; \n- separar em outra cadeia de caracteres e mostrar todos os símbolos não alfanuméricos (letras ou dígitos) na cadeia de caracteres ");

    
    
}
