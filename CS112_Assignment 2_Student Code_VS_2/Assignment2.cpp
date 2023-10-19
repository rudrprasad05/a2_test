// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "List.h"
#include "VisaApplication.h"

using namespace std;

void discard_line(ifstream& in);
void print(List& myList, ofstream& out, const string& header);
void print_success_list(List& myList, ofstream& out, const string& header);
void print_failure_list(List& myList, ofstream& out, const string& header);
void remove_success_failure_list(List& myList, ofstream& out, const string& header);

int main()
{
    List myList;

    ifstream in;
    ofstream out;
    in.open("applications.txt", ios::in);
    out.open("applications_outcome.txt", ios::out);


    if (!in.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    if (!out.is_open()) {
        cerr << "Failed to open the output file." << endl;
        return 1;
    }

    string header;
    getline(in, header); // Read and save the header line

    string visaType, invoiceNo, surname, firstName, contact, status, result;

    while (in >> visaType >> invoiceNo >> surname >> firstName >> contact >> status >> result) {
        VisaApplication* visaApp = new VisaApplication(visaType, invoiceNo, surname, firstName, contact, status, result);
        myList.appendNode(visaApp);
    }

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Print All Applications" << endl;
        cout << "2. Print Successful Applications" << endl;
        cout << "3. Print Failure Applications" << endl;
        cout << "4. Print Pending Decision Applications" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You Chose to Print all Applications:\n" << endl;
            out << "\nYou Chose to Print all Applications: " << endl;
            print(myList, out, header);
            break;
        case 2:
            cout << "You Chose to Print Successful Applications:\n" << endl;
            out << "\nYou Chose to Print Successful Applications:" << endl;
            print_success_list(myList, out, header);
            break;
        case 3:
            cout << "You Chose to Print Unsuccessful Applications:\n" << endl;
            out << "\nYou Chose to Print Unsuccessful Applications:" << endl;
            print_failure_list(myList, out, header);
            break;
        case 4:
            cout << "You Chose to Print Pending Applications:\n" << endl;
            out << "\nYou Chose to Print Pending Applications:" << endl;
            remove_success_failure_list(myList, out, header);
            break;
        case 5:
            cout << "Exiting the program.\n" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again.\n" << endl;
        }
    } while (choice != 5);


    in.close();
    out.close();

    cout << "Data has been written to the output file.\n" << endl;

    system("pause");
    return 0;
}

void discard_line(ifstream& in)
{
    char c;

    do
        in.get(c);
    while (c != '\n');
}

void print(List& myList, ofstream& out, const string& header) {
    cout << header << endl;
    out << header << endl;

    Node* pNode = myList.getpHead();
    while (pNode != NULL) {
        VisaApplication* visaApp = dynamic_cast<VisaApplication*>(pNode->getData());
        if (visaApp != NULL) {
            cout << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
            out << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
        }
        pNode = myList.nextNode(pNode);
    }
}

void print_success_list(List& myList, ofstream& out, const string& header) {
    cout << header << endl;
    out << header << endl;

    Node* pNode = myList.getpHead();
    while (pNode != NULL) {
        VisaApplication* visaApp = dynamic_cast<VisaApplication*>(pNode->getData());
        if (visaApp != NULL && visaApp->getResult() == "success") {
            cout << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
            out << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
        }
        pNode = myList.nextNode(pNode);
    }
}

void print_failure_list(List& myList, ofstream& out, const string& header) {
    cout << header << endl;
    out << header << endl;

    Node* pNode = myList.getpHead();
    while (pNode != NULL) {
        VisaApplication* visaApp = dynamic_cast<VisaApplication*>(pNode->getData());
        if (visaApp != NULL && visaApp->getResult() == "failure") {
            cout << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
            out << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
        }
        pNode = myList.nextNode(pNode);
    }
}

void remove_success_failure_list(List& myList, ofstream& out, const string& header) {
    cout << header << endl;
    out << header << endl;

    Node* pNode = myList.getpHead();
    while (pNode != NULL) {
        VisaApplication* visaApp = dynamic_cast<VisaApplication*>(pNode->getData());
        if (visaApp != NULL && visaApp->getResult() == "NODecision") {
            cout << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
            out << visaApp->getVisaType() << " " << visaApp->getInvoiceNo() << " " << visaApp->getSurname()
                << " " << visaApp->getFirstName() << " " << visaApp->getContact() << " " << visaApp->getStatus()
                << " " << visaApp->getResult() << endl;
        }
        pNode = myList.nextNode(pNode);
    }
}

