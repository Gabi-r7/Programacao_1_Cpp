//  Crie uma classe chamada “Retângulo” que possua atributos para armazenar a
//  largura e a altura. Implemente métodos para calcular a área e o perímetro do
//  retângulo.
#include <iostream>

class Retangulo {
    public:
        Retangulo(){};
        ~Retangulo(){};

        float calcArea(float _largura, float _altura) {
            return _largura * _altura;
        };

        float calcPerimetro(float _largura, float _altura) {
            return 2 * (_largura + _altura);
        }

    private:
        float largura;
        float altura;
};

int main() {
    Retangulo retangulo;
    float largura;
    float altura;

    std::cout << "Digite a largura do Retângulo: ";
    std::cin >> largura;
    std::cout << "Digite a altura do Retângulo: ";
    std::cin >> altura;
    float area = retangulo.calcArea(largura, altura);
    float perimetro = retangulo.calcPerimetro(largura, altura); 
    std::cout << "\n\nA área deste retângulo é de: " << area;
    std::cout << "\nO perimetro deste retângulo é de: " << perimetro << "\n";
    return 0;
}