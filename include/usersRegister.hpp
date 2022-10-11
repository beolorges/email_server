#ifndef USERS_REGISTER_HPP
#define USERS_REGISTER_HPP

#include "userCell.hpp"

class UsersRegister
{
private:
    UserCell* _first;
    int _size;

    bool isIdAlreadyRegistered(int id);
    bool isEmpty() { return this->_size == 0; };
    UserCell* findWhereToInsert(int id);

public:
    UsersRegister(){
        this->_size = 0;
        this->_first = new UserCell();
    };
    ~UsersRegister(){};

    void addUser(int id);
    void removeUser(int id);

    User* findUser(int id);

    void sendEmail(int id, Email email);
};




#endif