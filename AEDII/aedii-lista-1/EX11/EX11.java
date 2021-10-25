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

public class EX11 {
    public static void main(String[] args) throws Exception {
        Random gerador = new Random();
        Lista L1 = new Lista();
        for (int i = 0; i < 5; i++) {
            L1.InsereOrdenado(gerador.nextInt(100));
        }
        L1.printarElementos();

        L1.RemovePos(3);

        L1.printarElementos();


    }

    
}

class Lista {
    public Elemento primeiro;
    public Elemento ultimo;
    public int quantidade = 0;

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

    public void adicionarElemento(int valor) {
        Elemento novoElemento = new Elemento();
        novoElemento.setChave(valor);
        if (this.primeiro == null) {
            this.primeiro = novoElemento;
            this.ultimo = novoElemento;
            this.quantidade++;
        } else {
            Elemento antigoUltimo = new Elemento();
            antigoUltimo = this.ultimo;
            antigoUltimo.setProximo(novoElemento);
            this.ultimo = novoElemento;
            this.quantidade++;
        }
    }

    public void InsereAntesDe(Elemento ElementoAInserir, Elemento Elemento) {
        Elemento atual = this.primeiro;
        while (true) {
            if (atual == Elemento) {
                ElementoAInserir.setProximo(atual);
                this.primeiro = ElementoAInserir;
                this.quantidade++;
                System.out.println("Elemento inserido com sucesso");
                return;
            } else if (atual.getProximo() == Elemento) {
                ElementoAInserir.setProximo(atual.getProximo());
                atual.setProximo(ElementoAInserir);
                this.quantidade++;
                System.out.println("Elemento inserido com sucesso");
                return;
            } else if (atual.getProximo() == null) {
                System.out.println("Elemento não encontrado");
                return;
            } else {
                atual = atual.getProximo();
            }
        }
    }

    public void InsereDepoisDe(Elemento ElementoAInserir, Elemento Elemento) {
        Elemento atual = this.primeiro;

        for (int i = 0; i < this.quantidade; i++) {
            if (atual == Elemento) {
                if (atual == this.ultimo) {
                    atual.setProximo(ElementoAInserir);
                    this.ultimo = ElementoAInserir;
                } else {
                    Elemento antigoPosterior = atual.getProximo();
                    ElementoAInserir.setProximo(antigoPosterior);
                    atual.setProximo(ElementoAInserir);
                }
                this.quantidade++;
                System.out.println("Elemento inserido com sucesso");
                return;
            } else {
                atual = atual.getProximo();
            }
        }
        System.out.println("Elemento não encontrado");
    }

    public void InsereOrdenado(int ElementoAInserir) throws Exception {
        Elemento novoElemento = new Elemento();
        novoElemento.setChave(ElementoAInserir);
        if (this.quantidade == 0) {
            this.primeiro = novoElemento;
            this.ultimo = novoElemento;
            this.quantidade = 1;
        } else {
            Elemento atual = this.primeiro;
            int cont = this.quantidade;
            for (int i = 0; i < cont; i++) {
                Elemento proximoElemento = new Elemento();
                proximoElemento = atual.getProximo();
                if (i == 0 && novoElemento.getChave() < atual.getChave()) {
                    novoElemento.setProximo(atual);
                    this.primeiro = novoElemento;
                    this.quantidade++;
                    return;
                }else if (atual.getChave() <= novoElemento.getChave()) {
                    if (proximoElemento != null) {
                        if (novoElemento.getChave() < proximoElemento.getChave()) {
                            novoElemento.setProximo(proximoElemento);
                            atual.setProximo(novoElemento);
                            this.quantidade++;
                            return;
                        } else if (atual == this.ultimo) {
                            atual.setProximo(novoElemento);
                            this.ultimo = novoElemento;
                            this.quantidade++;
                            return;
                        }
                        atual = atual.getProximo();
                    } else {
                        this.ultimo = novoElemento;
                        atual.setProximo(novoElemento);
                        this.quantidade++;
                        return;
                    }
                }
            }

        }
    }

    void RemovePos(int n) throws Exception{
        if( n > this.quantidade ){
            throw new Exception("ERRO: A listanão possui a posição: "+n);
        }else if(n == 0){
            this.primeiro = this.primeiro.proximo;
            this.quantidade--;
        }else if(n == this.quantidade){
            Elemento atual = this.primeiro;
            for( int i = 0 ; i < this.quantidade ; i++ ){
                atual = atual.proximo;
            }
            this.ultimo = atual;
            this.quantidade--;
        }else{
            
            Elemento atual = this.primeiro;
            for ( int i = 1 ; i < n ; i++){
                atual = atual.proximo;
            }
            System.out.println("Elemento: "+atual.proximo.chave+"\nPosição: "+n+"\n-- Removido com sucesso --");
            atual.proximo = atual.proximo.proximo;
            this.quantidade--;
        }
    }

    public void printarElementos() {
        Elemento atual = this.primeiro;
        System.out.println("\n\n");
        for (int i = 0; i < this.quantidade; i++) {
            System.out.println("Posição: [" + i + "]\nChave: [" + atual.getChave() + "]\n==============\n");
            atual = atual.getProximo();
        }
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

