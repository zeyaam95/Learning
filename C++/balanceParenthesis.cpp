/*
Author: Zeyaam Shahid
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool isPair(char opening, char closing) {
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}

bool bracketBalance(string test) {
	stack<char> s;
	for (int i = 0; i < test.length(); i++) {
		if (test[i] == '(' || test[i] == '{' || test[i] == '[')
			s.push(test[i]);
		else if (test[i] == ')' || test[i] == '}' || test[i] == ']') {
			if (s.empty() || !isPair(s.top(), test[i]))
				return false;
			else
				s.pop();
		}
	}
	return s.empty() ? true : false;
}

int test() {
	string expression;
	cout << "Enter an expression:  "; // input expression from STDIN/Console
	cin >> expression;
	if (bracketBalance(expression))
		cout << "Balanced\n";
	else
		cout << "Not Balanced\n";
	return 0;
}