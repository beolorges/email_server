#include "user.hpp"

Email User::getEmail(){
    if(this->_inbox.isEmpty())
        throw "Caixa de entrada vazia";

    return this->_inbox.getEmail();
}

void User::receiveEmail(Email emailToInsert){
    this->_inbox.insertEmail(emailToInsert);
}

int User::getId(){
    return this->_id;
}