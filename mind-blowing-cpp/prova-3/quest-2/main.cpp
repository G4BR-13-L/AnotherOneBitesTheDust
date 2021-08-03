#include <string.h>
#include <math.h>
#include <iostream>
#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */

using namespace std;

class Funcionario {
  // Atributos
 public:
  string nome;
  int codigo;
  int anoAdimissao;
  float salarioBase, salarioAtual;
  Funcionario(string nome_, int codigo_, int ano_, float sal_);
  // Métodos

 public:
  void FuncionarioPadrao();
  void setNome(string nome_);
  string getNome();

  void setCodigo(int codigo_);
  int getCodigo();

  void setAnoAdimissao(int ano_);
  int getAnoAdimissao();

  void setSalariobase(float sal_);
  float getSalariobase();

  void setSalarioAtual(float sal_);
  float getSalarioAtual();
};
// Metodos setters

void Funcionario::setCodigo(int codigo_) { codigo = codigo_; };
void Funcionario::setAnoAdimissao(int ano_) { anoAdimissao = ano_; };
void Funcionario::setSalariobase(float sal_) { salarioBase = sal_; };
void Funcionario::setSalarioAtual(float sal_) { salarioAtual = sal_; };
void Funcionario::setNome(string nome_) { nome = nome_; };
Funcionario::Funcionario(string nome_, int codigo_, int ano_, float sal_) {
  codigo = codigo_;
  anoAdimissao = ano_;
  salarioBase = sal_;
  nome = nome_;
  salarioAtual = salarioBase*pow((0.01+1), (2021 - anoAdimissao));
}
void Funcionario::FuncionarioPadrao() {
  codigo = 99999;
  anoAdimissao = 2021;
  salarioBase = 1100;
  nome = "Sem nome";
  salarioAtual = salarioBase*pow((0.01+1), (2021 - anoAdimissao));
}
// Metodos getters
int Funcionario::getCodigo() { return codigo; };
int Funcionario::getAnoAdimissao() { return anoAdimissao; };
float Funcionario::getSalariobase() { return salarioBase; };
float Funcionario::getSalarioAtual() { return salarioAtual; };
string Funcionario::getNome() { return nome; };

int main() {

  Funcionario Fulano("Fulano", 1234, 2002, 2000);
  cout << BOLDRED << "\n\n-----------------------------------------------\n"
       << RESET;
  cout << BOLDRED << "Dados Funcionario" << RESET;
  cout << "\nNome: " << Fulano.getNome();
  cout << "\nCodigo: " << Fulano.getCodigo();
  cout << "\nAno de Adimissao: " << Fulano.getAnoAdimissao();
  cout << "\nSalario Base: " << Fulano.getSalariobase();
  cout << "\nSalario Atual: " << Fulano.getSalarioAtual();
  cout << BOLDRED << "\n-----------------------------------------------\n";

return 0;
}

// Fim do programa!
