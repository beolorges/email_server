#include "./emailQueue.hpp"

void EmailQueue::clear(){
    while(!isEmpty()){
        popFirst();
    }
}

void EmailQueue::popFirst(){

    Email *aux = this->_first;
    if(this->_first->_next != NULL){
        this->_first = this->_first->_next;
    }

    this->_size--;
    delete(aux);
}

void EmailQueue::pushBack(Email email){
    Email* cellToInsert = new Email(email);

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

Email EmailQueue::getEmail(){
    if(isEmpty())
        throw ErrorMessage(100, "CAIXA DE ENTRADA VAZIA");


    Email emailToReturn = *this->_first;
    popFirst();

    return emailToReturn;
}