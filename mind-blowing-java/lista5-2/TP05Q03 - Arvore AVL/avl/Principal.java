/**
 * Principal para Arvore Binaria de Pesquisa
 * @author Max do Val Machado
 */
public class Principal {
	public static void main(String[] args) {
		try {
			AVL avl = new AVL();
			//int array[] = {4,35,10,13,3,30,15,12,7,40,20};
			int array[] = {10, 15, 49, 18, 68, 1, 9, 94, 19, 3, 21, 17, 50};
			for(int item: array){
				System.out.println("Inserindo -> " + item);
				avl.inserir(item);
				avl.caminharPre();
			}
		} catch (Exception erro) {
			System.out.println(erro.getMessage());
		}
	}
}
