#ifndef STACK_EMAIL_HPP
#define STACK_EMAIL_HPP

#include "email.hpp"
#include "cellEmail.hpp"
#include <stdlib.h>

class stackEmail
{
private:
    CellEmail* _first;
    CellEmail* _last;
    int _size;
    int _priority;

public:
    stackEmail() {
        this->_size = 0;
    };
    stackEmail(int priority){
        this->_size = 0;
        this->_priority = priority;
    };
    ~stackEmail() {
        clear();
    };

    int getPriority() { return this->_priority; };
    bool isEmpty(){ return this->_size == 0; };

    Email getEmail();

    void popFirst();
    void pushBack(Email);

    void clear();

};


#endif