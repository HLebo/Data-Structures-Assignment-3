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
        void printTree();
        void insertNode(int number);
        void printTree(Node *root);


    protected:

    private:

        void insertNode(Node *root, int number);
};

#endif // SEARCHTREE_H
