#include<iostream>
#include<queue>
using namespace std;

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.


//approach 1: brute force:
/*  store all the values of the linked lists in a vector
    sort the vector
    merge all linked list one after other.
    replace the values of the merged ll with that of the sorted vector.
    TC: O(n*k) + O(k) + O(nklog(nk)) + O(n*k) = O(n*klog(nk)).
    sc: O(n*k).
*/

//approach 2 (optimized): we will create a min heap of type Node* which will initially store the first
//          elements of the lists.

// then we will start popping the min element from the heap and adding to our ans tail and
// pushing the next element (if available) to the minheap.
//Tc: klogk (pushing in min heap). + nklog(k). = n*klog(k).
// Sc: O(k). for minheap

//ek approach divide and conquer wali bhi hoti hai, but you can do that after completion of dp.

//aise he.
class Node{
    public:
        int val;
        Node* next;
};

//custom comparator class for comparing lists in minheap.
class comparator{
      public:
        bool operator()(Node* a, Node* b){
        return a->val > b->val;
    }
};

//utility
void insertInList(Node*& head, Node*& tail, Node* newnode){
    if(head==NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    
    tail->next = newnode;
    tail = newnode;
}

Node* mergeKLists(vector<Node*>& lists) {
    Node* head=NULL;
    Node* tail=NULL;
    
    int k = lists.size();
    
    if(k==0) return head;
    
    //1)create a custom heap.
    priority_queue<Node*, vector<Node*>, comparator> minheap;
    
    //2) store the firsts in the heap.
    for(int i=0; i<k; i++){
        if(lists[i]!=NULL)
            minheap.push(lists[i]);
    }
    
    //3) start popping the lowest from the heap and then pushing the next of that till heap is empty.
    
    while(!minheap.empty()){
        
        Node* mini = minheap.top();
        // cout<<mini->val<<endl;
        
        minheap.pop();
        
        insertInList(head, tail, mini);
        
        if(mini->next!=NULL) minheap.push(mini->next);
        
    }
    return head;
}

