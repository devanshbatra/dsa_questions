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


//approach: Whenever we see the view from the left we see the first element of every level
//so simply do a level order traversal and push the first element into the ans.
vector<int> leftView(Node *root)
{
   
   vector<int> ans;
   //base case
   if(root==NULL) return ans; //ye bhi dekh liya karo kai baar no. of nodes 0<=n<=10000 hoti hai.
   queue<Node* > q;
   q.push(root);
   
   while(!q.empty()){
       int n = q.size();//as size would be variable
       for(int i=0; i<n; i++){
           Node* currNode= q.front();
           if(i==0){ //sirf first element he push kiya har level ka
               ans.push_back(currNode->data);
           }
           q.pop();
           if(currNode->left) q.push(currNode->left);
           if(currNode->right) q.push(currNode->right);
       }
       
       
   }
   return ans;
}

//RIGHT VIEW OF BINARY TREE
//approach: is bhi level order traversal lagega but bas last element of level push karna hai.
    vector<int> rightView(Node *root)
    {
          vector<int> ans;
          //base case
          if(root==NULL) return ans; //ye bhi dekh liya karo kai baar no. of nodes 0<=n<=10000 hoti hai.
          queue<Node* > q;
          q.push(root);
          
          while(!q.empty()){
              int n = q.size();//as size would be variable
              for(int i=0; i<n; i++){
                  Node* currNode= q.front();
                  if(i==n-1){ //sirf first element he push kiya har level ka
                      ans.push_back(currNode->data);
                  }
                  q.pop();
                  if(currNode->left) q.push(currNode->left);
                  if(currNode->right) q.push(currNode->right);
              }
              
              
          }
   
          return ans;
    }

//APPROACH 2:  LEFT VIEW BY RECURSIVE APPROACH
//doing it by recursive way (preorder traversal).
void recursiveLeft(Node* root, int level, vector<int> &ans){
    
    //base case
    if(root==NULL) return;
    
    //now see agar ans ka size level ke barabar hai to matlab naya level shuru hua hai.(sochke dekho).
    if(level==ans.size()) ans.push_back(root->data);
    
    recursiveLeft(root->left, level+1, ans);
    recursiveLeft(root->right, level+1, ans);
    
}


vector<int> leftView(Node *root)
{
   
    vector<int> ans;
    recursiveLeft(root, 0, ans);
    return ans;
   
   
}

//RECURSIVE APP FOR RIGHT VIEW
//doing it by recursive way (POSTORDER traversal).
    void recursiveRight(Node* root, int level, vector<int> &ans){
        
        //base case
        if(root==NULL) return;
        
        //now see agar ans ka size level ke barabar hai to matlab naya level shuru hua hai.(sochke dekho).
        if(level==ans.size()) ans.push_back(root->data);
        
        //rigth view mein pehle right ki taraf chale jayenge.
        recursiveRight(root->right, level+1, ans);
        recursiveRight(root->left, level+1, ans);
        
    }


    // also try this question: 
    // https://leetcode.com/problems/n-ary-tree-level-order-traversal/