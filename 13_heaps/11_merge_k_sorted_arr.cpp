#include<iostream>
#include<queue>
using namespace std;

// Given K sorted arrays arranged in the form of a matrix of
// size K*K. The task is to merge them into one sorted array.
//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

/*
Approach 1: brute force- We will merge all the arrays straight one into another one by one.
            Now we will sort the big array.
            TC: O(nk log(nk)).
*/

//approach 2: using heap. (HERE WE WILL SEE HOW TO CHANGE THE DEFAULT BEFAVIOR OF PRIORITY QUEUE.)
//1)we will create a min heap of size k with elements as custom classes containing the data and indexing 
//of the elements.

//2)Now, we will take out the minimum element from the heap increase its index if present and then
// push that new index's data into the heap.

//3) in this way we would push and pop from the heap till the heap is empty. and we would get our
//   final sorted array.

//time complexity: pushing k elements in minheap = O(klogk), 
//                  pushing and popping operations for n*k elements in a heap of size k = nk(logk).
//sc: O(k) + O(n*k) = O(n*k). 

class node{
    public: 
        int data;
        int row;
        int col;
        
        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
};

//creating a comparator class for min heap 
class comparator{
    
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
    
};


vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    
    //1) creating a min heap of first elements of all k arrays.
    int n = arr[0].size();
    priority_queue<node*, vector<node*>, comparator> minheap; //here we designed our custom heap.
    
        //pushing elements
    for(int i=0; i<k ;i++){
        int data = arr[i][0];
        int r = i;
        int c = 0;
        node* newnode = new node(data, r, c);
        minheap.push(newnode);
    }
    
    // 2) pushing and popping from heap while it is empty.
    vector<int> ans;
    while(minheap.size()>0){
        
        ans.push_back(minheap.top()->data);
        int i = minheap.top()->row;
        int j = minheap.top()->col;
        minheap.pop();
        if(j+1 < n){
            node* newnode = new node(arr[i][j+1], i, j+1);
            minheap.push(newnode); 
        }
    }
    
    
    return ans;
    
}