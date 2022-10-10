#include "inbox.hpp"
#include "email.hpp"

#include<iostream>

using namespace std;

int main(){
    Inbox inboxTest;
    Email firstEmailLvl10= Email(1, 10, "Priority lvl 10 add first");
    Email secondEmailLvl10= Email(1, 10, "Priority lvl 10 add later");
    Email thirdEmailLvl9= Email(1, 9, "Priority lvl 9");
    Email thirdEmailLvl8= Email(1, 8, "Priority lvl 8");

    inboxTest.insertEmail(firstEmailLvl10);
    inboxTest.insertEmail(thirdEmailLvl8);
    inboxTest.insertEmail(secondEmailLvl10);
    inboxTest.insertEmail(thirdEmailLvl9);
    inboxTest.insertEmail(secondEmailLvl10);


    cout << inboxTest.getEmail().getMessage() << endl;
    cout << inboxTest.getEmail().getMessage() << endl;
    cout << inboxTest.getEmail().getMessage() << endl;
    cout << inboxTest.getEmail().getMessage() << endl;
    cout << inboxTest.getEmail().getMessage() << endl;


}