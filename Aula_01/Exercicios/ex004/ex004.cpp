//  Implemente uma classe chamada “Aluno” que possua atributos para armazenar o
//  nome, a matrícula e as notas de um aluno. Adicione métodos para calcular a média
//  das notas e verificar a situação do aluno (aprovado ou reprovado).
#include <iostream>

class Aluno {
    public:
        Aluno(){};
        ~Aluno(){};

        void setVar(std::string _nome, int _matricula, float _n1, float _n2, float _n3) {
            nome = _nome;
            matricula = _matricula;
            n1 = _n1;
            n2 = _n2;
            n3 = _n3;
        };

        float calcMedia() {
            media = (n1 + n2 + n3) / 3;
            return media;
        };

        bool Situacao() {
            if (media >= 6)
            {
                return 1;
            }
            else {
                return 0;
            }
        };

    private:
        std::string nome;
        int matricula;
        float n1, n2, n3;
        float media;
};

int main() {
    Aluno aluno;
    std::string nome;
    int matricula;
    float n1, n2, n3;
    float media;
    bool aprovado;
    std::cout << "Digite o nome do aluno: ";
    std::cin >> nome;
    std::cout << "Digite a matricula do aluno: ";
    std::cin >> matricula;
    std::cout << "Digite a primeira nota do aluno: ";
    std::cin >> n1;
    std::cout << "Digite a segunda nota do aluno: ";
    std::cin >> n2;
    std::cout << "Digite a terceira nota do aluno: ";
    std::cin >> n3;
    aluno.setVar(nome, matricula, n1, n2, n3);
    media = aluno.calcMedia();
    aprovado = aluno.Situacao();
    std::cout << "Nome: " << nome;
    std::cout << "Matrícula: " << matricula;
    std::cout << "Média: " << media:
    if (aprovado) {
        std::cout << "Aprovado!";
    }
    else {
        std::cout << "Reprovado!";
    }
    return 0;
}