# Exercício 4
##### Autor: Gabriel Victor Couto Martins de Paula
### a. Leia um número e imprima seu sucessor.
```go
inicio
    var a: inteiro
    escreva("Digite um numero: ")
    leia(a)
    escreva(a+1)
fim
```

```c
#include <stdio.h>

int main(){
    int a;
    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("\n %d \n \n", a+1);
    return 0;
}
```
### b. Calcule a média aritmética de quatro números inteiros dados.

```go
inicio
    var a, b, c, d: inteiro
    var media: real
    escreva("Digite um valor: ")
    leia(a)
    escreva("Digite outro valor: ")
    leia(b)
    escreva("Digite outro valor: ")
    leia(c)
    escreva("Digite mais um valor: ")
    leia(d)
    media <- ( a + b + c + d ) / 4
    escreva("A média aritimética é:" + media)   
fim
```
```c
#include <stdio.h>

int main(){
    int a, b, c, d; 
    float media;
    printf("Digite um valor: ");
    scanf("%d", &a);
    printf("Digite outro valor: ");
    scanf("%d", &b);
    printf("Digite outro valor: ");
    scanf("%d", &c);
    printf("Digite mais um valor: ");
    scanf("%d", &d);
    media = (a + b + c + d ) / 4;
    printf("\nA média aritmética é: %.2f\n", media);
    return 0;
}
```

### c. Faça um algoritmo que receba 3 (três) notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas.


```go
inicio
    var n1, n2, n3, p1, p2, p3: inteiro
    var media:real
    escreva("Digite os valores das notas:: ")
    escreva("n1: ")
    leia(n1)
    escreva("n2: ")
    leia(n2)
    escreva("n3: ")
    leia(n3)
    escreva("Digite os valores dos pesos respectivamente:: ")
    escreva("p1: ")
    leia(p1)
    escreva("p2: ")
    leia(p2)
    escreva("p3: ")
    leia(p3)
    media <- ( ( n1 * p1 ) + ( n2 * p2 ) + ( n3 * p3 ) ) / ( p1 + p2 + p3 );
    escreva("Media ponderada é: " + media)
fim
```
```c
#include <stdio.h>

int main(){
    int n1, n2, n3, p1, p2, p3; 
    double media;
    printf("Digite os valores das notas:: \n");
    printf("\nn1: ");
    scanf("%d", &n1);
    printf("\nn1: ");
    scanf("%d", &n2);
    printf("\nn1: ");
    scanf("%d", &n3);
    printf("\nDigite os valores dos pesos respectivamente:: \n");
    printf("\np1: ");
    scanf("%d", &p1);
    printf("\np2: ");
    scanf("%d", &p2);
    printf("\np3: ");
    scanf("%d", &p3);
    media = ( ( n1 * p1 ) + ( n2 * p2 ) + ( n3 * p3 ) ) / ( p1 + p2 + p3);
    printf("\nMédia ponderada: %.2f \n\n", media );
    return 0;
}
```

### d. Leia uma temperatura dada na escala Celsius (C) e imprima o equivalente em Fahrenheit (F).
> Fórmula de conversão: F = 9/5 * C + 32

>Implemente uma alteração neste exercício para verificar o resultado.

```go
importe matemática
inicio
    var c, verificação : inteiro
    var f: real
    escreva("Digite o valor em °C: ")
    leia(c)
    f <- ( (c * 9) / 5 ) + 32;
    verificação <- arredondamento(( f - 32 ) * 5 / 9);
    se ( verificação = c) então
        escreva("O valor em Fahrenheit é: " + f)
        escreva("verificação: " + verificação)
    senão
        escreva("O programa flahou, e a formula não foi utilizada corretamente")
        escreva("f: " + f)
        escreva("verificação: " + verificação)
    fimse
fim
```
```c
#include <stdio.h>
#include <math.h>

int main(){
    int c;
    float f, verification;
    printf("Digite o valor em °C: ");
    scanf("%d", &c);
    f = ( (c * 9) / 5 ) + 32;
    verification = round(( f - 32 ) * 5 / 9);
    if( verification == c){
        printf("O valor em Fahrenheit é: %.f°\n\n", f);
        printf("\nverificação: %.2f°\n", verification);
    }else{
        printf("O programa flahou, e a formula não foi utilizada corretamente\n");
        printf("\nf: %.2f°", f);
        printf("\nverificação: %.2f°\n", verification);       
    }
    return 0;

}
```

### e. Faça um algoritmo que receba o salário de um funcionário e o percentual de aumento, calcule e mostre o novo salário.

