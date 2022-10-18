#ifndef USER_HPP
#define USER_HPP

#include "inbox.h"
#include "errorMessage.h"

class User
{
    private:
        int _id;
        Inbox* _inbox;
        User* _left;
        User* _right;
        User* _upperLevel;

    public:
        User();
        
        User(int id);

        ~User();

        int getId();
        Email getEmail();
        void receiveEmail(Email);

    friend class UsersRegister;

};


#endif