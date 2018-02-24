#include <iostream>
#include <vector>
#include "sorting.h"

using namespace std;

struct Node {
    int value;
    Node * next = NULL;
};

Node * addNode(int value) {
    Node * temp = new Node;
    temp->value = value;
    temp->next = NULL;
    return temp;
}

Node * highestNumber(Node * head) {
    Node * temp = head;
    Node * last = new Node;
    do {
        last = head;
        head = head->next;
    } while (temp != head);
    return last;
}

Node * insertNode(Node * attach, int val) {
    Node *add = addNode(val);
    Node *highest = highestNumber(attach);
    if (highest->value < val) {
        highest->next = add;
        add->next = attach;
        return attach;
    }
    Node *temp = attach;
    while (add->value > attach->value) {
        if (add->value <= attach->next->value) {
            temp = attach->next;
            attach->next = add;
            add->next = temp;
            break;
        }
        else {
            attach = attach->next;
        }
    }
    return attach;
}

vector <int> bubbleSort(std::vector <int> numbers) {
    bool swapped;
    for (int i=0; i < numbers.size() - 1; i++) {
        swapped = false;
        for (int j=0; j < numbers.size() - i - 1; j++) {
            if (numbers[j] > numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
    return numbers;
}

vector <int> selectionSort(std::vector <int> numbers) {
    int minimum;
    for (int i=0; i < numbers.size() - 1; i++) {
        minimum = i;
        for (int inner = i+1; inner < numbers.size(); inner++) {
            if (numbers[inner] < numbers[minimum]) minimum = inner;
        }
        if (minimum != i) {
            int temp = numbers[i];
            numbers[i] = numbers[minimum];
            numbers[minimum] = temp;
        }
    }
    return numbers;
}

void printVector(vector <int> vec) {
    for (int i = 0; i< vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector <int> numbs = {1,2,9,4,5,8,7,6,0,2,5,3,2,1,0};
    cout << "Hello, World!" << endl;
    numbs = selectionSort(numbs);
    printVector(numbs);
    return 0;
}