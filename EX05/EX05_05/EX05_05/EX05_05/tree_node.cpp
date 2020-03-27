#include "tree_node.h"
#include <iostream>

//[CONSTRUCTOR]
//remaining: the amount of children this node need to have
tree_node::tree_node(int remaining)
{
	value = 1;

	//Adding more nodes to the tree
	if (remaining == 1)
	{
		left = new tree_node(0);
		right = nullptr;
	}
	else if (remaining != 0)
	{
		int leftRemain = remaining - (remaining / 2);
		int rightRemain = remaining - leftRemain;
		left = new tree_node(leftRemain - 1);
		right = new tree_node(rightRemain - 1);
	}

	if (remaining == 0)
	{
		left = nullptr;
		right = nullptr;
	}
}

//[HELPER]
//returns the last element of the binary tree recursively
tree_node* tree_node::getRightmostLeaf()
{
	if (right)
	{
		return right->getRightmostLeaf();
	}
	else if (left)
	{
		return left->getRightmostLeaf();
	}
	else
	{
		return this;
	}
}

void tree_node::beginIteration()
{
	iterator = this;
	if (right)
	{
		preOrderServer.push(right);
	}
	if (left)
	{
		preOrderServer.push(left);
	}
}

bool tree_node::operator!= (const tree_node& other)
{
	//TODO properly check if identical nodes
	//TODO allow for last node to also be shown
	return iterator->value != other.value;
}

tree_node& tree_node::operator++()
{
	if (preOrderServer.empty())
	{
		return *iterator;
	}

	iterator = preOrderServer.top();
	preOrderServer.pop();

	if (iterator->right)
	{
		preOrderServer.push(iterator->right);
	}
	
	if (iterator->left)
	{
		preOrderServer.push(iterator->left);
	}

	return *iterator;
}

int tree_node::operator*()
{
	return (*iterator).value;
}