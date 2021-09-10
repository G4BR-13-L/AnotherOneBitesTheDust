/*
# EX01

Crie uma classe para representar uma pessoa, com os atributos privados de nome, sexo, peso e
altura. Crie os métodos públicos necessários para sets e gets e também um método para imprimir todos dados de uma pessoa.
Crie um método para calcular o imc da pessoa. Faça o teste com
duas pessoas, uma passando os valores dos atributos no construtor e outro passando os valores
por get e set.
*/

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Criando Pessoas...");
        Pessoa pessoa1 = new Pessoa("Fulano", "masculino", 70, 1.80);
        System.out.println("=== Pessoa 1 ===\n" + pessoa1.exibirDados() + "\n==================\n");

        Pessoa pessoa2 = new Pessoa();
        pessoa2.setNome("Fulana");
        pessoa2.setSexo("Feminino");
        pessoa2.setPeso(60);
        pessoa2.setAltura(1.70);
        System.out.println("=== Pessoa 2 ===\n" + pessoa2.exibirDados() + "\n==================\n");
        
    }
}

class Pessoa {

    private String nome;
    private String sexo;
    private float peso;
    private double altura;

    Pessoa(){

    }
    Pessoa(String nome, String sexo, float peso, double altura) {
        this.nome = nome;
        this.sexo = sexo;
        this.peso = peso;
        this.altura = altura;
    }
    // IMC
    public float imc(){
        float imc = this.peso / (float)Math.pow(this.altura, 2);
        return imc;
    }

    // Exibir dados
    public String exibirDados(){
        String dados = "Nome: %s\nSexo: %s\nPeso: %s\nAltura: %s\nIMC: %s";
        float imc = this.imc();
        dados = String.format(dados, this.nome, this.sexo, this.peso, this.altura, imc);
        return dados;
    }

    // GETTERS E SETTERS
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

}