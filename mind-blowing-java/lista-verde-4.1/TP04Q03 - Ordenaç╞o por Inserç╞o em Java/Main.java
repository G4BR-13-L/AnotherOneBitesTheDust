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
        listaManipulavel.insercaoSort();
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
        BufferedWriter writer = new BufferedWriter(new FileWriter("739704_insercao.txt"));
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
            this.pais = (removerTagsHTML(br.readLine())).trim();

            while (!br.readLine().contains("Idioma original"))
                ;
            this.idioma = (removerTagsHTML(br.readLine())).trim();

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

    public void II(String nomeArquivoSerie) throws Exception {
        Serie novaSerie = new Serie();
        novaSerie.buscarDados(nomeArquivoSerie);
        for (int i = this.quantidade; i > 0; i--) {
            this.series[i] = this.series[i - 1];
        }
        this.series[0] = novaSerie;
        this.quantidade++;

    }

    public void IF(String nomeArquivoSerie) throws Exception {
        Serie novaSerie = new Serie();
        novaSerie.buscarDados(nomeArquivoSerie);
        this.series[this.quantidade] = novaSerie;
        this.quantidade++;
    }

    public void I(String nomeArquivoSerie, int posicao) throws Exception {
        Serie novaSerie = new Serie();
        novaSerie.buscarDados(nomeArquivoSerie);
        for (int i = this.quantidade; i >= posicao; i--) {
            this.series[i + 1] = this.series[i];
        }
        this.series[posicao] = novaSerie;
        this.quantidade++;
    }

    public void RI() {
        this.removidas[this.quantidadeRemovidas] = this.series[0];
        this.quantidadeRemovidas++;
        for (int i = 0; i < this.quantidade; i++) {
            this.series[i] = this.series[i + 1];
        }
        this.quantidade--;
    }

    public void RF() {
        this.removidas[this.quantidadeRemovidas] = this.series[this.quantidade - 1];
        this.quantidadeRemovidas++;
        this.quantidade--;
    }

    public void R(int posicao) throws Exception {
        this.removidas[this.quantidadeRemovidas] = this.series[posicao];
        this.quantidadeRemovidas++;
        for (int i = posicao; i < this.quantidade; i++) {
            this.series[i] = this.series[i + 1];
        }
        this.quantidade--;
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

    
    public void insercaoSort() {
        for (int i = 1; i < this.quantidade; i++) {
            this.comparacoesSort++;
            Serie tmp = this.series[i];
            this.movimentacoesSort++;
            int j = i - 1;

            while ((j >= 0) && comparaNomeEPais(this.series[j], tmp) ) {
                this.comparacoesSort++;
                this.series[j + 1] = this.series[j];
                this.movimentacoesSort++;
                j--;
            }
            this.series[j + 1] = tmp;
            this.movimentacoesSort++;
        }
    }

    public boolean comparaNomeEPais(Serie serie, Serie tempSerie){
        if((serie.getIdioma()).trim().compareTo((tempSerie.getIdioma()).trim()) > 0 ){
            return true;
        }else if( (serie.getIdioma()).trim().compareTo((tempSerie.getIdioma()).trim()) == 0 && ((serie.getNome()).trim().compareTo((tempSerie.getNome()).trim()) > 0 ) ){
            
                return true;
            
        }else{
            return false;
        }
        
    }

    public void mostrar() {
        for (int j = 0; j < this.quantidade; j++) {
            this.series[j].printarDadosSerie();
        }
    }

}
