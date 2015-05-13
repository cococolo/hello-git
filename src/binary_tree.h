#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H
#include "debug.h"
#include <fstream>

using namespace std;

template <typename CompareValue>
class binary_tree
{
public:
    binary_tree();
    binary_tree(const binary_tree & rhs);
    ~binary_tree();

    const CompareValue & findMin() const
    {

    }

    const CompareValue & findMax() const
    {

    }

    bool contains(const CompareValue & x) const
    {

    }

    bool isEmpty() const
    {

    }

    void makeEmpty()
    {

    }

    void insert(const CompareValue & x)
    {

    }

    void remove(CompareValue & x)
    {

    }

    binary_tree & operator=(const binary_tree & rhs)
    {

    }

private:
    struct BinaryNode
    {
        CompareValue *element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(CompareValue & x, BinaryNode *ltree, BinaryNode *rtree)
        : element(x), left(ltree), right(rtree)
        {}
    };

    BinaryNode *root;

    void insert(const CompareValue & x, BinaryNode * & t)
    {

    }

    void remove(const CompareValue & x, BinaryNode * & t)
    {

    }

    BinaryNode * findMin(BinaryNode *t) const
    {

    }

    BinaryNode * findMax(BinaryNode *t) const
    {

    }

    bool contains(const CompareValue & x, BinaryNode *t) const
    {

    }

    void makeEmpty(BinaryNode * & t)
    {

    }

    void printTree(BinaryNode *t, ostream & out) const
    {

    }

    BinaryNode * clone(BinaryNode *t) const
    {

    }
};





#endif
