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

//K SUM PATH: Given a binary tree and an integer K. Find the number of paths in the tree which
// have their sum equal to K. A path may start from any node and end at any node in the downward direction.
// https://practice.geeksforgeeks.org/problems/k-sum-paths/1


//approach: mai har ek node pe path banata jaunga, sum ke saath compare karata jaunga - traverse
//karte time.

void solve(Node* root, int k, int& count, vector<int> path){
    //base case
    if(root==NULL) return;
    
    
    //recursive call - we are on a node so store it in the path vector
    path.push_back(root->data);
    
    //ab pehle k se path ko compare kre is root pe ya phir leaf tk jaakar aur phir wapas aate hue.
    //compare kare?
    //do it after going to leaf(means head recursion). bcoz there are chances that a combination
    // path mathes k at parent (so count++) but at its child also it will match so again count++
    //which is not good.(aur isi cheez se bachne ke liye apna comparison peeche se shuru karo k aur path wala).
    
    solve(root->left, k, count, path);
    solve(root->right, k, count, path);
    
    //now compare
    int sum = 0;
    for(int i=path.size()-1; i>=0; i--){
        sum+=path[i];
        if(sum==k) count++;
    }
    
    //now on going back(backtracking) we should remove the last character from path
    path.pop_back();
    
}

int sumK(Node *root,int k)
{
    int count = 0;
    vector<int> path;
    solve(root, k, count, path);
    return count;
}
//TC: we traversed each node and at every node we compared the array path.
//since the max. length of path vector would be = height so tc: O(n*h) == O(n^2).

//sc: O(N) function call stack equal to height.