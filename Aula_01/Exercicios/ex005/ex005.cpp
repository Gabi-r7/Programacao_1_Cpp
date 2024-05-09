//  Crie uma classe chamada “Funcionário” com atributos para armazenar o nome, o
//  salário e o cargo do funcionário. Implemente métodos para calcular o salário líquido,
//  considerando descontos de impostos e benefícios.
#include <iostream>

class Funcionario {
  public:
    Funcionario(){};
    ~Funcionario(){};

    float calcSalario() {
      float salarioL;
      salarioL = salario;
      salarioL = salarioL -(salario * desconto / 100) - (salario * imposto / 100) + beneficio;
      return salarioL;
    };
    
    void setVar(std::string _nome, std::string _cargo, float _salario, float _desconto, float _imposto, float _beneficio) {
      nome = _nome;
      cargo = _cargo;
      salario = _salario;
      desconto = _desconto;
      imposto = _imposto;
      beneficio = _beneficio;
    };

  private:
    std::string nome, cargo;
    float salario, desconto, imposto, beneficio;
};

int main() {
  Funcionario funcionario;
  std::string nome, cargo;
  float salario, nSalario, desconto, imposto, beneficio;

  std::cout << "Digite o nome do funcionário: ";
  std::cin >> nome;
  std::cout << "Digite o cargo do funcionário: ";
  std::cin >> cargo;
  std::cout << "Digite o salário do funcionário: ";
  std::cin >> salario;
  std::cout << "Digite a porcentagem de desconto: ";
  std::cin >> desconto;
  std::cout << "Digite a porcentagem de imposto: ";
  std::cin >> imposto;
  std::cout << "Digite o valor do benefício: ";
  std::cin >> beneficio;
  funcionario.setVar(nome, cargo, salario, desconto, imposto, beneficio);

  nSalario = funcionario.calcSalario();

  std::cout << "\n\nNome: " << nome << "\nCargo: " << cargo << "\nSalário: " << nSalario << "\n";
  return 0;
};