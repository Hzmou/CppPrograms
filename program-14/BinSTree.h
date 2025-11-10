#pragma once
#include "TreeNode.h"
#include <vector>

using namespace std;

template <typename T>
class BinSTree // ==, <, > are defined on T
{
public:
	BinSTree();								 // empty tree is created
	bool empty() const;						 // return true if tree has no nodes
	void insert(T item);					 // item inserted into bst
	bool contains(T item) const;			 // return true if item is in tree
	std::vector<T> path(T target) const;	 // return vector of data from path root to target
	std::vector<T> children(T target) const; // return vector of children of target

private:
	TreeNode<T> *root; // root of tree
};

// return vector of data from path root to target
// the vector is empty if target is not found
template <typename T>
std::vector<T> BinSTree<T>::path(T target) const
{
	// traverse the tree and then return a vector from root to current node.

	vector<T> result;
	TreeNode<T> *current = root; // current node which is root.

	// traversing the BST:

	while (current != nullptr)
	{

		result.push_back(current->getItem());

		// found target, return the path.
		if (target == current->getItem())
		{
			return result;
		}
		else if (target < current->getItem())
		{

			// search left:

			current = current->getLeft();
		}
		else
		{

			// search right:
			current = current->getRight();
		}
	}

	// Traget not found, return an empty path vector.

	result.clear();
	return result;
}

// return vector of children of target
// the vector is empty if there are no children
template <typename T>
std::vector<T> BinSTree<T>::children(T target) const
{
    vector<T> thechildren{}; // vector of child data of target

    TreeNode<T> *current = root;

    while (current != nullptr)
    {
        if (target == current->getItem())
        {
            // found target, collect children beneath that target.

            if (current->getLeft() != nullptr)
            {
                thechildren.push_back(current->getLeft()->getItem());
            }

            if (current->getRight() != nullptr)
            {
                thechildren.push_back(current->getRight()->getItem());
            }

            return thechildren;
        }
        else if (target < current->getItem())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }
    
    return thechildren; // return empty vector if target not found
}
// empty tree is created
template <typename T>
BinSTree<T>::BinSTree()
{
	root = nullptr;
}

// return true if tree has no nodes
template <typename T>
bool BinSTree<T>::empty() const
{
	return root == nullptr;
}

// return true if item is in tree
template <typename T>
bool BinSTree<T>::contains(T item) const
{
	TreeNode<T> *ptr = root; // start search at root
	bool found = false;
	while (!found && ptr != nullptr) // while not found and more nodes...
	{
		if (item == ptr->getItem()) // found item
			found = true;
		else if (item < ptr->getItem()) // advance to left child
			ptr = ptr->getLeft();
		else
			ptr = ptr->getRight(); // advance to right child
	}
	return found;
}

// item inserted into bst
template <typename T>
void BinSTree<T>::insert(T item)
{
	if (root == nullptr) // make root node on empty tree
		root = new TreeNode<T>(item);
	else // insert into non-empty tree
	{
		TreeNode<T> *ptr = root;
		bool done = false; // loop until correct insertion location
		while (!done)
		{
			if (item == ptr->getItem()) // done if duplicate found, no insertion
				done = true;
			else if (item < ptr->getItem()) // search for insert location in left subtree
			{
				if (ptr->getLeft() == nullptr) // insert entry as left child of a leaf node
				{
					ptr->setLeft(new TreeNode<T>(item));
					done = true;
				}
				else // keep looking left
					ptr = ptr->getLeft();
			}
			else // search for insert location in right subtree
			{
				if (ptr->getRight() == NULL) // insert entry as right child of a leaf node
				{
					ptr->setRight(new TreeNode<T>(item));
					done = true;
				}
				else // keep looking right
					ptr = ptr->getRight();
			}
		}
	}
}
