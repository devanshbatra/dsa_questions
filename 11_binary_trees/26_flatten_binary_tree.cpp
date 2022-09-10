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
Given the root of a binary tree, flatten the tree into a "linked list":
    -The "linked list" should use the same Node class where the right child pointer points
        to the next node in the list and the left child pointer is always null.
    -The "linked list" should be in the same order as a pre-order traversal of the binary tree.

    https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

    approach 1: tc: O(n), sc: O(N) - bad approach- kisi bhi traversal se traverse karte jaao and 
    ek linked list banate jao (IT IS NOT INPLACE).

    approach 3: tc: o(n) , sc : o(n) - recursive approach using any of level, pre, post, or inorder 
    and then adjusting links for each node. (TAKING O(N) SPACE).

    approach 3: tc: O(n) sc: O(1) - MORRIS TRAVERSAL


*/


//APPROACH 3 - morris

Node* findPred(Node* curr){
    Node* temp = curr->left;
    while(temp->right!=NULL && temp->right!=curr){
        temp=temp->right;
    }
    return temp;
}

void flatten(Node* root) {
        
    Node* curr = root;
    while(curr!=NULL){

        if(curr->left){
            Node* pred = findPred(curr);
            if(pred->right==NULL){
                //visit(curr)
                pred->right = curr;
                curr = curr->left;
            }
            else{
                //visiting after backtrack
                Node* temp = curr->right;
                curr->right = curr->left;
                curr->left=NULL;

                curr=temp;
                pred->right = curr;
            }
        }
        else{
            //visit curr
            curr=curr->right;
        }

    }
}



