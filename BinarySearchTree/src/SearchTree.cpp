#include "SearchTree.h"
#include <cmath>


using namespace std;

//constructor for SearchTree object
SearchTree::SearchTree()
{
    head = NULL;
}

//deconstructor for SearchTree object
SearchTree::~SearchTree()
{
}

//function for printing BST in descending order of value
void SearchTree::printTree(){
    //empty tree case
    if(this->head == NULL){
        cout << "Cannot print because tree is empty" << endl;
        return;
    }
    //printing tree recursively
    printTree(this->head->right_child);
    cout << this->head->data << endl;
    printTree(this->head->left_child);
}

//overloaded BST print function
void SearchTree::printTree(Node *root){
    if(root == NULL){
        return;
    }
    printTree(root->right_child);
    cout << root->data << endl;
    printTree(root->left_child);
}

//function for inserting a node
void SearchTree::insertNode(int number){
    //empty tree case
    if(this->head == NULL){
        this->head = new Node;
        this->head->data = number;
        this->head->left_child = NULL;
        this->head->right_child = NULL;
    }
    //recursive call
    else{
        insertNode(this->head, number);
    }
}

//overloaded insert function
void SearchTree::insertNode(Node *root, int number){
    if(number < root->data){
        if(root->left_child == NULL){
            root->left_child = new Node;
            root->left_child->data = number;
            root->left_child->left_child = NULL;
            root->left_child->right_child = NULL;
        }
        else{
            insertNode(root->left_child, number);
        }
    }
    else if(number > root->data){
        if(root->right_child == NULL){
            root->right_child = new Node;
            root->right_child->data = number;
            root->right_child->left_child = NULL;
            root->right_child->right_child = NULL;
        }
        else{
            insertNode(root->right_child, number);
        }
    }
}

//function for finding node containing a certain value
void SearchTree::findKey(int number){
    //empty tree case
    if(this->head == NULL){
        cout << "Not found because tree is empty" << endl;
        return;
    }
    //recursive call
    else{
        findKey(this->head, number);
    }
}

//overloaded findKey function
void SearchTree::findKey(Node* root, int number){
    if(root->data == number){
        cout << "Key found at " << root << endl;
        return;
    }
    else if(root->data > number){
        if(root->left_child == NULL){
            cout << "Not found" << endl;
            return;
        }
        else
            findKey(root->left_child, number);
    }
    else if(root->data < number){
        if(root->right_child == NULL){
            cout << "Not found" << endl;
            return;
        }
        else
            findKey(root->right_child, number);
    }
}

//function for deleting a specified node
void SearchTree::deleteNode(int number){
    //empty tree case
    if(this->head == NULL){
        cout << "Cannot delete because tree is empty" << endl;
        return;
    }
    //recursive call
    else{
        deleteNode(this->head, this->head, number);
    }
}

//overloaded delete function
void SearchTree::deleteNode(Node *root, Node *parent, int number){
    if(root->data > number){
        deleteNode(root->left_child, root, number);
    }
    else if(root->data < number){
        deleteNode(root->right_child, root, number);
    }
    else if(root->data == number){
        //node is a leaf node
        if(root->left_child == NULL && root -> right_child == NULL){
            if(root->data <= parent->data) {
                parent->left_child = NULL;
            }
            else {
                parent->right_child = NULL;
            }
            delete root;
            root = NULL;
            return;
        }
        //node has one child
        else if(root->left_child == NULL || root->right_child == NULL){
            //node has only a right child
            if(root->left_child == NULL){
                Node *temp = root;
                root = root->right_child;
                if(temp->data < parent->data) {
                    parent->left_child = root;
                }
                else {
                    parent->right_child = root;
                }
                delete temp;
                temp = NULL;
                return;
            }
            //node has only a left child
            else{
                Node *temp = root;
                root = root->left_child;
                if(temp->data < parent->data) {
                    parent->left_child = root;
                }
                else {
                    parent->right_child = root;
                }
                delete temp;
                temp = NULL;
                return;
            }
        }
        //case where node has two children
        else{
            Node *temp = root->left_child;
            while(temp->right_child != NULL){
                temp = temp->right_child;
            }
            root->data = temp->data;
            deleteNode(root->left_child, root, temp->data);
            return;
        }
    }
}

//function for finding the depth of a particular node
int SearchTree::findDepth(int number){
    //empty tree
    if(this->head == NULL){
        return -1;
    }
    //node is root
    else if(this->head->data == number)
        return 0;
    //recursive call
    else{
        return findDepth(this->head, number);
    }
}

//overloaded findDepth function
int SearchTree::findDepth(Node* root, int number){
    if(root->data == number){
        return 0;
    }
    else if(root->data > number){
        if(root->left_child == NULL){
            return -1;
        }
        else{
            int previous = findDepth(root->left_child, number);
            if(previous == -1){
                return -1;
            }
            else{
                return 1 + previous;
            }
        }
    }
    else if(root->data < number){
        if(root->right_child == NULL){
            return -1;
        }
        else{
            int previous = findDepth(root->right_child, number);
            if(previous == -1){
                return -1;
            }
            else{
                return 1 + previous;
            }
        }
    }
    return -1;
}

//calculating cost of most "expensive" path from the root to a leaf node
int SearchTree::cost(){
    //empty tree case
    if(this->head == NULL){
        cout << "Cost is not applicable because tree is empty" << endl;
        return 0;
    }
    //recursive call
    else{
        return cost(this->head);
    }
    return 0;
}

//overloaded cost function
int SearchTree::cost(Node* root){
    if(root->right_child == NULL && root->left_child == NULL){
        return root->data;
    }
    else{
        int l;
        int r;

        if(root->left_child != NULL){
            l = cost(root->left_child);
        }
        else if(root->left_child == NULL){
            l = 0;
        }

        if(root->right_child != NULL){
            r = cost(root->right_child);
        }
        else if(root->right_child == NULL){
            r = 0;
        }

        return root->data + max(l,r);
    }
    return 0;
}

//function to determine height of a tree
int SearchTree::height(Node* root){
    //leaf node case
    if(root->left_child == NULL && root->right_child == NULL){
        return 0;
    }
    //node has two children
    else if(root->left_child != NULL && root->right_child != NULL){
        return 1 + max(height(root->left_child), height(root->right_child));
    }
    //node has only left child
    else if(root->left_child != NULL){
        return 1 + height(root->left_child);
    }
    //node has only right child
    else
        return 1 + height(root->right_child);
}

//function to determine if tree is balanced
bool SearchTree::isBalanced(){
    //empty tree case
    if(this->head == NULL){
        return true;
    }
    //recursive call
    else{
        return isBalanced(this->head);
    }
}

//overloaded isBalanced function
bool SearchTree::isBalanced(Node *root){
    //node is leaf node
    if(root->left_child == NULL && root->right_child == NULL)
        return true;
    //node has only right child
    else if(root->left_child == NULL){
        if(height(root->right_child) == 0)
            return true;
    }
    //node has only a left child
    else if(root->right_child == NULL){
        if(height(root->left_child) == 0)
            return true;
    }
    //node has two children
    else if(abs(height(root->left_child) - height(root->right_child)) <= 1){
        if(isBalanced(root->left_child) && isBalanced(root->right_child)){
            return true;
        }
    }
    //tree is unbalanced
    return false;
}
