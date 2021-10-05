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

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
        PrintStream stdout = new PrintStream(System.out, true, "ISO-8859-1");

        int n = Integer.parseInt(stdin.readLine());
        String[] lista = new String[n];
        for (int i = 0; i < n; i++) {
            lista[i] = stdin.readLine();
        }
        float[] listaFloat = new float[n];
        String zero = "0";
        for (int k = 0; k < n; k++) {
            listaFloat[k] = Float.parseFloat(zero.concat(lista[k]));
        }
        
        
        //PROCESSO DE ESCRITA NO ARQUIVO: listaFloat.txt
        OutputStream os = new FileOutputStream("listaFloat.txt");
        Writer wr = new OutputStreamWriter(os); 
        BufferedWriter bw = new BufferedWriter(wr);
        for( int m = n - 1; m >= 0; m-- ){
            bw.write(Float.toString(listaFloat[m]));
            bw.newLine();
        }
        bw.close();


        //PROCESSO DE LEITURA DO ARQUIVO: listaFloat.txt
        FileInputStream stream = new FileInputStream("listaFloat.txt");
        InputStreamReader reader = new InputStreamReader(stream);
        BufferedReader br = new BufferedReader(reader);
        String linha = br.readLine();
        String[] listaLida = new String[n];
        listaLida[0] = linha;
        for( int o = 1 ; o < n ; o++ ){
            linha = br.readLine();
            listaLida[o] = linha; 
        }


        //PRINTANDO A SAIDA
        for (int j = 0; j < n; j++) {
            float valor = Float.parseFloat(listaLida[j]);
            if (isInteiro( valor )){
                stdout.printf("%.0f\n", valor); 
            }else{
                stdout.println(valor); 
            }
        }
        stdin.close();
        stdout.close();
    }

    // ESSA FUNÇÃO VERIFICA SO O NUMEOR É INTEIRO, REOTORNANDO TRUE OU FALSE
    public static boolean isInteiro(double num) {
        int aux = (int) num;
        return (((double) aux) == num);
    }
}