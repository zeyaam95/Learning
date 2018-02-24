#include <iostream>
#include <vector>
#include <string>
#include "binaryTree.h"

using namespace std;

Node * newNode(int data) {
    Node * temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

vector<int> getVector() {
    vector<int> numbers;
    int size, num;
    cout << "How many nodes would you like to add to your binary tree? "<<endl;
    cin >> size;
    for (int i=0; i<size;i++) {
        cout << "\nEnter a value for your node: ";
        cin >> num;
        numbers.push_back(num);
    }
    return numbers;
}

int main() {
    string loop;
    do {
        binaryTree test;
        int rootNumber, searchNumber;
        string answer;
        bool input;
        cout << "\nPlease enter the root value of your binary tree: ";
        cin >> rootNumber;
        Node *root = newNode(rootNumber);
        test.addNode(root);
        vector<int> values = getVector();
        //Populating the Tree
        Node **nodes = new Node *[values.size()];
        for (int i = 0; i < values.size(); i++) {
            nodes[i] = newNode(values[i]);
            test.addNode(nodes[i]);
        }
        cout << "Would you like to search your binary tree for a value? (Yes or No)";
        cin >> answer;
        input = (answer == "Yes" || answer == "yes") ? true : false;
        if (input) {
            cout << "\nEnter the number you want to search: ";
            cin >> searchNumber;
            string search = (test.binarySearch(searchNumber)) ? "Number is in the binary tree."
                                                              : "Number is not in the binary tree.";
            cout << search << endl;
        }
        int tes = test.height(root);
        cout << "Would you like to print the binary tree? (Yes or No)";
        cin >> answer;
        input = (answer == "Yes" || answer == "yes") ? true : false;
        if (input) {
            cout << "Printing binary tree by inorder traversal." << endl;
            test.printTree(root);
            cout << "Height of Tree: " << tes << "\nDone" << endl;
        }
        cout << "Would you like to enter make another binary tree? (Y or N): ";
        cin >>loop;
    }while (loop == "Y");
    return 0;
}