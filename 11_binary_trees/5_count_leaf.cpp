#include<iostream>
#include<queue>

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

//we have to count the number of leaf node in the tree
//leaf node do not have left or right child.
//we can check this using any traversal method.
//using preorder
int preorder_leaves(Node* root, int &count){
    // cout<<root->data<<" ";
    if(root->left==NULL && root->right==NULL ) count++;
    
    if(root->left) preorder_leaves(root->left, count);
    if(root->right) preorder_leaves(root->right, count);
    
}

int main(){

    Node* root;

    root = buildTree(1);
//3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    int count = 0;
    preorder_leaves(root, count);

    cout<<endl<<"The number of leaves: "<<count;
    

    return 0;
}