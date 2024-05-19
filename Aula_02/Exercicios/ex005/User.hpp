#include <iostream>

class User {
    public:
        User(){};
        ~User(){};
        std::string login;
        int idUser;

        std::string getLogin(){
            return login;
        };

        std::string getPassword(){
            return password;
        };

        int getIdUser(){
            return idUser;
        };

        void setAdm(bool _adm){
            adm = _adm;
        };

        bool getAdm(){
            return adm;
        };

        void setIdUser(int _idUser){
            idUser = _idUser;
        };

        void setLoginSenha(std::string _login, std::string _senha){
            login = _login;
            password = _senha;
        };

        // bool EmprestarLivro(int idLivro){

        // };

        // bool DevolverLivro(int idLivro){

        // };

    protected:
        std::string password, email, phone, senha;
        bool adm;
        float valorMulta;
};