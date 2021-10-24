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


import java.util.Random;


public class EX01 {
    public static void main(String[] args) throws Exception {
        Random gerador = new Random();
        Lista lista = new Lista();
        for( int i = 0 ; i < 5; i++ ){
            lista.adicionarElemento(gerador.nextInt(256));
        }
        lista.printarElementos();
        Elemento teste1 = new Elemento();
        teste1.setChave(1);
        Elemento teste2 = new Elemento();
        teste2.setChave(5);
        Elemento teste3 = new Elemento();
        teste3.setChave(10);

        // Inserindo na primeira posição
        lista.InsereAntesDe(teste1, lista.getPrimeiro());

        // Inserindo na penultima posição
        lista.InsereAntesDe(teste2, lista.getUltimo());

        // Inserindo antes de um elemento que não existe
        Elemento naoExiste = new Elemento();
        naoExiste.setChave(1042);
        lista.InsereAntesDe(teste3, naoExiste);

        // Listando tudo
        lista.printarElementos();
    }
}

class Lista{
    private Elemento primeiro;
    private Elemento ultimo;
    private int quantidade;
    
    public Elemento getPrimeiro() {
        return primeiro;
    }
    public void setPrimeiro(Elemento primeiro) {
        this.primeiro = primeiro;
    }
    public Elemento getUltimo() {
        return ultimo;
    }
    public void setUltimo(Elemento ultimo) {
        this.ultimo = ultimo;
    }
    public int getQuantidade() {
        return quantidade;
    }
    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public void adicionarElemento(int valor){
        Elemento novoElemento = new Elemento();
        novoElemento.setChave(valor);
        if(this.primeiro == null){
            this.primeiro = novoElemento;
            this.ultimo = novoElemento;
            this.quantidade++;
        }else{
            Elemento antigoUltimo = new Elemento();
            antigoUltimo = this.ultimo;
            antigoUltimo.setProximo(novoElemento);
            this.ultimo = novoElemento;
            this.quantidade++;
        }
    }
    public void InsereAntesDe(Elemento ElementoAInserir, Elemento Elemento){
        Elemento atual = this.primeiro;
        while(true){
            if(atual == Elemento){
                ElementoAInserir.setProximo(atual);
                this.primeiro = ElementoAInserir;
                this.quantidade++;
                System.out.println("Elemento inserido com sucesso");
                return;
            }else if( atual.getProximo() == Elemento ){
                ElementoAInserir.setProximo(atual.getProximo());
                atual.setProximo(ElementoAInserir);
                this.quantidade++;
                System.out.println("Elemento inserido com sucesso");
                return;
            }else if( atual.getProximo() == null ){
                System.out.println("Elemento não encontrado");
                return;
            }else{
                atual = atual.getProximo();
            }
        }
    }


    public void printarElementos(){
        Elemento atual = this.primeiro;
        System.out.println("\n\n");
        for( int i  = 0 ; i < quantidade; i++ ){
            System.out.println("Posição: ["+i+"]\nChave: ["+atual.getChave()+"]\n==============\n");
            atual = atual.getProximo();
        }
    }
}

class Elemento{
    private int chave;
    private Elemento proximo;
    public int getChave() {
        return chave;
    }
    public void setChave(int chave) {
        this.chave = chave;
    }
    public Elemento getProximo() {
        return proximo;
    }
    public void setProximo(Elemento proximo) {
        this.proximo = proximo;
    }


    

}