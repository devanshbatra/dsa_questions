#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int d){
            data = d;
            this->right=NULL;
            this->left = NULL;
        }
};

/*
Balance a Binary Search Tree
https://leetcode.com/problems/balance-a-binary-search-tree/
Given the root of a binary search tree, return a balanced binary search tree with the same node
 values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by
 more than 1.


*/
// here in this question we need to apply some brain and use the property of bst
//INTUITION: dono balance bst aur unbalance bst mein common kya hai.
//dono ka inorder sorted order mein aayega aur same aayega.

//approach: 1) store the element of inorder in an array.
//2) apply binary division on the array through recursion and form a tree.
// iss step mein right aur left main pure pure array bhejne ki zarurat nhi hai just index se khelna hai.(IMP POINT).
//in this way every node will have same height or difference of left and right
//subtree.
//function to store the inorder in an array
void storeInorder(Node* root, vector<int>& v){
    if(root==NULL) return;
    
    //LNR
    storeInorder(root->left, v);
    v.push_back(root->data);
    storeInorder(root->right, v);
}

//function to form a tree through binary search
Node* formTree(vector<int>& v, int s, int e){
    
    if(s==e){//isme toh aakri he leaf bachi hai
        Node* newnode = new Node(v[s]);
        return newnode;
    }
    if(s>e){
        return NULL;
    }
    
    int mid = s+(e-s)/2;
    Node* newnode = new Node(v[mid]);
    
    newnode->left = formTree(v, s, mid-1);
    newnode->right = formTree(v, mid+1, e);
    
    return newnode;
    
}

//main function
Node* balanceBST(Node* root) {
    vector<int> v;
    storeInorder(root, v);
    
    
    //form tree through divide and conquer
    int s = 0, e = v.size()-1;
    return formTree(v, s, e);
    
}

//TC: O(n)for storing inorder + O(logn) for forming the tree. ==> O(n).
//SC: O(N) for strong inorder= O(N)