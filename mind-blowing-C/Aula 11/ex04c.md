# c. Faça um algoritmo que receba 3 (três) notas e seus respectivos pesos, calcule e mostre a média ponderada dessas notas.


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

