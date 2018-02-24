#pragma once
#ifndef CELLPHONE_H
#define CELLPHONE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {

	string firstName, lastName, homeNumber, mobileNumber;
};

class CellPhone {

private:

	vector<Contact> contacts;
	string display, currentCall;
	bool on, callActive;
	int contactCount();
	void showOutput();

public:
	// I had to make the class constructor public as it was inaccessible
	// in the main function
	CellPhone();
	bool newContact(string firstName, string lastName, string homeNumber, string mobileNumber);
	void dialContact(string firstName, string lastName);
	void displayContactNumberInformation(string homeNumber, string mobileNumber);
	void powerDown();
};

#endif 
