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
        int comparacoes = 0;
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("UTF-8")));
        PrintStream stdout = new PrintStream(System.out, true, "UTF-8");

        String[] listaNomeDeSeries = new String[1000];
        int firstIndex = 0;
        do {
            listaNomeDeSeries[firstIndex] = stdin.readLine();
            firstIndex++;
            comparacoes++;
        } while (isFim(listaNomeDeSeries[firstIndex - 1]) == false);
        firstIndex--;

        Serie[] listaDadosSeries = new Serie[firstIndex + 1];
        for (int i = 0; i < firstIndex; i++) {
            comparacoes++;
            Serie novaSerie = new Serie();
            novaSerie.buscarDados(listaNomeDeSeries[i]);
            listaDadosSeries[i] = novaSerie;
        }

        int secondIndex = 0;
        String[] nomeSerie = new String[1000];
        do {
            nomeSerie[secondIndex] = stdin.readLine();
            secondIndex++;
            comparacoes++;
        } while (isFim(nomeSerie[secondIndex - 1]) == false);
        secondIndex--;

        for (int i = 0; i < secondIndex; i++) {
            comparacoes++;
            for (int j = 0; j < firstIndex; j++) {
                comparacoes++;
                if (nomeSerie[i].equals(listaDadosSeries[j].getNome())) {
                    System.out.println("SIM");
                    comparacoes++;
                    j += firstIndex;
                } else if (j == firstIndex - 1) {
                    comparacoes++;
                    System.out.println("NÃO");
                }
            }
        }

        stdin.close();
        stdout.close();
        for ( int k = 0 ; k < firstIndex ; k++ ){
            comparacoes+=listaDadosSeries[k].comparacoes;
        }
        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        String stringDeLog = "739704\t" + duration + "ms\t"+comparacoes;
        escreverLog(stringDeLog);

    }

    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }

    public static void escreverLog(String logString) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("739704_sequencial.txt"));
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
            this.comparacoes++;
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
            this.comparacoes++;
            if (linha.charAt(i) >= '0' && linha.charAt(i) <= '9') {
                this.comparacoes += 2;
                resposta += linha.charAt(i);
            } else {
                i = linha.length();
                this.comparacoes++;
            }
        }
        return Integer.parseInt(resposta);
    }

    public String removerTagsHTML(String linha) {
        String resposta = "";
        int i = 0;
        while (i < linha.length()) {
            this.comparacoes++;
            if (linha.charAt(i) == '<') {
                this.comparacoes++;
                i++;
                while (linha.charAt(i) != '>') {
                    this.comparacoes++;
                    i++;
                }
            } else if (linha.charAt(i) == '&') {
                this.comparacoes++;
                i++;
                while (linha.charAt(i) != ';') {
                    this.comparacoes++;
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
            this.nome = qualONomeDaSerie(fileName);

            while (!br.readLine().contains("Formato"))
                this.comparacoes++;
            this.formato = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Duração"))
                this.comparacoes++;
            this.duracao = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("País de origem"))
                this.comparacoes++;
            this.pais = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Idioma original"))
                this.comparacoes++;
            this.idioma = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Emissora de televisão"))
                this.comparacoes++;
            this.broadcaster = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("Transmissão original"))
                this.comparacoes++;
            this.streaming = removerTagsHTML(br.readLine());

            while (!br.readLine().contains("N.º de temporadas"))
                this.comparacoes++;
            this.temporadas = converterParaInteiro(removerTagsHTML(br.readLine()));

            while (!br.readLine().contains("N.º de episódios"))
                this.comparacoes++;
            this.episodios = converterParaInteiro(removerTagsHTML(br.readLine()));

            br.close();
        } catch (FileNotFoundException e) {
            System.out.println("Não é possível abrir o arquivo'" + fileName + "'");
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo'" + fileName + "'");
        }
    }
}