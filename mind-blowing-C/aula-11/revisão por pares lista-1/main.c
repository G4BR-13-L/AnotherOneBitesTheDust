#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int exa();
int exb();
int exc();
int exd();
int exe();
int exf();
int exg();
int exh();
int exi();
int exj();

int main()
{
    setlocale(LC_ALL,"portuguese");
    exa();
    fflush(stdin); //limpar a entrada de dados
    getchar( ); //aguardar por enter
    system("cls"); //limpar a tela
    exb(); //próximo exercício
    exc();
    exd();
    exe();
    exf();
    exg();
    exh();
    exi();
    exj();
    return 0;
}
int exa()
{
    int num, suc;
    printf("a. leia um número e imprima seu sucessor\n");
    printf("-------------------------------------------\n");
    printf("Digite um número: ");
    scanf("%i", &num);
    suc=num+1;
    printf("Seu sucessor é %i", suc);
    printf("\nAperte ENTER para continuar...");
    return 0;
}
int exb()
{
    int n1,n2,n3,n4;
    float soma,media;
    printf("b. calcule a média aritmética de quatro números inteiros dados\n");
    printf("--------------------------------------------------------------\n");
    printf("Digite quatro números inteiros\n");
    printf("primeiro número: ");
    scanf("%i",&n1);
    printf("Segundo número: ");
    scanf("%i",&n2);
    printf("Terceiro número: ");
    scanf("%i",&n3);
    printf("Quarto número: ");
    scanf("%i",&n4);
    soma=n1+n2+n3+n4;
    media=soma/4;
    printf("A média desses quatro números é %.2f",media);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exc()
{
    float n1,n2,n3,p1,p2,p3;
    float soma,peso,media;
    printf("c. faça um algoritmo que receba 3 notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("Digite três notas e seus respectivos pesos\n");
    printf("Primeira nota: ");
    scanf("%f",&n1);
    printf("peso: ");
    scanf("%f",&p1);
    printf("segunda nota: ");
    scanf("%f",&n2);
    printf("peso: ");
    scanf("%f",&p2);
    printf("terceira nota: ");
    scanf("%f",&n3);
    printf("peso: ");
    scanf("%f",&p3);
    soma=((n1*p1)+(n2*p2)+(n3*p3));
    peso=p1+p2+p3;
    media=(soma/peso);
    printf("A média ponderada das notas é %.2f", media);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exd()
{
    float celsi,fahre;
    printf("d. leia uma temperatura dada na escala celsius e imprima o equivalente em fahrenheit\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("Digite a temperatura em graus celcius: ");
    scanf("%f",&celsi);
    fahre=(celsi*9/5)+32;
    printf("Essa temperatura em fahrenheit é %.2f",fahre);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exe()
{
    float sal,paum,nsal;
    printf("e. faça um algoritmo que receba o salário de um funcionário e o percentual de aumento, calcule e mostre o novo salário\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("Digite o salário do funcionário: ");
    scanf("%f",&sal);
    printf("Digite o percentual de aumento do seu novo salário: ");
    scanf("%f",&paum);
    nsal=sal+((paum/100)*sal);
    printf("O novo salário do funcionário será R$%.2f",nsal);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exf()
{
    float base,altura;
    float area;
    printf("f. faça um algoritmo que peça ao usuário a base e a altura e calcule a área de um triângulo\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("Digite a base do triângulo: ");
    scanf("%f",&base);
    printf("Digite a altura do triângulo: ");
    scanf("%f",&altura);
    area=(base*altura)/2;
    printf("A área do triângulo é %.2f",area);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exg()
{
    float saco5,dia5,sg,pg,sr;
    printf("g. Pedro comprou um saco de ração com peso em quilos.\n");
    printf("Pedro possui dois gatos para os quais fornece a quantidade de ração em gramas.\n");
    printf("Faça um algoritmo que receba o peso do saco de ração e a quantidade de ração fornecida para cada gato.\n");
    printf("Calcule e mostre quanto restará de ração no saco após cinco dias.\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("Digite a quantidade de ração do saco em quilogramas: ");
    scanf("%f",&sr);
    printf("Digite em gramas a quantidade de ração fornecida para cada gato em um dia\n");
    printf("primeiro gato: ");
    scanf("%f",&pg);
    printf("segundo gato: ");
    scanf("%f",&sg);
    dia5=(pg+sg)*5;
    saco5=(sr*1000)-dia5;
    printf("Em cinco dias, a quantidade restante de ração no saco será %.2fg",saco5);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exh()
{
    int a,b,c;
    printf("h. Leia dois números inteiros para variáveis a e b. Troque o valor de b com o de a e os imprima\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("Digite um valor inteiro para a: ");
    scanf("%i",&a);
    printf("Digite um valor inteiro para b: ");
    scanf("%i",&b);
    c=a;
    a=b;
    b=c;
    printf("a=%i\n",a);
    printf("b=%i",b);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exi()
{
    int num,resto;
    printf("i. Leia um número e imprima o resto da divisão por 7\n");
    printf("-------------------------------------------------\n");
    printf("Digite um número inteiro: ");
    scanf("%i",&num);
    resto=(num%7);
    printf("O resto da divisão é %i",resto);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
int exj()
{
    int t1,t2,nt,raz;
    float ultimot,soma;
    printf("j. calcule a soma dos termos de uma P.A lendo os valores\n");
    printf("do primeiro termo, do segundo termo e do número de termos\n");
    printf("---------------------------------------------------------\n");
    printf("Digite o primeiro termo: ");
    scanf("%i",&t1);
    printf("Digite o segundo termo: ");
    scanf("%i",&t2);
    printf("Digite o número de termos da P.A: ");
    scanf("%i",&nt);
    raz=t2-t1;
    ultimot=t1+(nt-1)*raz;
    soma=nt*(t1+ultimot)/2;
    printf("A soma dos termos dessa P.A. é %.2f",soma);
    printf("\nAperte ENTER para continuar...");
    fflush(stdin);
    getchar( );
    system("cls");
    return 0;
}
