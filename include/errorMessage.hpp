#ifndef ERROR_MESSAGE_HPP
#define ERROR_MESSAGE_HPP

#include <string>

using namespace std;

class ErrorMessage{
    public:
        ErrorMessage(int status, string message){
            this->_status = status;
            this->_message = message;
        };
        ~ErrorMessage(){};

        string getMessage() {return this->_message; };
        int getStatus() { return this->_status; };

    private:
        string _message;
        int _status;
};

#endif