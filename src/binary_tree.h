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
    binary_tree(const binary_tree & rhs)
        : root(NULL)
    {
        root = clone(rhs.root);
    }
    ~binary_tree();

    const CompareValue & findMin() const
    {

    }

    const CompareValue & findMax() const
    {

    }

    bool contains(const CompareValue & x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const
    {

    }

    void makeEmpty()
    {

    }

    void insert(const CompareValue & x)
    {
        insert(x, root);
    }

    void remove(CompareValue & x)
    {
        remove(x, root);
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
        if(t == NULL)
        {
            t = new BinaryNode(x, NULL, NULL);
        }
        else if(x < t->element)
        {
            insert(x, t->left);
        }
        else if(x > t->element)
        {
            insert(x, t->right);
        }
    }

    void remove(const CompareValue & x, BinaryNode * & t)
    {
        if(t == NULL)
        {
            return;
        }
        if(x < t->element)
        {
            remove(x, t->left);
        }
        else if(x > t->element)
        {
            remove(x, t->right);
        }
        else if(t->left != NULL && t->right != NULL)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete oldNode;
        }
    }

    BinaryNode * findMin(BinaryNode *t) const
    {
        if(t == NULL)
        {
            return NULL;
        }
        if(t->left == NULL)
        {
            return t;
        }
        return findMin(t->left);
    }

    BinaryNode * findMax(BinaryNode *t) const
    {
        if(t != NULL)
        {
            while(t->right != NULL)
            {
                t = t->right;
            }
        }
        return t;
    }

    bool contains(const CompareValue & x, BinaryNode *t) const
    {
        if(t == NULL)
        {
            return false;
        }
        else if(x < t->element)
        {
            return contains(x, t->left);
        }
        else if(x > t->element)
        {
            return contains(x, t->right);
        }
    }

    void makeEmpty(BinaryNode * & t)
    {
        if(t != NULL)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = NULL;
    }

    void printTree(BinaryNode *t, ostream & out) const
    {

    }

    BinaryNode * clone(BinaryNode *t) const
    {
        if(t == NULL)
        {
            return NULL;
        }
        else
        {
            return new BinaryNode(t->element, clone(t->left), clone(t->right));
        }
    }
};





#endif
