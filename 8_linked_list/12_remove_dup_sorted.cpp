#include<iostream>
using namespace std;
// removing duplicates from a sorted linked list
// in sorted linked list: 1 2 2 2 3 3 4 4 5
// we have an advantage that we find all the duplicated at adjacent positions.
// so we can just traverse a pointer and check for its next is similar to itself or not.

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

void removeDuplicates(Node* & head){
    //agar empty he hai to pehle he check karlo.
    if(head==NULL) return;
    Node* curr = head;
    while(curr->next!=NULL){
        if(curr->data == curr->next->data && curr->next!=NULL ){
            Node* temp = curr->next;
            curr-> next = curr->next->next;
            temp->next = NULL;
            delete temp; //important step for interview perspective.
        }else{
            curr = curr->next;
        }
    }
}

int main(){


    Node *head = NULL;
    
    insertAtHead(head, 4);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
 

    cout<<"Inserting 5 at end giving only head"<<endl;
    insertAtEnd2(head, 5);
    printList(head);

    //removing duplicates
    removeDuplicates(head);

    cout<<"After removing duplicates : "<<endl;
    printList(head);
    return 0;
}
// time complexity : saare nodes traverse kar rhe h - O(n).
// space complexity: recursion to hai nhi aur koi extra data structure bhi use nhi kia
// so O(1).


//do this ques too , its famous as well as good: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//found this in potd.