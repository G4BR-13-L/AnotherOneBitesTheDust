
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.Charset;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
        PrintStream stdout = new PrintStream(System.out, true, "ISO-8859-1");

        String linha;
       
        do {
            linha = stdin.readLine();
            if( Main.isFim(linha) ){
                break;
            }
            stdout.println(Main.encode(linha));
        }while( true);
        
        
        
        
        stdin.close();
        stdout.close();
    }
    public static String encode(String str){
        int tam = str.length();
        char caractere[] = new char[tam];
        for( int i = 0 ; i < tam ; i++ ){
            int codigo = (int) str.charAt(i) + 3;
            caractere[i] = (char) codigo;
        }
        return new String(caractere);
    }
    public static boolean isFim( String str) {
        if ( str.length() == 3 && str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M'){
            return true;
        }else{
            return false;
        }
    }
}
