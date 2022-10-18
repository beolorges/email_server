#include "interface.h"

/**
 * @brief Construct a new Interface:: Interface object
 * 
 */
Interface::Interface(){
    this->users = new UsersRegister();
}

/**
 * @brief Destroy the Interface:: Interface object
 * 
 */
Interface::~Interface(){
    delete users;
}

/**
 * @brief Tenta criar uma nova conta no registro de usuários com o Id passado como parâmetro.
 * Se houver algum erro, a mensagem da exceção será printada no terminal. Se tudo correr bem,
 * a mensagem de acerto também será printada no terminal.
 * 
 * @param id Id da conta a ser criada.
 */
void Interface::createAccount(int id){
    try
    {
        this->users->addUser(id);
        cout << "OK: CONTA " << to_string(id) << " CADASTRADA" << '\n';   

    }
    catch(ErrorMessage e)
    {
        cout << "ERRO: " << e.getMessage() << '\n';
    }
    
}

/**
 * @brief Tenta remover a conta referente ao ID passado como parâmetro do registro de usuários. 
 * Se houver algum erro, a mensagem da exceção será printada no terminal. Se tudo correr bem,
 * a mensagem de acerto também será printada no terminal.
 * 
 * @param id Id da conta a ser removida. 
 */
void Interface::removeAccount(int id){
    try
    {
        this->users->removeUser(id);
        cout << "OK: CONTA " << to_string(id) << " REMOVIDA" << '\n';   
    }
    catch(ErrorMessage e)
    {
        cout << "ERRO: " << e.getMessage() << '\n';
    }
}


/**
 * @brief Tenta enviar um email com a mensagem e a prioridade passados como parâmetro para o 
 * usuário referente ao id também passado como parâmetro.
 * Se houver algum erro, a mensagem da exceção será printada no terminal. Se tudo correr bem,
 * a mensagem de acerto também será printada no terminal.
 * 
 * @param id Id do usuário que irá receber o email.
 * @param priority Prioridade do email a ser enviado.
 * @param message Mensagem do email a ser enviado.
 */
void Interface::sendMail(int id, int priority, string message){
    try
    {
        Email email = Email(priority, message);

        this->users->findUser(id)->receiveEmail(email);

        cout << "OK: MENSAGEM PARA " << to_string(id) << " ENTREGUE" << '\n';   
    }
    catch(ErrorMessage e)
    {
        cout << "ERRO: " << e.getMessage() << '\n';
    }
}

/**
 * @brief Tenta ler o email de maior prioridade recebido a mais tempo do usuário passado como
 * parâmetro.
 * Se houver algum erro, a mensagem da exceção será printada no terminal. Se tudo correr bem,
 * a mensagem de acerto também será printada no terminal.
 * 
 * @param id Id do usuário do email a ser lido.
 */
void Interface::getMail(int id){
        try
    {
        Email email = this->users->findUser(id)->getEmail();
        cout << "CONSULTA " + to_string(id) + ": " << email.getMessage() << '\n';
    }
    catch(ErrorMessage e)
    {
        if(e.getStatus() == 100)
            cout << "CONSULTA " + to_string(id) + ": "<< e.getMessage() << '\n';

        else
            cout << "ERRO: " << e.getMessage() << '\n';
    }
}