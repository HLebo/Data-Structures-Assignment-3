#include "SearchTree.h"

using namespace std;


SearchTree::SearchTree()
{
    head = NULL;
    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    Node *n4 = new Node;
    Node *n5 = new Node;

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;
    n5->data = 5;

    n1->left_child = NULL;
    n2->left_child = NULL;
    n3->left_child = NULL;
    n4->left_child = NULL;
    n5->left_child = NULL;
    n5->right_child = NULL;

    head = n1;
    n1->right_child = n2;
    n2->right_child = n3;
    n3->right_child = n4;
    n4->right_child = n5;
    //ctor
}

SearchTree::~SearchTree()
{
    //dtor
}

void SearchTree::printTree(){
    if(this->head == NULL){
        return;
    }
    printTree(this->head->right_child);
    cout << this->head->data << " value" << endl;
    printTree(this->head->left_child);
}

void SearchTree::printTree(Node *root){
    if(root == NULL){
        return;
    }
    printTree(root->right_child);
    cout << root->data << " value" << endl;
    printTree(root->left_child);
}

void SearchTree::insertNode(int number){
    if(this->head == NULL){
        cout << "head is null" << endl;
        this->head = new Node;
        this->head->data = number;
        this->head->left_child = NULL;
        this->head->right_child = NULL;
    }
    else{
        insertNode(this->head, number);
    }

    /*
    else if(number < this->head->data){
        cout << "searching left" << endl;
        insertNode(this->head->left_child, number);
    }
    else if(number > this->head->data){
        cout << "searching right" << endl;
        insertNode(this->head->right_child, number);
    }*/
}


void SearchTree::insertNode(Node *root, int number){
    if(root == NULL){
        cout << "root is null" << endl;
        root = new Node;
        root->data = number;
        root->left_child = NULL;
        root->right_child = NULL;
    }

    if(number < root->data){
        if(root->left_child == NULL){
            root->left_child = new Node;
            root->left_child->data = number;
            root->left_child->left_child = NULL;
            root->left_child->right_child = NULL;
            cout << "inserting left" << endl;
        }
        else{
            cout << "searching left" << endl;
            insertNode(root->left_child, number);
        }
    }

    else if(number > root->data){
        if(root->right_child == NULL){
            root->right_child = new Node;
            root->right_child->data = number;
            root->right_child->left_child = NULL;
            root->right_child->right_child = NULL;
            cout << "inserting right" << endl;
        }
        else{
            cout << "searching right" << endl;
            insertNode(root->right_child, number);
        }
    }
}


