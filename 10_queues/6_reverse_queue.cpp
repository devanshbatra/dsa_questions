#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//reverse a queue.
//https://practice.geeksforgeeks.org/problems/queue-reversal/1/#
void printQ(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

//approach 1: using a stack
void reverse1(queue<int>& q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    //now stack has all the elements in reverse order
    //pushing back in queue.
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

/*
Approach2: using recursion , like in stack we use to pop all the elements one by one recursively and then
start pushing to the bottom. But here we have the advantage that we do not need to create a separate func.
for push at bottom as we already push at back by default in the queue.
*/

void reverse2(queue<int>& q){
    //base case
    if(q.empty()) return;

    // recursive call 
    int temp = q.front();
    q.pop();
    reverse2(q);
    q.push(temp);
}

int main(){

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    printQ(q);

    reverse2(q);

    cout<<"After reversal: ";
    printQ(q);



    return 0;
}