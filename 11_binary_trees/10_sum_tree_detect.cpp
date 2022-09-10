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
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves,
its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
https://practice.geeksforgeeks.org/problems/sum-tree/1


*/

//for a particular node a tree is sum tree if :
    // 1) left tree is sum tree .
    // 2) right tree is sum tree.
    // 3) currNode->data = sumLeftSubtree + sumRightSubTree
    
    // ab har node pe sum calculate krne bhej dia to TC gir jayegi
    //so sum lete hue he chalo aur return type as a pair rakho.
    
    //ek case solve karo baki recursion
    
    pair<int, bool> findSumTree(Node* root){
        //base case
         if(root==NULL){
             pair<int, bool> p = make_pair(0, true) ;
             return p;
         }
         if(root->left==NULL && root->right==NULL){
             pair<int, bool> p = make_pair(root->data, true) ;//sum would be root ka data.
             return p;
         }
         
         
         //recursive calls
         pair<int, bool> left = findSumTree(root->left);
         pair<int, bool> right = findSumTree(root->right);
         
         //now finding sum and isSum
         int sum = root->data + left.first + right.first;
         bool isSum = root->data == left.first + right.first;
         
         pair<int, bool> ans;
         ans.first = sum;
         if(isSum && left.second && right.second ){
             ans.second = true;
         }else{
             ans.second = false;
         }
         
         return ans;
         
    }
    
    bool isSumTree(Node* root)
    {
         
        pair<int, bool> ans;
        ans = findSumTree(root);
        return ans.second;
         
        
    }
    //TC: O(n)
    //SC: O(n)