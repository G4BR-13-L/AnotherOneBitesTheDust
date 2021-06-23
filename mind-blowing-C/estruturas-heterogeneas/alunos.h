#ifndef ALUNOS_H
#define ALUNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int randomNumber(int inicial, int final);

void criarCsvAlunos(int numeroAlunos) {
  FILE* fp;
  int i, count, id, micro, dcn, ds, rd;
  struct aluno {
    int id;
    char nome[20];
    int nota1;
    int nota2;
    int nota3;
  };
  struct aluno objectAluno[numeroAlunos];
    for(int i = 0 ; i < sizeof(objectAluno)/sizeof(objectAluno[0]) ; i++){
        objectAluno[i].id = i;
        sprintf(objectAluno[i].nome, "%s", "semnome");
        objectAluno[i].nota1 = randomNumber(0, 100);
        objectAluno[i].nota2 = randomNumber(0, 100);
        objectAluno[i].nota3 = randomNumber(0, 100);
    }
    printf("\nCriando Arquivo alunos.csv\n");
  fp = fopen("alunos.txt", "w+");
  for (int i = 0 ; i < sizeof(objectAluno)/sizeof(objectAluno[0]) ; i++) {
    fprintf(fp, "%d %s %d %d %d\n",objectAluno[i].id, objectAluno[i].nome, objectAluno[i].nota1, objectAluno[i].nota2, objectAluno[i].nota3);
  }
  fclose(fp);

  printf("\nalunos.csv Criado com SUCESSO\n");
}

int randomNumber(int inicial, int final) {
  int x;
  do {
    x = (rand() % (final - inicial + 1)) + inicial;
  } while (x < inicial);
  return x;
}

#endif