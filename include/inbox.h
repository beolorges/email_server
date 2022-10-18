#ifndef INBOX_HPP
#define INBOX_HPP

#include "emailQueue.h"

class Inbox
{
private:
    EmailQueue* _first;
    EmailQueue* _last;
    int _size;

    EmailQueue* getEmailQueueByPriority(int priority);

public:
    Inbox();

    ~Inbox();

    bool isEmpty() const;

    void clean();

    void insertEmail(Email);
    void popFirst();

    Email getEmail();
};


#endif