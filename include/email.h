#ifndef EMAIL_HPP
#define EMAIL_HPP

#include<string>

using namespace std;

class Email
{
private:
    int _priority;
    string _message;

    Email* _next;
    
public:
    Email();
    Email( int priority, string message);
    ~Email(){};

    string getMessage() const;
    int getPriority() const;

    void operator = (const Email e);

    friend class EmailQueue;
};

#endif