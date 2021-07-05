/*=====================================================
 *Código desenvolvido por:
 *
 * ██████╗  █████╗ ██████╗ ██████╗ ██╗███████╗██╗
 *██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██║██╔════╝██║
 *██║  ███╗███████║██████╔╝██████╔╝██║█████╗  ██║
 *██║   ██║██╔══██║██╔══██╗██╔══██╗██║██╔══╝  ██║
 *╚██████╔╝██║  ██║██████╔╝██║  ██║██║███████╗███████╗
 * ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝
 * =====================================================
 *
 *PUC Minas - Engenharia de Software
 *04/07/2021
 *
 *
 *Fazer um programa para:
 *
 *Crie uma SuperClasse denominada Veiculo
 *Com os atributos private: ano de fabricação, placa e km atual
 *Agora crie duas subclasses: uma automóvel com os atributos de
 *veiculo e mais os atributos próprios: numero de portas, km ultima
 *revisão a outra subclasse será caminhão contendo os atributos
 *próprios: nr de pneus, capacidade e valor frete por km.
 *Crie todos os métodos getters e setters e um objeto de cada classe preenchendo
 *e imprimndo os dados dos objetos por meio de seus métodos!
 *
 *Indique qual exercício você quer substituir - 0 a 3 ptos
 */

#include <string.h>

#include <iostream>
#include <string>
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

using namespace std;

class Veiculo {
  // Atributos
 public:
  int ano;
  string placa;
  int kmAtual;
  Veiculo(int ano_, string placa_, int kmAtual_);
  // Métodos

 public:
  void setAno(int ano_);
  int getAno();

  void setPlaca(string placa_);
  string getPlaca();

  void setKmAtual(int kmAtual_);
  int getKmAtual();
};
// Metodos setters

void Veiculo::setAno(int ano_) { ano = ano_; }
void Veiculo::setPlaca(string placa_) { placa = placa_; }
void Veiculo::setKmAtual(int kmAtual_) { kmAtual = kmAtual_; }
Veiculo::Veiculo(int ano_, string placa_, int kmAtual_) {
  ano = ano_;
  placa = placa_;
  kmAtual = kmAtual_;
}
// Metodos getters

int Veiculo::getAno() { return ano; }
string Veiculo::getPlaca() { return placa; }
int Veiculo::getKmAtual() { return kmAtual; }

/*===========Classe Automovel==========*/

class Automovel : public Veiculo {
  // Atributos
 public:
  int numeroPortas, kmRevisao;
  Automovel(int ano_, string placa_, int kmAtual_, int numeroPortas_,
            int kmRevisao_);
  // metodos de automovel
 public:
  void setPortas(int portas_);
  int getPortas();

  void setRevisao(int kmRevisao_);
  int getRevisao();
};
// metodods setters
void Automovel::setPortas(int portas_) { numeroPortas = portas_; }
void Automovel::setRevisao(int kmRevisao_) { kmRevisao = kmRevisao_; }
Automovel::Automovel(int ano_, string placa_, int kmAtual_, int numeroPortas_,
                     int kmRevisao_)
    : Veiculo{ano_, placa_, kmAtual_} {
  numeroPortas = numeroPortas_;
  kmRevisao = kmRevisao_;
}
// metodods getters
int Automovel::getPortas() { return numeroPortas; }
int Automovel::getRevisao() { return kmRevisao; }

/*===========Classe Caminhão==========*/

class Caminhao : public Veiculo {
  // Atributos
 public:
  int numeroPneus, capacidade;
  float frete;
  Caminhao(int ano_, string placa_, int kmAtual_, int numeroPneus_,
           int capacidade_, float frete_);
  // Métodos
 public:
  void setPneus(int pneus_);
  int getPneus();

  void setCapacidade(int capacidade_);
  int getCapacidade();

  void setFrete(int frete_);
  int getFrete();
};

// metodods setters
void Caminhao::setPneus(int pneus_) { numeroPneus = pneus_; }
void Caminhao::setCapacidade(int capacidade_) { capacidade = capacidade_; }
void Caminhao::setFrete(int frete_) { frete = frete_; }
Caminhao::Caminhao(int ano_, string placa_, int kmAtual_, int numeroPneus_,
                   int capacidade_, float frete_)
    : Veiculo{ano_, placa_, kmAtual_} {
  numeroPneus = numeroPneus_;
  capacidade = capacidade_;
  frete = frete_;
}

// metodods getters
int Caminhao::getPneus() { return numeroPneus; }
int Caminhao::getCapacidade() { return capacidade; }
int Caminhao::getFrete() { return frete; }

int main() {
  cout << BOLDRED << "\n\nIniciando objeto Veiculo..." << RESET;
  Veiculo veiculo(2021, "ABC-1234", 10);

  cout << BOLDGREEN << "\nIniciando objeto automovel..." << RESET;
  Automovel automovel(2020, "DEF-5678", 200, 4, 100);

  cout << BOLDBLUE << "\nIniciando objeto caminhao..." << RESET;
  Caminhao caminhao(2019, "GHI-9101", 600, 12, 22, 100);

  // Impress�o dos dados
  cout << BOLDRED << "\n\n-----------------------------------------------\n"
       << RESET;
  cout << BOLDRED << "Dados do objeto Veiculo" << RESET;
  cout << "\nPlaca: " << veiculo.getPlaca();
  cout << "\nAno de fabricacao: " << veiculo.getAno();
  cout << "\nQuilimetros rodados: " << veiculo.getKmAtual();
  cout << BOLDRED << "\n-----------------------------------------------\n"
       << RESET;
  cout << BOLDGREEN << "-----------------------------------------------\n"
       << RESET;
  cout << BOLDGREEN "Dados do objeto Automovel" << RESET;
  cout << "\nPlaca: " << automovel.getPlaca();
  cout << "\nAno de fabricação: " << automovel.getAno();
  cout << "\nQuilometros rodados: " << automovel.getKmAtual();
  cout << "\nQuantidade de portas: " << automovel.getPortas();
  cout << "\nkm da ultima revisao: " << automovel.getRevisao();
  cout << BOLDGREEN << "\n-----------------------------------------------\n"
       << RESET;
  cout << BOLDBLUE << "-----------------------------------------------\n"
       << RESET;

  cout << BOLDBLUE << "Dados do objeto Caminhao" << RESET;
  cout << "\nPlaca: " << caminhao.getPlaca();
  cout << "\nAno de fabricacao: " << caminhao.getAno();
  cout << "\nQuilometros rodados: " << caminhao.getKmAtual();
  cout << "\nQuantidade de pneus: " << caminhao.getPneus();
  cout << "\nCapacidade: " << caminhao.getCapacidade();
  cout << "\nValor do frete: " << caminhao.getFrete();
  cout << BOLDBLUE << "\n-----------------------------------------------\n"
       << RESET;

  return 0;
}

// Fim do programa!
