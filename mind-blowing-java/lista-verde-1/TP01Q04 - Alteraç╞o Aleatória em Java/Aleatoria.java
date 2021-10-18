

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
import java.util.Random;

public class Aleatoria {
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
        PrintStream stdout = new PrintStream(System.out, true, "ISO-8859-1");
        Aleatoria.rand.setSeed(4);
        String linha;
        do {
            linha = stdin.readLine();
            if (Aleatoria.isFim(linha)) {
                break;
            }
            stdout.println(Aleatoria.encode(linha));
        } while (true);
        stdin.close();
        stdout.close();
    }

    public static String encode(String str) {
        int tam = str.length();
        char caractere[] = new char[tam];
        char aux[] = { Aleatoria.GerarAleatorio(), Aleatoria.GerarAleatorio() };
        for (int i = 0; i < tam; i++) {
            char codigo = str.charAt(i);
            if (codigo == aux[0]) {
                codigo = aux[1];
            }
            caractere[i] = codigo;
        }
        return new String(caractere);
    }

    public static boolean isFim(String str) {
        if (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M') {
            return true;
        } else {
            return false;
        }
    }

    public static Random rand = new Random();

    public static char GerarAleatorio() {
        return (char) ('a' + (Math.abs(Aleatoria.rand.nextInt()) % 26));
    }
}
