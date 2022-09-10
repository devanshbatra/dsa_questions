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

/*
Maximum sum of non adjacent nodes (VERY GOOD CONCEPT AND VERY IMPORTANT QUESTION)
    https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
Given a binary tree with a value associated with each node, we need to choose a subset
 of these nodes such that sum of chosen nodes is maximum under a constraint that no two 
 chosen node in subset should be directly connected that is, if we have taken a node in our
  sum then we can’t take its any children or parents in consideration and vice versa.


    approach: We will find two values at each node(starting from end).
        1st will be the sum if we include this node and second will be the sum if we don't include.
        if(root==NULL) return <0,0>

        while backtrack
        //includes  = this->data + not includes of left and right.
        //notinclude= max(inc, notinc left) + max(inc, notinc right);

        TC = O(n)
        SC = O(h) == O(n) for skew tree.   
*/

pair<int, int> solve(Node* root){
        //base case
        if(root==NULL){
            return make_pair(0, 0);
        }
        
        //this is generally a back track algo so we need to first do rc then from bottom we will start returning pairs
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        //for this node
        //includes  = this->data + not includes of left and right.
        int includes = root->data + left.second + right.second;
        
        //notinclude= max(inc, notinc left) + max(inc, notinc right);
        int notIncludes = max(left.first, left.second) + max(right.first, right.second);
        
        return make_pair(includes, notIncludes);
        
    }
  
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }