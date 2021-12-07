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

        int quantidadeDeInstrucoes = 0;
        quantidadeDeInstrucoes = Integer.parseInt(stdin.readLine());

        Lista listaDinamica = new Lista();
        for ( int i = 0 ; i < listaDadosSeries.length - 1  ; i++ ){
            if( listaDinamica.quantidade == 0 ){
                Item novaSerie = new Item();
                novaSerie.serie = listaDadosSeries[i];
                listaDinamica.primeira = novaSerie;
                listaDinamica.ultima = novaSerie;
                listaDinamica.quantidade++;
            } else {
                listaDinamica.IF(listaDadosSeries[i].nomeDoArquivo);
            }
        } 


        for (int s = 0; s < quantidadeDeInstrucoes; s++) {
            String instrucoesEString = stdin.readLine();
            String instrucao = instrucoesEString.substring(0, 2);
            switch (instrucao) {
            case "II":
                listaDinamica.II(instrucoesEString.substring(3));
                break;
            case "IF":
                listaDinamica.IF(instrucoesEString.substring(3));
                break;
            case "I*":
                int posicao = Integer.parseInt(instrucoesEString.substring(3, 4));
                if (instrucoesEString.charAt(4) == ' ') {
                    posicao = Integer.parseInt(instrucoesEString.substring(3, 4));
                } else {
                    posicao = Integer.parseInt(instrucoesEString.substring(3, 5));
                }
                listaDinamica.I(instrucoesEString.substring(6), posicao);
                break;
            case "RI":
                listaDinamica.RI();
                break;
            case "RF":
                listaDinamica.RF();
                break;
            case "R*":
                int posicaoR = Integer.parseInt(instrucoesEString.substring(3, 4));
                if (instrucoesEString.charAt(4) == ' ') {
                    posicaoR = Integer.parseInt(instrucoesEString.substring(3, 4));
                } else {
                    posicaoR = Integer.parseInt(instrucoesEString.substring(3, 5));
                }
                listaDinamica.R(posicaoR);
                break;
            default:
                stdout.println("Pulando...");
                break;
            }
        }
        

        Item serieNaLista = listaDinamica.primeira;
        serieNaLista.serie.printarDadosSerie();
        for (int j = 0; j < listaDinamica.quantidade - 1; j++) {
            serieNaLista = serieNaLista.prox;
            serieNaLista.serie.printarDadosSerie();
            
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




class Lista {
    // LISTA DINAMICA
    public Item primeira;
    public Item ultima;
    public int quantidade = 0;

    public void IF(String nomeSerie) throws Exception {
        Serie dadosNovaSerie = new Serie();
        dadosNovaSerie.buscarDados(nomeSerie);
        Item novaSerie = new Item();
        novaSerie.serie = dadosNovaSerie;
        this.ultima.prox = novaSerie;
        this.ultima = novaSerie;
        this.quantidade++;
    }
    public void II(String nomeSerie) throws Exception {
        Serie dadosNovaSerie = new Serie();
        dadosNovaSerie.buscarDados(nomeSerie);
        Item novaSerie = new Item();
        novaSerie.serie = dadosNovaSerie;
        novaSerie.prox = this.primeira;
        this.primeira = novaSerie;
        this.quantidade++;
    }
    public void I(String nomeArquivoSerie, int posicao) throws Exception {
        
        Item posicaoDesejada = this.primeira;
        for( int i = 1 ; i < posicao ; i++ ){
            posicaoDesejada = posicaoDesejada.prox;
        }
        
        Serie dadosNovaSerie = new Serie();
        dadosNovaSerie.buscarDados(nomeArquivoSerie);
        Item novaSerie = new Item();
        novaSerie.serie = dadosNovaSerie;
        novaSerie.prox = posicaoDesejada.prox;
        posicaoDesejada.prox = novaSerie;
        this.quantidade++;
    }

    public void RI() {
        this.serieRemovida(this.primeira.serie);
        this.primeira = this.primeira.prox;
        this.quantidade--;
    }

    public void RF() {
        this.serieRemovida(this.ultima.serie);
        Item atual = this.primeira;
        for( int i = 0 ; i < this.quantidade -2 ; i++ ){
            atual = atual.prox;
        }
        atual.prox = null;
        this.ultima = atual;
        this.quantidade--;
    }

    public void R(int posicao) throws Exception {
        
        Item atual = this.primeira;
        for ( int i = 1 ; i < posicao ; i ++ ){
            atual = atual.prox;
        }
        this.serieRemovida(atual.prox.serie);
        atual.prox = atual.prox.prox;
        this.quantidade--;
    }

    public void serieRemovida(Serie aRemover){
        System.out.println("(R) " + aRemover.getNome());
    }
    
}

class Item{
    public Item prox;
    public Serie serie;
}