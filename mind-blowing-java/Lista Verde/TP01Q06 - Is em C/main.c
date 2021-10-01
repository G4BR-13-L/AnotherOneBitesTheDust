
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
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVogal(const char *str) {
  int tam = strlen(str);
  char array[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  for (int i = 0; i < tam; i++) {
    int valido = 0;
    for (int j = 0; j < 10; j++) {
      if (str[i] == array[j]) {
        valido = 1;
      }
    }
    if (!valido) {
      return 0;
    }
  }
  return 1;
}

int isConsoante(const char *str) {
  int tam = strlen(str);
  for (int i = 0; i < tam; i++) {
    char c = str[i];
    int isConsoante = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    char c2[] = {c, '\0'};
    if (!isConsoante || isVogal(c2)) {
      return 0;
    }
  }
  return 1;
}

int isInteiro(const char *str) {
  int tam = strlen(str);
  for (int i = 0; i < tam; i++) {
    if (!(str[i] >= '0' && str[i] <= '9')) {
      return 0;
    }
  }
  return 1;
}

int isReal(const char *str) {
  int tam = strlen(str);
  int isComma = 0;
  for (int i = 0; i < tam; i++) {
    char c = str[i];
    if (!(c >= '0' && c <= '9')) {
      if (c == ',' || c == '.') {
        if (isComma) {
          return 0;
        }
        isComma = 1;
      } else {
        return 0;
      }
    }
  }
  return 1;
}

int isFim(const char *str) {
  if (strlen(str) == 3 && str[0] == 'F' && str[1] == 'I' && str[2] == 'M') {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  setlocale(LC_ALL, "");
  char linha[700];
  do {
    fgets(linha, 700, stdin);
    int tam = strlen(linha);
    linha[tam - 1] = 0;
    if (isFim(linha)) {
      break;
    }
    if (isVogal(linha)) {
      printf("SIM NAO NAO NAO\n");
    } else if (isInteiro(linha)) {
      printf("NAO NAO SIM SIM\n");
    } else if (isReal(linha)) {
      printf("NAO NAO NAO SIM\n");
    } else if (isConsoante(linha)) {
      printf("NAO SIM NAO NAO\n");
    } else {
      printf("NAO NAO NAO NAO\n");
    }
  } while (1);
  return 0;
}