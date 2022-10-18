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
    Email() {
        this->_priority = 0;
        this->_message = " ";
    };

    Email( int priority, string message){
    _message = message;
    _priority = priority;
    };

    ~Email(){};

    string getMessage()const { return this->_message;};
    int getPriority() const {return this->_priority;};

    void operator = (const Email e){
        this->_priority = e.getPriority();
        this->_message = e.getMessage();
    }

    friend class EmailQueue;
};

#endif