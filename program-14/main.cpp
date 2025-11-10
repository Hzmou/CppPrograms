

/* Main application for the bionary search tree program. */

#include "TreeNode.h"
#include "BinSTree.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

	BinSTree<string> b{}; // binary search tree of animals
	string animalName;

	b.insert("kangaroo"); // insert animals in this order
	b.insert("mouse");
	b.insert("tick");
	b.insert("raccoon");
	b.insert("walrus");
	b.insert("crocodile");
	b.insert("emu");

	cout << "Enter the name of the Animal (quit to End): ";

	getline(cin, animalName);

	 while (animalName != "quit")
    {

        cout << "Path:" << endl;
        vector<string> pathResult = b.path(animalName);
        for (const string& animal : pathResult)
        {
            cout << animal << endl;
        }

        cout << endl << "Children:" << endl;
        vector<string> childrenResult = b.children(animalName);
        for (const string& animal : childrenResult)
        {
            cout << animal << endl;
        }

        cout << endl << "Enter the name of the Animal (quit to End): ";
        getline(cin, animalName);
    }

    return 0;
}