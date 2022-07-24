#include<iostream>
using namespace std;

//to implement circular queue
//https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=1

class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    
    CircularQueue(int n){
        
        size = n;
        front=-1;//initiating from -1 because we are using a cyclic queue here here the rear will be pointing to the last element.                        element and not after the last element.
        rear = -1;
        arr = new int[size];
    }

   
    bool enqueue(int value){
        //check if queue is full
        //ab full ki bhi 2 conditions hai
        //1) front at 0 and rear at size-1
        //2) front somewhere in between and rear just behind it i.e. if rear == (front-1)%(size-1) taki agar front last
        //mein hai to rear front wala mana jaaye.
        if((front==0&&rear==size-1) || (rear == (front-1)%(size-1)) ){ //full condition
            return false;
        }else if(front==-1&&rear==-1){//empty
            front = rear = 0;
        }else if(rear==size-1 && front!=0 ){//to maintain cyclic order - rear aage chala jayega agar jagah hai toh.
            rear = 0;
        }else{ //normal case
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        //wahi chaar cases yahan bhi check karne hai.
        //check if empty
        if(front==-1) return -1;
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front==rear){//single element present.
            front=rear=-1;
        }else if(front==size-1){//to maintain cyclic nature.
            front=0;
        }else{//normal flow
            front++;
        }
        
        return ans;
    }
};