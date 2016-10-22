#include <iostream>
#include "SearchTree.h"

using namespace std;

int main()
{
    //constructing tree
    SearchTree test;

    //printing an empty tree
    cout << "The tree's values are: " << endl;
    test.printTree();
    cout << endl << endl;

    //searching for a key in an empty tree
    cout << "Searching for the value 20: ";
    test.findKey(20);
    cout << endl << endl;

    //deleting a node from an empty tree
    cout << "Deleting the node with value 35";
    test.deleteNode(35);
    cout << endl << endl;

    //finding depth of a node in an empty tree
    cout << "The depth of the node with value 40: " << test.findDepth(40) << endl << endl;

    //finding cost of an empty tree
    cout << "The most expensive path in the tree is: " << test.cost() << endl << endl;

    //determining if an empty tree is balanced
    if(test.isBalanced())
        cout << "Is balanced" << endl << endl;
    else
        cout << "Is not balanced" << endl << endl;

    //building tree by adding values
    test.insertNode(19);
    test.insertNode(16);
    test.insertNode(22);

    //printing tree so far
    cout << "The tree is: " << endl;
    test.printTree();
    cout << endl << endl;

    //cost of tree, which is 41
    cout << "The cost of the tree is: " << test.cost() << endl << endl;

    //inserting more nodes into tree
    test.insertNode(17);
    test.insertNode(14);
    test.insertNode(24);
    test.insertNode(20);
    test.insertNode(9);
    test.insertNode(10);

    //printing tree so far
    cout << "The tree is: " << endl;
    test.printTree();
    cout << endl << endl;

    //cost of tree, which is 68
    cout << "The cost of the tree is: " << test.cost() << endl << endl;

    //tree is unbalanced
    if(test.isBalanced())
        cout << "Is balanced" << endl << endl;
    else
        cout << "Is not balanced" << endl << endl;

    //deleting node 16
    test.deleteNode(16);

    //printing tree so far
    cout << "After deleting 16, the tree is: " << endl;
    test.printTree();
    cout << endl << endl;

    //the tree is balanced
    if(test.isBalanced())
        cout << "Is balanced" << endl << endl;
    else
        cout << "Is not balanced" << endl << endl;

    //finding node 9
    test.findKey(9);

    //searching for a node that does not exist in tree
    test.findKey(16);

    cout << endl;

    //finding depth of node 19, which is 0
    cout << "The depth of node 19 is: " << test.findDepth(19) << endl;

    //finding depth of node 22, which is 1
    cout << "The depth of node 22 is: " << test.findDepth(22) << endl;

    //finding depth of node 24, which is 2
    cout << "The depth of node 24 is: " << test.findDepth(24) << endl;

    //finding depth of node 7, which is -1 since node is not in tree
    cout << "Finding depth when value is not in tree: " << test.findDepth(7) << endl;

    cout << endl;

    //deleting node 10
    test.deleteNode(10);

    //printing tree so far
    cout << "After deleting 10, the tree is: " << endl;
    test.printTree();
    cout << endl << endl;

    //cost of tree, which is 65
    cout << "The cost of the tree is: " << test.cost() << endl << endl;

    return 0;
}
