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

int decimais(const char *str) {
  char *dot = strstr(str, ".");
  if (dot == NULL) return 0;
  int len = strlen(dot) - 1;
  for (int i = len; i >= 0; i--) {
    if (dot[i] == '0')
      len--;
    else
      break;
  }
  return len > 0 ? len : 0;
};

int main() {
  // LEITURA DA QUANTIDADE DE NUMEROS
  int n = 0;
  scanf("%d", &n);

  // LEITURA DE TODOS OS NUMEROS COMO STRING
  char lista[n][500];
  for (int i = 0; i < n; i++) {
    char aux[500];
    scanf("%s", aux);
    sprintf(lista[i], "%s", aux);
  }

  // ESCRITA DE TODOS OS NUMEROS EM UM ARQUIVO
  FILE *arquivoEscrita;
  arquivoEscrita = fopen("lista.txt", "w+");
  for (int j = n - 1; j >= 0; j--) {
    fprintf(arquivoEscrita, "%s\n", lista[j]);
  }
  fclose(arquivoEscrita);

  // PRINTANDO OS NUMEROS
  for (int k = n - 1; k >= 0; k--) {
    int len = strlen(lista[k]);
    char string[len];
    strcpy(string, lista[k]);
    float value;
    sscanf(string, "%f", &value);
    int qt = decimais(string);
    char format[6] = {'%', '.', 'x', 'f', '\n', 0};
    format[2] = '0' + qt;
    printf(format, value);
  }

  return 0;
}