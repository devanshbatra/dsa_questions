#include<iostream>
#include<queue>
#include<map>
#include<vector>

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
Vertical order traversal of binary tree(good question).
approach: see approach from babbar but not his code.
            assume the horizontal as a number line with 0 on root.(see ss)
            as we go left in level order traversal we move left i.e -1 on the number line
            and as we go right in level order traversal we move +1 on the number line.

            so create an ordered mapping of the number of the number line and the nodes occuring on it.
            then simply push that data orderly in ans array.
            See ss.
*/

    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        
        queue<pair<Node*, int>> q;
        //insert root
        pair<Node*, int> p = make_pair(root, 0);
        q.push(p);
        map<int, vector<int>> ansmap;
        
        while(!q.empty()){
            
            //retrieve front and back.
            Node* currNode = q.front().first;
            int level = q.front().second;
            //store to ansmap
            ansmap[level].push_back(currNode->data);
            
            q.pop();
            
            //now check for left and right.
            if(currNode->left){
                pair<Node* , int> temp;
                temp.first = currNode->left;
                temp.second = level-1;//decrease the level of number line while going left.
                q.push(temp);
            }
            if(currNode->right){
                pair<Node*, int> temp;
                temp.first = currNode->right;
                temp.second = level+1;
                q.push(temp);
            }
            
        }
        
        vector<int> ans;
        
        
        for(auto it: ansmap){
            for(auto i: it.second){
                ans.push_back(i);
            }
        }
        
        
        
        return ans;
        
    }




int main(){

    Node* root;

    root = buildTree(10);
//20 40 -1 -1 60 -1 -1 30 -1 -1 

    vector<int> ans = verticalOrder(root);
    cout<<endl;
    cout<<"Vertical order is: ";
    for(auto i: ans){
        cout<<i<<" ";
    }


    return 0;
}

/*
also see this question on leetcode it has some variation which makes it a tough question
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/
*/