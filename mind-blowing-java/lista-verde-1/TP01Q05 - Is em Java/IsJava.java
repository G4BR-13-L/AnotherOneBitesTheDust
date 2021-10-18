
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

public class IsJava {
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
        PrintStream stdout = new PrintStream(System.out, true, "ISO-8859-1");
        String linha;
        do {
            linha = stdin.readLine();
            if (IsJava.isFim(linha)) {
                break;
            }
            if( IsJava.isVogal(linha) ){
                stdout.println("SIM NAO NAO NAO"); 
            }else if( IsJava.isInteiro(linha) ){
                stdout.println("NAO NAO SIM SIM"); 
            }else if( IsJava.isReal(linha) ){
                stdout.println("NAO NAO NAO SIM"); 
            }else if (IsJava.isConsoante(linha)){
                stdout.println("NAO SIM NAO NAO"); 
            }else{
                stdout.println("NAO NAO NAO NAO"); 
            }
        } while (true);
        stdin.close();
        stdout.close();
    }

    public static boolean isVogal(String str) {
        int tam = str.length();
        char[] array = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        for (int i = 0; i < tam; i++) {
            boolean valido = false;
            for (char c : array) {
                if (c == str.charAt(i)) {
                    valido = true;
                }
            }
            if (!valido) {
                return false;
            }
        }
        return true;
    }

    public static boolean isConsoante(String str){
        int tam = str.length();
        for( int i = 0 ; i < tam ; i++ ){
            char c= str.charAt(i);
            boolean isConsoante = ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') );
            char c2[] = {c};
            if( !isConsoante || IsJava.isVogal(new String(c2)) ){
                return false;
            }
        }
        return true;
    }

    public static boolean isInteiro(String str) {
        int tam = str.length();
        for (int i = 0; i < tam; i++) {
            if (!(str.charAt(i) >= '0' && str.charAt(i) <= '9')) {
                return false;
            }
        }
        return true;
    }

    public static boolean isReal(String str) {
        int tam = str.length();
        boolean isComma = false;
        for (int i = 0; i < tam; i++) {
            char c = str.charAt(i);
            if (!(c >= '0' && c <= '9')) {
                if (c == ',' || c == '.') {
                    if (isComma) {
                        return false;
                    }
                    isComma = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean isFim(String str) {
        if (str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M') {
            return true;
        } else {
            return false;
        }
    }

}
