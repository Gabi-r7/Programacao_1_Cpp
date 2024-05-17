// Desenvolva o diagrama de classes UML de um sistema de biblioteca e 
// implemente esse sistema. Você deve ser capaz de cadastrar usuários, apagar 
// usuários, modificar o status do usuário (e.g., verificar se o mesmo possui multas 
// por atraso, se a multa for maior que um valor X, ele não poderá mais pegar livros 
// emprestados), cadastrar livros, emprestar livros, devolver livros, aplicar multas 
// por atraso, e checar se um determinado livro está disponível para ser 
// emprestado. Utilize listas como se fossem seu banco de dados (std::vector)
#include <iostream>
#include <vector>

class User {
    public:
        User(){};
        ~User(){};
        std::string login, idUser;

        bool EmprestarLivro(int idLivro){

        };

        bool DevolverLivro(int idLivro){

        };

        vector<Emprestimo> ChecarEmprestimos(){

        };

    private:
        std::string login, password, email, phone;
        bool adm;
        float valorMulta;
        
};

