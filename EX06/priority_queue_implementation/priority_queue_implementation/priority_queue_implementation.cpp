//[DESCRIPTION]
//Author: Kostiantyn Makrasnov


#include <iostream>
#include <string>
#include "PriorityQueue.h" 

int main()
{
    PriorityQueue<std::string> myQueue;
    myQueue.insert(std::string("not very important"), 3);
    myQueue.insert(std::string("extremely important"), 120);
    myQueue.insert(std::string("midiocore importancy"), 60);
    myQueue.insert(std::string("something I dont care about"), 1);
    myQueue.insert(std::string("pretty important"), 80);
    myQueue.insert(std::string("something I have to do RIGHT NOW"), 1000);

    while (!myQueue.isEmpty())
    {
        std::cout << (*myQueue.peek()) << std::endl;
        myQueue.pop();
    }

    return 0;
}
