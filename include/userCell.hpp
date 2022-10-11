#ifndef USER_CELL_HPP
#define USER_CELL_HPP

#include "user.hpp"

class UserCell {
    private:
        User _data;
        UserCell* _left;
        UserCell* _right;

    public:
        UserCell(){
            this->_data = User(-1);
            this->_left = NULL;
            this->_right = NULL;
        };
        UserCell(int id) { 
            this->_data = User(id); 
            this->_left = NULL;
            this->_right = NULL;
            };
        ~UserCell(){};

    friend class UsersRegister;

};


#endif