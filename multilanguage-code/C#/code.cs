using System;
class MainClass{
  public static void Main (string[] args){
    Console.ForegroundColor = ConsoleColor.Green;
    Console.Write("\x1b[1m=====================================\nCódigo feito por Gabriel Victor Couto\nEngenharia de software - PUC Minas\n=====================================\n\n\x1b[0m");
    Console.ResetColor();

    Console.Write("\x1b[1mEsse programa serve para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Ele também indica ao final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo usuário em no máximo 10 tentativas! Através de um número intermediário o programa pergunta ao usuário se o número é igual(=), maior(>) ou menor(<) que o que foi escolhido.\n\n\x1b[0m");
    Random rand = new Random();
    int tentativas = 0, num = 512, aleatorio, resposta = 0, correto = 0;

    do{
        if(correto == 0 && tentativas < 10){
            resposta = 0;
            while(resposta <= 0 || resposta > 3){
                Console.Write("\nO numero que você está pensando é maior, menor ou igual a "+num+"?")  ;
                Console.Write("\n[ Maior: 1 | Menor: 2 | Igual: 3 ] : ");
                resposta = Convert.ToInt32(Console.ReadLine());
                if(resposta <= 0 || resposta > 3){
                    Console.Write("\x1b[1m\n\n===========Por favor digite valores válidos============\n\x1b[0m");
                    resposta = 0;
                }
            }
            switch (resposta){
                case 1:
                    aleatorio = rand.Next(num,1023);
                    num = aleatorio;
                break;
                case 2:
                    aleatorio = rand.Next(1,num);
                    num = aleatorio;
                break;
                case 3:
                    correto = 1;
                break;
                
                default:
                Console.Write("\x1b[1m\n=====ERRO DE PROGRAMAÇÃO=====\x1b[0m");
                    break;
            }
        }else if(correto == 1 && tentativas <= 10){
                Console.Write("\x1b[1m\nO numero é: "+num+"\nAcertei depois de "+tentativas+" tentativas\x1b[0m");
                tentativas = 12;
        }else if(correto == 0 || tentativas > 10){
                Console.Write("\x1b[1m\nNão consegui adivinhar o seu número com as tentativas programadas ;-;\x1b[0m");
        }else{
                Console.Write("\x1b[1m\n=====ERRO DE PROGRAMAÇÃO=====\x1b[0m");
        }
        tentativas++;   
        
    }while(tentativas <= 10);
    Console.Write("\x1b[1m\n\n\nFIM!!\n\n\n\x1b[0m");
  }
}