


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

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Nodo {
  char str[700];
  struct Nodo *prox;
};
typedef struct Nodo nodo;
nodo* lerStrings();
int palindrometro(const char *str);

int main() {
  setlocale(LC_ALL, "");
  nodo *list = lerStrings();
  while (list != NULL){
    int isPalindromo = palindrometro(list->str);
    const char *resultado = isPalindromo ? "SIM" : "NAO";
    printf("%s\n", resultado);
    list = list->prox;
  }
  return 0;
}

nodo* lerStrings() {
  nodo *list = (nodo*) malloc(sizeof(nodo));
  nodo *curr = list;
  nodo *pet;
  int isEnd = 0;
  do {
    fgets(curr->str, 700, stdin);
    int tam = strlen(curr->str);
    curr->str[tam - 1] = 0;
    isEnd = strcmp(curr->str, "FIM") == 0;
    if(!isEnd){
      curr->prox = (nodo*) malloc(sizeof(nodo));
      pet = curr;
      curr = curr->prox;
    } else {
      pet->prox = NULL;
    }
  } while (!isEnd);
  return list;
}

int palindrometro(const char *str) {
    int tam = strlen(str);
    for( int i = 0; i < tam ; i++){
        if( str[i] != str[ tam - i - 1 ] ){
            return 0;
        }
    }
    return 1;
}