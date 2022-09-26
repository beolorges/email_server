#ifndef USERS_REGISTER_HPP
#define USERS_REGISTER_HPP

#include "user.hpp"

class usersRegister
{
private:
    user* _users;

public:
    usersRegister();
    ~usersRegister();

    statusMessage addUser(int id);
    statusMessage removeUser(int id);
};

usersRegister::usersRegister()
{
}

usersRegister::~usersRegister()
{
}


#endif