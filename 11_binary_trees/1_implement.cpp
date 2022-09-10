//here we will create a class node for binary tree and then will create a function buildTree
//buildTree will create the tree 
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


//this will also be done with recursion or while loop. we have to just solve one case.
//we will print the q ka front and then push at the back the left and right elements 
//now every time the function is called it will just check the q ka front
//if the queue is foiund to be empty, it means that the operations are finished.

//WITHOUT LEVEL WISE PRINT (NO ENTER ON LEVEL END). using recursion
// void levelOrderTraversal(queue<Node*> q){

//     //base case 
//     if(q.empty()) return;

//     Node* currNode = q.front();
//     int data = currNode->data;
//     cout<<data<<" ";
//     q.pop();//removing front.

//     if(currNode->left) q.push(currNode->left);
//     if(currNode->right) q.push(currNode->right);


//     levelOrderTraversal(q);

// }

//using while loop
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* currNode = q.front();
        int data = currNode->data;
        cout<<data<<" ";
        q.pop();//removing front.

        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);

    }
}

//WITH LEVEL WISE PRINT (ENTER ON LEVEL END).
//whenever level ends we will induce NULL in the queue.
void levelOrderTraversal2(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL); //for end of root.

    while(!q.empty()){

        Node* currNode = q.front();

        q.pop();//removing front.

        if(currNode==NULL){ //ek level poora traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){  //abhi children bache hai neeche wale level ke , but uske neeche wale level ke nhi honge, so endl lagado.
                q.push(NULL);
            }
        }else{
            int data = currNode->data;
            cout<<data<<" ";
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }


    }
}


int main(){

    Node* root;

    root = buildTree(1);
//3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<endl<<"Printing the level order traversal: ";
    levelOrderTraversal(root);
    cout<<endl<<"Printing the level order traversal 2: "<<endl;
    levelOrderTraversal2(root);

    return 0;
}