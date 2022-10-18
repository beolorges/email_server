#include "email.h"

/**
 * @brief Construct a new Email:: Email object
 * 
 */
Email::Email(){
    this->_next = NULL;
    this->_priority = 0;
    this->_message = " ";
}


/**
 * @brief Construct a new Email:: Email object
 * 
 * @param priority Prioridade do email a ser construído.
 * @param message Mensagem do email a ser construído.
 */
Email::Email( int priority, string message){
    this->_next = NULL;
    this->_message = message;
    this->_priority = priority;
};


/**
 * @brief Retorna a mensagem do email.
 * 
 * @return string Mensagem
 */
string Email::getMessage() const {
    return this->_message;
}

/**
 * @brief Retorna a prioridade do email.
 * 
 * @return int Prioridade
 */
int Email::getPriority() const {
    return this->_priority;
}

/**
 * @brief Overload do operador =
 * Atribui os valores de prioridade e mensagem do parâmetro passado para 
 * esse email.
 * 
 * @param e Email a ser atribuído.
 */
void Email::operator=(const Email e){
    this->_priority = e.getPriority();
    this->_message = e.getMessage();
}