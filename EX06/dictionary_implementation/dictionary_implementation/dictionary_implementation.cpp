//[DESCRIPTION]
//Author: Kostiantyn Makrasnov

#include <iostream>
#include "Dictionary.h"

int main()
{
	//mapping players on feild with their emotions?
	Dictionary<std::string> myDictionary(50); //Dictionary with 50 buckets
	myDictionary.insert(1, "happy");
	myDictionary.insert(51, "happy");
	myDictionary.insert(3, "unhappy");
	myDictionary.insert(4, "sad");
	myDictionary.insert(5, "angry");
	myDictionary.insert(6, "excited");
	myDictionary.insert(56, "fluttered");

	//testing empty
	if (!myDictionary.isEmpty())
	{
		std::cout << "Dictionary is NOT EMPTY" << std::endl;
	}
	else
		std::cout << "Disctionary is EMPTY" << std::endl;

	//testing size property
	std::cout << "Dictionary has " << myDictionary.size() << " items" << std::endl;

	//testing presence (included for readability)
	if (myDictionary.exists(51))
	{
		std::cout << "Dictionary DOES have the key 51" << std::endl;
	}
	else
	{
		std::cout << "Dictionary DOESN'T have the key 51" << std::endl;
	}

	//testing lookup
	std::string* emotion = myDictionary[51];
	if(emotion)
		std::cout << "Emoption of player 51 stored as: " << *emotion << std::endl;


	//testing removal
	myDictionary.remove(51);
	std::cout << "Removed player 51's emotion from dictionary" << std::endl;
	if (myDictionary.exists(51))
	{
		std::cout << "Dictionary DOES have the key 51" << std::endl;
	}
	else
	{
		std::cout << "Dictionary DOESN'T have the key 51" << std::endl;
	}

	return 0;
}