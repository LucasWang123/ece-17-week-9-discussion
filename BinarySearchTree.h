//
// Created by Lucas on 11/27/2023.
//
class BinaryTree {
public:


    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);

    void printTree();

private:
    struct Node{
        int val;
        Node* left;
        Node* right;
    };
    Node* root;
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);
    void displayInOrder(Node *aNodePtr);


};
#ifndef WEEK_9_DISCUSSION_NEW_NODE_H
#define WEEK_9_DISCUSSION_NEW_NODE_H
#endif //WEEK_9_DISCUSSION_NEW_NODE_H
