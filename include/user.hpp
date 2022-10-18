#ifndef USER_HPP
#define USER_HPP

#include "inbox.hpp"
#include "errorMessage.hpp"

class User
{
    private:
        int _id;
        Inbox* _inbox;
        User* _left;
        User* _right;
        User* _upperLevel;

    public:
        User() {
            this->_inbox = new Inbox();
            this->_left = NULL;
            this->_right = NULL;
            this->_upperLevel = NULL;
        };
        
        User(int id){ 
            this->_left = NULL;
            this->_right = NULL;
            this->_upperLevel = NULL;
            this->_id = id; 
            this->_inbox = new Inbox();
        };

        ~User() {};

        int getId();
        Email getEmail();
        void receiveEmail(Email);

    friend class UsersRegister;

};


#endif