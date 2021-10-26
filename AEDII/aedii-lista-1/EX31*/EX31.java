
/*
=====================================================
Código desenvolvido por:
 ██████╗  █████╗ ██████╗ ██████╗ ██╗███████╗██╗
██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██║██╔════╝██║
██║  ███╗███████║██████╔╝██████╔╝██║█████╗  ██║
██║   ██║██╔══██║██╔══██╗██╔══██╗██║██╔══╝  ██║
╚██████╔╝██║  ██║██████╔╝██║  ██║██║███████╗███████╗
 ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝
 =====================================================
*/
import java.net.*;
import java.util.Scanner;

public class EX31 {
    public static void main(String[] args) throws Exception {
        Dicionario dicionario = new Dicionario();
        dicionario.adiciona("UUU", "Fenilalanina");
        dicionario.adiciona("UUC", "Fenilalanina");
        dicionario.adiciona("UUA", "Leucina");
        dicionario.adiciona("UUG", "Leucina");
        dicionario.adiciona("CUU", "Leucina");
        dicionario.adiciona("CUC", "Leucina");
        dicionario.adiciona("CUA", "Leucina");
        dicionario.adiciona("CUG", "Leucina");
        dicionario.adiciona("AUU", "Isoleucina");
        dicionario.adiciona("AUC", "Isoleucina");
        dicionario.adiciona("AUA", "Isoleucina");
        dicionario.adiciona("AUG", "Metionina");
        dicionario.adiciona("GUU", "Valina");
        dicionario.adiciona("GUC", "Valina");
        dicionario.adiciona("GUA", "Valina");
        dicionario.adiciona("GUG", "Valina");
        dicionario.adiciona("UCU", "Serina");
        dicionario.adiciona("UCC", "Serina");
        dicionario.adiciona("UCA", "Serina");
        dicionario.adiciona("UCG", "Serina");
        dicionario.adiciona("CCU", "Prolina");
        dicionario.adiciona("CCC", "Prolina");
        dicionario.adiciona("CCA", "Prolina");
        dicionario.adiciona("CCG", "Prolina");
        dicionario.adiciona("ACU", "Treonina");
        dicionario.adiciona("ACC", "Treonina");
        dicionario.adiciona("ACA", "Treonina");
        dicionario.adiciona("ACG", "Treonina");
        dicionario.adiciona("GCU", "Alanina");
        dicionario.adiciona("GCC", "Alanina");
        dicionario.adiciona("GCA", "Alanina");
        dicionario.adiciona("GCG", "Alanina");
        dicionario.adiciona("UAU", "Tirosina");
        dicionario.adiciona("UAC", "Tirosina");
        dicionario.adiciona("UAA", "Parada");
        dicionario.adiciona("UAG", "Parada");
        dicionario.adiciona("CAU", "Histidina");
        dicionario.adiciona("CAC", "Histidina");
        dicionario.adiciona("CAA", "Glutamina");
        dicionario.adiciona("CAG", "Glutamina");
        dicionario.adiciona("AAU", "Asparagina");
        dicionario.adiciona("AAC", "Asparagina");
        dicionario.adiciona("AAA", "Lisina");
        dicionario.adiciona("AAG", "Lisina");
        dicionario.adiciona("GAU", "Aspartato");
        dicionario.adiciona("GAC", "Aspartato");
        dicionario.adiciona("GAA", "Glutamato");
        dicionario.adiciona("GAG", "Glutamato");
        dicionario.adiciona("UGU", "Cisteina");
        dicionario.adiciona("UGC", "Cisteina");
        dicionario.adiciona("UGA", "Parada");
        dicionario.adiciona("UGG", "Triptofano");
        dicionario.adiciona("CGU", "Arginina");
        dicionario.adiciona("CGC", "Arginina");
        dicionario.adiciona("CGA", "Arginina");
        dicionario.adiciona("CGG", "Arginina");
        dicionario.adiciona("AGU", "Serina");
        dicionario.adiciona("AGC", "Serina");
        dicionario.adiciona("AGA", "Arginina");
        dicionario.adiciona("AGG", "Arginina");
        dicionario.adiciona("GGU", "Glicina");
        dicionario.adiciona("GGC", "Glicina");
        dicionario.adiciona("GGA", "Glicina");
        dicionario.adiciona("GGG", "Glicina");
        Scanner ler = new Scanner(System.in);
        while(true){

            System.out.println("\n\nPara ecerrar o programa digite [ FIM ]\nDigite a chave: ");
            String chaveLida = ler.nextLine();
            if(isFim(chaveLida) == true ){
                return;
            }else{
                String valorEncontrado = dicionario.recebeValor(chaveLida);
                System.out.println("\nResultado: \n"+valorEncontrado+"\n=============");
            }
        }
    }
    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }
}

class CelulaDicionario {
    // Atributos
    public String chave, valor;
    public CelulaDicionario proximo;

    // Construtora que anula os três atributos da célula
    public CelulaDicionario() {

    }

    // Construtora que inicializa key e value com os argumentos passados
    // por parâmetro e anula a referência à próxima célula
    public CelulaDicionario(String chave, String valor) {
        this.chave = chave;
        this.valor = valor;
    }

    // Construtora que inicializa todos os atribulos da célula com os argumentos
    // passados por parâmetro
    public CelulaDicionario(String chave, String valor, CelulaDicionario proxima) {
        this.chave = chave;
        this.valor = valor;
    }
}

class Dicionario {
    public CelulaDicionario primeira, ultima;
    public int quantidade = 0;

    public Dicionario() {
    }

    public boolean vazio() {
        if (this.primeira == null) {
            return true;
        } else {
            return false;
        }
    }

    public void adiciona(String chave, String valor) {
        if (this.primeira == null && this.quantidade == 0) {
            CelulaDicionario novoItem = new CelulaDicionario(chave, valor);
            this.primeira = novoItem;
            this.ultima = novoItem;
            this.quantidade++;
        } else {
            CelulaDicionario novoItem = new CelulaDicionario(chave, valor);
            this.ultima.proximo = novoItem;
            this.ultima = novoItem;
            this.quantidade++;
        }
    }

    public String recebeValor(String chave) throws Exception {
        CelulaDicionario atual = this.primeira;
        for (int i = 0; i < this.quantidade; i++) {
            if (atual.chave.equals(chave)) {
                return atual.valor;
            }
            atual = atual.proximo;
        }
        return "-- Valor não encontrado --";
    }

    public void printarElementos() {
        CelulaDicionario atual = this.primeira;
        System.out.println("\n\n");
        for (int i = 0; i < this.quantidade; i++) {
            System.out.println("Posição: [" + i + "]\nChave: [" + atual.chave + "]\nValor: [" + atual.valor
                    + "]\n==============\n");
            atual = atual.proximo;
        }
    }
}