//You will be given a key value and you have to find the inorder predecessor and inorder successor for 
//the given value.
// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

#include<iostream>
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

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    //base case
    if(root==NULL) {
        return;
    }
    
    
    //rc
    if(root->data==key){
        //finding predecessor - ek left jao aur phir right and right.
        if(root->left) {
            Node* temp = root->left;
            while(temp->right!=NULL){
                temp = temp->right;
            }
            pre = temp;
        }
        //finding successor - ek right jao aur phir left and left until null.
        if(root->right){
            Node* temp = root->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            suc = temp;
        }
        return;
    }
    
    //using the power of bst
    if(key<=root->data){
        suc = root; //since root value is greater than key so it can be a successor.
        findPreSuc(root->left, pre, suc, key);
    }else{
        //if root value is less than the key than it can be a predecessor of key.
        pre= root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main(){

    return 0;
}