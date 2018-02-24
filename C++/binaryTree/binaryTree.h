//
// Created by Zeyaam Shahid on 12/27/17.
//

#ifndef UNTITLED_BINARYTREE_H
#define UNTITLED_BINARYTREE_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int data;
    Node * left = NULL;
    Node * right = NULL;
};

class binaryTree {
private:
    Node * root;
public:
    binaryTree();
    bool addNode(Node * newNode);
    bool binarySearch(int data);
    void printTree(Node * node);
    int height(struct Node * node);
};

#endif //UNTITLED_BINARYTREE_H
