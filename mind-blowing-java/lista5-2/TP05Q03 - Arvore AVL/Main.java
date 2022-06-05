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

		AVL arvore = new AVL();
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
		BufferedWriter writer = new BufferedWriter(new FileWriter("739704_avl.txt"));
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

	public int comparar(Serie outro){
		return nome.compareTo(outro.nome);
	}

	public String qualONomeDaSerie(String fileName) {
		return fileName.replace(".html", "").replaceAll("_", " ").trim();
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
		this.nome = nome.trim();
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

// Java program for deletion in AVL Tree
 
class Node
{
    Serie key;
	int height;
    Node left, right;
 
    Node(Serie d)
    {
        key = d;
        height = 1;
    }
}
 
class AVL
{
    Node root;
	int comparacoes = 0;
 
    // A utility function to get height of the tree
    int height(Node N)
    {
        if (N == null)
            return 0;
        return N.height;
    }
 
    // A utility function to get maximum of two integers
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
 
    // A utility function to right rotate subtree rooted with y
    // See the diagram given above.
    Node rightRotate(Node y)
    {
        Node x = y.left;
        Node T2 = x.right;
 
        // Perform rotation
        x.right = y;
        y.left = T2;
 
        // Update heights
        y.height = max(height(y.left), height(y.right)) + 1;
        x.height = max(height(x.left), height(x.right)) + 1;
 
        // Return new root
        return x;
    }
 
    // A utility function to left rotate subtree rooted with x
    // See the diagram given above.
    Node leftRotate(Node x)
    {
        Node y = x.right;
        Node T2 = y.left;
 
        // Perform rotation
        y.left = x;
        x.right = T2;
 
        // Update heights
        x.height = max(height(x.left), height(x.right)) + 1;
        y.height = max(height(y.left), height(y.right)) + 1;
 
        // Return new root
        return y;
    }
 
    // Get Balance factor of node N
    int getBalance(Node N)
    {
        if (N == null)
            return 0;
        return height(N.left) - height(N.right);
    }

    Node insert(Node node, Serie key)
    {
        /* 1. Perform the normal BST rotation */
        if (node == null)
            return (new Node(key));
 
        if (key.comparar(node.key) < 0)
            node.left = insert(node.left, key);
        else if (key.comparar(node.key) > 0)
            node.right = insert(node.right, key);
        else // Equal keys not allowed
            return node;
 
        /* 2. Update height of this ancestor node */
        node.height = 1 + max(height(node.left),
                            height(node.right));
 
        /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        Wunbalanced */
        int balance = getBalance(node);
 
        // If this node becomes unbalanced, then
        // there are 4 cases Left Left Case
        if (balance > 1 && key.comparar(node.left.key) < 0)
            return rightRotate(node);
 
        // Right Right Case
        if (balance < -1 && key.comparar(node.right.key) > 0)
            return leftRotate(node);
 
        // Left Right Case
        if (balance > 1 && key.comparar(node.left.key) > 0)
        {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }
 
        // Right Left Case
        if (balance < -1 && key.comparar(node.right.key) < 0)
        {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }
 
        /* return the (unchanged) node pointer */
        return node;
    }

	void inserir(Serie key){
		root = insert(root, key);
	}
 
    /* Given a non-empty binary search tree, return the
    node with minimum key value found in that tree.
    Note that the entire tree does not need to be
    searched. */
    Node minValueNode(Node node)
    {
        Node current = node;
 
        /* loop down to find the leftmost leaf */
        while (current.left != null)
        current = current.left;
 
        return current;
    }
 
    Node deleteNode(Node root, Serie key)
    {
        // STEP 1: PERFORM STANDARD BST DELETE
        if (root == null)
            return root;
 
        // If the key to be deleted is smaller than
        // the root's key, then it lies in left subtree
        if (key.comparar(root.key) < 0)
            root.left = deleteNode(root.left, key);
 
        // If the key to be deleted is greater than the
        // root's key, then it lies in right subtree
        else if (key.comparar(root.key) > 0)
            root.right = deleteNode(root.right, key);
 
        // if key is same as root's key, then this is the node
        // to be deleted
        else
        {
 
            // node with only one child or no child
            if ((root.left == null) || (root.right == null))
            {
                Node temp = null;
                if (temp == root.left)
                    temp = root.right;
                else
                    temp = root.left;
 
                // No child case
                if (temp == null)
                {
                    temp = root;
                    root = null;
                }
                else // One child case
                    root = temp; // Copy the contents of
                                // the non-empty child
            }
            else
            {
 
                // node with two children: Get the inorder
                // successor (smallest in the right subtree)
                Node temp = minValueNode(root.right);
 
                // Copy the inorder successor's data to this node
                root.key = temp.key;
 
                // Delete the inorder successor
                root.right = deleteNode(root.right, temp.key);
            }
        }
 
        // If the tree had only one node then return
        if (root == null)
            return root;
 
        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root.height = max(height(root.left), height(root.right)) + 1;
 
        // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
        // this node became unbalanced)
        int balance = getBalance(root);
 
        // If this node becomes unbalanced, then there are 4 cases
        // Left Left Case
        if (balance > 1 && getBalance(root.left) >= 0)
            return rightRotate(root);
 
        // Left Right Case
        if (balance > 1 && getBalance(root.left) < 0)
        {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }
 
        // Right Right Case
        if (balance < -1 && getBalance(root.right) <= 0)
            return leftRotate(root);
 
        // Right Left Case
        if (balance < -1 && getBalance(root.right) > 0)
        {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }
 
        return root;
    }

	void remover(String key){
		Serie temp = new Serie();
		temp.setNome(key);
		root = deleteNode(root, temp);
	}
 
	public Node search(Node root, String key)
	{
		if(root == null){
			this.comparacoes++;
			System.out.println("NAO");
			return null;
		}

		if (root.key.getNome().equals(key)){
			this.comparacoes++;
			System.out.println("SIM");
			return root;
		}
	
		if (root.key.getNome().compareTo(key) < 0){
			this.comparacoes++;
			System.out.print("dir ");
			return search(root.right, key);
		}
	
		System.out.print("esq ");
		return search(root.left, key);
	}

	public void pesquisar(String key){
		System.out.print("raiz ");
		search(root, key);
	}

    // A utility function to print preorder traversal of
    // the tree. The function also prints height of every
    // node
    void preOrder(Node node)
    {
        if (node != null)
        {
            System.out.print(node.key + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }
}