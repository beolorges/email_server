#include "./include/stackEmail.hpp"

int stackEmail::getSize(){
    return this->_size;
}

void stackEmail::popFirst(){
    if(this->getSize() == 0)
        return;

    this->_size--;
    realloc(this->_data, sizeof(email) * this->getSize());
}

void stackEmail::pushBack(email emailToAdd){
    this->_size++;
    realloc(this->_data, sizeof(email) * this->getSize());

    email previousEmail = this->_data[0];
    this->_data[0] = emailToAdd;

    int i = 1;
    while(i < this->getSize()){
        email nextEmail = this->_data[i];
        this->_data[i] = previousEmail;

        previousEmail = nextEmail;
    }
}