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

import java.util.Random;

public class EX06 {
    public static void main(String[] args) throws Exception {
        Random gerador = new Random();
        Pilha P1 = new Pilha();
        Pilha P2 = new Pilha();
        for (int i = 0; i < P1.tamanho; i++) {
            P1.empilhar(gerador.nextInt(50));
            P2.empilhar(gerador.nextInt(50));
        }

        System.out.println("==============P1=============");        
        for( int i  = P1.array.length - 1 ; i >= 0 ; i-- ){
            System.out.println("["+i+"]:"+P1.array[i]);        
        }  
        System.out.println("==============P2=============");        
        for( int i  = P2.array.length - 1 ; i >= 0 ; i-- ){
            System.out.println("["+i+"]:"+P2.array[i]);        
        }  
        
        Pilha pilhaConcatenada = ConcatenaPilha(P1, P2);
        System.out.println("==============Pilha Concatenada=============");        
        for( int i  = pilhaConcatenada.array.length - 1 ; i >=0 ; i-- ){
            System.out.println("["+i+"]:"+pilhaConcatenada.array[i]);        
        } 
        

    }
    public static Pilha ConcatenaPilha(Pilha P1, Pilha P2) throws Exception{
        Pilha PilhaConcatenada = new Pilha(P1.tamanho + P2.tamanho);
        for( int i = 0 ; i < P1.tamanho  ; i++ ){
            PilhaConcatenada.empilhar(P1.array[i]);
        }
        for( int j = 0 ; j < P2.tamanho  ; j++ ){
            PilhaConcatenada.empilhar(P2.array[j]);
        }
        return PilhaConcatenada;
    }

    

}



class Pilha {
    public int[] array;
    public int tamanho;
    public int topo = 0;
    
    Pilha(){
        this(10);
    }
    Pilha(int tamanho){
        this.tamanho = tamanho;
        array = new int[tamanho];
    }

    void empilhar(int novoElemento) throws Exception{
        if( topo < tamanho  ){
            this.array[topo] = novoElemento;
            topo++;
        }else{
            throw new Exception("ERRO: A pilha está cheia");
        }
    }

    public int desempilhar()  throws Exception{
        if( topo < 0 )
            throw new Exception("ERRO: A pilha está vazia");
        
        topo--;
        int resp =  array[topo];
        return resp;
        
    }
}