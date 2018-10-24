#include <iostream>

using namespace std;

/*
===========================
    SINGLY LINKED LIST
===========================
*/
template<typename T>
class LinkedList {
private: 
    struct ListNode {
        T value;
        ListNode *next;
        ListNode(T &val) : value(val) {}
    };
    ListNode *head = NULL;
public:
    void addNode(T &);
    void addInOrder(T &);
    bool removeNode(T &);
    bool findValue(T &);
    LinkedList(T &val) : head(val) {};
    LinkedList(T &, int &);
};

template<typename T> 
LinkedList<T>::LinkedList(T &value, int &size) {
    for (int i=0; i< size; i++) {
        this->addNode(value);
    }
}

template<typename T> 
void LinkedList<T>::addNode(T &val) {
    if(!head) {
        this->head = ListNode(val);
        return;
    }
    ListNode *newNode = this->head;
    while(newNode->next) {
        newNode = newNode->next;
    }
    newNode->next = ListNode(val);
}

template<typename T> 
void LinkedList<T>::addInOrder(T &val) {
    if (!head) {
        this->head = ListNode(val);
        return;
    }
    ListNode *temp = this->head;
    ListNode *newNode = ListNode(val);
    while(temp->next) {
        if (temp->next->value > val) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
    }
    temp->next = newNode;
}

template<typename T> 
bool LinkedList<T>::findValue(T &value) {
    ListNode *temp = head;
    while(temp->next) {
        if (temp->value == value) return true;
    }
    return false;
}

template<typename T> 
bool LinkedList<T>::removeNode(T &value) {
    ListNode *temp = head;
    ListNode *prev = NULL, *current = NULL;
    while (temp->next) {
        if (temp->value == value) {
            prev->next = temp->next;
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}