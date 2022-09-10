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
You are given inorder and preorder of a tree you have to build the tree.(IMPORTANT QUES).
https://practice.geeksforgeeks.org/problems/construct-tree-1/1
solved on leetcode too. see for codestudio.

APPROACH:
    Divide the problem in subproblems
    at each individual node we will be provided with two arrays and we need to find root (first element of
    preorder) and then find the position of that root in the inorder(for that we will not run a function
    continuously we will create a map in the beginning.).

    we will not break the array instead we will pass on the preorderStart and end as well as inorderstart
    and end.

    Also we need to pass the map in the function as a reference else it will be creating a new map at every
    call which will take time as and hence you will face tle.

*/

Node *solve(int in[], int pre[], int inorderStart, int inorderEnd, int preorderStart, int preorderEnd, map<int, int> &nodetoindex)
{
    // base case
    if (preorderStart > preorderEnd || inorderStart > inorderEnd)
        return NULL;

    // processing
    int rootdata = pre[preorderStart];
    Node *root = new Node(rootdata);

    // now finding new inorder and new postorder for left and right

    // find pos of root in inorder
    int position = nodetoindex[rootdata];

    int noOfLeft = position - inorderStart;
    // int noOfRight = inorderEnd-position;

    // recursive calls

    root->left = solve(in, pre, inorderStart, position - 1, preorderStart + 1,
                       preorderStart + noOfLeft, nodetoindex);

    root->right = solve(in, pre, position + 1, inorderEnd, preorderStart + noOfLeft + 1,
                        preorderEnd, nodetoindex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{

    int inorderStart = 0, inorderEnd = n - 1;
    int preorderStart = 0, preorderEnd = n - 1;

    // hashing the inorder so that we do not need to find for the index of any element in inorder
    map<int, int> nodetoindex;
    for (int i = 0; i < n; i++)
    {
        nodetoindex[in[i]] = i;
    }

    Node *root = solve(in, pre, inorderStart, inorderEnd, preorderStart, preorderEnd, nodetoindex);

    return root;
}

// TC: O(nlog(N)) as first we traaverse the whole inorder and insert in the map at each element
//  and insertion in map takes log(n) it is inside for loop n so nlog(n) now
// the solve function traverse each node once so O(n).

// SC: O(n) for map and call stack.

// SIMILARLY: we can also build the tree using the inorder and postorder
//  as inorder has LNR and post order has LRN so we will find the root from post order and
// find its position and number of left and right from inorder.
// similar complexities, here is the solution(try yourself first ;-) )
Node *solve(int in[], int inStart, int inEnd, int post[], int postStart, int postEnd, map<int, int> &nodetoindex)
{

    // base case
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    // processing
    Node *root = new Node(post[postEnd]);

    // finding new start and ends for inorder and postorder for the left and right of this node.

    // finding position of root in inorder from map
    int position = nodetoindex[root->data];
    int numsRight = inEnd - position;

    // recursive calls
    root->left = solve(in, inStart, position - 1, post, postStart, postEnd - numsRight - 1, nodetoindex);
    root->right = solve(in, position + 1, inEnd, post, postEnd - numsRight, postEnd - 1, nodetoindex);

    return root;
}

// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{

    // hashing the inorder array
    map<int, int> nodetoindex;
    for (int i = 0; i < n; i++)
    {
        nodetoindex[in[i]] = i;
    }

    int inStart = 0, inEnd = n - 1;
    int postStart = 0, postEnd = n - 1;

    return solve(in, inStart, inEnd, post, postStart, postEnd, nodetoindex);
}

//If one of the traversal methods is Inorder then the tree can be constructed, otherwise not.

/*
Therefore, following combination can uniquely identify a tree.

    Inorder and Preorder. 
    Inorder and Postorder. 
    Inorder and Level-order.
*/