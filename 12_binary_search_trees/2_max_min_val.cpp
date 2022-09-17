#include<iostream>
#include<queue>
using namespace std;

/*
To find max and min value in a bst
We know that the inorder traversal is sorted in bst
and logically if we just go left and left till null we will get the minimum value and vice versa would yield
the max value.
*/

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
void printLevOrd(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" ";
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        cout<<endl;
    }

}


int findMax(Node *root)
{
    //code here
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}
int findMin(Node *root)
{
    //code here
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}
