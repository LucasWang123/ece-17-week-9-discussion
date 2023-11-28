//
// Created by Lucas on 11/27/2023.
//
#include "BinarySearchTree.h"
using namespace std;
#include <iostream>


void BinaryTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root, newNode);
}

void BinaryTree::remove(int aVal) {
    deleteNode(aVal, root);
}

bool BinaryTree::searchNode(int aVal) {
    Node* currentNode = root;
    while(currentNode){
        if (currentNode -> val == aVal)
            return true;
        else if (aVal < currentNode->val){
            currentNode = currentNode -> left;
        }
        else{
            currentNode = currentNode -> right;
        }
    }
}

void BinaryTree::insert(Node *&aNodePtr, Node *&aNewNodePtr) {
    if (aNodePtr == nullptr){
        aNodePtr = aNewNodePtr;
    }
    else if (aNewNodePtr -> val < aNodePtr -> val){
        insert(aNodePtr -> left,  aNewNodePtr);
    }
    else {
        insert(aNodePtr-> right, aNewNodePtr);
    }
}

void BinaryTree::deleteNode(int aVal, Node *&aNodePtr) {
    if (aVal < aNodePtr -> val){
        deleteNode(aVal, aNodePtr -> left);
    }
    else if (aVal > aNodePtr -> val){
        deleteNode(aVal, aNodePtr -> right);
    }
    else {
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(Node *&aNodePtr) {
    Node* tempNodePtr = nullptr;

    if (aNodePtr == nullptr){
        std::cout << "Cannot remove empty Node";
    }
    else if (aNodePtr -> right == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr-> right;
        delete tempNodePtr;
    }
    else if (aNodePtr -> left == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr-> left;
        delete tempNodePtr;
    }
    else {
        tempNodePtr = aNodePtr -> right;

        while(tempNodePtr-> left){
            tempNodePtr = tempNodePtr-> left;
        }

        tempNodePtr -> left = aNodePtr -> left;

        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr -> right;

        delete tempNodePtr;
    }
}

void BinaryTree::displayInOrder(Node* aNodePtr){
    if (aNodePtr) {
        displayInOrder(aNodePtr->left);
        std::cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}


void BinaryTree::printTree(){
    displayInOrder(root);
    std::cout << std::endl;
};