#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue
{
public:
    Queue(int);
    //~Queue(){};
    //circular queue methods
    bool enqueue(std::string word);
    std::string dequeue();
    void printQueue(); 
    bool queueIsFull(); 
    bool queueIsEmpty(); 
    
protected:
private:
    int queueSize;
    int queueHead;
    int queueTail;
    int queueCount;
    std::string *wordQueue;
};

#endif // QUEUE_H