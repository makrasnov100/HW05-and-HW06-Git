#pragma once

//[REFERENCES]
//hash function for generic types (not used): https://stackoverflow.com/questions/34563574/how-to-build-hash-function-for-various-template-types

#include <vector>

//[NOTES]
//1) Using generics for value type but only intergers for the key making this to be a more simple implementation
//2) Generic type needs to support copy assignment in order to use this datastructure

template<typename T>
class Dictionary {
private:
	std::vector<std::vector<std::pair<int,T>>> table; //table of buckets of values
	int amountItems;
public:
	Dictionary(int bucketAmount)
	{
		//Initialize buckets
		for (int i = 0; i < bucketAmount; i++)
		{
			table.push_back(std::vector<std::pair<int, T>>());
		}
	}

	//returns TRUE if key was found in dictionary
	bool exists(int key)
	{
		int bucketIdx = getHash(key);
		for (int i = 0; i < table[bucketIdx].size(); i++)
		{
			if (table[bucketIdx][i].first == key)
			{
				return true;
			}
		}

		return false;
	}

	//inserts an element into the proper bucket
	void insert(int key, T value)
	{
		if (exists(key))
		{
			//print error/cause exception
			return;
		}

		table[getHash(key)].push_back(std::make_pair(key, value));
		amountItems++;
	}

	//removes an item from the dictionary if its present
	void remove(int key)
	{
		if (isEmpty())
		{
			return;
		}

		if (!exists(key))
		{
			return;
		}

		int bucketIdx = getHash(key);
		for (int i = 0; i < table[bucketIdx].size(); i++)
		{
			if (table[bucketIdx][i].first == key)
			{
				table[bucketIdx][i] = table[bucketIdx][table[bucketIdx].size()-1];
				table[bucketIdx].pop_back();
				amountItems--;
			}
		}
	}

	//returns pointer to entry if found, nullptr if not
	T* operator[](int key)
	{
		int bucketIdx = getHash(key);
		for (int i = 0; i < table[bucketIdx].size(); i++)
		{
			if (table[bucketIdx][i].first == key)
			{
				return &table[bucketIdx][i].second;
			}
		}

		return nullptr;
	}

	//Assumes uniform distribution of values for best performance
	int getHash(int key)
	{
		return key % table.size();
	}

	//Returns TRUE if the dictionary has no items
	bool isEmpty()
	{
		if (amountItems == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int size()
	{
		return amountItems;
	}
};