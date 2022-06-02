/*
Flatten linked list: 
https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655?leftPanelTab=0

A linked list will be given with next as well as child nodes in sorted order
we have to flattenn the linked list
*/
#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            data = d;
            next = NULL; // similar to ---> (*this).next;
        }

        // destructor - will be called automatically when we free the memory for a node.
        ~Node(){
            int value = this->data;

            //iski koi zaroorat nahi hai as next wala link toh ham aise he free kr rhe h code mein.
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"memory freed for node with value: "<< value<<endl;
        }
};

void printList(Node* &head){
    if(head==NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

void insertAtHead(Node* &head, int d){
    if(head==NULL){
        Node* newnode = new Node(d);
        head = newnode;
        return;
    }
    //creating a new node for the given data
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd2(Node* &head, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    if(head==NULL){
        head = temp;
        return;
    }
    Node* tail = head;
    //traversing to the end 
    while(tail->next!=NULL) tail = tail->next;

    tail->next = temp;
}


/*
lec-58
Intuition-
We will do it with a very good recursive approach 
- assume we have a sorted vertical list(of the first node) and a sorted horizontal linked list given by
  recursion.
- Now we have to do just one step of merging the list and the base case, rest case the recursion
    will handle itself.
- 
*/


//merging two split linked lists- utility function
Node* merge_sorted(Node* a, Node* b){
    //base case
    if(a==NULL) return b;
    else if(b==NULL) return a;

    Node* result = NULL;
    //rc
    if(a->data<=b->data){
        result = a;
        result ->next = merge_sorted(a->next, b);
    }else{
        result = b;
        result->next=merge_sorted(a, b->next);
    }

    return result;
}

Node* flatten(Node* head){
    //base case
    if(head==NULL || head->next==NULL) return head;

    //rc
    Node* down = head;
    Node* right = flatten (head->next);
    //now remove both links
    down->next = NULL;

    //merging the two
    Node* result = merge_sorted(down, right);  
}