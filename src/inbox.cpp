#include "inbox.h"

/**
 * @brief Construct a new Inbox:: Inbox object
 * 
 */
Inbox::Inbox(){
    this->_first = NULL;
    this->_last = NULL;
    this->_size = 0; 
}

/**
 * @brief Destroy the Inbox:: Inbox object
 * 
 */
Inbox::~Inbox(){
    this->clean();
}

/**
 * @brief Verifica se a caixa de entrada está vazia
 * 
 * @return true Se a caixa está vazia
 * @return false Se a caixa não está vazia
 */
bool Inbox::isEmpty() const {
    return this->_size == 0; 
}

/**
 * @brief Limpa a caixa de entrada.
 * 
 */
void Inbox::clean(){
    while(!isEmpty()){
        popFirst();
    }
}

/**
 * @brief Remove o primeiro elemento da caixa de entrada.
 * 
 */
void Inbox::popFirst(){
    EmailQueue* aux = this->_first;

    this->_first = this->_first->_next;

    this->_size--;
    delete(aux);
}

/**
 * @brief Adiciona o email no fim da fila(Queue) referente a sua prioridade.
 * 
 * @param emailToInsert Email a ser inserido.
 */
void Inbox::insertEmail(Email emailToInsert){
    EmailQueue* emailQueueToBeInserted = getEmailQueueByPriority(emailToInsert.getPriority());
    emailQueueToBeInserted->pushBack(emailToInsert);
}

/**
 * @brief Retorna o primeiro email da fila(Queue) de maior prioridade
 * armazenada e o deleta.
 * 
 * @return Email Email de maior prioridade inserido a mais tempo na caixa.
 */
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
 * @details se já existe uma fila para a prioridade
 * Se houver, retorna o ponteiro para essa stack
 * Se não houver, aux receberá o ponteiro da fila com a posição anterior a qual
 * a nova fila de prioridade deve ser inserida.
 * 
 * 
 * @param priority Prioridade do email a ser inserido.
 * @return EmailQueue* Ponteiro para a fila de prioridade desejada.
 */

EmailQueue* Inbox::getEmailQueueByPriority(int priority){
    if(this->isEmpty()){
        EmailQueue *newEmailQueue = new EmailQueue(priority);
        this->_first = newEmailQueue;
        this->_last = _first;
        this->_size++;

        return this->_first;
    }

    if(this->_first->_priority == priority)
        return this->_first;

    if(this->_first->_priority < priority){
        EmailQueue* newEmailQueue = new EmailQueue(priority);
        this->_size++;

        newEmailQueue->_next = this->_first;
        this->_first = newEmailQueue;
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

    EmailQueue* newEmailQueue = new EmailQueue(priority);
    this->_size++;

    newEmailQueue->_next = aux->_next;
    aux->_next = newEmailQueue;

    return newEmailQueue;
}