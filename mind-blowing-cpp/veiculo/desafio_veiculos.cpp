#include <iostream>
#include <string.h>
#include <string>

using namespace std;


// **************************************SUPER-CLASSE*********************************************


class Veiculo
{

//Atributos:

private:
    int anoFabri, kmAtual;
    string placa;

// M�todos:

public:
    Veiculo();

    void setPlaca(string p);
    string getPlaca();

    void setAnoFabri(int af);
    int getAnoFabri();

    void setKm(int kma);
    int getKm();
};

// SETTERS

void Veiculo::setPlaca(string p)
{

    placa = p;

}

void Veiculo::setAnoFabri(int af)
{

    anoFabri = af;

}

void Veiculo::setKm(int kma)
{

    kmAtual = kma;
}


// GETTERS

string Veiculo::getPlaca()
{

    return placa;

}

int Veiculo::getAnoFabri()
{

    return anoFabri;

}

int Veiculo::getKm()
{

    return kmAtual;

}

// **********************************************************************************************

// ***************************************SUB-CLASSE AUTOM�VEL***********************************

class Automovel: public Veiculo
{

    // Atributos

public:
    int numPortas, kmRevisao;

    // M�todos

public:
    Automovel();

    void setPortas(int prt);
    int getPortas();

    void setRevisao(int kmr);
    int getRevisao();

};

// SETTERS

void Automovel::setPortas(int prt)
{
    numPortas = prt;

}

void Automovel::setRevisao (int kmr)
{
    kmRevisao = kmr;

}

// GETTERS

int Automovel::getPortas()
{

    return numPortas;


}

int Automovel::getRevisao()
{

    return kmRevisao;
}


// *********************************************************************************************


// ***************************************SUB-CLASSE CAMINH�O***********************************


class Caminhao: public Veiculo
{

    // Atributos

public:
    int numPneus, capacidade;
    float frete;

    // M�todos
public:
    Caminhao();

    void setPneus(int pn);
    int getPneus();

    void setCapacidade(int cap);
    int getCapacidade();

    void setFrete(int fr);
    int getFrete();


};

// SETTERS

void Caminhao::setPneus(int pn)
{
    numPneus = pn;

}

void Caminhao::setCapacidade (int cap)
{
    capacidade = cap;

}

void Caminhao::setFrete (int fr)
{
    frete = fr;

}

// GETTERS

int Caminhao::getPneus()
{

    return numPneus;


}

int Caminhao::getCapacidade()
{

    return capacidade;
}

int Caminhao::getFrete()
{

    return frete;
}

// *********************************************************************************************

int main()
{
    cout << "Criando um objeto da classe Ve�culo";

    Veiculo v;

    v.setPlaca("ABCDEFG-12345");
    v.setAnoFabri(2011);
    v.setKm(500);

    cout<< "\nCriando um objeto da classe Autom�vel";

    Automovel a;

    a.setPortas(4);
    a.setRevisao(2020);


    cout<< "\nCriando um objeto da classe Caminh�o";

    Caminhao c;

    c.setPneus(8);
    c.setCapacidade(200);
    c.setFrete(15);


    // Impress�o dos dados

    cout << "\nDados do objeto Ve�culo";
    cout << "\nPlaca: " << v.getPlaca();
    cout << "\nAno de fabrica��o: " << v.getAnoFabri();
    cout << "\nQuil�metros rodados: " << v.getKm();


    cout << "\nDados do objeto Autom�vel";
    cout << "\nDados do objeto Ve�culo";
    cout << "\nPlaca: " << a.getPlaca();
    cout << "\nAno de fabrica��o: " << a.getAnoFabri();
    cout << "\nQuil�metros rodados: " << a.getKm();
    cout << "\nQuantidade de portas: " << a.getPortas();
    cout << "\nAno da �ltima revis�o: " << a.getRevisao();


    cout << "\nDados do objeto Caminh�o";
    cout << "\nDados do objeto Ve�culo";
    cout << "\nPlaca: " << c.getPlaca();
    cout << "\nAno de fabrica��o: " << c.getAnoFabri();
    cout << "\nQuil�metros rodados: " << c.getKm();
    cout << "\nQuantidade de pneus: " << c.getPneus();
    cout << "\nCapacidade: " << c.getCapacidade();
    cout << "\nValor do frete: " << c.getFrete();


    return 0;

}

// Fim do programa!
