// Desenvolva o diagrama de classes UML de um sistema de biblioteca e 
// implemente esse sistema. Voce deve ser capaz de cadastrar usuarios, apagar 
// usuarios, modificar o status do usuario (e.g., verificar se o mesmo possui multas 
// por atraso, se a multa for maior que um valor X, ele não podera mais pegar livros 
// emprestados), cadastrar livros, emprestar livros, devolver livros, aplicar multas 
// por atraso, e checar se um determinado livro esta disponível para ser 
// emprestado. Utilize listas como se fossem seu banco de dados (std::vector)
#include <iostream>
#include <vector>
#include <locale.h>
#include "User.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Admin.hpp"
#define adminSenha 1230



void acoes(){
    User user;
    Livro livro;
    Emprestimo emprestimo;
    Admin admin;
    int aux, idLivro;
    int id = user.getIdUser();
    bool adm = user.getAdm(), funcionou, status;
    
    while (true){
        std::cout << "O que deseja fazer?" << std::endl;
        std::cout << "Digite 0 para sair"  << std::endl;
        std::cout << "Digite 1 para emprestar um livro"  << std::endl;
        std::cout << "Digite 2 para devolver um livro"  << std::endl;
        std::cout << "Digite 3 para ver os livros disponíveis"  << std::endl;
        if (adm){
            std::cout << "Digite 4 para cadastrar um livro"  << std::endl;
            std::cout << "Digite 5 para apagar um livro"  << std::endl;
            std::cout << "Digite 6 para modificar o status de um usuario"  << std::endl;
            std::cout << "Digite 7 para cadastrar um usuario"  << std::endl;
            std::cout << "Digite 8 para apagar um usuario"  << std::endl;
            std::cout << "Digite 9 para aplicar uma multa"  << std::endl;
        }
        std::cin >> aux;
        if (aux == 1){
            std::cout << "Digite o id do livro que deseja emprestar: ";
            std::cin >> idLivro;
            funcionou = emprestimo.EmprestarLivro(idLivro, id);
            if (funcionou){
                std::cout << "Livro emprestado com sucesso!" << std::endl;
            }
            else {
                std::cout << "Não foi possível emprestar o livro!" << std::endl;
            }
        }
        else if (aux == 2){
            std::cout << "Digite o id do livro que deseja devolver: ";
            std::cin >> idLivro;
            emprestimo.DevolverLivro(idLivro);
            std::cout << "Livro devolvido com sucesso!" << std::endl;
        }
        else if (aux == 3){
            livro.MostrarDisponiveis();
        }
        if (adm) {
            if (aux == 4){
                admin.CadastrarLivro();
                std::cout << "Livro cadastrado com sucesso!" << std::endl;
            }
            else if (aux == 5){
                admin.ApagarLivro();
                std::cout << "Livro apagado com sucesso!" << std::endl;
            }
            else if (aux == 6){
                status = admin.ModificarStatusUser(id);
                if (status) {
					std::cout << "O usuario agora e um devedor!" << std::endl;
				}
                else {
					std::cout << "O usuario não e mais um devedor!" << std::endl;
				}
            }
            else if (aux == 7){
                admin.CadastrarLivro();
            }
            else if (aux == 8){
                admin.ApagarUser();
                std::cout << "Usuario apagado com sucesso!" << std::endl;
            }
            else if (aux == 9){
                admin.AplicarMulta();
                std::cout << "Multa aplicada com sucesso!" << std::endl;
            }
        }
        else {
            std::cout << "Ate mais!";
            break;
        }
    }
};

void logar(){
    std::string login, password;
    std::cout << "Faca seu login!" << std::endl;
    while (true){
        std::cout << "Digite seu login: ";
        std::cin >> login;
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        for (User* user: users){
            if (login == user->getLogin() && password == user->getPassword()){
                std::cout << "Login realizado com sucesso!" << std::endl;
                acoes();
                break;
            }
        }
        std::cout << "Login ou senha incorretos!" << std::endl;
    }
};

void cadastrar(){
    User user;
    std::string login, password, email, phone;
    bool adm, existe;
    int admAux;
    while (true){
        std::cout << "Faca seu cadastro!" << std::endl;
        std::cout << "Digite seu login: ";
        std::cin >> login;
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        std::cout << "Digite seu email: ";
        std::cin >> email;
        std::cout << "Digite seu telefone: ";
        std::cin >> phone;
        std::cout << "Digite a senha de administrador caso voce seja: ";
        std::cin >> admAux;
        if (admAux == adminSenha){
            adm = true;
            user.setAdm(adm);
        }
        else {
            adm = false;
            user.setAdm(adm);
        }
        for (User* user: users){
            if (login == user->getLogin()){
                std::cout << "Login ja existente!" << std::endl;
                existe = true;
                break;
            }
        }
        if (!existe) {
            break;
        }
    }
    User* newUser = new User();
    newUser->setLoginSenha(login, password);
    users.push_back(newUser);
    std::cout << "Cadastro realizado com sucesso!" << std::endl;
    newUser->setIdUser(users.size() - 1);
    logar();
};


void inicializaSistema(){
    User user;
    int aux;
    int senha;
    std::cout << "Bem vindo ao sistema de biblioteca!" << std::endl;
    do{
        std::cout << "Digite:\n- 0 pra sair;\n - 1 para logar;\n - 2 para criar uma conta; Digite sua opcao: ";
        std::cin >> aux;
    } while (aux != 1 && aux != 2);

    switch (aux){
    case 1:
        logar();
        break;
    case 2:
        cadastrar();
        break;
    default:
        break;
    }
};


int main() {
    setlocale(LC_ALL, "Portuguese");
    inicializaSistema();


    return 0;
};