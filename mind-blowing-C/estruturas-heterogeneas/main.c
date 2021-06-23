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

/*
 *Trabalho de Acesso sequecial de arquivos
 * 20/06/2021
 * Algoritmos e Estruturas de dados - PUC Minas
 * Engenharia de Software;
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alunos.h"

#ifdef _WIN64
#include <windows.h>
void clear() { system("cls"); }
#elif _WIN32
#include <windows.h>
void clear() { system("cls"); }
#else
#include <unistd.h>
void clear() { printf("\033c"); }
#endif

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

/***
 * [] criar o arquivo pela primeira vez
 * [] cadastrar os alunos
 * - Gerar valores aleatórios para os alunos
 * [] exibir dados na tela
 */

typedef struct aluno {
  int id;
  char nome[20];
  int nota1;
  int nota2;
  int nota3;
} aluno;
void enterParaContinuar();
int exibirAlunos(int numeroAlunos, aluno *Alunos);
int cadastrarAluno(int numeroAlunos, aluno *Alunos);
int editarCadastro();
int excluirAluno();
int exportarDados();
int salvarDados();
int salvarSair();

bool alunosCadastrados = false;

int main() {
  clear();
  int escolha = 0;
  do {
    printf("             Seleciona uma opção:\n");
    printf(BOLDBLUE
           "[ 1 ] - Gerar uma lista com varios alunos ja cadastrados.\n" RESET);
    printf(BOLDCYAN "[ 2 ] - Cadastrar os alunos um por um.\n" RESET);
    printf(BOLDWHITE "Escolha: "RESET);
    scanf("%d", &escolha);
  } while (escolha <= 0 || escolha >= 3);

  int numeroAlunos = 0;
  aluno *Alunos;
  if (escolha == 1) {
    printf("\nQual o numero de alunos da turma? ");
    scanf("%d", &numeroAlunos);
    criarCsvAlunos(numeroAlunos);
    Alunos = (aluno *)malloc(numeroAlunos * sizeof(aluno));
    int contagem_de_linhas = 0, contagem_de_campos = 0;
    FILE *pFile;
    if ((pFile = fopen("alunos.txt", "r")) == NULL)  // Reading a file
    {
      printf("File could not be opened.\n");
    } else {
      char buffer[200];
      int i = 0;
      fgets(buffer, 200, pFile);
      while (!feof(pFile)) {
        sscanf(buffer, "%d %s %d %d %d", &Alunos[i].id, Alunos[i].nome,
               &Alunos[i].nota1, &Alunos[i].nota2, &Alunos[i].nota3);
        printf("lido: %d %s %d %d %d\n", Alunos[i].id, Alunos[i].nome,
               Alunos[i].nota1, Alunos[i].nota2, Alunos[i].nota3);
        fgets(buffer, 200, pFile);
        i++;
      }
    }
    fflush(stdin);
    fclose(pFile);
    alunosCadastrados = true;
  } else {
    alunosCadastrados = false;
    Alunos = (aluno *)malloc(sizeof(aluno));
  }
  fflush(stdout);
  int exec = 1;
  int opcao;
  
  do {
    
    printf("\nSelecione uma opção:\n");
    printf("= [ 1 ] - Exibir alunos cadastrados         =\n");
    printf("= [ 2 ] - Cadastrar aluno                   =\n");
    printf("= [ 3 ] - Editar cadastro de aluno          =\n");
    printf("= [ 4 ] - Excluir aluno                     =\n");
    printf("= [ 5 ] - Exportar dados                    =\n");
    printf("= [ 6 ] - Salvar Dados                      =\n");
    printf("= [ 7 ] - Salvar e Sair                     =\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
      clear();
        exibirAlunos(numeroAlunos, Alunos);
        break;
      case 2:
        cadastrarAluno(numeroAlunos, Alunos);
        numeroAlunos++;
        break;
      case 3:
        editarCadastro();
        break;
      case 4:
        excluirAluno();
        break;
      case 5:
        exportarDados();
        break;
      case 6:
        salvarDados();
        break;
      case 7:
        salvarSair();
        break;

      default:
        printf("função não chamada\n");
        clear();
        break;
    }
  } while (exec == 1);
  exibirAlunos(numeroAlunos, Alunos);

  return 0;
}
void enterParaContinuar(){
  char key;
  printf("\n\nPressione [ ENTER ] para continuar");
  scanf("%c", &key);
}
int exibirAlunos(int numeroAlunos, aluno *Alunos) {
  for (int j = 0; j < numeroAlunos; j++) {
    printf("------------------------\n");
    printf("ID: %d | Nome: %s\nNotas: [ 1:%d ] [ 2:%d ] [ 3:%d ]\n", Alunos[j].id,
           Alunos[j].nome, Alunos[j].nota1, Alunos[j].nota2, Alunos[j].nota3);
    printf("------------------------\n");
  }
}
int cadastrarAluno(int numeroAlunos, aluno *Alunos) {
  printf("\nFunção Chamada\n");
  if (!alunosCadastrados) {
    Alunos = (aluno *)realloc(Alunos, sizeof(aluno));
  }
  printf("\nQual o numero de matricula do aluno: ");
  scanf("%d", &Alunos[numeroAlunos].id);
  printf("\nQual nome do aluno: ");
  scanf("%s", Alunos[numeroAlunos].nome);
  printf("\nQual a primeira nota do aluno: ");
  scanf("%d", &Alunos[numeroAlunos].nota1);
  printf("\nQual a segunda nota do aluno: ");
  scanf("%d", &Alunos[numeroAlunos].nota2);
  printf("\nQual a terceira nota do aluno: ");
  scanf("%d", &Alunos[numeroAlunos].nota3);

  printf(BOLDGREEN "\nAluno Cadastrado com sucesso!\n" RESET);
  return 1;
}
int editarCadastro() { printf("\nFunção Chamada\n"); }
int excluirAluno() { printf("\nFunção Chamada\n"); }
int exportarDados() { printf("\nFunção Chamada\n"); }
int salvarDados() { printf("\nFunção Chamada\n"); }
int salvarSair() { printf("\nFunção Chamada\n"); }
