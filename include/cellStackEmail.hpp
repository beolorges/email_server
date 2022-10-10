#ifndef CELL_STACK_EMAIL_HPP
#define CELL_STACK_EMAIL_HPP

#include "stackEmail.hpp"

class CellStackEmail {
    public:
        CellStackEmail(int priority){
            this->_data = stackEmail(priority);
            this->_next = NULL;
            this->_priority = priority;
        };
        ~CellStackEmail(){
        };

        bool isEmpty() { return _data.isEmpty(); };

    private:
        stackEmail _data;
        CellStackEmail* _next;
        int _priority;

    friend class Inbox;

};

#endif