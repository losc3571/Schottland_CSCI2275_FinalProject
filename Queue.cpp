#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

Queue::Queue(int n){
    wordQueue = new string[n];
    queueSize = n;
    queueTail = 0;
    queueHead = -1;
    queueCount = 0;
}

bool Queue::enqueue(string word) {
    //queue full 
    if((queueHead == 0 && queueTail == queueSize-1) || (queueTail == (queueHead-1)%(queueSize-1))){
        //cout << "full" << endl;
        return false;
    }
    else if (queueHead == -1){
        queueHead = 0;
        queueTail = 0; 
        wordQueue[queueTail] = word;
        queueCount++;
        return true;
    }
    else if (queueTail == queueSize-1 && queueHead != 0){
        queueTail = 0; 
        wordQueue[queueTail] = word;
        queueCount++;
        return true;
    }

    else{
        queueTail++;
        wordQueue[queueTail] = word;
        queueCount++;
        return true ;
    }
}

string Queue::dequeue() {
    if(queueHead == -1){
        cout << "Queue is Empty" << endl;
        return "";
    }
    string toRet = wordQueue[queueHead];
    if (queueHead == queueSize-1){
        queueHead = 0; 
    }
    else if(queueHead == queueTail){
        queueHead = queueTail = -1; 
    }
    else{
        queueHead++;
    }
    queueCount--;
    return toRet;
}

bool Queue::queueIsFull() {
    return queueCount == queueSize;
}

bool Queue::queueIsEmpty() {
    return queueCount == 0;
}

void Queue::printQueue() {
    if (queueHead == -1) {
        cout << "Queue empty" << endl;
        return;
    }

    //cout << "\nPrinting (circular) queue: " << endl;
    if (queueTail >= queueHead) {
        for (int i = queueHead; i <= queueTail; i++) {
            cout << "q[" << i << "]: " << wordQueue[i] <<endl;
        }
    } else {
        for (int i = queueHead; i < queueSize; i++) {
            cout << "q[" << i << "]: " << wordQueue[i] <<endl;
        }
        for (int i = 0; i <= queueTail; i++) {
            cout << "q[" << i << "]: " << wordQueue[i] <<endl;
        }
    }
    cout << endl;
}