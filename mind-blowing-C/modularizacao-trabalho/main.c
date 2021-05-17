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
void ex05();
void ex06(int minimo, int maximo);
void ex07(int minimo, int maximo);
void ex08(int min, int max);
void ex09(float min, float max);
void ex10();
int main(){
    /*=================================================================================*/
    /*=================================================================================
    VARIAVEIS GLOBAIS DO EXERCÍCIO 6, 7,8*/
    
    int minimo = 1, maximo = 0;
    printf(BOLDCYAN"\n\nANTES DE TUDO INFORME OS VALORES GLOBAIS DO PROGRAMA, ELE SÃO REQUISITOS DOS EXERCÍCIOS 6,7,8.\nDIGITE UM VALOR MÍNIMO E UM VALOR MÁXIMO INTEIROS PARA OS EXÉCÍCIOS 6, 7 e 8:"RESET);
    do{
        printf("\nDigite um valor mínimo para o intervalo: ");
        scanf("%d", &minimo);
        printf("\nDigite um valor máximo para o intervalo: ");
        scanf("%d", &maximo);
    }while(maximo <= minimo);
    printf(BOLDCYAN"\n\nAGORA DIGITE VALORES QUE ESTEJAM ENTRE 0 E 1 PARA QUE SIRVÃO AO EXERCÍCIO 9: \n"RESET);
    
    float minimo9 = 0.1, maximo9 = 0;
    do{
        printf("\nDigite um valor mínimo entre 0 e 1 para o intervalo: ");
        scanf("%f", &minimo9);
        printf("\nDigite um valor máximo entre 0 e 1 e maior que o valor mínimo: ");
        scanf("%f", &maximo9);
    }while( ( maximo9 <= minimo9 ) || (maximo9 < 0 || maximo9 > 1) || (minimo9 < 0 || minimo9 > 1));
    /*=================================================================================*/
    /*=================================================================================*/
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
                ex06(minimo,maximo);
            break;
            case 7:
                ex07(minimo, maximo);
            break;
            case 8:   
                ex08(minimo, maximo);
            break;
            case 9:
                ex09(minimo9, maximo9);
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

void ex06(int minimo, int maximo){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex06=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler dois valores inteiros positivos, limites para definirem um intervalo;( esses valores deverão ser globais\n-ler uma quantidade de valores inteiros a serem testados –FLAG -1; um por vez;\n-contar e mostrar dentre esses valores lidos os que forem múltiplos de 2 e de 3, ao mesmo tempo, e pertençam ao intervalo.\n\n");
    //A variaveis globais ja foram declaradas no inicio do método principal
    
    int numeros[100], numControle = 0, fimDaLista = 0, valido = 0;

    typedef struct Analise{
        int num;
        int valido;
    } Analise;
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
    Analise analise[fimDaLista - 1];
    for(int j = 0 ; j < fimDaLista ; j++){
        if( ( numeros[j] % 2 == 0 && numeros[j] % 3 == 0 ) && numeros[j] >= minimo && numeros[j] <= maximo ){
            analise[j].num = numeros[j];
            analise[j].valido = 1;
            valido++;
        }else{
            analise[j].num = numeros[j];
            analise[j].valido = 0;
        }
    };

    printf("\nClassificação      Número\n");
    for(int k = 0 ; k < fimDaLista ; k++){
        if(analise[k].valido == 1){
            printf(BOLDGREEN"VÁLIDO   -        "RESET);
            printf(" %d\n", analise[k].num);
        }else{
            printf(BOLDRED"INVÁLIDO -        "RESET);
            printf(" %d\n", analise[k].num);
        }
    }
    printf("Total de números existentes entre %d e %d, e que são multiplos de 2 e de 3 simultaneamente: %d", minimo, maximo, valido);

}


void ex07(int minimo, int maximo){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex07=======================\n"RESET);
    printf("Crie um procedimento para:\n-ler dois valores inteiros positivos, limites para definirem um intervalo ( esses valores deverão ser globais)\n-ler uma quantidade de valores inteiros a serem testados;-Flag-1, um por vez;\n-contar e mostrar dentre esses valores lidos os que forem múltiplos de 3, que não forem também múltiplos de 5, e pertençam ao intervalo.\n\n");
    
    int numeros[100], numControle = 0, fimDaLista = 0, valido = 0;

    typedef struct Analise{
        int num;
        int valido;
    } Analise;
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
    Analise analise[fimDaLista - 1];
    for(int j = 0 ; j < fimDaLista ; j++){
        if( ( numeros[j] % 3 == 0 && numeros[j] % 5 != 0 ) && numeros[j] >= minimo && numeros[j] <= maximo ){
            analise[j].num = numeros[j];
            analise[j].valido = 1;
            valido++;
        }else{
            analise[j].num = numeros[j];
            analise[j].valido = 0;
        }
    };

    printf("\nClassificação      Número\n");
    for(int k = 0 ; k < fimDaLista ; k++){
        if(analise[k].valido == 1){
            printf(BOLDGREEN"VÁLIDO   -        "RESET);
            printf(" %d\n", analise[k].num);
        }else{
            printf(BOLDRED"INVÁLIDO -        "RESET);
            printf(" %d\n", analise[k].num);
        }
    }
    printf("Total de números existentes entre %d e %d, e que são multiplos de 3 mas não de 5: %d", minimo, maximo, valido);
}

void ex08(int min, int max){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex08=======================\n"RESET);
    printf("Crie um procedimento para: \n- ler dois valores reais, o primeiro menor que o segundo, caso não seja emita uma mensagem  de erro e peça novamente, para definirem um intervalo; ( esses valores deverão ser globais) \n- Crie outro procedimento para: \n  - ler a quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade; \n  - contar e mostrar todos os valores lidos, pertencentes ao do intervalo, cujas partes inteiras forem números ímpares. \nDICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int), antes de testar se é impar\n\n");
    int quantidade = 0, quantidadeImpares = 0;
    typedef struct Valores{
        float num;
        int numCast;
        int valido;
    } Valores;

    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &quantidade);
    Valores valores[quantidade];

    for( int i = 0 ; i < quantidade ; i++){
        printf("Digite um valor real: ");
        scanf("%f", &valores[i].num);
        valores[i].numCast = valores[i].num;
    }
    
    for(int j = 0 ; j < quantidade ; j++){
        if( valores[j].numCast % 2 == 0){
            valores[j].numCast = 0;
            valores[j].valido = 0;
        }else{
            if( valores[j].numCast >= min && valores[j].numCast <= max){
                valores[j].valido = 1;
            }else{
                valores[j].valido = 0;
            }
        }
    }
    printf("Numeros Impares dentro do intervalo: [ ");
    for(int k = 0 ; k < quantidade ; k++){
        if(valores[k].valido == 1){
            printf("%d, ", valores[k].numCast);
            quantidadeImpares++;
        }
    }
    printf("]");
    printf("Quantidade de números impares: %d", quantidadeImpares);

    
}

void ex09(float min, float max){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex09=======================\n"RESET);
    printf("Crie um procedimento para: \n- ler dois valores reais, maiores que 0 e menores que 1, caso não seja emita uma mensagem de erro e peça novamente, para definirem um intervalo de precisão; ; ( esses valores deverão ser globais) Crie um procedimento para: \n - ler uma quantidade de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade; contar e mostrar todos os valores lidos que tenham suas partes fracionárias maiores que o intervalo de precisão. \nDICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int), e obter a parte fracionária mediante a subtração da parte inteira, antes de testar.\n\n");

    int quantidade = 0;
    typedef struct Valores{
        float num;
        int numCastInt;
        float fracionaria;
        int valido;
    } Valores;

    printf("Digite a quantidade de valores a serem testados: ");
    scanf("%d", &quantidade);
    Valores valores[quantidade];

    for( int i = 0 ; i < quantidade ; i++){
        printf("\nDigite um valor real: ");
        scanf("%f", &valores[i].num);
        valores[i].numCastInt = valores[i].num;
        printf("\nParte Inteira: %d", valores[i].numCastInt);
        valores[i].fracionaria = valores[i].num - valores[i].numCastInt;
        if( valores[i].fracionaria >= min && valores[i].fracionaria <= max ){
            valores[i].valido = 1;
        }
    }
    printf("Partes fracionárias dentro do intervalo = [ ");
    for(int j = 0 ; j < quantidade ; j++){
        printf("%.5f, ", valores[j].fracionaria);
    }
    printf("]");

    
    
}

void ex10(){
    printf(BOLDWHITE"================================================\n"RESET);
    printf(BOLDWHITE"======================Ex10=======================\n"RESET);
    printf("Crie um procedimento para: \nler uma linha do teclado; defina essa linha como global ; \n- separar em outra cadeia de caracteres e mostrar todos os símbolos não alfanuméricos (letras ou dígitos) na cadeia de caracteres ");

    char cadeiaGlobal[50], outraCadeia[50];
    int len = strlen(cadeiaGlobal);
    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeiaGlobal);
    for(int i = 0, k = 0 ; i < len ; i++){
        if( (cadeiaGlobal[i] < 'a' && cadeiaGlobal[i] > 'z') && (cadeiaGlobal[i] < '0' && cadeiaGlobal[i] > '9') &&(cadeiaGlobal[i] < 'A' && cadeiaGlobal[i] > 'Z') ){
            outraCadeia[k] = cadeiaGlobal[i];
            k++;
        }
    }

    printf("Caracteres não alfanumericos: [");
    for(int j = 0 ; j < len ; j++){
        printf("%c, ", outraCadeia[j]);
    }
    printf("]");
    
}
