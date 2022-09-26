#ifndef STACK_EMAIL_HPP
#define STACK_EMAIL_HPP

#include "email.hpp"

class stackEmail
{
private:
    email* _data;
    int _size;

public:
    stackEmail() {};
    ~stackEmail() {};

    /*Elimina o elemento mais ao topo da lista*/
    void popFirst();

    /*Coloca um email no final da lista*/
    void pushBack(email);

    int getSize();
};


#endif