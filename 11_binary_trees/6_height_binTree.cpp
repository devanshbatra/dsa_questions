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


/*
height of binary tree = longest path between root and leaf nodes.
https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

I have two approaches , 
appraoch 1(standard easy recursive): we can derive a formula for height  = max(heigth(rightSubtree), heigth(leftsubtree))+1(for root).
                                    now if we apply this formula at every node through recursion then we can 
                                    calculate the total height.(try doing dry run using recursive tree.)

                                    Time comp: O(n) visited every node once.
                                    space comp: O(h)=>O(n) how?:  if we make a function call stack
                                                    highest stack would of the max height.
                                                    and for a skew tree( where only only or only right elements are there)
                                                    we have height = nodes n
                                                    so SC = O(n)

approach 2: in previous questions , we have done level order traversal. Remember we used a saperator as null
            to  separate the different levels to put an endl.
            similary here whenever we will encounter null we will increase the height variable.

*/


//DO THIS QUESTION ALSO: Max width of a binary tree.    
// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

int height_1(Node* root){
    //base case
    if(root==NULL) return 0; //null ki to kya he height hogi

    int height = max(height_1(root->left), height_1(root->right))+1;

    return height;
}


int height_2(Node* root){
        
        queue<Node*> q;
        q.push(root);
        
        q.push(NULL);
        int height = 0;
        
        while(!q.empty()){
            
            Node* temp = q.front();
            q.pop();
            
            if(temp==NULL){
                height++;
                if(!q.empty()) q.push(NULL);
            }else{
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            
        }
        
        return height;
        
        
    }

int main(){

    Node* root;

    root = buildTree(1);
//3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<endl<<"The height through 1st recursive method is: "<<height_1(root);
    cout<<endl<<"The height through 2nd level order queue method is: "<<height_1(root);

    
    

    return 0;
}


