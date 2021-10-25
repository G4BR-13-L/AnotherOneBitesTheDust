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

public class EX07 {
    public static void main(String[] args) throws Exception {
        Random gerador = new Random();
        RandomQueue fila = new RandomQueue(15);
        for (int i = 0; i < 10; i++) {
            fila.Enqueue(gerador.nextInt(100));
        }
        /*fila.printarTudo();
        System.out.println("\nElemento removido: "+fila.Dequeue());
        fila.printarTudo();
        System.out.println("\nElemento removido: "+fila.Dequeue());
        fila.printarTudo();
        System.out.println("\nElemento removido: "+fila.Dequeue());
        fila.printarTudo();*/

        System.out.println("\nElemento removido: "+fila.Dequeue());
        fila.printarTudo();

        System.out.println("\nElemento selecionado: "+fila.Sample());
        fila.printarTudo();
        System.out.println("\nElemento selecionado: "+fila.Sample());
        fila.printarTudo();


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

class RandomQueue extends Fila{
    public int posicoesOcupadas = 0;   
    // Construtora – cria uma RandomQueue vazia 
    RandomQueue(){
        this(10);
    } 
    
    RandomQueue(int tamanho) {
        array = new int[tamanho];
        primeiro = ultimo = 0;
        this.tamanho = tamanho;
    }     

    // Retorna true se a RandomQueue estiver vazia
    boolean IsEmpty() { 
        if( this.primeiro == this.ultimo ){
            return true;
        } else {
            return false;
        }
    }

     // Adiciona um item
    void Enqueue(int novoElemento) throws Exception{ 
        if(((ultimo + 1) % array.length) == primeiro){
            throw new Exception("ERRO: A fila esta cheia");
        }
        array[ultimo] = novoElemento;
        ultimo = ( ultimo + 1 ) % array.length;
        this.posicoesOcupadas++;
    }   

     // Remove e retorna um elemento aleatório da RandomQueue
    int Dequeue() throws Exception{  
        Random gerador = new Random();
        if( primeiro == ultimo ){
            throw new Exception("ERRO: A fila está vazia");
        }      

        int posicaoRemovida = gerador.nextInt(this.posicoesOcupadas);
        int resp = this.array[posicaoRemovida];
        for( int i = posicaoRemovida ; i <= posicoesOcupadas ; i++ ){
            this.array[i] = this.array[i+1];
        }
        this.posicoesOcupadas--;
        primeiro = ( primeiro + 1 ) % array.length;
        return resp;
    } 

     // Retorna um elemento aleatório sem removê-lo da RandomQueue 
    int Sample() throws Exception{ 
        Random gerador = new Random();
        if( primeiro == ultimo ){
            throw new Exception("ERRO: A fila está vazia");
        }      
        int posicaoAleatoria = gerador.nextInt(this.posicoesOcupadas);
        int resp = this.array[posicaoAleatoria];
        return resp;
    } 

    void printarTudo(){
        System.out.println("\n=====FILA====");
        for ( int i = 0 ; i < this.tamanho ; i++ ){
            System.out.print("["+this.array[i]+"] ");
        }
        this.status();
    }

    void status(){
        System.out.println("\nQuantidade de posições ocupadas: "+this.posicoesOcupadas+"\nPrimeiro: "+this.primeiro+"\nUltimo: "+this.ultimo+"\n\n");
    }
} 