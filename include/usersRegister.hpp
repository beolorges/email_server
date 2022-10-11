#ifndef USERS_REGISTER_HPP
#define USERS_REGISTER_HPP

#include "userCell.hpp"
#include "errorMessage.hpp"

class UsersRegister
{
private:
    UserCell* _first;
    int _size;

    bool isIdAlreadyRegistered(int id);
    bool isEmpty() { return this->_size == 0; };
    UserCell* findWhereToInsert(int id);
    UserCell* findUserCell(int id);
    UserCell* findMinimum(UserCell* cell);
    void transplant(UserCell* u, UserCell* v);

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