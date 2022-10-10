#include "./stackEmail.hpp"

void stackEmail::clear(){
    while(!isEmpty()){
        popFirst();
    }
}

void stackEmail::popFirst(){

    CellEmail *aux = this->_first;
    if(this->_first->_next != NULL){
        this->_first = this->_first->_next;
    }

    this->_size--;
    delete(aux);
}

void stackEmail::pushBack(Email email){
    CellEmail* cellToInsert = new CellEmail();
    cellToInsert->_data = email;

    if(isEmpty()){
        this->_first = cellToInsert;
        this->_last = cellToInsert;
    }

    else{
        this->_last->_next = cellToInsert;
        this->_last = cellToInsert;
    }

    this->_size++;
}

Email stackEmail::getEmail(){
    if(isEmpty())
        throw "This line is empty";

    Email emailToReturn = this->_first->_data;
    popFirst();

    return emailToReturn;
}