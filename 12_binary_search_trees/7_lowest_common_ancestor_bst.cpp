#include <iostream>
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

//LOWEST COMMON ANCESTOR IN BST
//  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/

/*
//waise to we have already solved this type of question in binary tree also,
//but here we can use the powers of bst to simplify the process.

//approach 1: 
//we will perform a Preorder traversal and will check the range p to q.
//the first node encountered which is between p and q will be the lowest
//common ancestor of the two nodes.*/
Node* solve(Node* root, Node* p, Node* q){
    //base case
    if(root==NULL) return NULL;
    
    //rc
    //curr node
    int minRange = min(p->data, q->data);
    int maxRange = max(p->data, q->data);
    if(root->data >= minRange && root->data<=maxRange ) return root; //equal to isliye aaya 
    //bcoz ye bhi to ho skta hai ki p aur q mein se he koi ancestor ho common wala
    
    //left
    Node* left = solve(root->left, p, q);
    if(left!=NULL) return left;//whi concept ki agar abhi processing bachi hai to if use karke return karo taki right ko bhi mauka mile but right call last hai to phir kuch toh return karoge he.
    
    //right
    return solve(root->right, p, q);
}


//approach 2 : babbar soln. more efficient
//aise socha karo ki tum ek node pe khade ho aur tumhe left jaana hai ya right.
/*
//we will check the range p to q.
    // agar root p aur q dono se bada hai toh left mein search karo agar root
    //p aur q dono se chotta hai to right mein search karo
    //the first node encountered which is between p and q will be the lowest
    //common ancestor of the two nodes.
*/
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    
    //base case
    if(root==NULL) return NULL;
    
    if(root->data > p->data && root->data > q->data)
        return lowestCommonAncestor(root->left, p, q);
    else if(root->data < p->data && root->data < q->data)
        return lowestCommonAncestor(root->right, p, q);
    else //unke beech mein hai
        return root;
    
}

//tc: O(N) sc: O(N).

//to save space we can do it in iterative way.
Node* LCAinaBST(Node* root, Node* p, Node* q)
{
    Node* curr = root;
    
    while(curr!=NULL){
        if(curr->data > p->data && curr->data > q->data){
            curr=curr->left;
        }else if(curr->data < p->data && curr->data < q->data){
            curr=curr->right;
        }else{
            break;
        }
    }
    return curr;
    
}
//now sc: O(1).