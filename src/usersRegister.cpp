#include "usersRegister.hpp"

bool UsersRegister::isIdAlreadyRegistered(int id){
    if(isEmpty())
        return false;
    
    UserCell* aux = _first;

    while(true){
        if(aux->_data.getId() == id)
            return true;

        if(id < aux->_data.getId()){
            if(aux->_left != NULL)
                aux = aux->_left;

            else
                return false;
        }

        else if(id > aux->_data.getId()){
            if(aux->_right != NULL)
                aux = aux->_right;

            else
                return false;

        }
    }

}

void UsersRegister::addUser(int id){
    if(isIdAlreadyRegistered(id))
        throw "Conta já existente";

    User userToInsert = User(id);

    if(isEmpty()){
        UserCell* firstCell = new UserCell(id);
        _first = firstCell;

        this->_size++;
        return;
    }

    UserCell* whereToInsert = findWhereToInsert(id);
    whereToInsert->_data = userToInsert;
    this->_size++;
}

UserCell* UsersRegister::findWhereToInsert(int id){
    UserCell* aux = this->_first;

    while(true){
        if(id < aux->_data.getId()){
            if(aux->_left == NULL){
                aux->_left = new UserCell();
                return aux->_left;
            }

            aux = aux->_left;
        }
        else if(id > aux->_data.getId()){
            if(aux->_right == NULL){
                aux->_right = new UserCell();
                return aux->_right;
            }

            aux = aux->_right;
        }
    }
}

User* UsersRegister::findUser(int id){
    UserCell* aux = this->_first;

    while(true){
        if(aux->_data.getId() == id)
            return &aux->_data;

        if(id < aux->_data.getId()){
            if(aux->_left != NULL)
                aux = aux->_left;

            else
                throw "Id não cadastrado";
        }

        else if(id > aux->_data.getId()){
            if(aux->_right != NULL)
                aux = aux->_right;

            else
                throw "Id não cadastrado";
        }
    }

}

void UsersRegister::sendEmail(int id, Email email){
    if(!isIdAlreadyRegistered(id))
        throw "Conta não existente";

    findUser(id)->receiveEmail(email);
}