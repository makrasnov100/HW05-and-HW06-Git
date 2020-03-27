#include "BinaryTree.h"


//[CONSTRUCTORS]
BinaryTree::BinaryTree(int* values, int length)
{
	//Create binary tree structure (initialized to 0)
	root = new tree_node(length-1);

	//Populate the tree with initial values (TODO: improve)
	root->value = values[0];
	root->left->value = values[1];
	root->right->value = values[2];
	root->left->left->value = values[3];
	root->left->right->value = values[4];
	root->right->left->value = values[5];
	root->right->right->value = values[6];
}

//[ITERATION FUNCTIONS]
//Returns the starting node
tree_node BinaryTree::begin()
{	
	if (!root)
	{
		//TODO: HAndle no nodes
	}

	root->beginIteration();
	return *root;
}

//Returns the last node in the string
tree_node BinaryTree::end()
{
	return *(root->getRightmostLeaf());
}

//int BinaryTree::operator*()
//{
//	return root->iterator->value;
//}
