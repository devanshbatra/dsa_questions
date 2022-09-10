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

//diameter of binary tree is the longest distance between any two end points (whether it be the root or leaf nodes).
/*
approach: 
    There are three ways by which we can have the longest path as our ans (shown in ss).
    1) connecting two end points in the left subtree itself without including root.
    2) connecting two end points in the right subtree itself without including root.
    3) connectng both root, right and left sub tree.

    so we will find the these three paths and then we will select the longest of them
    dia = max[dia(leftSubTree), dia(rightSubtree), (heigth(left)+ height(right)+1)]

*/
//used in dia function
// int height_tree(Node* root){
        
//         if(root==NULL) return 0;
        
//         int height = max(height_tree(root->right), height_tree(root->left)) + 1;
//         return height;
        
//     }

// int diameter(Node* root) {
        
//         //base case
//         if(root==NULL) return 0;
        
//         int option1 = diameter(root->right);
//         int option2 = diameter(root->left);
//         int option3 = height_tree(root->left)+height_tree(root->right)+1;
//         int dia = max(option1, max(option2, option3));
        
//         return dia;
        
//     }

//but in this method the time complexity is coming O(n^2) as at every step we are calculating height also
// which is not good at all.

/*
SAME APPROACH WITH OPTIMISED METHOD(O(n)) - behtreen solution.
    - since we are traversing every node for the diameter already, so why can we calcuate height also altogether.
    - we will make the return type as a pair and will return a pair of diameter of that part and height of 
        that part which is used in the calculation of diameter. 
        dia = maximum of[leftdia, rightdia, (left_height+right_height+1)]
*/

pair<int, int> fastDiameter(Node* root){

    //base case- for null node both dia and height = 0
    if(root==NULL) {
        pair<int, int> p = make_pair(0, 0);//taking first as height and second as diameter.
        return p;
    }

    // recursive calls 
    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);

    //recursive call ends now we can fetch our height and dia.
    int option1 = left.second;//left sub tree ka dia
    int option2 = right.second;//right sub tree ka dia
    int option3 = left.first+right.first+1;

    int height = max(left.first, right.first)+1;
    int dia = max(option1, max(option2, option3));

    pair<int, int> heightDiaPair = make_pair(height, dia);
    return heightDiaPair;
}
//TC: O(n).
//SC: O(height) and height can be max n so - O(n).

int main(){

    Node* root;

    root = buildTree(10);
//20 40 -1 -1 60 -1 -1 30 -1 -1 - ans should be 4.

    pair<int, int> ans = fastDiameter(root);
    int dia = ans.second;

    cout<<endl<<"The diameter of the given tree is: "<<dia;

    
    

    return 0;
}