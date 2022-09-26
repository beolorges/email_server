#ifndef EMAIL_HPP
#define EMAIL_HPP

#include<string>

using namespace std;

class email
{
private:
    int _idSender;
    int _priority;
    string _message;


public:
    email(int idSender, int priority, string message);
    ~email();

    string getMessage();
    int getIdSender();
    int getPriority();
};

email::email(int idSender, int priority, string message)
{
    _idSender = idSender;
    _message = message;
    _priority = priority;
}

email::~email()
{
}

int email::getIdSender(){
    return this->_idSender;
}

int email::getPriority(){
    return this->_priority;
}

string email::getMessage(){
    return this->_message;
}


#endif