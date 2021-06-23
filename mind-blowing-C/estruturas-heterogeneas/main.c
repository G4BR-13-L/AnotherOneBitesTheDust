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
int enterParaContinuar();
int exibirAlunos(int numeroAlunos, aluno *Alunos);
int cadastrarAluno(int numeroAlunos, aluno *Alunos);
int editarCadastro(int numeroAlunos, aluno *Alunos);
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
    printf(BOLDWHITE "Escolha: " RESET);
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
    clear();
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
        clear();
        cadastrarAluno(numeroAlunos, Alunos);
        numeroAlunos++;
        break;
      case 3:
        clear();
        editarCadastro(numeroAlunos, Alunos);
        break;
      case 4:
        clear();
        excluirAluno();
        break;
      case 5:
        clear();
        exportarDados();
        break;
      case 6:
        clear();
        salvarDados();
        break;
      case 7:
        clear();
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
int enterParaContinuar() {
  int key;
  printf("\n\nPressione [ 9 ] para continuar");
  scanf("%d", &key);
}
int exibirAlunos(int numeroAlunos, aluno *Alunos) {
  for (int j = 0; j < numeroAlunos; j++) {
    printf("------------------------\n");
    printf("ID: %d | Nome: %s\nNotas: [ 1:%d ] [ 2:%d ] [ 3:%d ]\n",
           Alunos[j].id, Alunos[j].nome, Alunos[j].nota1, Alunos[j].nota2,
           Alunos[j].nota3);
    printf("------------------------\n");
  }
  enterParaContinuar();
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
  return 0;
}
int editarCadastro(int numeroAlunos, aluno *Alunos) {
  for (int j = 0; j < numeroAlunos; j++) {
    printf("------------------------\n");
    printf("ID: %d | Nome: %s\n", Alunos[j].id, Alunos[j].nome);
    printf("------------------------\n");
  }
  int alunoEncontrado = 0;
  do {
    int id;
    printf("Digite o ID do aluno que deseja editar: ");
    scanf("%d", &id);
    int k = 0;
    for (k; k < numeroAlunos; k++) {
      if (id == Alunos[k].id) {
        printf(BOLDBLUE "\n[ Aluno encontrado ]" RESET);
        alunoEncontrado = 1;
        break;
      }
    }
    if (alunoEncontrado) {
      printf("\n------------------------\n");
      printf("ID: %d | Nome: %s\nNotas: [ 1:%d ] [ 2:%d ] [ 3:%d ]\n",
             Alunos[k].id, Alunos[k].nome, Alunos[k].nota1, Alunos[k].nota2,
             Alunos[k].nota3);
      printf("------------------------\n");
      int dado = 0;
      char novoNome[30];
      int novaNota;
      do {
        printf("\n Qual dado deseja editar? ");
        printf("\n===========================");
        printf("\n= [ 1 ] - Nome            =");
        printf("\n= [ 2 ] - Nota 1          =");
        printf("\n= [ 3 ] - Nota 2          =");
        printf("\n= [ 4 ] - Nota 3          =");
        printf("\n===========================");
        printf("\nDado: ");
        scanf("%d", &dado);
        switch (dado) {
          case 1:
            printf("\nDigite o novo nome do aluno: ");
            scanf("%s", novoNome);
            strcpy(Alunos[k].nome, novoNome);
            break;
          case 2:
            printf("\nDigite a nova nota 1 para o aluno: ");
            scanf("%d", &novaNota);
            Alunos[k].nota1 = novaNota;
            break;
          case 3:
            printf("\nDigite a nova nota 2 para o aluno: ");
            scanf("%d", &novaNota);
            Alunos[k].nota2 = novaNota;
            break;
          case 4:
            printf("\nDigite a nova nota 3 para o aluno: ");
            scanf("%d", &novaNota);
            Alunos[k].nota3 = novaNota;
            break;
          default:
            printf(BOLDRED "\n[ ERRO ] - Opção inexistente\n" RESET);
            break;
        }
      } while (dado < 1 || dado > 4);
      alunoEncontrado = 1;
      printf(BOLDGREEN "\nDados alterados com sucesso\n" RESET);
    } else {
      int tentarNovamente;
      printf(BOLDRED "\n[ ERRO ] - Aluno não encontrado.\n" RESET);
      printf(BOLDWHITE"Para tentar novamente digite [ 1 ]\n");
      printf(BOLDWHITE"Para cancelar a operação de cadastro digite [ 2 ]\n");
      scanf("%d", &tentarNovamente);
      clear();
      if(tentarNovamente == 1){
        alunoEncontrado = 0;
        clear();
      }else{
        alunoEncontrado = 1;
        printf(BOLDRED "\n[ Operação cancelada ] \n" RESET);
      }
    }
  } while (alunoEncontrado == 0);
}
int excluirAluno() { printf("\nFunção Chamada\n"); }
int exportarDados() { printf("\nFunção Chamada\n"); }
int salvarDados() { printf("\nFunção Chamada\n"); }
int salvarSair() { printf("\nFunção Chamada\n"); }
