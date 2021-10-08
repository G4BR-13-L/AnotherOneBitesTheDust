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

import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.io.*;
import java.io.IOException;
import java.net.URL;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("UTF-8")));
        PrintStream stdout = new PrintStream(System.out, true, "UTF-8");
        ListaString listaLigadaDeSites = lerTudo();
        String[] listaDeSites = new String[listaLigadaDeSites.getQntelementos()];
        String[] listaDeUrls = new String[listaLigadaDeSites.getQntelementos()];
        ItemLista aux = listaLigadaDeSites.getPrimeiro();
        for (int i = 0; i < listaLigadaDeSites.getQntelementos(); i++) {
            listaDeSites[i] = aux.chave;
            listaDeUrls[i] = aux.url;
            aux = aux.getProximo();
        }
        String caracteres[] = { "a", "e", "i", "o", "u", "á", "é", "í", "ó", "ú", "à", "è", "ì", "ò", "ù", "ã", "õ", "â", "ê", "î", "ô", "û", "consoante", "<br>", "<table>"};
        for (int k = 0; k < listaDeSites.length; k++) {
            int[] nElementos = new int[25];
            String stringHTML = meDeAStringDoHTML(listaDeUrls[k]);
            nElementos = quantosElementosTemNaString(stringHTML);
            nElementos[23] = contabilizarElementosHTML("<br>", stringHTML);
            nElementos[24] = contabilizarElementosHTML("<table>", stringHTML);
            nElementos[0] = nElementos[0] - nElementos[24];
            nElementos[1] = nElementos[1] - nElementos[24];
            nElementos[22] = nElementos[22] - nElementos[23] * 2;
            nElementos[22] = nElementos[22] - nElementos[24] * 3;

            StringFormat[] listaDeChaveValor = new StringFormat[25];
            listaDeChaveValor = gerarChaveValor(caracteres, nElementos, 25);
            for(int t = 0 ; t < 25 ; t++){
                stdout.print(listaDeChaveValor[t].chave+"("+listaDeChaveValor[t].quantidade+") ");
            }
            stdout.println(listaDeSites[k]);
        }
        stdin.close();
        stdout.close();
    }

    /**
     * Função que verifica de uma String é igual a FIM
     * @return True ou False
     * */
    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }


    /**
     * Essa função lé capaz de ler todos os nomes de series
     * e urls de sites, colocando todos os valores em uma lista ligada. 
     * @return Retorna uma lista ligada.
     * @throws Exception
     */
    public static ListaString lerTudo() throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
        ListaString listaSites = new ListaString();
        String aux;
        boolean boo = true;
        do {
            ItemLista novoSite = new ItemLista();
            novoSite.setChave(stdin.readLine());
            aux = novoSite.chave;
            if (isFim(aux) == false) {
                if (listaSites.getQntelementos() == 0) {
                    novoSite.setUrl(stdin.readLine());
                    listaSites.setPrimeiro(novoSite);
                    listaSites.setUltimo(novoSite);
                    listaSites.incrementarQuantidade();
                } else {
                    novoSite.setUrl(stdin.readLine());
                    ItemLista antigoUltimo = listaSites.getUltimo();
                    antigoUltimo.proximo = novoSite;
                    listaSites.setUltimo(novoSite);
                    listaSites.incrementarQuantidade();
                }
            }else{
                boo = false;
            }
        } while (boo);
        stdin.close();
        return listaSites;
    }

    public static String meDeAStringDoHTML(String urlDoSite) throws IOException {
        URL url = new URL(urlDoSite);
        Scanner sc = new Scanner(url.openStream());
        StringBuffer sb = new StringBuffer();
        while (sc.hasNext()) {
            sb.append(sc.next());
        }
        String result = sb.toString();
        return result;

    }

    /**
     * Função que pesquisa por todas as vogai e consoantes
     * @return um Array de 25 posições com varios numeros
     */
    public static int[] quantosElementosTemNaString(String html) {
        int[] encontrados = new int[25];
        for ( int j = 0 ; j < 25 ; j++ ){
            encontrados[j] = 0;
        }
        for (int i = 0; i < html.length(); i++) {
            switch(html.charAt(i)){ 
                case 'a':encontrados[0]++; break;
                case 'e':encontrados[1]++;break;
                case 'i':encontrados[2]++;break;
                case 'o':encontrados[3]++;break;
                case 'u':encontrados[4]++;break;
                case 'á':encontrados[5]++;break;
                case 'é':encontrados[6]++;break;
                case 'í':encontrados[7]++;break;
                case 'ó':encontrados[8]++;break;
                case 'ú':encontrados[9]++;break;
                case 'à':encontrados[10]++;break;
                case 'è':encontrados[11]++;break;
                case 'ì':encontrados[12]++;break;
                case 'ò':encontrados[13]++;break;
                case 'ù':encontrados[14]++;break;
                case 'ã':encontrados[15]++;break;
                case 'õ':encontrados[16]++;break;
                case 'â':encontrados[17]++;break;
                case 'ê':encontrados[18]++;break;
                case 'î':encontrados[19]++;break;
                case 'ô':encontrados[20]++;break;
                case 'û':encontrados[21]++;break;
                // -----
                case 'b':encontrados[22]++;break;
                case 'c':encontrados[22]++;break;
                case 'd':encontrados[22]++;break;
                case 'f':encontrados[22]++;break;
                case 'g':encontrados[22]++;break;
                case 'h':encontrados[22]++;break;
                case 'j':encontrados[22]++;break;
                case 'k':encontrados[22]++;break;
                case 'l':encontrados[22]++;break;
                case 'm':encontrados[22]++;break;
                case 'n':encontrados[22]++;break;
                case 'p':encontrados[22]++;break;
                case 'q':encontrados[22]++;break;
                case 'r':encontrados[22]++;break;
                case 's':encontrados[22]++;break;
                case 't':encontrados[22]++;break;
                case 'v':encontrados[22]++;break;
                case 'w':encontrados[22]++;break;
                case 'x':encontrados[22]++;break;
                case 'y':encontrados[22]++;break;
                case 'z':encontrados[22]++;break;
                default:    ;break; 
            }
        }
        return encontrados;
    }

    /**
     * Função que pesquisa por elementos específicos como <br> e <table>
     * @return Um inteiro que representa a quantidade de elementos encontrados
     */
    public static int contabilizarElementosHTML(String pesquisa, String html) {
        int tamanho = pesquisa.length();
        int posicao = 0;
        int encontrados = 0;
        for (int i = 0; i < html.length(); i++) {
          if (html.charAt(i) == pesquisa.charAt(posicao)){
            posicao = posicao + 1;
          } else {
            posicao = 0;
          }
          if (posicao == tamanho) {
            posicao = 0;
            encontrados++;
          }
        }
        return encontrados;
    }
    public static StringFormat[] gerarChaveValor(String[] chaves, int[] valores, int quantidade){
        StringFormat[] listaDeChavesValor = new StringFormat[quantidade];
        for( int h = 0 ; h < quantidade ; h++ ){
            StringFormat novoObjeto = new StringFormat(chaves[h], valores[h]);
            listaDeChavesValor[h] = novoObjeto; 
        }
        return listaDeChavesValor;
    }
}

// CLASSE PARA FORMATAÇÃO DA SAIDA COM CHAVE E QUANTIDADE DE ELEMENTOS ENCONTRADOS
class StringFormat{
    public String chave;
    public int quantidade;

    StringFormat(String chave, int quantidade){
        this.chave = chave;
        this.quantidade = quantidade;
    }
}


// CLASSES PARA CRIAÇÃO DE LISTAS LIGADAS
// ======================================

class ItemLista {
    public String chave;
    public String url;
    public ItemLista proximo;

    ItemLista() {
        this.proximo = null;
    }

    public String getChave() {
        return chave;
    }

    public void setChave(String chave) {
        this.chave = chave;
    }

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public ItemLista getProximo() {
        return proximo;
    }

}

class ListaString {
    public int qntelementos;
    public ItemLista primeiro;
    public ItemLista ultimo;

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