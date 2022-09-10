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

//LOWEST COMMON ANCESTOR: Given a Binary Tree with all unique values and two nodes value, n1 and n2.
// The task is to find the lowest common ancestor of the given two nodes. We may assume that either
// both n1 and n2 are present in the tree or none of them are present. 
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

//approach 1: bruteforce(not recomended at all)- we will store the path of n1 from root in a vector and path of root to n2 in
//another vector and then compare those vector from last the first common element found will be the 
//lowest common ancestor. But this is a very lengthy process.We are also taking extra space in form 
//of vectors and then also extra code to compare the two vectors.

/*approach 2: recursive(efficient): 
we will traverse to every node recursively and check if n1 or n2 is found
    // now at every node three cases exist:
    //1) found n1 or n2: return that n1 or n2(don't go down further).Now ancestors will know that they
         have n1 or n2
    //2) found null node: return null so that ancestors get to know that n1,n2 not found.
    //3) found a normal node other than n1,n2 - do nothing , go further and find its left and right
            //i)now if left!=NULL and right!=NULL that means this node has both n1 and n2 in it so return
                 the node.
            //ii) if one of either left or right is not NULL, then this means either n1 or n2 is present
                 under this so root will be anywhere upwards so return the node found.
            //iii) if both left and right are null , then that means there is no n1 or n2 under this
                 node move up return null.

*/

Node* lca(Node* root ,int n1 ,int n2 )
{
    
    //base case
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2) return root;
    
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    
    if(left!=NULL && right!=NULL ){
        return root;
    }
    if(left!=NULL && right==NULL) {
        return left;
    }
    else if(left==NULL && right!=NULL) {
        return right;
    }else {
        return NULL;
    }
   
}

