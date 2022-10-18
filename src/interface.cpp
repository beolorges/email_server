#include "interface.h"

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