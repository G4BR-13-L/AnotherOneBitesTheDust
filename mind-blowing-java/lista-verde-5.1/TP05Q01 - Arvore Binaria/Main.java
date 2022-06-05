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

		ArvoreBinaria arvore = new ArvoreBinaria();
		try {
			// int array[] = {4,35,10,13,3,30,15,12,7,40,20};
			for (Serie item : listaDadosSeries) {
				// System.out.println("Inserindo -> " + item);
				arvore.inserir(item);
			}
		} catch (Exception erro) {
			System.out.println(erro.getMessage());
		}

		int quantidadeDeInstrucoes = Integer.parseInt(stdin.readLine());
		for (int i = 0; i < quantidadeDeInstrucoes; i++) {
			String instrucao = stdin.readLine();
			if (instrucao.charAt(0) == 'I') {
				Serie novaSreie = new Serie();
				novaSreie.buscarDados(instrucao.substring(2));
				arvore.inserir(novaSreie);
			} else {
				arvore.remover(instrucao.substring(2).trim());
			}

		}

		String nomeSerie = stdin.readLine();
		do {
			arvore.pesquisar(nomeSerie);
			nomeSerie = stdin.readLine();
		} while (isFim(nomeSerie) == false);

		stdin.close();
		stdout.close();
		long endTime = System.nanoTime();
		long duration = (endTime - startTime) / 1000000;
		String stringDeLog = "739704\t" + duration + "ms\t" + arvore.comparacoes;
		escreverLog(stringDeLog);

	}

	public static boolean isFim(String s) {
		return (s.length() == 3 && s.charAt(0) == 'F' && s.charAt(1) == 'I' && s.charAt(2) == 'M');
	}

	public static void escreverLog(String logString) throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter("739704_arvoreBinaria.txt"));
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

/* =================================================================== */


class No {
	public Serie elemento; // Conteudo do no.
	public No esq, dir; // Filhos da esq e dir.

	public No(Serie elemento) {
		this(elemento, null, null);
	}

	public No(Serie elemento, No esq, No dir) {
		this.elemento = elemento;
		this.esq = esq;
		this.dir = dir;
	}
}

class ArvoreBinaria {
	private No raiz; 
	public int comparacoes = 0;

	public ArvoreBinaria() {
		raiz = null;
	}

	public void inserir(Serie x) {
		No novoNo = new No(x);
		if (this.raiz == null) {
			this.raiz = novoNo;
		} else {

			No atual = this.raiz;
			while (true) {
				if (atual == null) {
					return;
				} else if (novoNo.elemento.getNome().trim().compareTo(atual.elemento.getNome().trim()) > 0
						&& atual.dir == null) {
					atual.dir = novoNo;
					//System.out.println("Inserido: " + atual.dir.elemento.getNome());
					return;
				} else if (novoNo.elemento.getNome().trim().compareTo(atual.elemento.getNome().trim()) > 0
						&& atual.dir != null) {
					atual = atual.dir;
				} else if (novoNo.elemento.getNome().trim().compareTo(atual.elemento.getNome().trim()) < 0
						&& atual.esq == null) {
					atual.esq = novoNo;
					//System.out.println("Inserido: " + atual.esq.elemento.getNome());
					return;
				} else if (novoNo.elemento.getNome().trim().compareTo(atual.elemento.getNome().trim()) < 0
						&& atual.esq != null) {
					atual = atual.esq;
				} else if (novoNo.elemento.getNome().trim().equals(atual.elemento.getNome().trim())) {
					return;
				}
			}
		}
	}

	public void remover(String x) throws Exception {
		raiz = remover(x, raiz);

	}

	private No remover(String x, No i) throws Exception {

		if (i == null) {
			//System.out.println("Elemento não encontrado: " + x);

		} else if (x.trim().compareTo(i.elemento.getNome().trim()) < 0) {
			i.esq = remover(x, i.esq);

		} else if (x.trim().compareTo(i.elemento.getNome().trim()) > 0) {
			i.dir = remover(x, i.dir);
		
		} else if (i.dir == null) {
			i = i.esq;


		} else if (i.esq == null) {
			i = i.dir;

			
		} else {
			i.esq = maiorEsq(i, i.esq);
		}

		return i;
	}

	private No maiorEsq(No i, No j) {


		if (j.dir == null) {
			i.elemento = j.elemento; 
			j = j.esq; 

			
		} else {
			j.dir = maiorEsq(i, j.dir);
		}
		return j;
	}

	public void pesquisar(String x){
		System.out.print("raiz ");
		pesquisar(x, raiz);
	}

	private void pesquisar(String x, No i){
		if (i == null) {
			this.comparacoes++;
			System.out.println("NAO");

		} else if (x.trim().compareTo(i.elemento.getNome().trim()) < 0) {
			this.comparacoes++;
			System.out.print("esq ");
			pesquisar(x, i.esq);

		} else if (x.trim().compareTo(i.elemento.getNome().trim()) > 0) {
			this.comparacoes++;
			System.out.print("dir ");
			pesquisar(x, i.dir);
		}else{
			System.out.println("SIM");
			
		}
	}

}
