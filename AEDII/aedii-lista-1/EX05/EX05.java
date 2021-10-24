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

public class EX05 {
    public static void main(String[] args) throws Exception {
        Random gerador = new Random();
        Fila F1 = new Fila();
        Fila F2 = new Fila();
        for (int i = 0; i < 9; i++) {
            F1.enfileirar(gerador.nextInt(50));
            F2.enfileirar(gerador.nextInt(50));
        }

        System.out.println("==============F1=============");        
        for( int i  = 0 ; i < F1.array.length ; i++ ){
            System.out.println(F1.array[i]);        
        }  
        System.out.println("==============F2=============");        
        for( int i  = 0 ; i < F2.array.length ; i++ ){
            System.out.println(F2.array[i]);        
        }  
        
        Fila filaConcatenada = ConcatenaFila(F1, F2); 
        System.out.println("==============Fila Concatenada=============");        
        for( int i  = 0 ; i < filaConcatenada.array.length ; i++ ){
            System.out.println(filaConcatenada.array[i]);        
        }  
        

    }

    public static Fila ConcatenaFila(Fila  F1,  Fila  F2) throws Exception{
        Fila FilaConcatenada = new Fila(F1.tamanho + F2.tamanho);
        for( int i = 0 ; i < 10 - 1 ; i++ ){
            FilaConcatenada.enfileirar(F1.array[i]);
        }
        for( int j = 0 ; j < 10 ; j++ ){
            FilaConcatenada.enfileirar(F2.array[j]);

        }
        return FilaConcatenada;
    }

}



class Fila{
    public int[] array;
    public int primeiro;
    public int ultimo;
    public int tamanho;

    Fila(){
        this(10);
    }
    Fila(int tamanho){
        array = new int[tamanho];
        primeiro = ultimo = 0;
        this.tamanho = tamanho;
    }

    void enfileirar(int novoElemento) throws Exception{
        if(((ultimo + 1) % array.length) == primeiro){
            throw new Exception("ERRO: A fila esta cheia");
        }
        array[ultimo] = novoElemento;
        ultimo = ( ultimo + 1 ) % array.length;

    }

    int desenfileirar() throws Exception{
        if( primeiro == ultimo ){
            throw new Exception("ERRO: A fila está vazia");
        }
        int resp = array[primeiro];
        primeiro = ( primeiro + 1 ) % array.length;
        
        return resp;
    }

    
}