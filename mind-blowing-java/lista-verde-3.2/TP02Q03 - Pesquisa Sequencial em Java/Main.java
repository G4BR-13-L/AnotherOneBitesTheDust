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
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("UTF-8")));
        PrintStream stdout = new PrintStream(System.out, true, "UTF-8");

        
        String[] listaNomeDeSeries = new String[1000];
        int index = 0;
        do {
            listaNomeDeSeries[index] = stdin.readLine();
            index++;
        } while (isFim(listaDeSeries[index - 1]) == false);
        index--;

        Serie[] listaDadosSeries = new Serie[index + 1];
        for( int i = 0 ; i < index ; i++ ){
            listaDadosSeries[i].buscarDados(listaNomeDeSeries[i]);
        }

        stdin.close();
        stdout.close();
    }
    public static String lerArquivoHTML(String arquivoHtml) throws FileNotFoundException {
        String caminhoDoArquivo = "../series/" + arquivoHtml;
        StringBuilder html = new StringBuilder();
        FileReader fr = new FileReader(caminhoDoArquivo);
        try {
            BufferedReader br = new BufferedReader(fr);
            String val;
            while ((val = br.readLine()) != null) {
                html.append(val);
            }
            String result = html.toString();
            br.close();
            return result;
        } catch (Exception ex) {
            return ex.getMessage();
        }
    }
    public static boolean isFim(String s) {
        return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
    }
}
class Serie{
    private String nome;
    private String formato;
    private String duracao;
    private String pais;
    private String idioma;
    private String broadcaster;
    private String streaming;
    private int temporadas;
    private int episodios;

    public void printarDadosSerie(){
        System.out.println(this.nome + " " + this.formato + " " + this.duracao + " " + this.pais + " " + this.idioma + " " + this.broadcaster + " " + this.streaming + " " + this.temporadas + " " + this.episodios);
    }
    public String qualONomeDaSerie(String fileName){
        String resp = "";
        for(int i = 0; i < fileName.length(); i++){
            if(fileName.charAt(i)  == '_'){
                resp += ' ';
            } else {
                resp += fileName.charAt(i);
            }
        }
        return resp.substring(0, resp.length()-5);
    }
    public int converterParaInteiro(String linha){
        String resposta = "";
        for(int i = 0; i < linha.length(); i++){
            if(linha.charAt(i) >= '0' && linha.charAt(i) <= '9'){ 
                resposta += linha.charAt(i);
            } else { 
                i = linha.length();
            }
        }
        return Integer.parseInt(resposta); 
    }
    public String removerTagsHTML(String linha){
        String resposta = "";
        int i = 0;
        while(i < linha.length()){
            if(linha.charAt(i) == '<'){ 
                i++;
                while(linha.charAt(i) != '>') i++; 
            } else if(linha.charAt(i) == '&'){ 
                i++;
                while(linha.charAt(i) != ';') i++;
            } else { 
                resposta += linha.charAt(i);
            }
            i++;
        }
        if(resposta.charAt(0) == ' '){
            resposta = resposta.substring(1);
        }
        return resposta;
    }
    public void buscarDados(String fileName){
        String file = "/tmp/series/" + fileName;
        try {
            FileReader fileReader = new FileReader(file);
            BufferedReader br = new BufferedReader(fileReader);
            this.nome = qualONomeDaSerie(fileName);

            while(!br.readLine().contains("Formato"));
            this.formato = removerTagsHTML(br.readLine());

            while(!br.readLine().contains("Duração"));
            this.duracao = removerTagsHTML(br.readLine());

            while(!br.readLine().contains("País de origem"));
            this.pais = removerTagsHTML(br.readLine());

            while(!br.readLine().contains("Idioma original"));
            this.idioma = removerTagsHTML(br.readLine());

            while(!br.readLine().contains("Emissora de televisão"));
            this.broadcaster = removerTagsHTML(br.readLine());

            while(!br.readLine().contains("Transmissão original"));
            this.streaming = removerTagsHTML(br.readLine());

            while(!br.readLine().contains("N.º de temporadas"));
            this.temporadas = converterParaInteiro(removerTagsHTML(br.readLine()));

            while(!br.readLine().contains("N.º de episódios"));
            this.episodios = converterParaInteiro(removerTagsHTML(br.readLine()));
        
            br.close();         
        } catch(FileNotFoundException e) {
            System.out.println("Não é possível abrir o arquivo'" + fileName + "'");                
        } catch(IOException e) {
            System.out.println("Erro ao ler o arquivo'" + fileName + "'");
        }
    }
}