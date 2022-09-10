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

//In general traversals that we know till now like level order traversals or pre, in, post, all were
//consuming a space complexity of O(n) as they needed either a queue or a functional call stack.

//using morris traversal we can find any traversal like inorder, preorder or postorder.

//In this traversal we do not need recursion to backtrack, it will be handled by making temporary links.
//we will make a temporary link from predecessor to the current node.
//predecessor of a node is found by moving one step to the left and then moving to right until null.
//SEE WHOLE ALGORITHM IN SS.


 //finding predecessor
Node* findPred(Node* curr){
    Node* temp = curr->left;
    while(temp->right!=NULL && temp->right!=curr){
        temp = temp->right;
    }
    return temp;
}
    
//morris traversal - inorder
void solve_inorder(Node* root, vector<int> &v){
    
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left){
            Node* pred = findPred(curr);
            if(pred->right==NULL){ //making temporary links
                pred->right = curr;
                curr= curr->left;
            }else{ //removing temporary links - means came here after backtrack
                pred->right = NULL;
                v.push_back(curr->data);
                curr = curr->right;
            }
        }else{
            v.push_back(curr->data);
            curr = curr->right;
        }
    }
    
}
//morris traversal - preorder
void solve_preorder(Node* root, vector<int> &v){
    
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left){
            Node* pred = findPred(curr);
            if(pred->right==NULL){ //making temporary links
                v.push_back(curr->data);
                pred->right = curr;
                curr= curr->left;
            }else{ //removing temporary links - means came here after backtrack
                pred->right = NULL;
                curr = curr->right;
            }
        }else{
            v.push_back(curr->data);
            curr = curr->right;
        }
    }
    
}

