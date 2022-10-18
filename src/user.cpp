#include "user.h"

/**
 * @brief Construct a new User:: User object
 * 
 */
User::User(){
    this->_left = NULL;
    this->_right = NULL;
    this->_upperLevel = NULL;
    this->_inbox = new Inbox();
}

/**
 * @brief Construct a new User:: User object
 * 
 * @param id Id do usuário a ser construído. 
 */
User::User(int id){
    this->_left = NULL;
    this->_right = NULL;
    this->_upperLevel = NULL;
    this->_id = id; 
    this->_inbox = new Inbox();
}

/**
 * @brief Destroy the User:: User object
 * 
 */
User::~User(){}

/**
 * @brief Retorna o email de maior prioridade inserido primeiro e o apaga.
 * 
 * @return Email Email de maior prioridade inserido primeiro.
 */
Email User::getEmail(){
    if(this->_inbox->isEmpty())
        throw ErrorMessage(100, "CAIXA DE ENTRADA VAZIA");

    return this->_inbox->getEmail();
}

/**
 * @brief Insere o email passado como parâmetro na caixa de entrada do usuário.
 * 
 * @param emailToInsert Email a ser inserido na caixa de entrada do usuário.
 */
void User::receiveEmail(Email emailToInsert){
    this->_inbox->insertEmail(emailToInsert);
}

/**
 * @brief Retorna o ID do usuário.
 * 
 * @return int Id do usuário.
 */
int User::getId(){
    return this->_id;
}