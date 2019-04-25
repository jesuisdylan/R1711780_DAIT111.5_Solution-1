#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include<cstring>
#include "Client.h"

using namespace std;

class Client {
public:
    Client();
    Client(int PhoneNum, char* name, char* address, char* email);
    void GetClient();
    void WriteToFile(Client client);
    void GetRecordDetails();
    void ReadFromFile(streamsize position);
    void ReadRecordPosition();

private:
    int PNum;
    char Nme[50];
    char Adress[50];
    char EEmail[50];

};

#endif 