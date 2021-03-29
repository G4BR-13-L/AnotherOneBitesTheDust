# Exercício 4
##### Autor: Gabriel Victor Couto
## a. Leia um número e imprima seu sucessor.
```javascript
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
}
```
## b. Calcule a média aritmética de quatro números inteiros dados.

```javascript
inicio
    var a, b, contador: inteiro
    var media: real
    contador <- 0
    enquanto(contador<4)faça
        escreva("Digite um valor: ")
        leia(a)
        b <- a + b
    fimenquanto 
    media <- b / 4
    escreva("A média aritimética é:" + media)   
fim
```
## c. Faça um algoritmo que receba 3 (três) notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas.


```javascript
inicio
    var nota, peso, valorNota, valorPeso contador: inteiro
    var media:real
    contador <- 0
    enquanto(contador < 3)faça
        escreva("Digite a nota: ")
        leia(nota)
        escreva("Digite um peso para essa nota: ")
        leia(peso)
        valorPeso <- valorPeso + peso
        valorNota <- valorNota + nota * peso
    fimenquanto
    media <- valorNota / 3
    escreva("A media ponderada é: " + valorNota)
fim
```