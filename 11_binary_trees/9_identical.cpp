#include<iostream>
#include<queue>
#include<utility>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(int data){
    //base case
    if(data == -1) return NULL;

    //creating a node
    Node* newnode = new Node(data);

    //recursive calls for left and right
    cout<<"Enter the left child for "<<data<<": ";
    int d;
    cin>>d;
    newnode->left = buildTree(d);

    cout<<"Enter the right child for "<<data<<": ";
    cin>>d;
    newnode->right = buildTree(d);

    return newnode;
}

/*
Given two binary trees, the task is to find if both of them are identical or not.  
https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
*/
//Function to check if two trees are identical.
//at a particular node, two trees are identical if:
//both node data is equal
//rightSub tree of both nodes is equal
//leftSub tree of both nodes is equeal

//ek case solve karo baaki recursion kr lega.(simple hai bhai recursion mein mastery karo bas.)
bool isIdentical(Node *r1, Node *r2)
{
    //base cases
    if(r1==NULL && r2==NULL){
        return true;
    }else if(r1==NULL && r2!=NULL ) return false;
    else if(r1!=NULL && r2==NULL ) return false;
    
    
    //recursive calls
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical (r1->right, r2->right);
    
    bool currNode = r1->data==r2->data? true: false;
    
    if(left && right && currNode ) return true;
    else return false;
    
    
}

//TC: O(n) traversed every node once
//SC: O(n) it would be O(height) actually as highest function stack would be equivalent to the most deep leaf
//for worst case in skew tree n==height so SC = O(n).