```go
inicio
    var salario, percentual: inteiro
    var aumento, novoSalario: real
    ecreva("Digite o valor do salário: ")
    leia(salario)
    escreva("Digite o percentual de aumento: ")
    leia(percentual)
    aumento <-  salario *  percentual / 100 
    novoSalario <- salario + aumento
    escreva("Valor do aumento: " + aumento)
    escreva("O salário com aumento: " + novoSalario)
fim
```
```c
#include <stdio.h>
#include <math.h>

int main(){
    int salario, percentual;
    double aumento, novoSalario;
    printf("Digite o valor do salário: ");
    scanf("%d", &salario); 
    printf("\nDigite o percentual de aumento: ");
    scanf("%d", &percentual);
    aumento = salario * percentual / 100;
    novoSalario = salario + aumento;
    printf("\nValor do aumento: %5.2f", aumento);
    printf("\nO salário com aumento: %5.2f\n", novoSalario);
    return 0;

}
```
### f. Faça um algoritmo que peça ao usuário a base e a altura e calcule a área de um triangulo.
```go
inicio
    var base, altura: inteiro
    var area: real
    ecreva("Digite a base do triangulo: ")
    leia(base)
    escreva("Digite a altura do triangulo: ")
    leia(altura)
    area <- ( base * altura ) / 2
    escreva("Área: " + area)
fim
```
```c
#include <stdio.h>

int main(){
    int base, altura;
    float area;
    printf("Digite a base do triangulo: ");
    scanf("%d", &base);
    printf("\nDigite a altura do triangulo: ");
    scanf("%d", &altura);
    area = ( base * altura ) / 2;
    printf("\nÁrea: %.2f\n\n", area);
    return 0;
}
```
### g. Pedro comprou um saco de Ração com peso em quilos. Pedro possui 2 (dois) gatos para os quais fornece a quantidade de ração em gramas. Faça um algoritmo que receba o peso do Saco de ração e a quantidade de ração fornecida para cada gato. Calcule e mostre quanto restará de ração no saco após 5 (cinco) dias
```go
inicio
    var peso, porção: inteiro
    var restante: real
    ecreva("Digite o peso do scao de ração(Kg): ")
    leia(peso)
    escreva("Digite a porção para cada gato(g): ")
    leia(porção)
    peso <- peso * 1000;
    restante <- peso - porção * 2 * 5;
    restante <- restante / 1000
    se( (restante > 0) ou (restante = 0))então
        escreva("Restarão " + restante + "Kg de ração no saco após 5 dias")
    senão
        escreva( ( restante * -1 ) + "Kg é o que falta de ração para alimentar os gatos")
    fimse
fim
```
```c
#include <stdio.h>

int main(){
    int weight, portion;
    float rest;
    printf("Digite o peso do saco de ração(Kg): ");
    scanf("%d", &weight);
    printf("\nDigite a porção para cada gato(g): ");
    scanf("%d", &portion);
    weight = weight * 1000;
    rest = weight - portion * 2 * 5;
    rest = rest / 1000;
    if( ( rest > 0 ) || ( rest == 0 ) ){
        printf("\nRestarão %.0fKg de ração no saco após 5 dias\n\n", rest);
    }else{
        printf("\n%.0fKg é o que falta de ração para alimentar os gatos\n\n", rest * -1);
    }
    return 0;
}
```


### h. Ler dois números inteiros para variáveis A e B. Trocar o valor de b com o de a, e imprimi-los.
```go
inicio
    var a, b: inteiro
    ecreva("Digite o primeiro numero: ")
    leia(a)
    escreva("Digite o segundo numero: ")
    leia(b)
    escreva("a = "+ a + " = " + a + " + " + b )
    a <- a + b
    escreva("b = "+ a + " = " + a + " - " + b )
    b <- a - b
    escreva("a = "+ a + " = " + a + " - " + b )
    a <- a - b
    escreva("Agora a vale " + a + " e b vale " + b )
fim
```
```c
#include <stdio.h>

int main(){
    int a, b;
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);   
    printf("\nDigite o segundo numero: ");
    scanf("%d", &b);
    printf("\na =  %d  =  %d +  %d", a, a, b); 
    a = a + b;
    printf("\nb =  %d  =  %d -  %d", b, a, b);
    b = a - b;
    printf("\na =  %d  =  %d -  %d", a, a, b);
    a = a - b;
    printf("\nAgora a vale %d e b vale %d\n\n", a, b);
    return 0;
}
```
### i. Leia um número e imprima o resto da divisão por 7. Utilize o comando resto (a,b) na linguagem C (a % b).
```go
inicio
    var num: inteiro
    var resto: real
    escreva("Digite um numero")
    leia(num)
    resto = num % 7 
    escreva("O resto da divisão de " + num + " por 7 é: " + resto )
fim
```
```c
#include <stdio.h>

int main(){
    int num;
    double rest;
    printf("Digite um numero: ");
    scanf("%d", &num);
    rest = num % 7;
    printf("O resto da divisão de %d por 7 é: %.2f\n\n", num, rest);
    return 0;
}
```
### j. Calcular a soma dos termos de uma P.A. lendo os valores do primeiro termo, do segundo termo e do número de termos. formulas:


> $$
>S_{n} = n * \frac{( a1 + an )} {2}
>$$
>onde $S_{ n }$  é a soma dos termos, $a_{ 1 }$ o primeiro termo e $a_{n}$ o último termo. O n-ésimo termo de uma
progressão aritmética, pode ser obtido por meio da formula: 
>$$
>a_{n}=a_{1}+(n-1).r
>$$
>onde $r$ é a razão da P.A

```go
inicio
    var a1, a2, an, n, Sn: real
    escreva("Digite o primeiro termo: ")
    leia(a1)
    escreva("Digite o segundo termo: ")
    leia(a2);
    escreva("Quantos termos tem a progressão? ")
    leia(n)
    r <- a2 - a1
    an <- a1 + ( n - 1 ) * r
    Sn <- n * ( ( a1 + an ) / 2 )
    escreva("A soma de todos os termos da progressão é: " + Sn)
fim
```
```c
#include <stdio.h>

int main(){
    float a1, a2, an, n, r, Sn;
    printf("Digite o primeiro termo: ");
    scanf("%f", &a1);
    printf("Digite o segundo termo: ");
    scanf("%f", &a2);
    printf("Quantos termos tem a progressão? ");
    scanf("%f", &n);  
    r = a2 - a1;
    an = a1 + ( n - 1 ) * r;
    Sn = n * ( ( a1 + an ) / 2 );
    printf("A soma de todos os termos da progressão é: %.2f\n\n", Sn);
    return 0;
}
```