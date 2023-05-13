#include <iostream>
#include <queue>
using namespace std;

/*

implement stack using queue:

approach 1: using two queues
            whenever we push num pop all the elements from the queue1 and push to queue2.
            now push num to queue1 and after that readd all other elements from queue2 to queue1.
            now the front will refer to the top of the stack

            pop operation is normal here. This was method to make push more operational and pop simple

            another method could be to make pop more operational and push simple.


code: 
https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1/

void push(struct Queue *q1,struct Queue *q2,int num)
{
    //code here
    if(isEmpty(q1)) enqueue(q1, num);
    else{
        while(!isEmpty(q1)){
            enqueue(q2, front(q1));
            dequeue(q1);
        }
        enqueue(q1, num);
        while(!isEmpty(q2)){
            enqueue(q1, front(q2));
            dequeue(q2);
        }
    }
}

//Function to pop an element from stack using two queues. 
int pop(struct Queue *q1)
{
    if(isEmpty(q1)) return -1;
    else{
        int temp = front(q1);
        dequeue(q1);
        return temp;
        
    }
}

*/


/*
Approach 2: Using a single queue.
Most optimal - just simple method. Do try to think what we want to mimic and do yourself.

*/

 class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();

        q.push(x);

        while(n>0){
            int ele = q.front();
            q.pop();
            q.push(ele);
            n--;
        }

    }
    
    int pop() {
        if(q.empty()) return -1;
        int ans = q.front();
        q.pop();
        return ans;
    
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

