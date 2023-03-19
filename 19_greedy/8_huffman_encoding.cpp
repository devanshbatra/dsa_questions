// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

//how is huffman tree made:
//take the two smallest characters
//add their values and make them child of root having sum of them.
//aslo add this sum back to the array.
//now again repeat.
    
class Node{
    public:
        char ch;
        int freq;
        Node* right;
        Node* left;
        
        Node(char ch, int freq){
            this->ch = ch;
            this->freq = freq;
            left=right=NULL;
        }
};

class comparator{
    public:
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

void inorder(Node* root, string store, vector<string>& ans){
    //base case
    if(root->left==NULL && root->right==NULL){
        ans.push_back(store);
        return;
    }
    
    //rc
    //inorder lNr
    inorder(root->left, store+"0", ans);
    
    
    
    inorder(root->right, store+"1", ans);
    
}

vector<string> huffmanCodes(string S,vector<int> f,int N)
{
    //push all elements in the priority queue
    priority_queue<Node*, vector<Node*>, comparator> pq;
    for(int i=0; i<N; i++){
        Node* newnode = new Node(S[i], f[i]);
        pq.push(newnode);
    }
    
    //start making huffman tree
    //do nikalo add karo subtree banao, root ko wapas daalo
    
    while(pq.size()>1){
        Node* a = pq.top();
        pq.pop();
        Node* b = pq.top();
        pq.pop();
        
        int sum = a->freq + b->freq;
        
        Node* newnode = new Node('\0', sum);
        newnode->left = a;
        newnode->right = b;
        pq.push(newnode);
    }
    
    
    vector<string> ans;
    string store = "";
    inorder(pq.top(), store, ans);
    return ans;
}

//time complexity: O(nlog n)[for insertion of n nodes in the heap].
//space complexity: O(n).