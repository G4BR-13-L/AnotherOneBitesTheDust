import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;



class Vela {
    private double abertura;
    private double fechamento;
    private double minimo;
    private double maximo;

    public Vela(double abertura, double fechamento, double minimo, double maximo) {
        this.abertura = abertura;
        this.fechamento = fechamento;
        this.minimo = minimo;
        this.maximo = maximo;
    }

    public double getAbertura() {
        return this.abertura;
    };

    public double getFechamento() {
        return this.fechamento;
    }

}



class Grafico {
    public List<Vela> velas;

    public Grafico(List<Vela> velas) {
        this.velas = velas;
    }

    /**
     * A solução por streams não funciona porque stream são abstrações
     * das listas, cuja a iteração pode acontecer em paralelo ou
     * na ordem reversa. Streams não podem depender de uma ordem lógica no fluxo.
     * No caso, não é possivel faz uma Stream e comparar o valor do elemento atual da
     * iteração com o próximo, poi o proximo elemento não é necessariamente 
     * o proximo na ordem das velas do grafico.
     * @return long
     */
    public long contarGapsStream() {
        AtomicInteger index = new AtomicInteger();
        return this.velas.stream()
        .filter(a -> a.getFechamento() > this.velas.get(index.incrementAndGet()).getAbertura())
        .count();      
    }


    /**
     * Esse método é a melhor solução por utilizar o classico for com contador
     * Estava errado em achar que Streams era a melhor solução
     * por conta das vantajens que poderiam vir no futuro. Como reuso e extensibilidade.
     * Foi um classico erro de over egineering 
     * @return int
     */
    public int contarGapsFor(){
        int contagem = 0;
        for ( int i  = 0 ; i < this.velas.size()-1 ; i++ ){
            if( this.velas.get(i).getFechamento() != this.velas.get(i+1).getAbertura() ){
                contagem++;
            }
        }
        return contagem;
    }
}

class Main {
    public static void main(String[] args) {

        List<Vela> velas = new ArrayList<>();

        velas.add(new Vela(10, 20, 8, 24));
        velas.add(new Vela(12, 15, 10, 20));
        velas.add(new Vela(11, 16, 10, 21));
        velas.add(new Vela(16, 15, 6, 18));
        velas.add(new Vela(15, 14, 5, 16));
        velas.add(new Vela(13, 21, 12, 28));
        velas.add(new Vela(19, 20, 18, 23));

        Grafico grafico = new Grafico(velas);
        System.out.println(grafico.contarGapsFor());

    }
}