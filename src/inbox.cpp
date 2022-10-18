#include "inbox.hpp"

void Inbox::clean(){
    while(!isEmpty()){
        popFirst();
    }
}

void Inbox::popFirst(){
    EmailQueue* aux = this->_first;

    this->_first = this->_first->_next;

    this->_size--;
    delete(aux);
}

void Inbox::insertEmail(Email emailToInsert){
    EmailQueue* stackEmailToBeInserted = getStackEmailByPriority(emailToInsert.getPriority());
    stackEmailToBeInserted->pushBack(emailToInsert);
}

Email Inbox::getEmail(){
    Email emailToReturn = this->_first->getEmail();

    if(this->_first->isEmpty()){
        EmailQueue* aux = this->_first;

        this->_first = this->_first->_next;

        this->_size--;
        delete(aux);
    }

    return emailToReturn;
}

/**
 * @brief Função criada para retornar um ponteiro para a fila de prioridade desejada. 
 * Verifica se já existe uma fila para a prioridade
 * Se houver, retorna o ponteiro para essa stack
 * Se não houver, aux receberá o ponteiro da fila com a posição anterior a qual
 * a nova fila de prioridade deve ser inserida.
 * 
 * 
 * @param priority Prioridade do email a ser inserido.
 * @return EmailQueue* Ponteiro para a fila de prioridade desejada.
 */

EmailQueue* Inbox::getStackEmailByPriority(int priority){
    if(this->isEmpty()){
        EmailQueue *newStackEmail = new EmailQueue(priority);
        this->_first = newStackEmail;
        this->_last = _first;
        this->_size++;

        return this->_first;
    }

    if(this->_first->_priority == priority)
        return this->_first;

    if(this->_first->_priority < priority){
        EmailQueue* newStackEmail = new EmailQueue(priority);
        this->_size++;

        newStackEmail->_next = this->_first;
        this->_first = newStackEmail;
    }

    EmailQueue* aux = this->_first;

    while(aux->_next != NULL){
        if(aux->_priority == priority)
            return aux;

        if(aux->_next->_priority < priority)
            break;

        aux = aux->_next;
    }

    if(aux->_priority == priority)
        return aux;

    EmailQueue* newStackEmail = new EmailQueue(priority);
    this->_size++;

    newStackEmail->_next = aux->_next;
    aux->_next = newStackEmail;

    return newStackEmail;
}