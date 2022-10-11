#include<iostream>
#include<queue> //queue is only used for priority queue also.

using namespace std;

/*
Priority queue is used to implement max and min heap in stl.
Default is maxHeap.
*/

int main(){

    priority_queue<int> pq;
    pq.push(5);
    pq.push(8);
    pq.push(1);
    cout<<"size of pq is : "<<pq.size()<<endl;
    cout<<"Element at top: "<< pq.top()<<endl;
    pq.pop();
    cout<<"Element at top: "<< pq.top()<<endl;
    pq.pop();
    if(pq.empty()) cout<<"priority queue is empty"<<endl;
    else cout<<"Not empty"<<endl;

    //min heap
    // priority_queue supports a constructor that requires two extra arguments to make it min-heap. 
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(5);
    minheap.push(3);
    minheap.push(7);
    minheap.push(8);

    cout<<"size of pq is : "<<minheap.size()<<endl;
    cout<<"Element at top: "<< minheap.top()<<endl;
    minheap.pop();
    cout<<"Element at top: "<< minheap.top()<<endl;
    minheap.pop();
    if(minheap.empty()) cout<<"min heap priority queue is empty"<<endl;
    else cout<<"Not empty"<<endl;




    return 0;
}
