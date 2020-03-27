//Kostiantyn Makrasnov
//Stack Linked List Implementation w/ generaics

#include <iostream>
#include "Stack.h"

int main()
{
    //INTEGERS
    std::cout << "Integers: " << std::endl;
    Stack<int> myStackInt;
    myStackInt.push(1);
    myStackInt.push(2);
    myStackInt.push(3);
    myStackInt.push(4);
    myStackInt.push(5);

    if(!myStackInt.isEmpty())
        std::cout << "Top of Stack at start: " << *(myStackInt.peek()) << std::endl;

    myStackInt.pop();
    myStackInt.pop();
    myStackInt.pop();

    if (!myStackInt.isEmpty())
        std::cout << "Top of Stack after three pops: " << *(myStackInt.peek()) << std::endl << std::endl;



    //CHARACTERS
    std::cout << "Characters: " << std::endl;
    Stack<char> myStackChar;
    myStackChar.push('a');
    myStackChar.push('b');
    myStackChar.push('c');
    myStackChar.push('d');
    myStackChar.push('e');

    if (!myStackChar.isEmpty())
        std::cout << "Top of Stack at start: " << *(myStackChar.peek()) << std::endl;

    myStackChar.pop();
    myStackChar.pop();
    myStackChar.pop();

    if (!myStackChar.isEmpty())
        std::cout << "Top of Stack after three pops: " << *(myStackChar.peek()) << std::endl;
}
