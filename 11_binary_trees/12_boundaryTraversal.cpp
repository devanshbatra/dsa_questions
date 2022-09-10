#include<iostream>
#include<queue>
#include<utility>

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
The approach is that pehle we will print the left nodes, then the leaf nodes and then the right nodes.
Now - left nodes -  should not include the root(will print first) and the leaf. Remember there
        may be a chance when left node is not available then we have to check right node also
        as it will complete the boundary.

leaf node print is easy.
right nodes- we have to leave the leaf nodes as well as we need to push the elements in reversed order.
            for reverse order we will use head recursion.
            and remember to check for left nodes if the right node is not available as it that case
            left node may be completing the boundary.
*/
void left(Node* root, vector<int> & ans){
    //base case 
    if(root==NULL || (root->left==NULL && root->right==NULL) ) return;
    
    ans.push_back(root->data);
    if(root->left){
        left(root->left, ans);
    }else{
        left(root->right, ans);
    }
}
void leaf(Node* root, vector<int> & ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    
    leaf(root->left, ans);
    leaf(root->right, ans);
}
void right(Node* root, vector<int> & ans){
    //base case
    if( root==NULL || root->right==NULL && root->left==NULL ) return;
    
    if(root->right){
        right(root->right, ans);
    }else{
        right(root->left, ans);
    }
    
    //reverse krne ke liye head recursion use kiya , so wapas aane par he push krega.
    ans.push_back(root->data);
    // cout<<root->data<<" ";
}

vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    ans.push_back(root->data);//so that baar baar root print na ho.
    left(root->left, ans);
    
    //for left subTree
    leaf(root->left, ans);
    
    //for right subTree
    leaf(root->right, ans);
    
    right(root->right, ans);
    return ans;
}




int main(){

    Node* root;

    root = buildTree(10);
//20 40 -1 -1 60 -1 -1 30 -1 -1 

    vector<int> ans = boundary(root);
    cout<<endl;
    cout<<"boundary pattern is: ";
    for(auto i: ans){
        cout<<i<<" ";
    }


    return 0;
}