#ifndef CELL_STACK_EMAIL_HPP
#define CELL_STACK_EMAIL_HPP

#include "emailQueue.hpp"

class CellStackEmail {
    public:
        CellStackEmail(int priority){
            this->_data = EmailQueue(priority);
            this->_next = NULL;
            this->_priority = priority;
        };
        ~CellStackEmail(){
        };

        bool isEmpty() { return _data.isEmpty(); };

    private:
        EmailQueue _data;
        CellStackEmail* _next;
        int _priority;

    friend class Inbox;

};

#endif