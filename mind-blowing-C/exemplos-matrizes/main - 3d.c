#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
const int linha=5;
const int coluna=5;
const int dimensao=3;
int ***preenchematriz(int d,int l, int c);
int main()
{
    setlocale(LC_ALL,"portuguese");
    int ***m;
    int i,j,k;
    m=preenchematriz(dimensao,linha,coluna);
    for (i=0; i<dimensao; i++)
    {
        printf("Dimensão:%i\n",i);
        for (j=0; j<linha; j++)
        {
            printf("linha:%i\n",j);
            for (k=0; k<coluna; k++)
            {
                printf("%3i",m[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
int ***preenchematriz(int d,int l, int c)
{
    int v=1;
    aluno ***m;
    m=malloc(sizeof(int*)*d);
    for (int i=0; i<d; i++)
    {
        m[i]=malloc(sizeof(int*)*l);
        for (int j=0; j<l; j++)
        {
            m[i][j]=malloc(sizeof(int)*c);
        }
    }

    for (int i=0; i<d; i++)
    {
        for (int j=0; j<l; j++)
        {
            for (int k=0; k<c; k++)
            {
                m[i][j][k]=v++;
            }
        }
    }
    return m;
}
