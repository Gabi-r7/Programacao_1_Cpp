// Implemente a classe Funcionario com nome, salario e os métodos
// addAumento(double valor), ganhoAnual() e exibeDados() - imprime os valores do
// funcionário.
//
// a. crie a classe Assistente, que também é um funcionário, e que possui um
// número de matrícula (faça os métodos GET e SET). Sobrescreva o método
// exibeDados().
//
// b. sabendo que os Assistentes Técnicos possuem um bônus salarial e que os
// Assistentes Administrativos possuem um turno (dia ou noite) e um adicional
// noturno, crie as classes Tecnico e Administrativo e sobrescreva o método
// ganhoAnual() de ambas as classes (Administrativo e Tecnico)
#include <iostream>

class Funcionarios {
    public:
        Funcionarios(){};
        ~Funcionarios(){};

        void setSalario(float _salario) {
            salario = _salario;
        };

        double addAumento(double valor) {
            salario += valor;
            return salario;
        };

        void ganhoAnual(float salario) {
            std::cout << "O ganho Anual é de: " << salario * 12;
        };

        void exibeDados(std::string nome) {
            std::cout << "\n\nNome: " << nome;
            std::cout << "\nSalário: " << salario;
        };

    private:
        std::string nome;
        float salario;
};


int main() {
    Funcionarios funcionarios;
    std::string nome;
    float salario;
    double valor;
    int opcao;

    std::cout << "Digite o nome do funcionário: ";
    std::cin >> nome;
    std::cout << "Digite o salário do funcionário: ";
    std::cin >> salario;
    funcionarios.setSalario(salario);

    do
    {
        std::cout << "\nEscolha uma opção:\n  - 0 para sair\n  - 1 para dar aumento\n - 2 para exibir o ganho anual\n - 3 para exibir os dados\n Digite uma opção válida: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            std::cout << "Digite o valor do aumento: ";
            std::cin >> valor;
            salario = funcionarios.addAumento(valor);
            funcionarios.setSalario(salario);
            break;
        case 2:
            funcionarios.ganhoAnual(salario);
            break;
        case 3:
            funcionarios.exibeDados(nome);
            break;    
        default:
            break;
        }
    } while (opcao != 0);
    
    std::cout << "Bye Bye amigo!";
    return 0;
}