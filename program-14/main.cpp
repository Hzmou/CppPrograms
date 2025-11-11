

/* Main application for the bionary search tree program. */

#include "TreeNode.h"
#include "BinSTree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    BinSTree<string> bst1{}; // creating our own BST

    string input;

    bst1.insert("Integrals");
    bst1.insert("Derivatives");
    bst1.insert("Partial derivatives");
    bst1.insert("Tensors");
    bst1.insert("Transformers");
    bst1.insert("Manifolds");
    bst1.insert("Laplace Transform");

    cout << "Enter a Calculus tool (q to quit): " << endl;
    getline(cin, input);

    vector<string> path;
    vector<string> children;

    while (input != "q")
    {

        cout << "Path: " << endl;

        path = bst1.path(input);

        for (int i = 0; i < path.size(); ++i)
        {
            cout << path[i] << endl;
        }

        children = bst1.children(input);

        cout << "Children: " << endl;

        for (int i = 0; i < children.size(); ++i)
        {

            cout << children[i] << endl;
        }

        cout << "Enter a Calculus tool (q to quit): " << endl;
        getline(cin, input);
    }
}