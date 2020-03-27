#pragma once

#include "tree_node.h";


class BinaryTree {

public:

	tree_node* root;

	//[CONSTRUCTORS]
	BinaryTree(int* values, int length);

	//[ITERATION FUNCTIONS]
	tree_node begin();
	tree_node end();
	//int operator*();
};