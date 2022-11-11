#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            data = d;
            left=NULL;
            right = NULL;
        }
};

void storeInorder(Node* root, vector<int> &v){
    if(root==NULL) return;
    
    //lnr
    storeInorder(root->left, v);
    v.push_back(root->data);
    storeInorder(root->right, v);
  
}
void preOrder(Node* root, vector<int> &v, int& i){
    if(root==NULL) return;
    
    //preorder = NLR
    root->data = v[i];
    i++;
    preOrder(root->left, v, i);
    preOrder(root->right, v, i);
    
    
}

Node* convertBST(Node* root)
{
    //acc. to GFG: https://www.geeksforgeeks.org/convert-bst-min-heap/
    //The problem is to convert the given BST into a Min Heap
    //with the condition that all the values in the left subtree of a node 
    //should be less than all the values in the right subtree of the node
    //code studio se prblm stmt read mat karna ek condition chor rakhi hai.
    //https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0
	//It is given that the binary tree is already complete.
    //also two condition to complete are:
    //1) n< r,l (for following minheap)
    //2) l<r
    //if we combine both of these conditions we would get:
    //n<l<r - which is preorder
    //so preorder should be in ascending order and we are getting ascending order array from the bst already
    //if we get a sorted array from inorder of bst we can directly do a preorder of the 
    //tree and replace the values with the array values.
    vector<int> v;
    storeInorder(root, v);
    
    int i= 0;
    preOrder(root, v, i);
    return root;
}
