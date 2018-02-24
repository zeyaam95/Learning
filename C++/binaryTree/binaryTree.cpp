//
// Created by Zeyaam Shahid on 12/27/17.
//

#include "binaryTree.h"
using namespace std;

binaryTree::binaryTree(){
    root = NULL;
    return;
}
/*
 The binary tree adds a node by comparing the node's data value with the root's data value
 if the value is less than the root's value the function repeats the same procedure with the
 left node of the root and if it is more that the root's value then the process is repeated
 with the right node of the root node. The function keeps traversing the tree until it reaches
 the end of a branch and then it appends the node to the tree.
 */
bool binaryTree::addNode(Node * newNode){
    Node *temporary, *last;
    temporary = root;
    last = NULL;
    while(temporary != NULL) {
        last = temporary;
        temporary = (newNode->data < temporary->data)? temporary->left : temporary->right;
    }
    if (last == NULL) {
        root = newNode;
    }
    else {
        if (newNode->data < last->data) last->left = newNode;
        else last->right = newNode;
    }
    return true;
}

/*
 The binary search traverses the tree in the same way as the addNode function and if it
 finds the value of the function it returns true and false otherwise.
 */
bool binaryTree::binarySearch(int data) {
    Node * node = root;
    while (node != NULL) {
        if (node->data == data) break;
        node = (data > node->data)? node->right: node->left;
    }
    if (node==NULL) return false;
    else return true;
}

/*
 The height function finds the longest branch in the binary tree and it does so by starting
 at the given and recursively finding the depth/height of the branch of the right and left
 nodes. This function, when called on the root of the tree returns the height of the binary
 tree.
 */
int binaryTree::height(struct Node * node) {
    if (node==NULL) {
        return 0;
    }
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight) return lheight + 1;
        else return rheight + 1;
    }
}
/*
 The print function does an inorder traversal of the binary tree and prints the values.
 Inorder traversal works in a way so it prints the values of the binary tree in ascending
 order.
 */
void binaryTree::printTree(Node * rootNode){
    while (rootNode != NULL) {
        printTree(rootNode->left);
        cout << rootNode->data << '\n';
        printTree(rootNode->right);
        break;
    }
}

