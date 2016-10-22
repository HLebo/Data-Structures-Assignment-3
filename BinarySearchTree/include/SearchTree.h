#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include <iostream>

struct Node{
    int data;
    Node *left_child;
    Node *right_child;
};

class SearchTree
{
    public:
        Node *head;

        SearchTree();
        virtual ~SearchTree();
        void insertNode(int number);
        void printTree();
        void findKey(int number);
        void deleteNode(int number);
        int findDepth(int number);
        int cost();
        bool isBalanced();

    protected:

    private:

        //overloaded functions
        void insertNode(Node *root, int number);
        void printTree(Node *root);
        void findKey(Node* root, int number);
        void deleteNode(Node* root, Node* parent, int number);
        int findDepth(Node* root, int number);
        int cost(Node* root);
        int height(Node* root);
        bool isBalanced(Node *root);
};

#endif // SEARCHTREE_H
