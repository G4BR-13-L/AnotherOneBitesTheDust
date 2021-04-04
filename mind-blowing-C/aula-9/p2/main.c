#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pow.h>

int main()
{
    float h,r,areaBase,v,y;
    printf("Digite a altura do cilindro: \n");
    scanf("%d", &h);
    printf("Digite o raio da base do cilindro: \n");
    scanf("%d", &r);
    y = pow(r,2);
    areaBase = 3,14195*y;
    v = areaBase*h;
    printf("Volume do cilindro é %f \n", v);
    return 0;

}
