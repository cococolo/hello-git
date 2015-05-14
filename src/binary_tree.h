#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H
#include "debug.h"
#include <fstream>

using namespace std;

template<typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree() : root(NULL)
	{
		debug("BinarySearchTree constructer");
	}
	BinarySearchTree(const BinarySearchTree & rhs);
	~BinarySearchTree( )
	{
		makeEmpty();
		debug("BinarySearchTree desconstructor");
	}


	const Comparable & findMin() const
	{
		return findMin(root)->element;
	}
	const Comparable & findMax() const
	{
		return findMax(root)->element;
	}

	bool contains(const Comparable & x) const
	{
		return contains(x, root);
	}

	bool isEmpty() const
	{
		return (root == NULL) ? true :false;
	}
	void printTree() const
	{
		debug("print tree");
		printNode(root);
	}
	void makeEmpty()
	{
		makeEmpty(root);
	}
	void insert(const Comparable & x)
	{
		insert(x, root);
	}
	void remove(const Comparable & x)
	{
		remove(x, root);
	}
	BinarySearchTree & operator=( const BinarySearchTree & rhs );

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
		: element(theElement), left(lt), right(rt)
		{
			//debug("BinaryNode constructer!");
		}

	};

	BinaryNode *root;

	//use * &t, can not use *t, new will have no effect
	void insert( const Comparable & x, BinaryNode * &t)
	{
		if(t == NULL)
		{
			t = new BinaryNode(x, NULL, NULL);
		}
		else if(x <= t->element)
		{
			insert(x, t->left);
		}
		else if(x > t->element)
		{
			insert(x, t->right);
		}
	}
	void remove(const Comparable & x, BinaryNode * &t)
	{
		if(t == NULL)
		{
			return;
		}

		if(x <= t->element)
		{
			remove(x, t->left);
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
		}
	}
	BinaryNode * findMin( BinaryNode *t ) const
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
	BinaryNode * findMax( BinaryNode *t ) const
	{
		if(t == NULL)
		{
			return NULL;
		}

		if(t->right == NULL)
		{
			return t;
		}
		return findMax(t->right);
	}
	bool contains( const Comparable & x, BinaryNode *t ) const
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
		else
		{
			return true;
		}
	}
	void makeEmpty( BinaryNode *t)
	{
		if(t != NULL)
		{
			printf("%d ", t->element);
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = NULL;
	}
	void printTree( BinaryNode *t, ostream & out ) const;
	BinaryNode * clone( BinaryNode *t ) const;



	void printNode(BinaryNode *t) const
	{
		if(t == NULL)
		{
			return;
		}
		printf("%d ", t->element);

		if(t->left != NULL)
		{
			printNode(t->left);
		}

		if(t->right != NULL)
		{
			printNode(t->right);
		}
	}
};



#endif
