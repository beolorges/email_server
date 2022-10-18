#ifndef EMAIL_QUEUE_H
#define EMAIL_QUEUE_H

#include "email.h"
#include "errorMessage.h"
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
        EmailQueue();

        EmailQueue(int priority);

        ~EmailQueue();

        int getPriority() const ;
        bool isEmpty() const ;

        Email getEmail();

        void popFirst();
        void pushBack(Email);

        void clear();

    friend class Inbox;

};


#endif