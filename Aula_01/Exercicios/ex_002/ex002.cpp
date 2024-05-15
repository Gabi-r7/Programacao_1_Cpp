// Implemente uma classe chamada “ContaBancária” que possua atributos para
//  armazenar o número da conta, nome do titular e saldo. Adicione métodos para
//  realizar depósitos e saques.
#include <iostream>
class ContaBancaria {
    public:
        ContaBancaria(){};
        ~ContaBancaria(){};
        float deposito(float _valor) {
            valor = _valor;
            saldo += valor;
            return saldo;
        };
        float saque(float _valor) {
            valor = _valor;
            if (saldo > 0 && (saldo - valor) > 0) {
                saldo -= valor;
                return saldo;
            }
            else {
                std::cout << "\nSaldo insuficiente!\n";
                return saldo;
            }
        };
        void setVar(float _saldo, float _nConta, std::string _nomeTitular) {
            saldo = _saldo;
            nConta = _nConta;
            nomeTitular = _nomeTitular;
        };
    private:
        int nConta;
        std::string nomeTitular;
        float saldo;
        float valor;
};
int main() {
    ContaBancaria conta;
    int nConta;
    std::string nomeTitular;
    float saldo;
    float valor = 0;
    int opcao;
    std::cout << "Digite o número da conta: ";
    std::cin >> nConta;
    std::cout << "Digite o nome do Titular: ";
    std::cin >> nomeTitular;
    std::cout << "Digite seu saldo: ";
    std::cin >> saldo;
    conta.setVar(saldo, nConta, nomeTitular);
    do
    {
        std::cout << "\nDigite:\n - 0 para encerrar!\n - 1 para fazer um depósito! \n - 2 para fazer um saque!\n - 3 para verificar seu saldo\n Digite sua opção: ";
        std::cin >> opcao;
        switch (opcao)
        {
        case 1:
            std::cout << "\nDigite o valor do depósito: ";
            std::cin >> valor;
            saldo = conta.deposito(valor);
            break;
        case 2:
            std::cout << "\nDigite o valor do saque: ";
            std::cin >> valor;
            saldo = conta.saque(valor);
            break;
        case 3:
            std::cout << "\nSeu saldo é de: " << saldo;
        default:
            break;
        }
    } while (opcao != 0);
    std::cout << "Seus dados:\n" << "\nNúmero da conta: " << nConta << "\nNome do Titular: " << nomeTitular << "\n Saldo final:" << saldo;
    std::cout << "\nPrograma encerrado!";
};