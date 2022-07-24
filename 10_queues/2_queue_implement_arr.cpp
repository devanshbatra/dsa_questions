/*
Queues can implemented using both arrays and linked lists.
implementing with array.
*/

#include<iostream>

using namespace std;

class Queue {
    int * arr;
    int size;
    int qfront;
    int rear;
    
public:
    Queue() {
        //size param not provided so taking some random big size.
        size = 10001;
        arr = new int[size];
        qfront =0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear==qfront) return true;
        else return false;
    }

    void enqueue(int data) {
        
        //check overflow
        if(rear==size) return;
        
        arr[rear] = data;
        rear++;
        
        
    }

    int dequeue() {
        if(rear==qfront) return -1;
        int temp = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        //IMPORTANT POINT - now since the front has come ahead - it wastes that space so try to always reset the queue
        //when it is empty
        //now if after popping our queue it becomes empty, then reset.
        if(qfront==rear) {
            qfront =0;
            rear=0;
        }
        
        
        return temp;
    }

    int front() {
        // Implement the front() function
        if(rear==qfront) return -1;
        
        return arr[qfront];
    }
};

//TC: O(1).