#pragma once
#include "Data.h"
#include <iostream>
using namespace std;

class VisaApplication : public Data {
private:
    string visaType;
    string invoiceNo;
    string surname;
    string firstName;
    string contact;
    string status;
    string result;

public:
    VisaApplication(string visaType, string invoiceNo, string surname, string firstName, string contact, string status, string result)
        : visaType(visaType), invoiceNo(invoiceNo), surname(surname), firstName(firstName), contact(contact), status(status), result(result) {}

    void print()  {
        cout << "Visa Type: " << visaType << endl;
        cout << "Invoice Number: " << invoiceNo << endl;
        cout << "Surname: " << surname << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Contact: " << contact << endl;
        cout << "Status: " << status << endl;
        cout << "Result: " << result << endl;
    }

    // Getter functions to access private members
    string getVisaType() const { return visaType; }
    string getInvoiceNo() const { return invoiceNo; }
    string getSurname() const { return surname; }
    string getFirstName() const { return firstName; }
    string getContact() const { return contact; }
    string getStatus() const { return status; }
    string getResult() const { return result; }
};


