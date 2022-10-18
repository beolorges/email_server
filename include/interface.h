#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "usersRegister.h"
#include <iostream>

class Interface{
    public:
        Interface() { this->users = new UsersRegister();};
        ~Interface() { delete (users); };

        void createAccount(int id);
        void removeAccount(int id);
        
        void sendMail(int id, int priority, string message);
        void getMail(int id);
    
    private:
        UsersRegister* users;
};


#endif