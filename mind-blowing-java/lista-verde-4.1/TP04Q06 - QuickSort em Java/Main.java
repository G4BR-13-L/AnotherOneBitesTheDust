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

        Serie[] listaDadosSeries = new Serie[index + 1];
        for (int i = 0; i < index; i++) {
            Serie novaSerie = new Serie();
            novaSerie.buscarDados(listaNomeDeSeries[i]);
            listaDadosSeries[i] = novaSerie;
        }
        Lista listaManipulavel = new Lista();

        listaManipulavel.adicionarSeries(listaDadosSeries);
        listaManipulavel.quantidade--;
        listaManipulavel.quickSort( 0, listaManipulavel.quantidade - 1);
        listaManipulavel.mostrar();

        stdin.close();
        stdout.close();
        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        String stringDeLog = "739704\t" + listaManipulavel.comparacoesSort + "\t" + listaManipulavel.movimentacoesSort
                + "\t" + duration + "ms";
        escreverLog(stringDeLog);

    }

    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void escreverLog(String logString) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("739704_quicksort.txt"));
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
            this.pais = (removerTagsHTML(br.readLine()));

            while (!br.readLine().contains("Idioma original"))
                ;
            this.idioma = (removerTagsHTML(br.readLine()));

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

class Lista {
    public Serie[] series;
    public int quantidade;
    public Serie[] removidas;
    public int quantidadeRemovidas = 0;
    public int comparacoesSort;
    public int movimentacoesSort;

    Lista(int tamanho) {
        this.quantidade = 0;
        this.series = new Serie[tamanho];
        this.removidas = new Serie[tamanho * 2];
        this.comparacoesSort = 0;
        this.movimentacoesSort = 0;
    }

    Lista() {
        this(500);
    }

    public void adicionarSeries(Serie[] seriesIniciais) throws Exception {
        if (this.series.length > seriesIniciais.length) {
            for (int i = 0; i < seriesIniciais.length; i++) {
                this.series[i] = seriesIniciais[i];
            }
            this.quantidade = seriesIniciais.length;
        } else if (this.series.length == seriesIniciais.length) {
            for (int i = 0; i < seriesIniciais.length; i++) {
                this.series[i] = seriesIniciais[i];
            }
            this.quantidade = seriesIniciais.length;
        } else if (this.series.length < seriesIniciais.length) {
            throw new Exception("ERRO: O array de series é maior do que a lista");
        }
    }

    public void swap(int i, int j) {
        Serie temp = this.series[i];
        this.series[i] = this.series[j];
        this.series[j] = temp;
    }

    public static String blank(String s) {
        String resp = "";
        for (int i = 0; i < s.length(); i++) {
            char x = s.charAt(i);
            if (x != ' ') {
                resp += x;
            }
        }
        return resp;
    }

    public int comparar( Serie A, Serie B){
        if(A.getPais().trim().equals(B.getPais().trim())){
            return A.getNome().compareTo(B.getNome());
        }
        return A.getPais().trim().compareTo(B.getPais().trim());
    } 


    public void quickSort( int inicio, int fim) {
        if(fim > inicio) {
          int indexPivo = dividir( inicio, fim);
          quickSort(inicio, indexPivo - 1);
          quickSort(indexPivo + 1, fim);
        }
    }

    
    public int dividir( int inicio, int fim) {
        int pontEsq, pontDir = fim+1;
        pontEsq = inicio - 1;
        Serie pivo = this.series[inicio];

        while (true) {
            /*while (pontEsq <= pontDir && comparar(vetor[pontEsq], pivo) <= 0 () ) {
                pontEsq++;
            }*/

            do{
                pontEsq++;
            }while(comparar(this.series[ pontEsq ], pivo ) < 0);

            do{
                pontDir--;
            }while(comparar(this.series[ pontDir ], pivo ) > 0);
            
            if( pontEsq >= pontDir ){
                return pontDir;
            }
            swap(pontEsq, pontDir);
            /**while( vetor[pontEsq].getPais().compareTo( pivo.getPais() ) < 0 || ( vetor[pontEsq].getPais().compareTo( pivo.getPais() ) == 0 &&  vetor[pontEsq].getNome().compareTo( pivo.getNome() ) < 0 )){
                pontEsq++;
            }

            while( vetor[pontDir].getPais().compareTo( pivo.getPais() ) > 0 || ( vetor[pontDir].getPais().compareTo( pivo.getPais() ) == 0 &&  vetor[pontDir].getNome().compareTo( pivo.getNome() ) > 0 )){
                pontDir++;
            }*/

           /* while (pontDir >= pontEsq && comparar(vetor[pontEsq], pivo) > 0) {
                pontDir--;
            }*/
            
        }
    }


    public void mostrar() {
        for (int j = 0; j < this.quantidade; j++) {
            this.series[j].printarDadosSerie();
        }
    }

}
