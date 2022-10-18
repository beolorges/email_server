#ifndef EMAIL_QUEUE_H
#define EMAIL_QUEUE_H

#include "email.hpp"
#include "errorMessage.hpp"
#include <stdlib.h>

class EmailQueue
{
    private:
        Email* _first;
        Email* _last;
        int _size;
        int _priority;
        
        EmailQueue* _next;

    public:
        EmailQueue() {
            this->_size = 0;
        };

        EmailQueue(int priority){
            this->_size = 0;
            this->_priority = priority;
        };

        ~EmailQueue() {
            clear();
        };

        int getPriority() { return this->_priority; };
        bool isEmpty(){ return this->_size == 0; };

        Email getEmail();

        void popFirst();
        void pushBack(Email);

        void clear();

    friend class Inbox;

};


#endif