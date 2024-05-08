#include <iostream>

class Circulo {
    public:
        Circulo(){};
        ~Circulo(){};

        float calcArea() {
            return 3.1415 * raio * raio;
        };

        float perimetro() {
            return 2 * 3.1415 * raio;
        };

        void setRaio(float _raio) {
            raio = _raio;
        };

    private:
        float raio;
};

int main() {
    Circulo c;
    float raio;
    float area = c.calcArea();
    float perimetro = c.perimetro();
    
    std::cout << "Digite o raio: " << "\n";
    std::cin >> raio;
    c.setRaio(raio);
    std::cout << "Area: " << area << "\n";
    std::cout << "Perimetro: " << perimetro << "\n";
}