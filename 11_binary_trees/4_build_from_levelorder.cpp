#include<iostream>
#include<stack>
#include<queue>

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

//we have to build the tree from values arranged in level order 
//remember level order means we first go from root, then next level roots, then next level roots
//and this is done with queues.
void buildTree_level(Node* root){

    queue<Node*> q;
    cout<<"Enter the data for the root element: ";
    int d;
    cin>>d;
    root = new Node(d);

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<<temp->data<<": ";
        int d;
        cin>>d;
        if(d!=-1){
            temp->left= new Node(d);;
            q.push(temp->left);
        }

        cout<<"Enter the data to the right of "<<temp->data<<": ";
        int r;
        cin>>r;
        if(r!=-1){
            temp->right= new Node(r);
            q.push(temp->right);
        }


    }


}


int main(){

    Node* root;

    buildTree_level(root);

    return 0;
}