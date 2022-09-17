// https://practice.geeksforgeeks.org/problems/largest-bst/1
/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree. IMPORTANT QUESTION.
*/


#include <iostream>
#include <vector>
#include <algorithm>
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
Bruteforce: at every node validate the bst below it. O(N^2)

approach 2: optimized

    ham neeche se shuru karenge aur har node ko dekhenge ki wo valid hai ya nhi using data given by 
    below left and right sub trees.
    so a node would be valid if:
    1)left subTree is valid
    2) right subTree is valid
    3) maxLeft < root->data < minRight
    now if it is valid update the maxsize variable.


    so as a return type we would need 4 values max of tree, min of a tree, isValid or not and size of the tree
    for four return type we can make a class and return its instance or pointer to instance in the function
    calls.
*/

class NodeRes{
    
    public:
        int maxi;
        int mini;
        bool isValid;
        int size;
        
        NodeRes(int maxi, int mini, bool isValid, int size){
            this->maxi = maxi;
            this->mini = mini;
            this->isValid = isValid;
            this->size = size;
        }
    
};

NodeRes* solve(Node* root, int &maxsize){ //will return whether a valid bst and the maxInteger in the subbst
        
    //base case
    if(root==NULL){
        NodeRes* h1 = new NodeRes(INT_MIN, INT_MAX  , true, 0);
        return h1;
    }
    
    //rc
    //this node will be said valid if:
    //1)left subTree is valid
    //2) right subTree is valid
    //3) maxLeft < root->data < minRight
    //now if it is valid update the maxsize variable.
    
    NodeRes* leftRes = solve(root->left, maxsize);
    NodeRes* rightRes = solve(root->right, maxsize);
    
    int size = leftRes->size + rightRes->size + 1;
    int maxi = max(root->data, rightRes->maxi); //kyuki aisa bhi toh ho skta h ki ye wala root valid na ho aur root ki value right wale se bhi badi aa rhi ho, but agar normal case h to bhi chal jayega.
    int mini = min(root->data, leftRes->mini);
    
    //validity
    bool isBst;
    if(leftRes->isValid && rightRes->isValid && leftRes->maxi < root->data && rightRes->mini > root->data){
        isBst = true;
    }else{
        isBst = false;
    }
    
    
    //update maxsize
    if(isBst){
        maxsize = max(maxsize, size);
    }
    
    NodeRes* ans = new NodeRes(maxi, mini, isBst, size);
    return ans;
    
}


int largestBst(Node *root)
{
    int maxsize = 0;
    NodeRes* ans = solve(root, maxsize);
        
    return maxsize;
}


//TC: O(n) SC: O(H) = = O(N).

//now try this: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/