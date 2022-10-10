#include "inbox.hpp"

void Inbox::clean(){
    while(!isEmpty()){
        popFirst();
    }
}

void Inbox::popFirst(){
    CellStackEmail* aux = this->_first;

    this->_first = this->_first->_next;

    this->_size--;
    delete(aux);
}

void Inbox::insertEmail(Email emailToInsert){
    stackEmail* stackEmailToBeInserted = getStackEmailByPriority(emailToInsert.getPriority());
    stackEmailToBeInserted->pushBack(emailToInsert);
}

Email Inbox::getEmail(){
    Email emailToReturn = this->_first->_data.getEmail();

    if(this->_first->isEmpty()){
        CellStackEmail* aux = this->_first;

        this->_first = this->_first->_next;

        this->_size--;
        delete(aux);
    }

    return emailToReturn;
}

stackEmail* Inbox::getStackEmailByPriority(int priority){
    /*
    DOIS PRINCIPAIS CASOS:
        - SE JÁ TEM O STACK DE PRIORIDADE, NADA A FAZER, APENAS RETORNAR O STACK -> DATA
        - SE NÃO:
            - CRIAR UMA STACK COM ESSA PRIORIDADE;
            - APONTAR ESSA STACK PARA A ANTERIOR -> NEXT;
            - APONTAR A ANTERIOR PARA ESSA;
    */

    if(this->isEmpty()){
        CellStackEmail *newStackEmail = new CellStackEmail(priority);
        this->_first = newStackEmail;
        this->_size++;

        return &this->_first->_data;
    }

    if(this->_first->_priority == priority)
        return &this->_first->_data;

    CellStackEmail* aux = this->_first;

    while(aux->_next != NULL){
        if(aux->_priority == priority)
            return &aux->_data;

        if(aux->_next->_priority < priority)
            break;

        aux = aux->_next;
    }

    CellStackEmail* newStackEmail = new CellStackEmail(priority);
    this->_size++;

    newStackEmail->_next = aux->_next;
    aux->_next = newStackEmail;

    return &newStackEmail->_data;
}