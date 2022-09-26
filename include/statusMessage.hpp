#ifndef STATUS_MESSAGE_HPP
#define STATUS_MESSAGE_HPP

#include<string>

using namespace std;

class statusMessage
{
private:
    int id;
    int status;
    string type;

public:
    statusMessage(int id, int status, string type);
    ~statusMessage();
};

statusMessage::statusMessage(int id, int status, string type)
{
    this->id = id;
    this->status = status;
    this->type = type;
}

statusMessage::~statusMessage()
{
}


#endif