

/* Main application for the bionary search tree program. */

#include "TreeNode.h"
#include "BinSTree.h"
#include<iostream>
#include<string>

using namespace std;

int main(){

   BinSTree<string> b {};			// binary search tree of animals


	b.insert ("kangaroo");			// insert animals in this order
	b.insert ("mouse");	
	b.insert ("tick");  
	b.insert ("raccoon");
	b.insert ("walrus");	
	b.insert ("crocodile");	
	b.insert ("emu");

	

	cout << "Enter the name of the Animal: ";



    return 0;
}