#include "CellPhone.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

CellPhone::CellPhone() {
	on = true;
}


int CellPhone::contactCount() {

	return contacts.size();
}

void CellPhone::showOutput() {

	cout << " - - - - DISPLAY - - - - \n\n" << display << endl;
}

bool CellPhone::newContact(string firstName, string lastName, string homeNumber, string mobileNumber) {

	if (contacts.size() < 100) {
		contacts.push_back({ firstName, lastName, homeNumber, mobileNumber });
		cout << "\nThe contact was added."<<endl;
		return true;
	}
	cout << "The contact was not added as the contact book is full.\n" << endl;
	return false;
}

void CellPhone::dialContact(string firstName, string lastName) {

	bool found = false;

	for (int i = 0; i < contacts.size() && !found; i++) {

		if (contacts[i].firstName == firstName) {

			if (contacts[i].lastName == lastName) {

				string choice;
				do {
				cout << "Would you like to dial:\nA Home phone\nB Mobile phone\n";
				cin >> choice;
				} while (choice != "a" && choice != "A" && choice != "b" && choice != "B");
				if (choice == "A" || choice == "a") {
					display = "Dialing Home phone: " + contacts[i].homeNumber;
					currentCall = "Home phone: ";
				}
				else {
					display = "Dialing Mobile phone: " + contacts[i].mobileNumber;
					currentCall = "Mobile phone: ";
				}
				showOutput();
				found = true;
			}
		}
	}
	if (found == false)
		cout << "The contact doesn't exist.\n" << endl;
}

void CellPhone::displayContactNumberInformation(string homeNumber, string mobileNumber) {

	bool found = false;
	for (int i = 0; i < contacts.size() && !found; i++) {
		if (contacts[i].homeNumber == homeNumber) {
			if (contacts[i].mobileNumber == mobileNumber) {

				display = "First Name: " + contacts[i].firstName + \
						  "\nLast Name: " + contacts[i].lastName +"\n";
				showOutput();
				found = true;
			}
		}
	}
	if (found == true) {
		cout << " - - - - - - - - - - - - " << endl;
	}
	else {
		cout << "The contact doesn't exist.\n" << endl;
	}
}

void CellPhone::powerDown() {

	display = "This device has been powered off";
	showOutput();
	on = false;
}