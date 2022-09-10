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

//diagonal traversal: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1   


//approach: The approach is same as the vertical order traversal.
//since we can see that the elements that are right to a node come in the same diagonal
//so we will perform a preorder traversal and create a map and store the root at 0, left of a node at xcoord+1 and right at same
//xcoord.

//REMEMBER : THIS QUES CANNOT BE DONE BY NORMAL LEVEL ORDER TRAVERSAL AS there are issues coming when
//          in the order of the elements recieved in the ans vector.


void diagonalRecursive(Node* root, map<int, vector<int>>& ansmap, int level){
    
    //base case 
    if(root==NULL) return ;
    
    //doing by preorder N-> L-> R
    ansmap[level].push_back(root->data);
    
    diagonalRecursive(root->left, ansmap, level+1);
    diagonalRecursive(root->right, ansmap, level);
    
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;

    
    map<int, vector<int>> ansmap;
    
    diagonalRecursive(root, ansmap, 0);
    
    for(auto it: ansmap){
        for(auto i: it.second){
            ans.push_back(i);
        }
    }
    
    return ans;

    
}