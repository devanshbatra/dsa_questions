#include<iostream>
#include<queue>
//do the reverse level order traversal
//pehle last level fir up and then up...
// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
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


vector<int> reverseLevelOrder(Node *root)
{
    
    queue<Node*> q;
    q.push(root);
    vector<int> store;
    while(!q.empty()){
        
        Node* currNode = q.front();
        q.pop();
        
        store.push_back(currNode->data);
        //ab isme ham pehle right push kr denge aur phir left (reverse of what we did back there).
        //isse vector mein har level reverse order mein store ho jayega
        //phir ham uss vector ko he reverse kar denge aur ans aa jayega.
        if(currNode->right) q.push(currNode->right);
        if(currNode->left) q.push(currNode->left);
            
        
    }
    
    //reverse the store array   
    int front = 0;
    int rear = store.size()-1;
    
    while(front<rear){
        int temp = store[front];
        store[front] = store[rear];
        store[rear] = temp;
        
        //updating
        front++;
        rear--;
    }
    
    
    return store;
    
    
}


int main(){

    Node* root;

    root = buildTree(1);
//3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<endl<<"Printing the reverse level order traversal: ";

    vector<int> ans = reverseLevelOrder(root);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}