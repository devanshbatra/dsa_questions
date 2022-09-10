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


/*Given a binary tree of size  N, a node and a positive integer k., Your task is to complete the
 function kthAncestor(), the function should return the kth ancestor of the given node in the binary
  tree. If there does not exist any such ancestor then return -1.
  
  approach 1: (taking extra space)- we can do this by storing the path till node in a vector and then
                finding the kth element from the last.

    approach 2: we will do it recursively, at every node we will check if it is null or equal to node.
                if null return null, if node return node.
                base case over.can also see ss.

                go to right, go to left
                if(right or left !=NULL) that means node was found increase count and compare count with k.
                
  */


//approach 2:  - tc: O(n), sc: O(n)
 Node* solve(Node* root, int k, int node, int& count){
    
    //base case
    if(root==NULL){
        return NULL;//first one is node and second one is number of ancestor.
    }
    if(root->data==node) {
        return root;
    }
    
    //recursive calls-null bhi nhi h aur node ke equal bhi nhi
    Node* left = solve(root->left, k, node, count);
    Node* right = solve(root->right, k, node, count);
    
    //now backtrack
    if(left!=NULL && right==NULL ){
        count++;
        if(count==k){
            count=INT_MIN; //taaki wapas k ke equal na aa paye.
            return root;
        }
        else return left;
    }
    else if(left==NULL && right!=NULL){
        count++;
        if(count==k){
            count=INT_MIN; //taaki wapas k ke equal na aa paye.
            return root;
        }
        else return right;  
    }
    else {
        return NULL;
    }
    
}


int kthAncestor(Node *root, int k, int node)
{

    int count = 0;
    Node* ans = solve(root, k, node, count);
    if(ans==NULL) return -1;
    if(ans->data==node) return -1;//kahin abhi tak kth ancestor pahaucha he nhi tha.
    return ans->data;

}


//APPROACH 1: homework - path nikalne wala method.
void solve(Node* root, int k, int node, vector<int> path, vector<int>& ans){
    
    //base case
    if(root==NULL) return;
    if(root->data==node){
        path.push_back(root->data);
        ans = path;
    }
    
    //add to path.
    path.push_back(root->data);
    
    solve(root->left, k, node, path, ans);
    solve(root->right, k, node, path, ans);
    
    //backtrack
    path.pop_back();
    
    
}


int kthAncestor(Node *root, int k, int node)
{

    vector<int> path, ans;
    solve(root, k, node, path, ans);
    
    int n = ans.size();
    if(n<=k) return -1;
    
    return ans[n-1-k];
    

}