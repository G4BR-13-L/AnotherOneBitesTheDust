public class Carro {
  
    private String fabricante;
    private int ano;
    private int capacidade;
    private float combustivel;
  
    public String getFabricante(){
      return this.fabricante;
    }
    public int getAno(){
      return this.ano;
    }
    public float getCombustivel(){
      return this.combustivel;
    }
    public int getCapacidade(){
        return this.capacidade;
    }

    public String mostrarStatus(){
      String status = "Fabricante: "+this.fabricante+"\nAno: "+this.ano+"\nCapacidade: "+this.capacidade+"\nCombustivel: "+this.combustivel;
      return status;
    }


    public void setFabricante(String fabricante){
      this.fabricante = fabricante;
    }
    public void setAno(int ano){
      this.ano = ano;
    }
    public void encherTanque(){
        this.combustivel = capacidade;
    }
    public void dirigir(int km ){
      this.combustivel -= km/8;
      if( combustivel < 0 ){
        this.combustivel = 0;
      }
    }
    public void clearScreen(){
      System.out.print("\033[H\033[2J");
      System.out.flush();
      this.mostrarStatus();
    }
    Carro(){
         this.fabricante = "Generico";
         this.ano = 2021;
         this.capacidade = 100;
         this.combustivel = 100;
    }
  
  
    /**
     * @param capacidade the capacidade to set
     */
    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }

    /**
     * @param combustivel the combustivel to set
     */
    public void setCombustivel(float combustivel) {
        this.combustivel = combustivel;
    }

}