#pragma once

//[REFERENCES]
//1) refresher: https://www.geeksforgeeks.org/priority-queue-set-1-introduction/
//2) heapify instructions: https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
//3) copy assignment: https://en.cppreference.com/w/cpp/language/copy_assignment

#include <vector>
#include <iostream>

template<typename G>
class Node {
	G value;

public:
	int priority;
	Node(G value, int priority)
	{
		this->value = value;
		this->priority = priority;
	}

	//Copy assignement
	Node& operator=(const Node& other)
	{
		this->value = other.value;
		this->priority = other.priority;
		return (*this);
	}

	G* getValue()
	{
		return &value;
	}
};


template<typename T>
class PriorityQueue {
	std::vector<Node<T>> nodes;
	int amountNodes;

public:
	PriorityQueue()
	{
		amountNodes = 0;
	}

	//inserts a value into queue
	void insert(T newValue, int priority)
	{
		nodes.push_back(Node<T>(newValue, priority));
		amountNodes++;
		heapifyUp(amountNodes-1);
	}

	//removes highest priority node value
	void pop()
	{
		if (isEmpty())
			return;

		//first element gets replaced by the last element
		if(amountNodes > 1)
			nodes[0] = nodes[amountNodes - 1];

		nodes.pop_back();
		amountNodes--;
		heapifyDown(0);
	}

	void heapifyUp(int nodeIdx)
	{
		//Check invalid index
		if (nodeIdx >= amountNodes || nodeIdx == 0)
			return;

		//Get parent index
		int parent = (nodeIdx - 1) / 2;

		//Check if parent priority is higher, swap and repeat if not
		if (nodes[parent].priority < nodes[nodeIdx].priority)
		{
			Node<T> temp = nodes[nodeIdx];
			nodes[nodeIdx] = nodes[parent];
			nodes[parent] = temp;
			heapifyUp(parent);
		}
	}

	void heapifyDown(int nodeIdx)
	{
		//Check invalid index
		if (nodeIdx >= amountNodes)
			return;

		//Get child indexes
		int mostImportant = nodeIdx; //root at start
		int left = 2 * nodeIdx + 1;
		int right = 2 * nodeIdx + 2;

		//Check left child value to be lower
		if (left < amountNodes && nodes[mostImportant].priority < nodes[left].priority)
		{
			mostImportant = left;
		}
		//Check left child value to be lower
		if (right < amountNodes && nodes[mostImportant].priority < nodes[right].priority)
		{
			mostImportant = right;
		}

		//heapify further if root doesnt already have the highst priority
		if (nodeIdx != mostImportant)
		{
			Node<T> temp = nodes[nodeIdx];
			nodes[nodeIdx] = nodes[mostImportant];
			nodes[mostImportant] = temp;
			heapifyDown(mostImportant);
		}
	}

	//returns the highest priority node value
	T* peek()
	{
		if (nodes.size() != 0)
			return nodes[0].getValue();
		else
			return nullptr;
	}
	//returns TRUE if no items in queue
	bool isEmpty()
	{
		if (amountNodes == 0)
			return true;
		else
			return false;
	}

	//DEBUG
	void printTree()
	{
		for (int i = 0; i < amountNodes; i++)
		{
			std::cout << nodes[i].priority << ", ";
		}
		std::cout << std::endl;
	}
};