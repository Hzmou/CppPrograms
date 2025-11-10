#pragma once
#include <cstddef>

template <typename T> 
class TreeNode
{
public:
	TreeNode (T it, TreeNode<T>* lptr = NULL, TreeNode<T>*rptr = NULL);
	// POST:  object is created with supplied data 

	T getItem( );						// POST: return item
	TreeNode<T> * getLeft ( );			// POST: return address of left child of  object
	TreeNode<T> * getRight ( );			// POST: return address of right child of  object
	void setItem (T it);				// POST: set item field
	void setLeft (TreeNode<T> * ptr);	// POST: set the left child of object
	void setRight (TreeNode<T> * ptr);	// POST: set the right child of object
	bool isLeaf ( );					// POST: return true if node has no children
private:
	T item;					
	TreeNode<T> * left;				// pointer to left child
	TreeNode<T> * right;			// pointer to right child

};

// Implementation of TreeNode class

template <typename T>
TreeNode<T>::TreeNode (T it, TreeNode<T>* lptr, TreeNode<T>*rptr)
// POST:  new object is filled with data
{	item = it;
	left = lptr;
	right = rptr;
}

template <typename T>
T TreeNode<T>::getItem( )						// POST: return item
{	return item;	}

template <typename T>
TreeNode<T> * TreeNode<T>::getLeft ( )			// POST:  return address of left child of  object
{	return left;	}

template <typename T>
TreeNode<T> * TreeNode<T>::getRight ( )			// POST:  return address of right child of  object
{	return right;	}

template <typename T>
void TreeNode<T>::setItem (T it)				// POST: set the item
{	item = it;	}

template <typename T>
void TreeNode<T>::setLeft (TreeNode<T> * ptr)	// POST: set the left child of object
{	left = ptr;	}

template <typename T>
void TreeNode<T>::setRight (TreeNode<T> * ptr)	// POST: set the right child of object
{	right = ptr;	}

template <typename T>
bool TreeNode<T>::isLeaf ()						// POST: return true if node is a leaf node
{
	return (left == 0 && right == 0);
}



