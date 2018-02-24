#include <iostream>
#include <vector>
#include <string>
#include "CellPhone.h"

using namespace std;

int main() {
	string decision, outcome, firstName, lastName, homeNumber, mobileNumber;
	char option;

	do {
		cout << "Hello User. Would you like to turn on this cellphone? (yes or no)\n";
		cin >> decision;
	} while (decision != "no" && decision != "yes");

	outcome = (decision == "no") ? \
		"Thank you. Please restart the program when you wish to use the device\n"\
		: "\n- - - - - MENU - - - - -\nA. Turn off Cell Phone\nB. Add A New Contact\n\C. Display Contact Information\nD. Dial Contact\n";
	
	if (decision == "yes") {
		CellPhone galaxyS8;
		do {
			cout << outcome;
			cin >> option;
			switch (option) {
			case 'A':
			case 'a':
				galaxyS8.powerDown();
				decision = "off";
				break;
			case 'B':
			case 'b': {
				cout << "Please enter the first name, last name, home number and mobile phone number of the contact that you want to add.\n" << endl;
				cin >> firstName >> lastName >> homeNumber >> mobileNumber;
				galaxyS8.newContact(firstName, lastName, homeNumber, mobileNumber);
				break;
			}
			case 'C':
			case 'c':
				cout << "Please enter the home number and mobile phone number of the contact that you want to view.\n" << endl;
				cin >> homeNumber >> mobileNumber;
				galaxyS8.displayContactNumberInformation(homeNumber, mobileNumber);
				break;
			case 'D':
			case 'd':
				cout << "Please enter the first name, last name of the contact that you want to call.\n" << endl;
				cin >> firstName >> lastName;
				galaxyS8.dialContact(firstName, lastName);
				break;
			default:
				cout << "Please select a different option." << endl;
			}
		} while (decision != "off");
	}
	else
		cout << "Thank you. Please restart the program when you wish to use the device.\n";
	
	cout << "Enter any key to exit the program.\n";
	cin >> decision;
	return 0;
}
