
/*
2. Crie uma classe denominada Elevador para armazenar as informações de um elevador dentro de
um prédio. A classe deve armazenar o andar atual (térreo = 0), total de andares no prédio (des-
considerando o térreo), capacidade do elevador e quantas pessoas estão presentes nele. A classe
deve também disponibilizar os seguintes métodos: 

Inicializa : que deve receber como parâmetros a capacidade do elevador e o total de andares no prédio (os elevadores sempre começam no térreo e vazio); 

Entra : para acrescentar uma pessoa no elevador (só deve acrescentar se ainda houver
espaço); 

Sai : para remover uma pessoa do elevador (só deve remover se houver alguém dentro
dele); 

Sobe : para subir um andar (não deve subir se já estiver no último andar); 

Desce : paradescer um andar (não deve descer se já estiver no térreo); Encapsular todos os atributos da classe
(criar os métodos set e get)

*/
public class App {
    public static void main(String[] args) throws Exception {
        Elevador elevador = new Elevador();
        elevador.inicializa(7, 10);
        System.out.println(elevador.entra());
        System.out.println(elevador.entra());
        System.out.println(elevador.sobe());
        System.out.println(elevador.sobe());
        System.out.println(elevador.status());
        System.out.println(elevador.entra());
        System.out.println(elevador.desce());
        System.out.println(elevador.status());


    }
}

class Elevador {
    private int andarAtual;
    private int totalAndares;
    private int capacidade;
    private int pessoasPresentes;

    public void inicializa(int capacidade, int totalAndares) {
        this.capacidade = capacidade;
        this.totalAndares = totalAndares;
    }

    public String entra() {
        if (this.pessoasPresentes >= this.capacidade) {
            return "---- O elevador está cheio ----";
        } else {
            this.pessoasPresentes++;
            return "---- Pessoa adicionada com sucesso ----";
        }
    }

    public String sai() {
        if (this.pessoasPresentes > 0) {
            this.pessoasPresentes--;
            return "---- Pessoa removida com sucesso ----";
        } else {
            return "--- Não há ninguem no elevador ----";
        }
    }

    public String sobe() {
        if (this.andarAtual < this.totalAndares) {
            this.andarAtual++;
            String resposta = "---- Agora o elevador está no %sº andar ----";
            resposta = String.format(resposta, this.andarAtual);
            return resposta;
        } else {
            return "---- O elevador já está no último andar ----";
        }
    }

    public String desce() {
        if (this.andarAtual > 0) {
            this.andarAtual--;
            String resposta = "---- Agora o elevador está no %sº andar ----";
            resposta = String.format(resposta, this.andarAtual);
            return resposta;
        } else {
            return "---- O elevador já está no terreo ----";
        }
    }

    public String status() {
        String status = "=============status===========\nAndar atual: %s\nPessoas presentes: %s\nTotal de andares: %s\nCapacidade: %s\n=============================";
        status = String.format(status, this.andarAtual, this.pessoasPresentes, this.totalAndares, this.capacidade);
        return status;
    }

    // Getters e Setters
    public int getAndarAtual() {
        return andarAtual;
    }

    public void setAndarAtual(int andarAtual) {
        this.andarAtual = andarAtual;
    }

    public int getTotalAndares() {
        return totalAndares;
    }

    public void setTotalAndares(int totalAndares) {
        this.totalAndares = totalAndares;
    }

    public int getCapacidade() {
        return capacidade;
    }

    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }

    public int getPessoasPresentes() {
        return pessoasPresentes;
    }

    public void setPessoasPresentes(int pessoasPresentes) {
        this.pessoasPresentes = pessoasPresentes;
    }

}
