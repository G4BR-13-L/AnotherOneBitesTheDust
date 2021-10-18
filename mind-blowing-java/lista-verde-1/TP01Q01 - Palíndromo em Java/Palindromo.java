
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

import java.util.Scanner;
public class Palindromo {
    public static boolean palindrometro(String isPalindromo) {
        int len = isPalindromo.length();
        int indexLen = isPalindromo.length() - 1;
        boolean palindromoPorEnquanto = true;
        for (int i = 0, j = indexLen; i < len / 2; i++, j--) {
            if (isPalindromo.charAt(i) != isPalindromo.charAt(j)) {
                palindromoPorEnquanto = false;
                if(!palindromoPorEnquanto){
                    i = len;
                }
            } else {
                palindromoPorEnquanto = true;
            }
        }
        return palindromoPorEnquanto;
    }
    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }
    public static ListaString lerTudo() {
        Scanner ler = new Scanner(System.in);
        ListaString listaPalindromos = new ListaString();
        String aux;
        int repeat = 0;
        do {
            ItemLista palindromoString = new ItemLista();
            palindromoString.setUnknowPalindromo(ler.nextLine());
            if (listaPalindromos.getPrimeiro() == null) {
                listaPalindromos.setPrimeiro(palindromoString);
                listaPalindromos.setUltimo(palindromoString);
                listaPalindromos.setQntelementos(1);
            } else {
                ItemLista antigoUltimo = listaPalindromos.getUltimo();
                antigoUltimo.setProximo(palindromoString);
                listaPalindromos.setUltimo(palindromoString);
                listaPalindromos.incrementarQuantidade();
            }
            aux = palindromoString.getUnknowPalindromo();
        } while (isFim(aux) == false);
        ler.close();
        return listaPalindromos;
    }
    public static void main(String[] args) {
        ListaString listaLigadaDePalindromos = lerTudo();
        String[] listaDePalindromos = new String[listaLigadaDePalindromos.getQntelementos() -1];
        ItemLista aux = listaLigadaDePalindromos.getPrimeiro();
        for(int i = 0 ; i < listaLigadaDePalindromos.getQntelementos() -1 ; i++){
            listaDePalindromos[i] = aux.getUnknowPalindromo();
            aux = aux.getProximo();
        }
        for (int j = 0; j < listaDePalindromos.length; j++) {
            //System.out.println(listaDePalindromos[j]);
            boolean resposta = palindrometro(listaDePalindromos[j]);
            if (resposta) { 
                System.out.println("SIM"); 
            } else { System.out.println("NAO"); }
            
        }
        
    }
}
class ItemLista {
    private String unknowPalindromo;
    private ItemLista proximo;

    public String getUnknowPalindromo() {
        return unknowPalindromo;
    }

    public void setUnknowPalindromo(String unknowPalindromo) {
        this.unknowPalindromo = unknowPalindromo;
    }

    public ItemLista getProximo() {
        return proximo;
    }

    public void setProximo(ItemLista proximo) {
        this.proximo = proximo;
    }

}

class ListaString {
    private int qntelementos;
    private ItemLista primeiro;
    private ItemLista ultimo;

    public ListaString() {
        this.qntelementos = 0;
        this.primeiro = null;
        this.ultimo = null;
    }

    public int getQntelementos() {
        return qntelementos;
    }

    public void setQntelementos(int qntelementos) {
        this.qntelementos = qntelementos;
    }
    public void incrementarQuantidade() {
        this.qntelementos++;
    }

    public ItemLista getPrimeiro() {
        return primeiro;
    }

    public void setPrimeiro(ItemLista primeiro) {
        this.primeiro = primeiro;
    }

    public ItemLista getUltimo() {
        return ultimo;
    }

    public void setUltimo(ItemLista ultimo) {
        this.ultimo = ultimo;
    }

}