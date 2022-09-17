//you will be given a array of preorder traversal
//now you need to form a binary search tree from the same.
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int d){
            data = d;
            this->right=NULL;
            this->left = NULL;
        }
};

/*
approach 1: Bruteforce
            1) as we did in intro of this folder for a bst without using the power of preorder.
            2) will take O(N^2) Time complexity.
*/
Node* insertNode(Node* root, int val){
    
    if(root==NULL){
        Node* newnode = new Node(val);
        return newnode;
    }
    
    if(val<root->data){
        root->left = insertNode(root->left, val);
    }else{
        root->right = insertNode(root->right, val);
    }
    
    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int n = preorder.size();
    Node* root = new Node(preorder[0]);
    for(int i=1; i<n; i++){
        root = insertNode(root, preorder[i]);
    }
    
    return root;
}


/*
approach 2: If we sort the preorder traveral then we would get inorder traversal as inorder of bst
            is sorted.
            now if we get inorder and preorder then we can construct a tree from them.

            TC: O(NlogN).
            SC: O(N).
*/
int binarySearch(vector<int> arr, int key, int l, int h){
    //base case
    if(l>h){
        return -1;
    }
    
    int mid = l+(h-l)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(key<=arr[mid]){
        return binarySearch(arr, key, l, mid-1);
    }else{
        return binarySearch(arr, key, mid+1, h);
    }
    
    
}

Node* formTree(vector<int> inorder, int instart, int inend, vector<int> preorder, int prestart, int preend){
    
    //base case
    if(instart>inend || prestart>preend ) return NULL;
    
    //finding root in inorder
    int index = binarySearch(inorder, preorder[prestart], instart, inend);
    int leftSpace = index-instart;
    // int rightSpace = inend-index;
    
    //recursive calls
    Node* newnode = new Node(preorder[prestart]);
    
    newnode->left = formTree(inorder, instart, index-1, preorder, prestart+1, prestart+leftSpace );
    
    newnode->right = formTree(inorder, index+1, inend, preorder, prestart+leftSpace+1, preend);
    
    return newnode;
    
    
    
}

Node* bstFromPreorder(vector<int>& preorder) {
    vector<int> inorder;
    inorder = preorder;
    sort(inorder.begin(), inorder.end());
    
    for(auto i: inorder){
        cout<<i<<" ";
    }
    //now our inorder is ready.
    //lets make some pointers for both the arrays to start our tree making
    int instart = 0, inend = inorder.size()-1;
    int prestart= 0, preend = preorder.size()-1;
    
    Node* ans = formTree(inorder, instart, inend, preorder, prestart, preend);
    
    return ans;
}

//approach 3: LAST FINAL AND THE BEST APPROACH TC: O(N) SC: O(H).

//we had seen a ques of validating the bst which involved the check of ranges at every node.
//here also we will do the same we will :
//1) make a recursive function with i as counter to the array, and max and min range
//2) base case would be if(i exceedes arr || arr[i] is out of max min range ) then return NULL
//3) if in range the make a newnode with that value.
//i++;
//4) recursively call newnode->left = fun(updated min and max, i).
//5) recursively call newnode->right = fun(updated min and max, i).

Node* solve(int min, int max, vector<int>& preorder, int &i){
    //base case
    if( i>=preorder.size() || preorder[i]>max || preorder[i]<min  ) return NULL;
    
    
    Node* newnode = new Node(preorder[i]);
    i++;
    newnode->left = solve(min, newnode->data, preorder, i);
    newnode->right = solve(newnode->data, max, preorder, i);
    return newnode;
    
}

Node* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return solve(INT_MIN, INT_MAX, preorder, i);
}

//more optimized would be if we do not use min variable and only use upper bound bas if condition mein 
//change karna padega.

//saare leetcode pe he kiye hain
