#include <iostream>
#include <string>

using namespace std;

struct node {
	string data;
	node * next;

};


node * newNode(string data) {
	node * temp = new node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void realReverse(node * current, node * previous, node ** head) {
	if (!current->next) {
		*head = current;
		current->next = previous;
		return;
	}
	node * next = current->next;
	current->next = previous;
	realReverse(next, current, head);
}

void reverse(node ** head) {
	if (!head) {
		return;
	}
	realReverse(*head, NULL, head);

}

void print(node * head) {
	while (head != NULL) {
		cout << head->data << endl;
		head = head->next;
	}
}

int testing() {
	node * test = newNode("Zeyaam");
	test->next = newNode("Eddy");
	test->next->next = newNode("Matic");
	node * temp = new node;
	temp = test;
	print(test);
	reverse(&test);
	temp = test;
	while (temp != NULL) {
		print(temp);
		temp = temp->next;
	}
	return 0;
}