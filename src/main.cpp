#include "interface.hpp"
#include<string.h>
#include<iostream>

using namespace std;

int main(int argc, char* argv[]){
    Interface interfaceMail;
    FILE* file = fopen("../input.txt", "rt");

    if(file == NULL){
        cout << "Arquivo não encontrado" << endl;
        return -1;
    }

    while(!feof(file)){
        char command[20];
        int id;
        fscanf(file, "%s %d", command, &id);

        if(strcmp(command, "CADASTRA") == 0){
            interfaceMail.createAccount(id);
            continue;
        }

        if(strcmp(command, "REMOVE") == 0){
            interfaceMail.removeAccount(id);
            continue;
        }
        
        if(strcmp(command, "ENTREGA") == 0){
            int priority;
            
            fscanf(file, " %d", &priority);

            string message = "";

            for(char word[20] = ""; 
            strcmp(word, "FIM") != 0;
            fscanf(file, "%s", word)){
                message += " ";
                message += word;
            }

            message.erase(0, 2);

            interfaceMail.sendMail(id, priority, message);
            continue;
        }

        if(strcmp(command, "CONSULTA") == 0){
            interfaceMail.getMail(id);
            continue;
        }
    
    }

    return 0;
}