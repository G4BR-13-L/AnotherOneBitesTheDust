import random
class color:
   BOLD = '\033[1m'
   END = '\033[0m'
   GREEN = '\033[92m'

print(color.BOLD + color.GREEN + "=====================================\nCódigo feito por Gabriel Victor Couto\nEngenharia de software - PUC Minas\n=====================================\n\n" + color.END)
print(color.BOLD + "Esse programa serve para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Ele também indica ao final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo usuário em no máximo 10 tentativas! Através de um número intermediário o programa pergunta ao usuário se o número é igual(=), maior(>) ou menor(<) que o que foi escolhido."+ color.END)

tentativas = 0
num = 512
aleatorio = 0
resposta = 0
correto = 0

while tentativas < 11:
    if(correto == 0 and tentativas < 10):
        resposta = 0;
        while(resposta <= 0 or resposta > 3):
            print("\nO numero que você está pensando é maior, menor ou igual a {}?" .format(num))
            resposta = int(input("[ Maior: 1 | Menor: 2 | Igual: 3 ] : "))
            if(resposta <= 0 or resposta > 3):
                print(color.BOLD + "\n\n===========Por favor digite valores válidos============\n\n" + color.END)
                resposta = 0
        if resposta == 1:
            aleatorio = random.randint(num,1023)
            num = aleatorio
        elif resposta == 2:
            aleatorio = random.randint(1,num)
            num = aleatorio
        elif resposta == 3:
            correto = 1
        else:
            print(color.BOLD + "=====ERRO DE PROGRAMAÇÃO=====" + color.END)
            tentativas = 20
        
    elif(correto == 1 or tentativas <= 10):
        print(color.BOLD + "\n\nO numero é: {}\nAcertei depois de {} tentativas" .format(num, tentativas) + color.END)
        tentativas = 20
    elif(correto == 0 or tentativas > 10):
        print(color.BOLD + "\n\nNão consegui adivinhar o seu número com as tentativas programadas ;-;" + color.END)
    else:
        print(color.BOLD + "\n\n=====ERRO DE PROGRAMAÇÃO=====" + color.END)
    
    tentativas += 1
print(color.BOLD + "\n\n\nFIM!!\n\n\n" + color.END)
    