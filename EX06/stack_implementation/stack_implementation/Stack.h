#pragma once
template<typename T>
class Node {
private:
	T value;
public:
	Node* next;
	Node(T value, Node* next)
	{
		this->value = value;
		this->next = next;
	}

	T* getValue()
	{
		return &value;
	}
};

template<typename G>
class Stack {
private:
	Node<G>* top;
public:
	Stack()
	{
		top = nullptr;
	}

	void push(G newValue)
	{
		top = new Node<G>(newValue, top);
	}

	void pop()
	{
		Node<G>* temp = top->next;
		delete top;
		top = temp;
	}

	G* peek()
	{
		if (top)
		{
			return top->getValue();
		}
		else
		{
			return nullptr;
		}
	}

	bool isEmpty()
	{
		if (top)
			return false;
		else
			return true;
	}
};