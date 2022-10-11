#ifndef USER_HPP
#define USER_HPP

#include "inbox.hpp"

class User
{
private:
    int _id;
    Inbox _inbox;

public:
    User() {};
    User(int id){ this->_id = id; };
    ~User() {};

    int getId();
    Email getEmail();
    void receiveEmail(Email);
};


#endif