#include "inbox.hpp"
#include "email.hpp"
#include "usersRegister.hpp"

#include<iostream>

using namespace std;

int main(){
    UsersRegister testRegister = UsersRegister();

    testRegister.addUser(1);
    testRegister.addUser(10);
    testRegister.addUser(15);
    testRegister.addUser(3);
    testRegister.addUser(6);
    testRegister.addUser(8);
    testRegister.addUser(7);
    testRegister.addUser(11);
    testRegister.addUser(113);
    testRegister.addUser(9);

    testRegister.sendEmail(1, Email(10, 8, "Olá tudo bem?"));
    testRegister.sendEmail(6, Email(10, 7, "Olá tudo legal?"));

    cout << testRegister.findUser(1)->getEmail().getMessage() << endl;
    cout << testRegister.findUser(6)->getEmail().getMessage() << endl;

}