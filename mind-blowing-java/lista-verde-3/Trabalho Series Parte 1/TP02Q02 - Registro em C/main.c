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

struct Serie {
  char nome[200];
  char formato[200];
  char duracao[200];
  char pais[200];
  char idioma[200];
  char broadcaster[200];
  char streaming[200];
  int temporadas;
  int episodios;
};
typedef struct Serie serie;

int isFim(char *s) {
  if (strlen(s) == 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M') {
    return 1;
  } else {
    return 0;
  }
}
int extrairDados(char *nomeArquivo) {
  FILE *pFile;
  char [2500];
  if ((pFile = fopen("../series/", "r")) == NULL)  // Reading a file
  {
    printf("File could not be opened.\n");
  } else {
    char buffer[2500];
    int i = 0;
    fgets(buffer, 200, pFile);
    while (!feof(pFile)) {
      sscanf(buffer, "%f", &fibonacci[i]);
      fgets(buffer, 200, pFile);
      i++;
    }
  }
  fclose(pFile);
}
int main() {
  char listaDeSeries[1000][500];
  int index = 0;
  do {
    scanf("%s", listaDeSeries[index]);
    index++;
  } while (isFim(listaDeSeries[index - 1]) == 0);
  index--;
  for (int i = 0; i < index; i++) {
    printf("%s\n", listaDeSeries[i]);
  }

  return 0;
}
