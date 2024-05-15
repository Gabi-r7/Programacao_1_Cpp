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

        float getSalario() {
            return salario;
        }

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

class Assistente : public Funcionarios {
    public:
        Assistente(){};
        ~Assistente(){};

        void setMatricula(int _matricula) {
            matricula = _matricula;
        };

        int getMatricula() {
            return matricula;
        };

        void exibeDados() {
            std::cout << "\n\nMatricula: " << matricula;
        }
    private:
        int matricula;
};

class Administrativo : public Assistente {
    public:
        Administrativo(){};
        ~Administrativo(){};

        void adicionalNoturno(float adicional) {
            setSalario(getSalario() + adicional); 
        }
        
        void ganhoAnual(float salario) {
            std::cout << "\nGanho anual assistente administrativo: " << salario * 12;
        }
};

class Tecnico : public Assistente {
    public:
        Tecnico(){};
        ~Tecnico(){};

        void addBonus(float bonus){
            setSalario(getSalario() + bonus);
        }

        void ganhoAnual(float salario) {
            std::cout << "\nGanho anual assistente técnico: " << salario * 12;
        }
};

int main() {
    Funcionarios funcionarios;
    Assistente assistente;
    Administrativo administrativo;
    Tecnico tecnico;
    std::string nome;
    float salario, bonus, adicional;
    double valor;
    int aux1, aux2, matricula, turno;

    std::cout << "Digite o nome do funcionário: ";
    std::cin >> nome;
    std::cout << "Digite o salário do funcionário: ";
    std::cin >> salario;
    std::cout << "Digite sua matrícula: ";
    std::cin >> matricula;
    do{
        std::cout << "\nDigite:\n - 1 para Assistente Técnico;\n - 2 para Assistente Administrativo;\n Sua opção: ";
        std::cin >> aux2;
        if (aux2 != 1 && aux2 != 2)
        {
            std::cout << "\nResposta inválida!";
        }
    } while(aux2 != 1 && aux2 != 2);
    if (aux2 == 2) //Administrativo
    {
        do
        {
            std::cout << "\nDigite:\n - 0 se você trabalha de dia\n - 1 se você trabalha a noite: ";
            std::cin >> turno;
            if (turno == 1)
            {
                std::cout << "Digite o valor do adicional noturno: ";
                std::cin >> adicional;
                administrativo.adicionalNoturno(adicional);
            }
        } while (turno != 0 && turno != 1);
    }
    else { //Técnico
        std::cout << "Digite um valor para ser adicionado de bônus para o funcionário: ";
        std::cin >> bonus;
        tecnico.addBonus(bonus);
    }
    
    assistente.setMatricula(matricula);
    funcionarios.setSalario(salario);

    do
    {
        std::cout << "\nEscolha uma opção:\n  - 0 para sair\n  - 1 para dar aumento\n - 2 para exibir o ganho anual\n - 3 para exibir os dados\n Digite uma opção válida: ";
        std::cin >> aux1;

        switch (aux1)
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
            assistente.exibeDados();
            break;    
        default:
            break;
        }
    } while (aux1 != 0);
    
    std::cout << "Bye Bye amigo!";
    return 0;
}