#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    file =fopen("gabriel.txt","w");
    int N,i,x,cont,j;
    cont =0;
    printf("Insira um numero:\n");
    scanf("%d",&N);
    for (i=0; i<N; i++)
    {
        x=(66+(rand() % 10));
       fprintf(file,"%d\n",x);
    }
    fclose(file);

    FILE *file2;
    file2=fopen("gabriel1.txt","w");
    file=fopen("gabriel.txt","r");
    int v[N];
    int v2[N];
    for (i=0; i<N; i++)
    {
        fscanf(file,"%d",&v[i]);
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<cont; j++)
        {
            if(v[i]==v2[j])
            {
                break;
            }
        }
        if (j==cont)
        {
            v2[cont]=v[i];
            cont++;
        }
    }
    for (i=0; i<cont; i++)
    {
        if(v2[i]%3==0)
        {
          fprintf(file2,"O numero %d e divisivel por 3\n",v2[i]);
        }
        else
        {
           fprintf(file2,"O numero %d nao e divisivel por 3\n",v2[i]);
        }
    }
    fclose(file2);
    return 0;
}

