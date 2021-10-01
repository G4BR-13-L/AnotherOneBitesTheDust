

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

struct Nodo {
  char str[500];
  struct Nodo *prox;
};
typedef struct Nodo nodo;

struct Lista {
  int quantidade;
  struct Nodo *primeiro;
  struct Nodo *ultimo;
};
typedef struct Lista lista;

lista lerStrings();
int palindrometro(const char *str);

int main() {
  lista listaDePalindromos = lerStrings();
  nodo *aux = listaDePalindromos.primeiro;
  for (int i = 0; i < listaDePalindromos.quantidade; i++) {
    int isPalindromo = palindrometro(aux->str);
    aux = aux->prox;
    const char *resultado = isPalindromo ? "SIM\n" : "NAO\n";
    printf("%s", resultado);
  }
}

lista lerStrings() {
  lista listaDeStrings;
  listaDeStrings.primeiro = NULL;
  listaDeStrings.ultimo = NULL;
  listaDeStrings.quantidade = 0;
  do {
    nodo string;
    fgets(string.str, 500, stdin);
    int tam = strlen(string.str);
    string.str[tam - 1] = 0;
    if (listaDeStrings.primeiro == NULL && listaDeStrings.ultimo == NULL) {
      listaDeStrings.primeiro = &string;
      listaDeStrings.ultimo = &string;
      listaDeStrings.quantidade = 1;
    } else {
      nodo *anterior = listaDeStrings.ultimo;
      anterior->prox = &string;
      listaDeStrings.ultimo = &string;
      listaDeStrings.quantidade++;
      // printf("Quantidade: %d\n", listaDeStrings.quantidade);
    }
  } while (strcmp(listaDeStrings.ultimo->str, "FIM") != 0);
  return listaDeStrings;
}

int palindrometro(const char *str) {
    int tam = strlen(str);
    int verify = 0
    for( int i = 0, j = tam - 1 ; i < tam ; i++, j--){
        if( str[i] == str[j] ){
            if()verify = 0
        }else{
            verify = 1;
        }
    }
}