
import java.util.Scanner;

class Main{
  public static void main(String args[]){
    
    System.out.println("\033[1m\033[32m=====================================\nCódigo feito por Gabriel Victor Couto\nEngenharia de software - PUC Minas\n=====================================\n\n\033[0m");

    System.out.println("\033[1m\033[37mEsse programa serve para adivinhar um número escolhido pelo usuário, entre 1 e 1023. Ele também indica ao final quantas tentativas foram necessárias. O programa deverá localizar o número escolhido pelo usuário em no máximo 10 tentativas! Através de um número intermediário o programa pergunta ao usuário se o número é igual(=), maior(>) ou menor(<) que o que foi escolhido.\n\n\033[0m");

    int tentativas = 0, num = 512, aleatorio, resposta = 0, correto = 0;
    Scanner ler = new Scanner(System.in);
    do{
        if(correto == 0 && tentativas < 10){
            resposta = 0;
            while(resposta <= 0 || resposta > 3){
                System.out.println("\nO numero que você está pensando é maior, menor ou igual a "+num+"?")  ;
                System.out.println("\n[ Maior: 1 | Menor: 2 | Igual: 3 ] : ");
                resposta = Integer.parseInt(ler.nextLine());
                if(resposta <= 0 || resposta > 3){
                    System.out.println("\033[1m\033[37m\n\n===========Por favor digite valores válidos============\n\033[0m");
                    resposta = 0;
                }
            }
            switch (resposta){
                case 1:
                    aleatorio = (int)(Math.random() * (1023 - num + 1) + num);
                    num = aleatorio;
                break;
                case 2:
                    aleatorio = (int)(Math.random() * (num - 1 + 1) + 1); 
                    num = aleatorio;
                break;
                case 3:
                    correto = 1;
                break;
                
                default:
                System.out.println("\033[1m\033[37m\n=====ERRO DE PROGRAMAÇÃO=====\033[0m");
                    break;
            }
        }else if(correto == 1 && tentativas <= 10){
                System.out.println("\033[1m\033[37m\nO numero é: "+num+"\nAcertei depois de "+tentativas+" tentativas\033[0m");
                tentativas = 12;
        }else if(correto == 0 || tentativas > 10){
                System.out.println("\033[1m\033[37m\nNão consegui adivinhar o seu número com as tentativas programadas ;-;\033[0m");
        }else{
                System.out.println("\033[1m\033[37m\n=====ERRO DE PROGRAMAÇÃO=====\033[0m");
        }
        tentativas++;   
        
    }while(tentativas <= 10);
    System.out.println("\033[1m\033[37m\n\n\nFIM!!\n\n\n");
  }
}
