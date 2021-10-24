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

public class EX03 {
    public static void main(String[] args) throws Exception {
        Random gerador = new Random();
        Lista lista = new Lista();
        for (int i = 0; i < 5; i++) {
            lista.InsereOrdenado(gerador.nextInt(100));
        }
        lista.printarElementos();

    }
}

class Lista {
    private Elemento primeiro;
    private Elemento ultimo;
    private int quantidade = 0;

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

    public void printarElementos() {
        Elemento atual = this.primeiro;
        System.out.println("\n\n");
        for (int i = 0; i < quantidade; i++) {
            System.out.println("Posição: [" + i + "]\nChave: [" + atual.getChave() + "]\n==============\n");
            atual = atual.getProximo();
        }
    }
}

class Elemento {
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

/*





*/