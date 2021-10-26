public class EX32 {

}

class CCelula {
  public int item;
  public CCelula prox;
}

class CListaSimples {
  private CCelula primeira, ultima;
  public CListaSimples() {
    // Código da função construtora         
  }
  public bool vazia() {
    // Código para verificar se a Lista está vazia 
    if(this.primeira ==  null && this.ultima == null){
        return true;
    }else{
        return false;
    }       
  }
  public void insereComeco(Object valorItem) { 
      // Código para inserir valorItem no início da Lista
      CCelula novoItem = new CCelula();
      novoItem.item = Integer.parseInt(valorItem);
      novoItem.prox = this.primeira;
      this.primeira = novoItem;

  }
  public Object removeComeco() {
    // Código para remover e retornar o elemento do início da Lista 
    Object removido = this.primeira.item;        
    this.primeira = this.primeira.prox;
    return removido;
  }
  public void insereFim(Object valorItem) { 
      // Código para inserir valorItem no fim da Lista     
      CCelula atualUltimo = this.ultima;
      CCelula novoItem = new CCelula(); 
      novoItem.item = Integer.parseInt(valorItem);
      atualUltimo.prox = novoItem;
      this.ultima = novoItem;   
  }
  public Object removeFim() {
    // Código para remover e retornar o elemento do fim da Lista
    if(this.vazia()){
        return "Lista vazia";
    }else{
        if ( this.primeira == this.ultima ){
            this.primeira = null;
            this.ultima = null;
        }else{

            CCelula atual = this.primeira.prox;
            while(true){
                if(atual.prox.prox == null){
                    int removido = atual.prox.item;
                    atual.prox = null;
                    return removido;
                }else{
                    atual = atual.prox;
                }
            }      
        }
    }
  }
  public void imprime() {
    // Código para imprimir todos os elementos da Lista 
    CCelula atual = this.primeiro;
        System.out.println("\n\n");
        for (int i = 0; i < this.quantidade; i++) {
            System.out.println("Posição: [" + i + "]\nChave: [" + atual.item + "]\n==============\n");
            atual = atual.prox;
        }        
  }
  public bool contem(Object elemento) {
    // Código para verifica se a Lista contem o elemento passado              
    // como parâmetro 
    
    if (this.primeira.item == Integer.parseInt(elemento)  ){
        return true;
    }else{
        CCelula atual = this.primeira;
        do{
            if( atual.item == Integer.parseInt(elemento) ){
                return true;
            }else{
                atual = atual.prox;
            }
        }while(atual.prox != null);
        return false;
    }
  }
}

