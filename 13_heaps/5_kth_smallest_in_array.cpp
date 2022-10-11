#include <iostream>
#include <queue>
using namespace std;

/*
We have to find the kth smallest element in the array
approach 1: Simply sort the array and then return the arr[k-1]th element. TC: O(nlog(n)).

approach 2: Optimized - using heaps -> 
            1) first build a max heap with first k elements
            2) now traverse other n-k elements and if the element is less than the top of the heap then pop
                pop from the heap and push that element in the heap.

                iss tarah hame sabse chote teen element mil jayenge - make a dry run.
            
done it here: https://leetcode.com/problems/kth-largest-element-in-an-array/   but isme largest kth nikalna tha
next time try gfg.
*/

int main(){

    int arr[6] = {8,4,9,1,3,0};
    int n = 6;
    
    priority_queue<int> pq;
    int k= 3;//3rd smallest
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i=k; i<n; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout<<"The "<<k<<"th smallest element is: "<<pq.top()<<endl;


    return 0;
}

//TC: in pushing k elements to queue log(k) + in traversing n-k elements and pushing or popping n-k(log(k)).
// ==> (n-k) log(k)

//sc: O(logk).

