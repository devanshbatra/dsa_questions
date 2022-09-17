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

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//We have to find the kth smallest element in the bst.
//here we will perform recursion here
//The inorder traversal gives a sorted order, so traverse by inorder and count when k meets return
//is ques mein recursion mein bas ek node par dekh lo baaki recursion sambhal lega.
int solve(Node* root, int k, int &i){
    
    if(root==NULL) return -1;
    
    //left
    int left = solve(root->left, k, i); 
     if(left!=-1) return left; //we are invoking an if condn. bcoz aage bhi processing hai so if left!=-1 aage process krne ki koi zarorat nhi.
    
    //this node
    i++;
    if(i==k) return root->data; //isme bhi isliye he if lagaya hai
    
    //right
    return solve(root->right, k, i); //ab jo bhi aa rha h return to karna he hai bcoz aage koi processing nhi h
   
}
int kthSmallest(Node* root, int k) {
    int i=0;
    return solve(root, k, i);
}

//tc: O(N) sc: O(H) --> O(N).

//we can optimize this space complexity by doing morris traversal.
//approach 2

Node* findPre(Node* root){
    Node* temp = root->left;
    while(temp->right!=NULL && temp->right!=root ) temp = temp->right;
    return temp;
}
int kthSmallest(Node* root, int k) {
    int i=0;
    int ans = -1;
    
    //morris traversal
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left){
            Node* pred = findPre(curr);
            // cout<<"found pre of: "<<curr->val<<" as: "<<pred->val<<endl;
            if(pred->right==NULL){  //first time coming on node
                
                pred->right = curr;
                curr = curr->left;
                
            }else{ //coming after backtrack from left
                
                // cout<<curr->val;
                if(i==k-1){
                    ans = curr->data;
                }
                i++;
                pred->right = NULL;
                curr=curr->right;
                
            }
        }else{
            // cout<<curr->val;
            if(i==k-1){
                ans = curr->data;
            }
            i++;
            curr=curr->right;
        }
    }
    return ans;
    
}


//for kth largest element we would traverse RNL OR IT IS ALSO (N-K+1)TH SMALLEST ELEMENT.
int solve(Node* root, int k, int &i){
    if(root==NULL) return -1;
    
    //left
    int right = solve(root->right, k, i);
    if(right!=-1) return right;
    
    //curr
    // cout<<root->data<<" ";
    if(i==k-1) return root->data;
    i++;
    
    //right
    return solve(root->left, k, i);
}
int kthLargest(Node* root, int k)
{
    int i = 0;
    return solve(root, k, i);
    
}