#include <iostream>
#include <vector>
#include "User.hpp"
#include "Livro.hpp"
std::vector<User*> users;
std::vector<Livro*> livros;

class Emprestimo{
    public:
        Emprestimo(){};
        ~Emprestimo(){};

        bool EmprestarLivro(int idLivro, int idUser){
            if (users[idUser]->getMulta() > 50.00){
                std::cout << "Usuário com multa acima de R$50,00. Não é possível emprestar livros." << std::endl;
                return false;
            }
            else{
                livros[idLivro]->setEmprestado(true);
                livros[idLivro]->setIdUser(idUser);
                return true;
            }
        };

        void DevolverLivro(int idLivro){
            livros[idLivro]->setEmprestado(false);
            livros[idLivro]->setIdUser(-1);
        };



};
