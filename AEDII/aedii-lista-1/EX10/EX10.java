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

public class EX10 {
    public static void main(String[] args) throws Exception {

    }
}
class Elemento {
    public int chave;
    public Elemento proximo;

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

class Deque {    
    public Elemento esquerda;
    public Elemento direita;
    public int quantidade;
    // Construtora – cria uma Deque vazia    
    Deque() {

    } 
    // Retorna true se a Deque estiver vazia    
    boolean isEmpty() { 
        if ( this.esquerda == null ){
            return true;
        }else{
            return false;
        }

    } 
    // Retorna a quantidade de itens da Deque    
    int size() { 
        return this.quantidade;
    } 
    // Adiciona um item no lado esquerdo da Deque    
    void pushLeft(int item) { 
        Elemento novoElemento = new Elemento();
        novoElemento.setChave(item);
        novoElemento.setProximo(this.esquerda);
        this.esquerda = novoElemento;
        this.quantidade++;
    } 
    // Adiciona um item no lado direito da Deque    
    void pushRight(int item) {
        Elemento novoElemento = new Elemento();
        novoElemento.setChave(item);
        novoElemento.setProximo(this.direita);
        this.direita = novoElemento;
        this.quantidade++;
    } 
    // Remove e retorna um item do lado esquerdo da Deque    
    int popLeft() { 
        int leftPop = this.esquerda.chave;
        this.esquerda = this.esquerda.proximo;
        this.quantidade--;
        return leftPop;
    } 
    // Remove e retorna um item do lado direito da Deque    
    Object popRight() { 
        int rightPop = this.direita.chave;
        this.direita = this.direita.proximo;
        this.quantidade--;
        return rightPop;
    } 
}