#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "usersRegister.h"
#include <iostream>


/**
 * @brief Classe para funcionar como uma interface para a classe de UsersRegister
 * Nessa classe, há o tratamento de exceções e as respectivas mensagens que devem ser
 * printadas no terminal para cada comando.
 * 
 */
class Interface{
    public:
        Interface();
        ~Interface();

        void createAccount(int id);
        void removeAccount(int id);
        
        void sendMail(int id, int priority, string message);
        void getMail(int id);
    
    private:
        UsersRegister* users;
};


#endif