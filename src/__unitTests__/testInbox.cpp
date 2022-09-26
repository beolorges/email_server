#include "./include/inbox.hpp"
#include "./include/email.hpp"

#include <iostream>
using namespace std;

int main() {
    inbox validInbox;

    validInbox.addEmail(email(10, 1, "this is a valid message"));

    if(validInbox.getQtdEmail() != 1)
        cout << "Not passed in line 17" << endl;

    validInbox.addEmail(email(10, 9, "this message should be printed"));

    if(validInbox.getQtdEmail() != 2)
        cout << "Not passed in line 23" << endl;

    if(validInbox.getEmail() != "this message should be printed")
        cout << "Not passed in line 26" << endl;

    if(validInbox.getQtdEmail() != 1)
        cout << "Not passed in line 29" << endl;


    validInbox.addEmail(email(10, 9, "this message should be printed"));
    validInbox.addEmail(email(10, 9, "this message should not be printed"));

    if(validInbox.getEmail() != "this message should be printed")
        cout << "Not passed in line 35" << endl;

}