
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


public class EX30 {
    public static void main(String[] args) throws Exception {
        String[] listaDeEnderecos = { "www.google.com", "www.yahoo.com", "www.amazon.com", "www.uol.com.br",
                "www.pucminas.br", "www.microsoft.com", "research.microsoft.com", "www.hotmail.com", "www.gmail.com",
                "www.twitter.com", "ww.facebook.com", "www.cplusplus.com", "www.youtube.com", "www.brasil.gov.br",
                "www.whitehouse.gov", "www.nyt.com", "www.capes.gov.br", "www.wikipedia.com", "www.answers.com",
                "www.apple.com" };

        Dicionario dicionario = new Dicionario();
        for( int i = 0 ; i < listaDeEnderecos.length; i++){
            dicionario.adiciona(listaDeEnderecos[i], pegarIP(listaDeEnderecos[i]));
        }
        System.out.println("\n=================\n\nBuscando endereços de IP ...\n\n=================\n\n");
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
        
        //dicionario.printarElementos();

    }
    public static String pegarIP(String endereco) throws Exception{
        endereco = "https://" + endereco;
        String IP;
        InetAddress ip = InetAddress.getByName(new URL(endereco).getHost());
        IP = ip.toString();
        IP = IP.substring(IP.indexOf('/') + 1);
        
        return IP;
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
        if( this.primeira == null ){
            return true;
        }else{
            return false;
        }
    }

    public void adiciona(String chave, String valor) {
        if( this.primeira == null && this.quantidade == 0 ){
            CelulaDicionario novoItem = new CelulaDicionario(chave, valor);
            this.primeira = novoItem;
            this.ultima = novoItem;
            this.quantidade++;
        }else{
            CelulaDicionario novoItem = new CelulaDicionario(chave, valor);
            this.ultima.proximo = novoItem;
            this.ultima = novoItem;
            this.quantidade++;
        }
    }

    public String recebeValor(String chave) throws Exception {
        CelulaDicionario atual = this.primeira;
        for(int i = 0; i < this.quantidade ; i++ ){
            if( atual.chave.equals(chave) ){
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
            System.out.println("Posição: [" + i + "]\nChave: [" + atual.chave + "]\nValor: ["+atual.valor+"]\n==============\n");
            atual = atual.proximo;
        }
    }
}