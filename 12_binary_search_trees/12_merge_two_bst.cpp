
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

//MERGE TWO BSTs
//here we will be given roots of two bst and we need to return the root of merged bst.

//approach 1: we know that inorder of bst is sorted
// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0
// 1) find and store inorder traversal of both the bst.
// 2) then apply merge two sorted arrays and merge them into one array.
// 3) then we know how to make a bst using given inorder traversal using the binary search approach
// 4) return the tree
// TC: O(m)+O(n)+O(m+n)+O(m+n) = O(m+n).
// SC: O(m+n).

void traverse(Node * root, vector<int>& inorder){
    
    if(root==NULL) return;
    
    //LNR
    traverse(root->left, inorder);
    inorder.push_back(root->data);
    traverse(root->right, inorder);
}

vector<int> mergeSortedArray(vector<int> v1, vector<int> v2){
    
    int n1 = v1.size();
    int n2 = v2.size();
    
    vector<int> ans(n1+n2);
    
    int i=0, j=0;
    int index = 0;
    
    while(i<n1 && j<n2){
        
        if(v1[i]<=v2[j]){
            ans[index++] = v1[i++];
        }else if(v2[j] <= v1[i]) {
            ans[index++] = v2[j++];
        }
        
    }
    
    while(i<n1){
        ans[index++] = v1[i++];
    }
    while(j<n2){
        ans[index++] = v2[j++];
    }
    
    return ans;
}

Node* inorderToBst(vector<int>& v, int s, int e){
        
    if(s>e) return NULL;
    
    int mid = s+(e-s)/2;
    Node* newnode = new Node(v[mid]);
    
    //calling left and right
    newnode->left = inorderToBst(v, s, mid-1);    
    newnode->right = inorderToBst(v, mid+1, e);
    
    return newnode;
    
}

Node *mergeBST(Node *root1, Node *root2){
    
    vector<int> inorder1;
    vector<int> inorder2;
    traverse(root1, inorder1);
    traverse(root2, inorder2);
       
    vector<int> merged = mergeSortedArray(inorder1, inorder2);
    
    return inorderToBst(merged, 0, merged.size()-1);
}


/*
APPROACH 2: If it needs to be done in less space rather than O(N+M) if we need to do it in O(h1+h2). Then
            we will use linked lists 
            The question will be divided into 3 different questions: 
            1) form the sorted ll from both the bst (individually important question)
            2) merge two sorted linked list. (individually important question)
            3) form bst from a sorted linked list (individually important question)https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
*/

//to convert a bst into a sorted linked list
//same question already done using storage as vector but here, we need to do that in O(h1+h2) space complexity
// So we will do it using recursion. Lets make a doubly linked list using this.
// for recursion focus on one node get the head of the ll of the right sub tree and then form links with node
// then call for recursion of the ll for left subtree and for the links and write the base and its done.


//hame jahan jahan jaan hai for making a linked list wahan jaakar head ko set krte jaa rhe h
//right mein pehle isliye gaye taki ek dum end mein head ekdum chotte element pe point kr 
//rha hoga which is in the extreme left

//1) step 1 form dll(for practices waise ll se bhi chal jayega) from bst
void formDll(Node * root, Node * & head){

    if(root==NULL) return;

    formDll(root->right, head);

    root->right= head;
    // if(head) cout<<"linked "<<root->data<<" ka to right to "<<head->data<<endl;
    if(head) head->left = root;

    head= root;

    formDll(root->left, head);
}

// 2)2ND STEP MERGE SORTED LL
//ek head aur tail bana liya aur shuru mein chote par laga diya ab h1 aur h2 ko aage badhate jao
//aur chote wale par tail lagate jao.
Node * mergeSortedList(Node * head1, Node * head2){
    Node * head= NULL;
    Node * tail = NULL;

    while(head1!=NULL && head2!=NULL){

        if(head1->data < head2->data){

            if(head==NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }else{
                tail->right = head1;
                tail = tail->right;
                head1 = head1->right;
            }

        }else{

            if(head==NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else{
                tail->right = head2;
                tail=tail->right;
                head2 = head2->right;
            }

        }

    }
    //agar koi bacha ho
    while(head1!=NULL){
        tail->right = head1;
        tail = tail->right;
        head1 = head1->right;
    }
    while(head2!=NULL){
        tail->right = head2;
        tail = tail->right;
        head2 = head2->right;
    }

    return head;

}

// 3) KA UTILITY FUNC.
int countNodes(Node* head){
    int count = 0;
    while(head!=NULL) {
        count++;
        head = head->right;
    }
    return count;
}

//3)
Node* formBstFromList(Node * &head, int n){
    
    //base case
    if(n<=0 || head==NULL) return NULL;
    
    Node * leftTree = formBstFromList(head, n/2);
    
    Node* root = new Node(head->data);
    
    root->left = leftTree;
    
    head = head->right;
    
    root->right = formBstFromList(head, n-(n/2)-1);//n mein se aadhe left le gaya, 1 root le gaya bache n-n/2-1 
    //agar n/2-1 bhejoge to nhi chalega bcoz for integer
    //5/2 -1 = 1 but
    // 5-5/2-1 = 2.
    return root;
    
    
}

//MAIN FUNCTION
Node *mergeBST(Node *root1, Node *root2){
    // Write your code here.
    //1) form dll from bst
    Node* head1 = NULL;
    Node* head2 = NULL;
    formDll(root1, head1);
    formDll(root2, head2);

    //2) merge sorted ll
    Node* head = mergeSortedList(head1, head2);
  
    //3) form bst from sorted ll in order of n time.
    int n = countNodes(head);
    return formBstFromList(head, n);
    
}
