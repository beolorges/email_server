#include "usersRegister.hpp"

bool UsersRegister::isIdAlreadyRegistered(int id){
    if(isEmpty())
        return false;
    
    User* aux = _first;

    while(true){
        if(aux->getId() == id)
            return true;

        if(id < aux->getId()){
            if(aux->_left != NULL)
                aux = aux->_left;

            else
                return false;
        }

        else if(id > aux->getId()){
            if(aux->_right != NULL)
                aux = aux->_right;

            else
                return false;

        }
    }

}

void UsersRegister::transplant(User* u, User* v){
    if(u->_upperLevel == NULL)
        this->_first = v;

    else if(u == u->_upperLevel->_left)
        u->_upperLevel->_left = v;

    else u->_upperLevel->_right = v;

    if(v != NULL)
        v->_upperLevel = u->_upperLevel;
}

User* UsersRegister::findMinimum(User* x){
    User* aux = x;
    
    while(aux->_left != NULL)
        aux = aux->_left;

    return aux;
}


void UsersRegister::removeUser(int id){
    User* userCellToBeRemoved = this->findUser(id);
    
    if(userCellToBeRemoved->_left == NULL)
        transplant(userCellToBeRemoved, userCellToBeRemoved->_right);

    else if(userCellToBeRemoved->_right == NULL)
        transplant(userCellToBeRemoved, userCellToBeRemoved->_left);
    
    else{
        User* y = findMinimum(userCellToBeRemoved->_right);

        if(y->_upperLevel != userCellToBeRemoved){
            transplant(y, y->_right);
            y->_right = userCellToBeRemoved->_right;
            y->_right->_upperLevel = y;
        }
        
        transplant(userCellToBeRemoved, y);
        y->_left = userCellToBeRemoved->_left;
        y->_left->_upperLevel = y;
    }

    this->_size--;
    delete userCellToBeRemoved;
}

void UsersRegister::addUser(int id){
    if(isIdAlreadyRegistered(id))
        throw ErrorMessage(200,"CONTA" + std::to_string(id) + "JÁ EXISTENTE");
    
    if(isEmpty()){
        User* firstCell = new User(id);
        _first = firstCell;

        this->_size++;
        return;
    }

    User* userToInsert = new User(id);
    User* aux = this->_first;

    while(true){
        if(id < aux->getId()){
            if(aux->_left == NULL){
                aux->_left = userToInsert;
                aux->_left->_upperLevel = aux;
                this->_size++;
                return;
            }

            aux = aux->_left;
        }
        else if(id > aux->getId()){
            if(aux->_right == NULL){
                aux->_right = userToInsert;
                aux->_right->_upperLevel = aux;
                this->_size++;
                return;
            }

            aux = aux->_right;
        }
    }

}


User* UsersRegister::findUser(int id){
    User* aux = this->_first;

    while(true){
        if(aux->getId() == id)
            return aux;

        if(id < aux->getId()){
            if(aux->_left != NULL)
                aux = aux->_left;

            else
                throw ErrorMessage(200,"CONTA " + std::to_string(id) + " NÃO EXISTE");
        }

        else if(id > aux->getId()){
            if(aux->_right != NULL)
                aux = aux->_right;

            else
                throw ErrorMessage(200,"CONTA " + std::to_string(id) + " NÃO EXISTE");
        }
    }

}

void UsersRegister::sendEmail(int id, Email email){
    if(!isIdAlreadyRegistered(id))
        throw ErrorMessage(200,"CONTA " + std::to_string(id) + " NÃO EXISTE");

    findUser(id)->receiveEmail(email);
}