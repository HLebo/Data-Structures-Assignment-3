#include <iostream>
#include "SearchTree.h"

using namespace std;

int main()
{
    SearchTree test;
    test.insertNode(19);
    test.insertNode(16);
    //test.insertNode(22);
    cout << test.cost() << endl;
    //test.insertNode(17);
    test.insertNode(14);
    /*test.insertNode(24);
    test.insertNode(20);
    test.insertNode(9);
    test.insertNode(10);
    */
    test.printTree();
    cout << endl;
    //test.deleteNode(16);
    //test.printTree();

    if(test.isBalanced())
        cout << "Is balanced" << endl;
    else
        cout << "Is not balanced" << endl;

    /*test.findKey(9);
    test.findKey(16);
    cout << test.findDepth(19) << endl;
    cout << test.findDepth(22) << endl;
    cout << test.findDepth(24) << endl;
    cout << "finding depth when value is not in tree: " << test.findDepth(7) << endl;

    cout << test.cost() << endl;

    test.insertNode(9);
    test.printTree();
    cout << test.cost() << endl;

    test.insertNode(15);
    test.printTree();
    cout << test.cost() << endl;

    test.insertNode(10);
    test.printTree();
    cout << test.cost() << endl;
    */

    return 0;
}
