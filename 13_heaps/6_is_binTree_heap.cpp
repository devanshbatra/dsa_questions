// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
//We will be given a binary tree head and we have to tell if it is a max heap or not.

#include<iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left=NULL;
            right = NULL;
        }
};
//utility function
int countNodes(Node* tree){
    Node* temp = tree;
    queue<Node*> q;
    int count = 0;
    q.push(temp);
    while(!q.empty()){
        Node* currEle = q.front();
        q.pop();
        count++;
        if(currEle->left) q.push(currEle->left);
        if(currEle->right) q.push(currEle->right);
        
    }
    
    return count;
}

//we will calculate the number of nodes
//for 0 based indexing left = 2*i+1 and right=2*i+2
//so if we find a node on which left exists(Not NULL) and its left i.e 2*i+1 is
//>=number of nodes than it means it is leaving a gap in the tree so it is not a complete 
//binary tree.

bool isCbt(Node* tree){
    int n = countNodes(tree);
    
    //level order traversal
    int i = 0;
    queue<Node*> q;
    Node* temp = tree;
    q.push(temp);
    
    while(!q.empty()){
        Node* currEle = q.front();
        q.pop();
        
        if(currEle->left){
            if((2*i+1) >= n ) return false;
            
            q.push(currEle->left);
        }
        if(currEle->right){
            if( (2*i+2) >= n ) return false;
            q.push(currEle->right);
        }
        
        i++;
    }
    
    return true;
    
}

    
bool isHeapOrder(Node* tree){
    Node* temp = tree;
    queue<Node* > q;
    q.push(temp);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr->left){
            if(curr->data < curr->left->data) return false;
            
            q.push(curr->left);
        }
        if(curr->right){
            if(curr->data < curr->right->data) return false;
            
            q.push(curr->right);
        }
        
    }
    return true;
}

    
bool isHeap(Node* tree) {
    // for a binary tree to be a heap we have to check two condition:
        //1) it should be a complete binary tree.
        //2) it should be following heap order property (max heap here).
        

        //we could have done this in same function but to make you understand better we have used two.
        return isCbt(tree) && isHeapOrder(tree); 
}
// TC: O(N), sc: O(H)

//try to make a recursive solution for this. (IMPORTANT).