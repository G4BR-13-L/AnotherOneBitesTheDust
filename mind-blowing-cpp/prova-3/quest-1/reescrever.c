
/*Programa que verifica se um numero é divisivel por 3*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
  FILE *fp;
  char c, letra = '\n';
  int nLinhas = 0;
  fp = fopen("gabrielvictor.txt", "r");
  while (fread(&c, sizeof(char), 1, fp)) {
    if (c == letra) {
      nLinhas++;
    }
  }
  printf("\nLinhas: %i\n", nLinhas);
  fclose(fp);
  int listaNumeros[nLinhas];
  if ((fp = fopen("gabrielvictor.txt", "r")) == NULL)  // Reading a file
  {
    printf("Erro ao abrir arquivo.\n");
  } else {
    char buffer[64];
    int i = 0;
    fgets(buffer, 64, fp);
    while (!feof(fp)) {
      sscanf(buffer, "%d", &listaNumeros[i]);
      fgets(buffer, 64, fp);
      i++;
    }
  }
  fflush(stdin);
  fclose(fp);
  printf(BOLDWHITE"Numeros divisiveis por 3\n"RESET);
  int listaNumerosLen = sizeof(listaNumeros) / sizeof(listaNumeros[0]);
  for (int k = 0; k < listaNumerosLen; k++) {
    if (listaNumeros[k] % 3 == 0) {
      printf("%d é divisivel por 3\n", listaNumeros[k]);
    }else{
      printf("%d Não é divisivel por 3\n", listaNumeros[k]);
    }
  }
}