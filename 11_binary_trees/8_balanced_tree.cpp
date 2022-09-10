/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left
 and right subtrees is not more than one for all nodes of tree. 
 https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
*/

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


    //isme tume har node ke liye height of right sub tree chahiye aur left ki height chahiye,
    //so tum ek case solve kar do baaki recursion kar dega.
    //uss ek case mein hame call karna padega function which will return :
    //1) height of subtree and 
    //2) were all the nodes of the tree balanced?
    //so to get two things we used pair as our return type. warna har point pe agar height 
    //wala function use karne lage toh TC: would be bad(O(n^2))
    
    //toh har node pe teen condition check karni hai
    //left subtree balanced hona chahiye
    //right subtree balanced hona chahiye
    //dono ki height ka diff <=1
    
    pair<int, bool> balanceChk(Node* root){
        //base case
        if(root==NULL){
            pair<int, bool> p = make_pair(0, true);
            return p;
        }
        
        //recursive call
        pair<int, bool> left = balanceChk(root->left);
        pair<int, bool> right = balanceChk(root->right);
        
        
        int rightHeight = left.first;
        int leftHeight = right.first;
        int totalHeight = max(rightHeight, leftHeight)+1;
        
        bool isBalanced = abs(rightHeight-leftHeight)<=1? true: false;
        
        pair<int, bool> ans;
        if(!left.second || !right.second ) { //agar pichli baar he balanced nhi tha then false he jayega uppar tak
            ans  = make_pair(totalHeight, false);
            return ans;
        }
        ans = make_pair(totalHeight, isBalanced);
        return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        pair<int, bool> ans;
        ans = balanceChk(root);
        return ans.second;
    }