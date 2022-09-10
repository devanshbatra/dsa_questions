#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int data)
{
    // base case
    if (data == -1)
        return NULL;

    // creating a node
    Node *newnode = new Node(data);

    // recursive calls for left and right
    cout << "Enter the left child for " << data << ": ";
    int d;
    cin >> d;
    newnode->left = buildTree(d);

    cout << "Enter the right child for " << data << ": ";
    cin >> d;
    newnode->right = buildTree(d);

    return newnode;
}

//Minimum time to burn the entire tree for the given target node.
// https://practice.geeksforgeeks.org/problems/burning-tree/1

//here we have created the mapping and found the target node
void createMapping(Node* root, map<Node*, Node*>& nodetoparent, Node* &startPoint, int target){
        
    if(root==NULL) return;
    //finding the target node;
    if(root->data==target) startPoint = root;
    //mapping purpose
    if(root->left) nodetoparent[root->left] = root;
    if(root->right) nodetoparent[root->right] = root;
    
    createMapping(root->left, nodetoparent, startPoint, target);
    createMapping(root->right, nodetoparent, startPoint, target);
    
}

//main function which finds the minimum time.
int minTime(Node* root, int target) 
{
    // Your code goes here
    map<Node*, Node*> nodetoparent;
    nodetoparent[root]=NULL;
    Node* startPoint=NULL;
    createMapping(root, nodetoparent, startPoint, target);
    
    
    //finding time to burn
    queue<Node*> q;
    map<Node*, bool> visited;
    q.push(startPoint);
    int time=0;
    while(!q.empty()){
        
        bool inserted = false;
        
        int n=q.size();
        
        //ye loop isliye hai bcoz when we burn some nodes then after that they will not wait for each other instead they wouild be burning sumultaneously.
        for(int i=0; i<n; i++){
            
            Node* currNode = q.front();
            q.pop();
            visited[currNode] = true;
            //parent
            Node* parent = nodetoparent[currNode];
            
            if(parent!=NULL && !visited[parent]){
                // cout<<"came to parent for: "<<parent->data<<endl;
                q.push(parent);
                inserted = true;
            }
            
            //children
            Node* left = currNode->left;
            Node* right = currNode->right;
            if(left!=NULL && !visited[left]) {
                // cout<<"came to left child for: "<<left->data<<endl;
                q.push(left);
                inserted=true;
            }
            if(right!=NULL && !visited[right]){
                // cout<<"came to right child for: "<<right->data<<endl;
                q.push(right);
                inserted = true;
            }
            
        }
        //if inserted in queue then time plus plus.
        if(inserted) time++;
    }
    
    return time;
    
    
}

//tc: O(n) or O(nlogn) depends on type of map used if unorderedmap used then insertion in o(1) else o(logn).
//sc: O(n)