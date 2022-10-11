#include "interface.hpp"
#include<string.h>
#include<iostream>

using namespace std;

int main(){
    Interface interfaceMail;
    FILE* file = fopen("../input.txt", "rt");

    if(file == NULL){
        cout << "Arquivo não encontrado" << endl;
        return -1;
    }

    while(!feof(file)){
        char command[20];
        fscanf(file, "%s", command);

        if(strcmp(command, "CADASTRA") == 0){
            int idToCreate;
            fscanf(file, " %d", &idToCreate);
            interfaceMail.createAccount(idToCreate);
        }

        else if(strcmp(command, "REMOVE") == 0){
            int idToRemove;
            fscanf(file, " %d", &idToRemove);
            interfaceMail.removeAccount(idToRemove);
        }
        
            else if(strcmp(command, "ENTREGA") == 0){
                int idToSend;
                int priority;
                
                fscanf(file, " %d %d", &idToSend, &priority);
                char word[20] = "";

                string message = "";
                fscanf(file, " %s", word);
                while(strcmp(word, "FIM") != 0){
                    message += word;
                    message += " ";
                    fscanf(file, " %s", word);
                }

                interfaceMail.sendMail(idToSend, priority, message);
            }

                else{
                    int idToGetEmail;
                    fscanf(file, " %d", &idToGetEmail);
                    interfaceMail.getMail(idToGetEmail);
                }
    
    }

    // User* userTest = new User();
    // // Inbox* inboxTest = new Inbox();
    // Email firstEmailLvl10= Email(1, 10, "Priority lvl 10 add first");
    // Email secondEmailLvl10= Email(1, 10, "Priority lvl 10 add later");
    // Email thirdEmailLvl9= Email(1, 9, "Priority lvl 9");
    // Email thirdEmailLvl8= Email(1, 8, "Priority lvl 8");

    // userTest->receiveEmail(thirdEmailLvl8);
    // userTest->receiveEmail(firstEmailLvl10);
    // userTest->receiveEmail(secondEmailLvl10);
    // userTest->receiveEmail(thirdEmailLvl9);

    // cout << userTest->getEmail().getMessage() << endl;
    // cout << userTest->getEmail().getMessage() << endl;
    // cout << userTest->getEmail().getMessage() << endl;
    // cout << userTest->getEmail().getMessage() << endl;
    // cout << userTest->getEmail().getMessage() << endl;

    return 0;
    

}