import java.util.Scanner;

/*

Criar uma classe Carro com pelo menos 3 atributos e 3 métodos a seu critério. Criar uma classe Aplicativo (ou Main) com o metodo main e testar seu carro.
*/
class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");

    Carro car = new Carro();
    Scanner leitor = new Scanner(System.in);
    System.out.println("CARRO CRIADO");
    System.out.println("Qual o modelo do seu novo carro?");
    String fabricanteCarro = leitor.nextLine();
    car.setFabricante(fabricanteCarro);
    car.clearScreen();

    


  }

}

/**
class Batmovel extends carro
class DeLorean extends carro
class Xwing extends carro
class  

*/