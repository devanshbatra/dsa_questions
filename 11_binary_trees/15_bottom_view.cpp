#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

//Bottom view: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
//approach : similar to the vertical order: maintain the mapping of int-xcoord and vector<int> nodes
    //but when pushing in the ans array push just the last element of every number of number line.
    //OR OR OR you can say that just take map<int,int> and keep assigning node to xcoord
    //the last assigned number would be the ans
    vector <int> bottomView(Node *root) {
        map<int, int> ansmap;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            Node* currNode = q.front().first;
            int xcoord = q.front().second;
            
            ansmap[xcoord]=currNode->data;
            q.pop();
            
            if(currNode->left) q.push(make_pair(currNode->left, xcoord-1));
            if(currNode->right) q.push(make_pair(currNode->right, xcoord+1));
            
        }
        
        vector<int> ans;
        for(auto it: ansmap){
            ans.push_back(it.second);
        }
        return ans;
    }