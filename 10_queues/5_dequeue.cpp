#include<iostream>
using namespace std;

/*
Deque: deque is a type of queue which is a combination of stack and queue both as we can push at front and back
        as well as pop at front and back.
        deque is used extensively in OS.

        Implementation of deque.
*/

class Deque
{
public:
    // Initialize your data structure.
    int * arr;
    int front;
    int rear;
    int size;
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front= -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //checking for overflow
        if(isFull() ){
            return false;
        }
        else if(front==-1)//empty condition
        {
            front=0;
            rear = 0;
        }else if(front==0){//cyclic condition
            front=size-1;
        }else{//normal condition
            front--;
        }
        
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        //checking for overflow
        if(isFull()){
            return false;
        }
        else if(front==-1)//empty condition
        {
            front=0;
            rear = 0;
        }
        else if(rear==size-1)
        {
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        //underflow condition
        if(front==-1){
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front==rear){ // single element condition
            front=rear=-1;
        }
        else if(front==size-1){//to maintiain cyclic nature
            front=0;
        }else { //normal condition
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        //underflow
        if(front==-1) return -1;
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front==rear){// single element condition
            front=rear=-1;
        }
        else if(rear==0) //cyclic
        {
            rear=size-1;
        }else{//normal case
            rear--;
        }
        
        return ans;
        
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(front==-1) return -1;
        
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(front==-1) return -1;
        
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front==-1) return true;
        else return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front==0&&rear==size-1) || ( (front!=0) && rear==(front-1)%(size-1)) ){//isme yahan par ek alag se condition lagi hai ki agar front =0  hua to front-1 = -1 hoga and -1%(size-1)= 0 which is wrong
             return true;
        }
        else return false;
    }
};