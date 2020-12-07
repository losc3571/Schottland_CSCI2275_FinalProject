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
    void printQueue(); //prints queue but mostly for debugging not used in actual program
    bool queueIsFull(); 
    bool queueIsEmpty();
    void printCurrentlyQueuedWords(); //prints words awaiting in queue in program
    
protected:
private:
    int queueSize;
    int queueHead;
    int queueTail;
    int queueCount;
    std::string *wordQueue;
};

#endif // QUEUE_H