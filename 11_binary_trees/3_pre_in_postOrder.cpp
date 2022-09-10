#include<iostream>
#include<stack>
#include<queue>
//do the preorder , postorder and inorder traversal of the binary tree.
// we can relate to root and simply remember order by traversal name-
// preOrderTraversal = root, left, right
// inOrderTraversal = left, root, right
// postOrderTraversal = left, right, root
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

//very easy
void preOrderTrav(Node* root){

    //base case
    if(root==NULL) return;

    //follow NLR
    cout<<root->data<<" ";
    preOrderTrav(root->left);
    preOrderTrav(root->right);

}
void inOrderTrav(Node* root){

    //base case
    if(root==NULL) return;

    //follow LNR
    inOrderTrav(root->left);
    cout<<root->data<<" ";
    inOrderTrav(root->right);

}
void postOrderTrav(Node* root){

    //base case
    if(root==NULL) return;

    //follow LRN
    postOrderTrav(root->left);
    postOrderTrav(root->right);
    cout<<root->data<<" ";

}

//through iteration - h/w 
// here The right child is pushed before the left child to make sure that the left subtree is processed first.
// as we are using a stack which follows lifo.
void preorder_iter(Node* root){

    Node* temp = root;
    queue<Node*> q;
    q.push(root);
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";

        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }


    }

}

int main(){

    Node* root;

    root = buildTree(1);
    //3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<endl<<"Printing the pre order traversal: ";
    preorder_iter(root);
    cout<<endl;

    cout<<endl<<"Printing the in order traversal: ";
    inOrderTrav(root);
    cout<<endl;

    cout<<endl<<"Printing the post order traversal: ";
    postOrderTrav(root);



    return 0;
}
