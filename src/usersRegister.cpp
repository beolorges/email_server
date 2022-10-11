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

void UsersRegister::transplant(UserCell* u, UserCell* v){
    if(u->_upperLevel == NULL)
        this->_first = v;

    else if(u == u->_upperLevel->_left)
        u->_upperLevel->_left = v;

    else u->_upperLevel->_right = v;

    if(v != NULL)
        v->_upperLevel = u->_upperLevel;
}

UserCell* UsersRegister::findMinimum(UserCell* x){
    UserCell* aux = x;
    
    while(aux->_left != NULL)
        aux = aux->_left;

    return aux;
}


void UsersRegister::removeUser(int id){
    UserCell* userCellToBeRemoved = this->findUserCell(id);
    
    if(userCellToBeRemoved->_left == NULL)
        transplant(userCellToBeRemoved, userCellToBeRemoved->_right);

    else if(userCellToBeRemoved->_right == NULL)
        transplant(userCellToBeRemoved, userCellToBeRemoved->_left);
    
    else{
        UserCell* y = findMinimum(userCellToBeRemoved->_right);

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
                aux->_left->_upperLevel = aux;
                return aux->_left;
            }

            aux = aux->_left;
        }
        else if(id > aux->_data.getId()){
            if(aux->_right == NULL){
                aux->_right = new UserCell();
                aux->_right->_upperLevel = aux;
                return aux->_right;
            }

            aux = aux->_right;
        }
    }
}

User* UsersRegister::findUser(int id){
    return &this->findUserCell(id)->_data;
}

UserCell* UsersRegister::findUserCell(int id){
    UserCell* aux = this->_first;

    while(true){
        if(aux->_data.getId() == id)
            return aux;

        if(id < aux->_data.getId()){
            if(aux->_left != NULL)
                aux = aux->_left;

            else
                throw ErrorMessage(200,"CONTA " + std::to_string(id) + " NÃO EXISTE");
        }

        else if(id > aux->_data.getId()){
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