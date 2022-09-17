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


//You will be given a key and you have to tell if there exists any pair in bst whose sum is equal to key.
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/

/*
approach1: bruteforce - visit a node let say curr and then see in the tree if there exists a node with
                        value key-curr. tc: O(N^2).

approach 2: efficient - we know inorder gives a sorted order. store it in array then apply two sum on
                array with two pointer approach 
                Tc: O(n) sc: O(n).

*/

void storeInorder(Node* root, vector<int>& v){
    if(root==NULL) return;
    
    //LNR
    storeInorder(root->left, v);
    v.push_back(root->data);
    storeInorder(root->right, v);
    
}
bool findTarget(Node* root, int k) {
    vector<int> v;
    storeInorder(root, v);
    
    //now find two sum in an array with 2 pointer approach
    int i=0, j=v.size()-1;
    while(i<j){
        
        if(v[i]+v[j]==k) return true;
        
        else if(v[i]+v[j] < k ) i++;
        else j--;
        
    }
    return false;
    
}
