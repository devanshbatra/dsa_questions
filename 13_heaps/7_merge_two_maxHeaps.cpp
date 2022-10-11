// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
#include <iostream>
#include <vector>
using namespace std;

//we will simply merge the arrays of the two heaps one over other in any order.
    //now we will build the heap using heapify method.
    // and a third vector will be created according to the heap.
    
    void heapify(vector<int>& arr, int n, int i){
        int largest = i;
        int left = i*2+1;
        int right = i*2+2;
        
        if(left<n && arr[largest]<arr[left]){
            largest = left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest = right;
        }
        
        if(i!=largest){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    void buildHeap(vector<int> &b){
        //we know that from n/2 to n-1 all are leaf nodes, no need to see them from reverse
        //in reverse, bcoz ham neeche se shuru karenge.
        int n= b.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(b, n, i);
        }
    }
    
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(auto i: a){
            b.push_back(i);
        }
        
        buildHeap(b);
        
        return b;
        
    }

    //time complexity: 1) O(M+N) for merging both the arrays 2) O(m+n) for building the heap of size m+n.
    //space complexity O(M+N).