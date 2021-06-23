#include <stdio.h>
#include <stdlib.h>
const int linha=5;
const int coluna=5;
int **preenchematriz(int l, int c);
int main()
{
    int **m;
    int i,j;
    m=preenchematriz(linha,coluna);
    for (i=0;i<linha;i++)
    {
        for (j=0;j<coluna;j++)
        {
            printf("%3i",m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int **preenchematriz(int l, int c)
{
    int v=1;
    int **m;
    m=malloc(sizeof(int*)*l);
    for (int i=0;i<l;i++)
    {
        m[i]=malloc(sizeof(int)*c);
    }
    for (int i=0;i<linha;i++)
    {
        for (int j=0;j<coluna;j++)
        {
            m[i][j]=v++;
        }
    }
  return m;
}
