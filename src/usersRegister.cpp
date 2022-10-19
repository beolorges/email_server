#include "usersRegister.h"

/**
 * @brief Construct a new Users Register:: Users Register object
 * 
 */
UsersRegister::UsersRegister(){
    this->_first = NULL;
    this->_size = 0;
    this->_first = new User();
}

/**
 * @brief Destroy the Users Register:: Users Register object
 * 
 */
UsersRegister::~UsersRegister(){};

/**
 * @brief Verifica se a árvore está vazia
 * 
 * @return true Se a árvore estiver vazia
 * @return false Se a árvore não estiver vazia
 */
bool UsersRegister::isEmpty() const {
    return this->_size == 0;
}

/**
 * @brief Verifica se o ID já consta na árvore.
 * 
 * @param id Id a ser verificado a existência.
 * @return true Se o ID já estiver registrado.
 * @return false Se o ID não estiver registrado.
 */
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

/**
 * @brief Passo intermediário para a remoção de um nó da árvore.
 * Transplanta o nó v para a posição onde se encontrada o nó u.
 * 
 * @param u Nó a ser removido da árvore.
 * @param v Nó a ser posto no lugar.
 */
void UsersRegister::transplant(User* u, User* v){
    if(u->_upperLevel == NULL)
        this->_first = v;

    else if(u == u->_upperLevel->_left)
        u->_upperLevel->_left = v;

    else u->_upperLevel->_right = v;

    if(v != NULL)
        v->_upperLevel = u->_upperLevel;
}

/**
 * @brief Encontra o nó de menor valor a partir do nó X. Por exemplo, se desejar
 * descobrir o menor valor da árvore como um todo, deve ser passado a raiz como parâmetro X.
 * 
 * @param x Nó inicial de onde parte a verificação do menor valor da árvore.
 * @return User* Nó de menor valor a partir do Nó X. 
 */
User* UsersRegister::findMinimum(User* x){
    User* aux = x;
    
    while(aux->_left != NULL)
        aux = aux->_left;

    return aux;
}

/**
 * @brief Remove um nó (usuário) da árvore.
 * @details A remoção de um dos nós de uma árvore, lida com 2 subproblemas:
 * O primeiro, e mais simples, deles é quando o nó não possui ao menos um filho, podendo
 * ser para a direita ou para a esquerda, tratados nos ifs das linhas 114 e 117. Nesse caso,
 * é simplesmente realizado um transplante entre o filho não nulo do nó e o próprio nó.
 * O segundo caso acontece quando o nó possui ambos os filhos. Nesse caso, estou procedendo
 * encontrando o filho de menor valor a partir do filho da direita do nó a ser removido. Após isso,
 * é trocado a direita desse mínimo com a posição do próprio mínimo e depois o mínimo assume a posição do nó
 * a ser removido.
 * 
 * 
 * @param id Id do usuário a ser removido.
 */
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

/**
 * @brief Adiciona um usuário na árvore com base na ordenação crescente de ID.
 * 
 * @param id Id do usuário a ser inserido.
 */
void UsersRegister::addUser(int id){
    if(isIdAlreadyRegistered(id))
        throw ErrorMessage(200,"CONTA" + std::to_string(id) + "JÁ EXISTENTE");
    
    if(isEmpty()){
        _first = new User(id);

        this->_size++;
        return;
    }

    User* aux = this->_first;

    while(true){
        if(id < aux->getId()){
            if(aux->_left == NULL){
                aux->_left = new User(id);
                aux->_left->_upperLevel = aux;
                this->_size++;
                return;
            }

            aux = aux->_left;
        }
        else if(id > aux->getId()){
            if(aux->_right == NULL){
                aux->_right = new User(id);
                aux->_right->_upperLevel = aux;
                this->_size++;
                return;
            }

            aux = aux->_right;
        }
    }

}

/**
 * @brief Método de busca binária pela árvore. Faz verificações para saber se o id
 * da posição atual é maior ou menos ao id buscado e continua para a esquerda ou direita
 * a partir disso.
 * 
 * @param id Id do usuário a ser buscado.
 * @return User* Ponteiro para o usuário referente ao ID passado como parâmetro.
 */
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

/**
 * @brief Envia email para o usuário passado como parâmetro.
 * 
 * @param id Id do usuário a receber o email.
 * @param email Email a ser enviado para o usuário.
 */
void UsersRegister::sendEmail(int id, Email email){
    if(!isIdAlreadyRegistered(id))
        throw ErrorMessage(200,"CONTA " + std::to_string(id) + " NÃO EXISTE");

    findUser(id)->receiveEmail(email);
}