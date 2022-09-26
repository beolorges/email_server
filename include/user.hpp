#ifndef USER_HPP
#define USER_HPP

#include "inbox.hpp"

class user
{
private:
    int _id;
    inbox _inbox;

public:
    user(int id);
    ~user();

    statusMessage getEmail();
    statusMessage sendEmail(email email);

    statusMessage removeAccount();
};

user::user(int id)
{
    this->_id = id;
}

user::~user()
{
}


#endif