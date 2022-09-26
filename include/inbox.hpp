#ifndef INBOX_HPP
#define INBOX_HPP

#include "email.hpp"
#include "statusMessage.hpp"

class inbox
{
private:
    int _qtdEmails;
    email** _dataEmails;

public:
    inbox();
    ~inbox();

    void addEmail(email email);
    string getEmail();

    int getQtdEmail();
};

inbox::inbox()
{
    this->_qtdEmails = 0;
    this->_dataEmails = (email**) malloc(0);
}

inbox::~inbox()
{
}


#endif