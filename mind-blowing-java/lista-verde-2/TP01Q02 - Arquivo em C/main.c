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

int main() {
  // LEITURA DA QUANTIDADE DE NUMEROS
  int n = 0;
  scanf("%d", &n);

  // LEITURA DE TODOS OS NUMEROS COMO STRING
  char lista[n][500];
  for (int i = 0; i < n; i++) {
    char aux[500];
    scanf("%s", aux);
    sprintf(lista[i], "0%s", aux);
  }

  // ESCRITA DE TODOS OS NUMEROS EM UM ARQUIVO
  FILE* arquivoEscrita;
  arquivoEscrita = fopen("lista.txt", "w+");
  for (int j = n - 1; j >= 0; j--) {
    fprintf(arquivoEscrita, "%s\n", lista[j]);
  }
  fclose(arquivoEscrita);

  // LEITURA DOS NUMEROS DO ARQUIVO COMO FLOAT
  FILE* arquivoLeitura;
  char listaNumerosLidos[n][50];
  if ((arquivoLeitura = fopen("lista.txt", "r")) == NULL) {
    printf("impossivel abrir o arquivo\n");
  } else {
    char buffer[50];
    int i = 0;
    fgets(buffer, 50, arquivoLeitura);
    while (!feof(arquivoLeitura)) {
      sscanf(buffer, "%s", listaNumerosLidos[i]);
      fgets(buffer, 50, arquivoLeitura);
      i++;
    }
  }
  fclose(arquivoLeitura);

  // PRINTANDO OS NUMEROS
  /*for( int h = 0 ; h < n ; h++ ){
  printf("%s\n", listaNumerosLidos[h]);
  }*/
  for (int k = 0; k < n; k++) {
    int len = strlen(listaNumerosLidos[k]);
    char string[len];
    strcpy(string, listaNumerosLidos[k]);
    for (int m = 1; m < len; m++) {
      if (string[1] == '.' && m == 1) {
        printf("0");
      }
      if (string[m] != '0' && string[m + 1] == '0' && string[m + 2] == '0') {
        printf("%c", string[m]);
        m = len;
      } else if (string[m] != '0' && string[m + 1] == '0' &&
                 string[m + 2] != '0') {
        printf("%c%c%c", string[m], string[m++], string[m + 1]);
      } else if (string[m] == '0' && string[m + 1] == '0' && string[m + 2] == '0') {
        m = len;
      } else if (string[m] == '0' && m == len - 1) {
        m = len;
      } else {
        printf("%c", string[m]);
      }
    }
    printf("\n");
  }

  return 0;
}