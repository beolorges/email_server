#ifndef USERS_REGISTER_HPP
#define USERS_REGISTER_HPP

#include "user.h"
#include "errorMessage.h"

class UsersRegister
{
private:
    User* _first;
    int _size;

    bool isIdAlreadyRegistered(int id);
    bool isEmpty() { return this->_size == 0; };
    User* findMinimum(User* cell);
    void transplant(User* u, User* v);

public:
    UsersRegister(){
        this->_first = NULL;
        this->_size = 0;
        this->_first = new User();
    };
    ~UsersRegister(){};

    void addUser(int id);
    void removeUser(int id);

    User* findUser(int id);
    void sendEmail(int id, Email email);
};




#endif