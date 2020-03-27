//Author: Kostiantyn Makrasnov

//References: 
// 1) (assignment prompt) - Programming languages Textbook
// 2) (traversing order refresher) - https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// 3) (range based for loop implementation example) - https://www.youtube.com/watch?v=A9ouSdcpmX4
// 4) (another range based for loop example) - https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html 

#include <iostream>
#include "BinaryTree.h"

int main()
{
	//HUGE ASSUMTIONS THAT I DID NOT FIX:
	// - there are no repeated values in the binary tree
	// - the binary tree is balanced (not tested)


	//Test Tree Structure
	//	     1
	//	  2      3
	//  4   5  6   7

	//Constructing test binary tree
	int* treeValues = new int[7] {1,2,3,4,5,6,7};
	BinaryTree my_tree(treeValues, 7);

	std::cout << "Pre-order Traversal:" << std::endl;
	for (int n : my_tree)
	{
		std::cout << n << "\n";
	}

	std::cout << my_tree.root->getRightmostLeaf()->value << "\n";
	//work around for my implementation not showing the last node,
	//would have been fixed have if I had the time to implement a 
	//node ID system

	//de allocating tree values
	//delete my_tree;
	delete[] treeValues;

}