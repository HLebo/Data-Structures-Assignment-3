#ifndef SEARCHTREE_H
#define SEARCHTREE_H


struct Node{
    int data;
    Node *left_child;
    Node *right_child;
};

class SearchTree
{
    public:
        SearchTree();
        virtual ~SearchTree();

    protected:

    private:
};

#endif // SEARCHTREE_H
