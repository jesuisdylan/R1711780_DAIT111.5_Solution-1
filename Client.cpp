#include "Client.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<cstring>
#include "Client.h"

using namespace std;

Client::Client() {
}

Client::Client(int PhoneNum, char* name, char* address, char* email) {
    PNum = PhoneNum;
    strcpy(Nme, name);
    strcpy(Adress, address);
    strcpy(EEmail, email);

}

void Client::GetClient() {
    cout << "\n";
    cout << "Phone number: " << PNum << endl;
    cout << "Name: " << Nme << endl;
    cout << "Address: " << Adress << endl;
    cout << "E-mail address: " << EEmail << endl;
}

void Client::GetRecordDetails() {
    char opt;
    char ch;

    int PNum;
    char Nme[50];
    char Adress[50];
    char EEmail[50];

    do {
        cout << "Enter Phone Number: ";
        cin >> PNum;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(Nme, 50);
        cout << "Enter Address: ";
        cin.getline(Adress, 50);
        cout << "Enter E-mail Address: ";
        cin.getline(EEmail, 50);
        Client client(PNum, Nme, Adress, EEmail);
        WriteToFile(client);

        cout << "Another record? <Y-yes or N-no>" << endl;
        opt = getchar();
        cin.ignore();

    } while (opt != 'n');


}

void Client::WriteToFile(Client client) {

    ofstream outFile("client", ios::app | ios::binary);
    outFile.write((char*) &client, sizeof (Client));
    outFile.flush();

    if (outFile)
        cout << "\nRecord successfully saved." << endl;
    else
        cout << "Error saving file." << endl;

    outFile.close();

}

void Client::ReadRecordPosition() {
    streamsize position;
    cout << "Enter the record number to retrieve...";
    cin>>position;
    ReadFromFile(position);
}

void Client::ReadFromFile(streamsize position) {
    Client client;

    ifstream inFile("client", ios::in | ios::binary);

    inFile.seekg(sizeof (Client)*(position - 1), ios::beg);
    inFile.read((char *) &client, sizeof (Client));
    client.GetClient();
}