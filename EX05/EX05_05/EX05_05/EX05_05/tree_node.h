#pragma once

#include <stack>;

class tree_node {

public:
	tree_node* left;
	tree_node* right;
	int value;

	tree_node* iterator;
	std::stack<tree_node*> preOrderServer;

	//[CONSTRUCTORS]
	tree_node(int remaining);	 //normal tree node

	//[HELPER]
	tree_node* getRightmostLeaf();
	void beginIteration();

	//[OP OVERLOADS]
	bool operator!= (const tree_node& other);
	tree_node& operator++();
	int operator*();
};