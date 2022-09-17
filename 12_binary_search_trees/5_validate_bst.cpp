/*
We will be given a node and we have to find whether it is a dataid bst or not.

approach #1: We know that the inorder traversal of the bst is sorted , so we will save the inorder of the 
            tree in an array and then see if it is sorted or not.
            Tc: O(N), sc: O(N).
            solved here: https://leetcode.com/problems/dataidate-binary-search-tree/

approach #2: If you think that you will se at every node if it is greater or smaller than its parent than
            you are completely wrong as there may be a grand or grand grand parent usse bhi toh chota hona
            mangta.
            Now the appraoch would be that we will maintain a range for every node for root node it 
            would be <int_min, int_max> root cannot be lower than range.first and cannnot be greater 
            than range.second. Now, for its left part we will set the range as <range.first, root->data>
            and for the right part <root->data, range.second> as right part must not be lower than root->data.
            and do this recursively.
            solved here: https://www.codingninjas.com/codestudio/problems/dataidate-bst_981275?leftPanelTab=0
*/

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

//approach 1.
void solve(Node* root, vector<int>& v){
        
    if(root==NULL) return;
    
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
    
}
bool isdataidBST(Node* root) {
    vector<int> v;
    solve(root, v);
    int n = v.size();
    bool isdataid = true;
    for(int i=1; i<n; i++){
        if(v[i-1]>=v[i]) isdataid = false;
    }
    return isdataid;
}

//appraoch #2
bool solve(Node* root, pair<int, int> range){
    if(root==NULL) return true;
    
    if(root->data> range.first && root->data<range.second){
        pair<int, int> rangeLeft = make_pair(range.first, root->data);
        pair<int, int> rangeRight = make_pair(root->data, range.second); 
        bool left = solve(root->left, rangeLeft);
        bool right = solve(root->right, rangeRight);
        return left && right;
    }
    else return false;
}
