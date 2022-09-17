//Very important concept and easy also
/*
To delete a given node from the bst, there arise 4 cases here zero child, one child and two child.
*/

#include <iostream>
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


//here we have to find pred where we know that left is not null so not that much logic of finding original predecessor.
Node* findPred(Node* root){
    Node* temp = root->left;
    while(temp->right!=NULL) temp = temp->right;
    
    return temp;
}
Node* deleteNode(Node* root, int key) {
    //base case
    if(root==NULL) return root;
    
    if(root->data==key){
        //deletion logic
        
        //0 child
        //just delete the node.
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL; //jab uppar jayega to root->left ya root->right ko null value assign ho jayegi.  
        }
        
        
        
        //1 child
        //store the node of child delete this node and then return that child .
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        //replace node's dataue with inorder predecessor and then give command to delete that predecessor.
        else{
            Node* pred = findPred(root);
            root->data = pred->data;
            root->left = deleteNode(root->left, pred->data);
            return root;
        }
        
    } 
    else if(key <= root->data) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else {
        root->right = deleteNode(root->right, key);
        return root;
    }
    
}