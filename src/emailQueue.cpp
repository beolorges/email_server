#include "./emailQueue.h"

/**
 * @brief Construct a new Email Queue:: Email Queue object
 * 
 */
EmailQueue::EmailQueue(){
    this->_first = NULL;
    this->_last = NULL;
    this->_next = NULL;
    this->_size = 0;
}

/**
 * @brief Construct a new Email Queue:: Email Queue object
 * 
 * @param priority Prioridade da fila a ser criada.
 */
EmailQueue::EmailQueue(int priority){
    this->_first = NULL;
    this->_last = NULL;
    this->_next = NULL;
    
    this->_size = 0;
    this->_priority = priority;
}

/**
 * @brief Destroy the Email Queue:: Email Queue object
 * 
 */
EmailQueue::~EmailQueue(){
    clear();
}

/**
 * @brief Retorna a prioridade da fila.
 * 
 * @return int Prioridade
 */
int EmailQueue::getPriority() const {
    return this->_priority;
}

/**
 * @brief Verifica se a fila está vazia.
 * 
 * @return true Para fila vazia.
 * @return false Para fila não vazia.
 */
bool EmailQueue::isEmpty() const {
    return this->_size == 0;
}

/**
 * @brief Limpa a fila.
 * 
 */
void EmailQueue::clear(){
    while(!isEmpty()){
        popFirst();
    }
}

/**
 * @brief Limpa o primeiro item da fila.
 * 
 */
void EmailQueue::popFirst(){

    Email *aux = this->_first;
    if(this->_first->_next != NULL){
        this->_first = this->_first->_next;
    }

    this->_size--;
    delete(aux);
}

/**
 * @brief Adiciona um novo email no fim da fila.
 * 
 * @param email Email a ser adicionado.
 */
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

/**
 * @brief Retorna o primeiro email da fila e o remove da fila.
 * Se a fila estivar vazia lança um erro do tipo ErrorMessage de status 100, 
 * com a mensagem "CAIXA DE ENTRADA VAZIA"
 * 
 * @return Email Primeiro email da fila.
 */
Email EmailQueue::getEmail(){
    if(isEmpty())
        throw ErrorMessage(100, "CAIXA DE ENTRADA VAZIA");


    Email emailToReturn = *this->_first;
    popFirst();

    return emailToReturn;
}