#ifndef EMAIL_HPP
#define EMAIL_HPP

#include<string>

using namespace std;

class Email
{
private:
    int _priority;
    string _message;
    int _idSender;


public:
    Email() {
        this->_idSender = 0;
        this->_priority = 0;
        this->_message = " ";
    };

    Email( int priority, string message){
    _message = message;
    _priority = priority;
    };

    Email(int idSender, int priority, string message){
    _idSender = idSender;
    _message = message;
    _priority = priority;
};
    ~Email(){};

    string getMessage()const { return this->_message;};
    int getIdSender() const {return this->_idSender;};
    int getPriority() const {return this->_priority;};

    void operator = (const Email e){
        this->_idSender = e.getIdSender();
        this->_priority = e.getPriority();
        this->_message = e.getMessage();
    }
};

#endif