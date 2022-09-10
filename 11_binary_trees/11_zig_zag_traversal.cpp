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
before solving this ques , first remember what do we do in level order traversal.
we traverse root, pop it, then push its right and left to queue.
now again entering the while loop we explore left and same.

but what if we want to cover the whole level in one while iteration.
we would use a for loop inside the while and pop out all the elements.
Actually this is also a better method to enter space in levels instead of using NULL saperator.
So, try it also in level order.
(seen striver's video)

approach: 
    make a vector of vectors(or vectors here) such that inner vector store the levels with specific order
    push root in node
    enter the !q.empty() while loop
    now use a for loop to process all the elements present in the queue.
    process means: 
        1) store them in the row array in the specific order
        2)push their left and right in the queue.
    
    remember to change the order flag on exit of for loop for the next level.
*/

vector<int> zigZagTraversal(Node* root){

    vector<int> result;
    queue<Node* > q;
    q.push(root);
    bool reversed = false;
    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);
        for(int i=0; i<size; i++){

            Node* currNode = q.front();
            q.pop();
            int index = reversed?size-i-1: i;
            row[index] = currNode->data;

            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);

        }
        //change the reversed flag
        reversed = !reversed;
        //insert the level row in result
        for(auto i: row){
            result.push_back(i);
        }
    }
    return result;

}

//tc: O(n)
//sc: O(n) aage jaakar tree ka har level itna bada ho jata hai ki wo n ko he tend krne lagta hai.

int main(){

    Node* root;

    root = buildTree(10);
//20 40 -1 -1 60 -1 -1 30 -1 -1 

    vector<int> ans = zigZagTraversal(root);
    cout<<endl;
    cout<<"zig zag pattern is: ";
    for(auto i: ans){
        cout<<i<<" ";
    }


    return 0;
}