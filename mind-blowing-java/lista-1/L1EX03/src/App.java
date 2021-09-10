/*
3. Crie uma classe Televisao com métodos que podem controlar o volume e trocar os canais da
televisão. 

A TV só funciona ligada e deve ter limites de volume e canais. 

Os canais ao chegar no último volta para o primeiro. 

Crie os seguintes controles: 

aumentar ou diminuir a potência do volume de som em uma unidade de cada vez; 
aumentar e diminuir o número do canal em uma unidade 
trocar para um canal indicado ou subir um canal caso não seja informado o canal;
consultar o valor do volume de som e o canal selecionado.

*/

public class App {
    public static void main(String[] args) throws Exception {
        
        Televisao tv = new Televisao();
        tv.status();
        tv.ligar();
        System.out.println(tv.trocarCanal());
        System.out.println(tv.trocarCanal());
        System.out.println(tv.trocarCanal(90));
        tv.aumentarVolume();
        tv.aumentarVolume();
        tv.status();
        tv.desligar();

    }
}

class Televisao {

    private boolean isLigada;
    private int totalCanais;
    private int canalAtual;
    private int volumeMax;
    private int volumeAtual;

    Televisao(){
        this.totalCanais = 100;
        this.canalAtual = 0;
        this.volumeAtual = 20;
        this.volumeMax = 30;
        this.isLigada = false;
    }
    public void ligar(){
        this.setIsLigada(true);
        System.out.println("--- Tv Ligada ---");
    }
    public void desligar(){
        this.setIsLigada(false);
        System.out.println("--- Tv desligada ---");
    }
    public String trocarCanal() {
        if(!isLigada){
            return "A TV está deslidaga";
        }else if (this.canalAtual == this.totalCanais) {
            this.canalAtual = 0;
        return "Estamos no canal: " + this.canalAtual;

        } else {
            this.canalAtual++;
        return "Estamos no canal: " + this.canalAtual;

        }

    }

    public String trocarCanal(int canal) {
        if(!isLigada){
            return "A TV está deslidaga";
        }else if (canal > this.totalCanais || canal < 0) {
            return "---- Canal inexistente ----";
        } else {
            this.canalAtual = canal;
            return "Estamos no canal: " + this.canalAtual;
        }
    }

    public void aumentarVolume() {
        if (this.isLigada) {
            if( this.volumeAtual < this.volumeMax){
                this.volumeAtual++;
                System.out.println("Volume: " + this.volumeAtual);
            }else{
                System.out.println("Volume ja esta no máximo");
            }
        }else{
            tvDesligada();
        }
    }

    public void diminuirVolume() {
        if (this.isLigada) {
            if( this.volumeAtual > 0){
                this.volumeAtual--;
                System.out.println("Volume: " + this.volumeAtual);
            }else{
                System.out.println("A tv ja está muda");
            }
        }else{
            tvDesligada();
        }
    }
    public void status(){
        String status = "======status======\nLigada: %s\nCanal Atual: %s\nVolume: %s\n==================";
        status = String.format(status, this.isLigada, this.canalAtual, this.volumeAtual);
        System.out.println(status);
    }
    public void tvDesligada(){
        System.out.println("A TV está deslidaga");
    }
    // GETTERS E SETTERS
    public int getTotalCanais() {
        return totalCanais;
    }

    public void setTotalCanais(int totalCanais) {
        this.totalCanais = totalCanais;
    }

    public int getCanalAtual() {
        return canalAtual;
    }

    public void setCanalAtual(int canalAtual) {
        this.canalAtual = canalAtual;
    }

    public int getVolumeMax() {
        return volumeMax;
    }

    public void setVolumeMax(int volumeMax) {
        this.volumeMax = volumeMax;
    }

    public int getVolumeAtual() {
        return volumeAtual;
    }

    public void setVolumeAtual(int volumeAtual) {
        this.volumeAtual = volumeAtual;
    }

    public boolean isIsLigada() {
        return isLigada;
    }

    public void setIsLigada(boolean isLigada) {
        this.isLigada = isLigada;
    }

}