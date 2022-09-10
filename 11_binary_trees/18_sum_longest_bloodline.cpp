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


//You have to print of the sum of elements coming in the longest path from root to leaves.
//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

//approach 1: 
/*
We will do the same way as we find the height of the tree but at every node we will also take the sum
of the elements covered till now.
Now don't be confused since it is a recursive algo so just focus on one case and let recursion solve
other cases.

TC: O(n).
SC: O(height) === O(n).derived by making function call stack
*/

pair<int, int> sumHeight(Node* root){
    
    if(root==NULL) {
        pair<int, int> p = make_pair(0,0);
        return p;
    }
    
    cout<<root->data<<endl;
    pair<int, int> left = sumHeight(root->left);
    pair<int, int> right = sumHeight(root->right);
    int leftsum = left.first;
    int rightsum = right.first;
    int leftheight = left.second;
    int rightheight = right.second;
    
    if(leftheight>rightheight){
        
        pair<int, int> temp = make_pair(leftsum+root->data, leftheight+1);//+1 for node itself
        return temp;
        
    }else if(leftheight<rightheight){
        pair<int, int> temp = make_pair(rightsum+root->data, rightheight+1);//+1 for node itself
        return temp;
    }else{
        
        if(rightsum>leftsum){
            pair<int, int> temp = make_pair(rightsum+root->data, rightheight+1);//+1 for node itself
            return temp;
        }else{
            pair<int, int> temp = make_pair(leftsum+root->data, leftheight+1);//+1 for node itself
            return temp;
        }
        
    }
    
}

//approach 2: isme bhi recursive way se karenge but isme ham uppar se he length aur sum lete hue 
//niche jayenge aur jaise he null milega tab agar len>maxlength hui to maxsum aur maxlength ko 
//update krte jayenge. approach 1 mein neeche se uppar tha isme uppar se neeche hai.
void solve(Node* root, int& maxsum, int& maxlength, int sum, int len){
    
    if(root==NULL){
        //now there may three cases ki ye path previously max path se 
        //1)greater h(we need to update the maxlength and maxsum)
        //2)equal h(we need to update the sum)
        //3)smaller h(dont care)
        
        if(len>maxlength){
            maxlength = len;
            maxsum = sum;
        } 
        else if(len==maxlength){
            maxsum=sum;
        }
        return;
        
    }
    
    solve(root->left, maxsum, maxlength, sum+root->data, len+1);
    solve(root->right, maxsum, maxlength, sum+root->data, len+1);
    
}//time and space both O(n).


int main()
{

    Node *root;

    root = buildTree(10);
    // 20 40 -1 -1 60 -1 -1 30 -1 -1
    cout<<endl;

    cout<<"the sum of longest bloodline from approach 1 is: "<<sumHeight(root).first<<endl;

    //for approach 2
    int maxsum=0;
    int maxlength = 0;
    solve(root, maxsum, maxlength, 0, 0);
    cout<<"the sum of longest bloodline from approach 2 is: "<<maxsum;

    return 0;
}