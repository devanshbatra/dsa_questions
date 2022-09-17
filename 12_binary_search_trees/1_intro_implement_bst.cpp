#include<iostream>
#include<queue>
using namespace std;

/*
Binary Search Tree - Its just like the binary tree having 0,1 or 2 children except one extra condition
    Extra condition- On every node - The left subtree should have lower values and the right subtree 
    should have greater values.
*/

//implement a bst
//given an array put that into a bst by applying the above logic.

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


Node* insertInBst(Node* root, int n){
    //base case
    if(root==NULL){
        root = new Node(n);
        return root;
    }

    //rc
    if(n>root->data){//bada hai to right part mein insert kar dia.  
        root->right = insertInBst(root->right, n);
    }else{
        root->left = insertInBst(root->left, n);
    }

    return root;

}
//insertion complexity would be O(height)~O(n) as in worst case the tree may be left skewed and the smallest 
//element came to be inserted.

//but for average case, it may have w(logn) as it is like a binary search and we are reducing our search space.

void takeInput(Node* &root){

    int n;
    cin>>n;

    while(n!=-1){
        root = insertInBst(root, n);
        cin>>n;
    }
}


//searching in binary tree - if found will return node else return null.
Node* searchBST(Node* root, int val) {
    //base case
    if( root==NULL || root->data==val ){
        return root;
    }
    //rc - utilizing the powers of bst
    if(val<=root->data)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
    
}

int main(){

    Node* root = NULL;

    cout<<"Enter the data for the bst: ";
    takeInput(root);
    //10 8 21 7 27 5 4 3 -1
    cout<<endl;
    cout<<"printing level order: ";
    printLevOrd(root);

    int key  = 5;
    Node* ans = searchBST(root, key);
    if(ans) cout<<"found";
    else cout<<"not found";


    return 0;
}

//IMPORTANT PROPERTY: inorder traversal of bst is in sorted order LNR.