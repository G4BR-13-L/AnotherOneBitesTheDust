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

public class Main {
    public static void main(String[] args) throws Exception {
        long startTime = System.nanoTime();
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("UTF-8")));
        PrintStream stdout = new PrintStream(System.out, true, "UTF-8");

        String[] listaNomeDeSeries = new String[1000];
        int index = 0;
        do {
            listaNomeDeSeries[index] = stdin.readLine();
            index++;
        } while (isFim(listaNomeDeSeries[index - 1]) == false);
        index--;

        Serie[] listaDadosSeries = new Serie[index];
        for (int i = 0; i < index; i++) {
            Serie novaSerie = new Serie();
            novaSerie.buscarDados(listaNomeDeSeries[i]);
            listaDadosSeries[i] = novaSerie;
        }

        int quantidadeDeInstrucoes = 0;
        quantidadeDeInstrucoes = Integer.parseInt(stdin.readLine());
        Fila filaManipulavel = new Fila();

        for (int h = 0; h < listaDadosSeries.length; h++) {
            filaManipulavel.enfileirar(listaDadosSeries[h]);
        }

        for (int s = 0; s < quantidadeDeInstrucoes; s++) {
            String instrucoesEString = stdin.readLine();
            if (instrucoesEString.charAt(0) == 'I') {

                Serie novaSerie = new Serie();
                novaSerie.buscarDados(instrucoesEString.substring(2));
                filaManipulavel.enfileirar(novaSerie);
            } else {
                filaManipulavel.desenfileirar();
            }
        }
        stdin.close();
        stdout.close();
        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        String stringDeLog = "739704\t" + duration + "ms";
        escreverLog(stringDeLog);

    }

    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void escreverLog(String logString) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("log.txt"));
        writer.write(logString);

        writer.close();
    }
}

class Serie {
    private String nome;
    private String formato;
    private String duracao;
    private String pais;
    private String idioma;
    private String broadcaster;
    private String streaming;
    private int temporadas;
    private int episodios;
    public int comparacoes = 0;
    public String nomeDoArquivo;

    public String getNome() {
        return this.nome;
    }

    public void printarDadosSerie() {
        System.out.println(this.nome + " " + this.formato + " " + this.duracao + " " + this.pais + " " + this.idioma
                + " " + this.broadcaster + " " + this.streaming + " " + this.temporadas + " " + this.episodios);
    }

    public String qualONomeDaSerie(String fileName) {
        String resp = "";
        for (int i = 0; i < fileName.length(); i++) {
            if (fileName.charAt(i) == '_') {
                resp += ' ';
            } else {
                resp += fileName.charAt(i);
            }
        }
        return resp.substring(0, resp.length() - 5);
    }

    public int converterParaInteiro(String linha) {
        String resposta = "";
        for (int i = 0; i < linha.length(); i++) {
            if (linha.charAt(i) >= '0' && linha.charAt(i) <= '9') {
                resposta += linha.charAt(i);
            } else {
                i = linha.length();
            }
        }
        return Integer.parseInt(resposta);
    }

    public String removerTagsHTML(String linha) {
        String resposta = "";
        int i = 0;
        while (i < linha.length()) {
            if (linha.charAt(i) == '<') {
                i++;
                while (linha.charAt(i) != '>') {
                    i++;
                }
            } else if (linha.charAt(i) == '&') {
                i++;
                while (linha.charAt(i) != ';') {
                    i++;
                }
            } else {
                resposta += linha.charAt(i);
            }
            i++;
        }
        if (resposta.charAt(0) == ' ') {
            resposta = resposta.substring(1);
        }
        return resposta;
    }

    public void buscarDados(String fileName) {
        String file = "/tmp/series/" + fileName;
        try {
            FileReader fileReader = new FileReader(file);
            BufferedReader br = new BufferedReader(fileReader);
            this.nomeDoArquivo = fileName;
            this.nome = qualONomeDaSerie(fileName);

            while (!br.readLine().contains("Formato"))
                ;
            this.formato = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Duração"))
                ;
            this.duracao = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("País de origem"))
                ;
            this.pais = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Idioma original"))
                ;
            this.idioma = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Emissora de televisão"))
                ;
            this.broadcaster = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Transmissão original"))
                ;
            this.streaming = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("N.º de temporadas"))
                ;
            this.temporadas = converterParaInteiro(removerTagsHTML(br.readLine()));

            while (!br.readLine().contains("N.º de episódios"))
                ;
            this.episodios = converterParaInteiro(removerTagsHTML(br.readLine()));

            br.close();
        } catch (FileNotFoundException e) {
            System.out.println("Não é possível abrir o arquivo'" + fileName + "'");
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo'" + fileName + "'");
        }
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getFormato() {
        return formato;
    }

    public void setFormato(String formato) {
        this.formato = formato;
    }

    public String getDuracao() {
        return duracao;
    }

    public void setDuracao(String duracao) {
        this.duracao = duracao;
    }

    public String getPais() {
        return pais;
    }

    public void setPais(String pais) {
        this.pais = pais;
    }

    public String getIdioma() {
        return idioma;
    }

    public void setIdioma(String idioma) {
        this.idioma = idioma;
    }

    public String getBroadcaster() {
        return broadcaster;
    }

    public void setBroadcaster(String broadcaster) {
        this.broadcaster = broadcaster;
    }

    public String getStreaming() {
        return streaming;
    }

    public void setStreaming(String streaming) {
        this.streaming = streaming;
    }

    public int getTemporadas() {
        return temporadas;
    }

    public void setTemporadas(int temporadas) {
        this.temporadas = temporadas;
    }

    public int getEpisodios() {
        return episodios;
    }

    public void setEpisodios(int episodios) {
        this.episodios = episodios;
    }
}

class Fila {
    public Item fimDaFila;
    public int quantidade = 0;

    public void enfileirar(Serie novaSerie) {
        if (this.quantidade == 0) {
            Item novoItem = new Item();
            novoItem.serie = novaSerie;
            novoItem.proxFrente = null;
            this.fimDaFila = novoItem;
        } else if (this.quantidade == 5) {
            this.desenfileirar();
        }
        Item novoItem = new Item();
        novoItem.serie = novaSerie;
        Item atual = this.fimDaFila;
        while (atual.proxFrente != null) {
            atual = atual.proxFrente;
        }
        atual.proxFrente = novoItem;
        this.quantidade++;

        Item auxItem = fimDaFila;
        int soma = 0;
        try {
            for (int i = 0; i < this.quantidade; i++) {
                auxItem = auxItem.proxFrente;
                soma += auxItem.serie.getTemporadas();
                //System.out.println(auxItem.serie.getNome());
            }

        } catch (NullPointerException e) {

        }

        float media = (float)soma / (float)this.quantidade;
        System.out.println(Math.round(media));
    }

    public void desenfileirar() {
        fimDaFila = fimDaFila.proxFrente;
        this.quantidade--;
    }

}

class Item {
    public Item proxFrente = null;
    public Serie serie;
}