#ifndef INBOX_HPP
#define INBOX_HPP

#include "cellStackEmail.hpp"

class Inbox
{
private:
    CellStackEmail* _first;
    CellStackEmail* _last;
    int _size;

    EmailQueue* getStackEmailByPriority(int priority);

public:
    Inbox() { 
        this->_first = NULL;
        this->_last = NULL;
        this->_size = 0; };
    ~Inbox() { this->clean(); };

    bool isEmpty() { return this->_size == 0; };

    void clean();

    void insertEmail(Email);
    void popFirst();

    Email getEmail();
};


#endif