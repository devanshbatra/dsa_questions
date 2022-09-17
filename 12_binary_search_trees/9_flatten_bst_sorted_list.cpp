/*
    We have to flatten a bst to a linked list such that all right pointer point to next element and left
    pointers point to NULL.

    I thought of morris traversal but It cannot be applied here as jab backtrack ke baad right jaate hai
    to we cannot detect ki right sahi mein tree wala hai ya temp link wala.

    so we will do this by a simpler approach
    store the inorder in an array of Node* and then for every node put left to null and right to next element.
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




void storeInorder(Node* root, vector<Node*>& v){
    
    if(root==NULL) return;
    
    //rc - LNR
    storeInorder(root->left, v);
    v.push_back(root);
    storeInorder(root->right, v);
    
}

Node* flatten(Node* root)
{
    vector<Node*> v;
    storeInorder(root, v);
    Node* ans = v[0];
    int n = v.size();
    for(int i=0; i<n-1; i++){
        v[i]->left = NULL;
        v[i]->right = v[i+1];
    }
    
    v[n-1]->left = NULL;
    v[n-1]->right = NULL;
    
    return ans; 
    
}


/*
Approch 2: This can be done by using recursion
//to convert a bst into a sorted linked list
//same question already done using storage as vector but here, we need to do that in O(h1+h2) space complexity
// So we will do it using recursion. Lets make a doubly linked list using this.
// for recursion focus on one node get the head of the ll of the right sub tree and then form links with node
// then call for recursion of the ll for left subtree and for the links and write the base and its done.


//hame jahan jahan jaan hai for making a linked list wahan jaakar head ko set krte jaa rhe h
//right mein pehle isliye gaye taki ek dum end mein head ekdum chotte element pe point kr 
//rha hoga which is in the extreme left
*/

void formDll(Node* root, Node* & head){ //head apne aap se liya hai isse NULL se initialize kr dia hoga
        
    if(root==NULL) return;
    
    formDll(root->right, head);
    
    root->right= head;
    // if(head) cout<<"linked "<<root->data<<" ka to right to "<<head->data<<endl;
    if(head) head->left = root;
    
    head= root;
    
    formDll(root->left, head);
}

void flatten2(Node* root){
    Node* head = NULL;
    formDll(root, head);
}


