/*
QUEUE : it is a data structure which follows FIFO technique of accessing the elements.
        The member which has been pushed first will be popped first.
        It is just like a line out side ATM.

queues has two pointers - front and back(rear) 
    front points to the first element of the queue which has to be popped first
    back or rear points to the last position after the last element added to the queue.

    front and rear are both at 0 index at the starting (i.e. empty queue).
*/

//queue functions included with stl.
//these are basic functions see others on cppreference.com
#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue <int> q;
    q.push(8);
    q.push(5);
    q.push(12);

    cout<<"The front element of the queue is: "<<q.front()<<endl;
    cout<<"The back element of the queue is: "<<q.back()<<endl;
    q.pop();
    cout<<"The front element of the queue is: "<<q.front()<<endl;
    cout<<"The back element of the queue is: "<<q.back()<<endl;

    // q.pop();
    // q.pop();

    if(q.empty()) cout<<"The queue is empty"<<endl;
    else cout<<"The queue is not empty"<<endl;

    return 0;
}

/*
enqueue and dequeue are also used
enqueue - insert or push
dequeue - remove or pop.
*/