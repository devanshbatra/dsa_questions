#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        // constructor
        Node(int d){
            this->data = d;
            this ->next = NULL;
            this -> prev = NULL;
        }
        //destructor for handling delete keyword
        ~Node(){
            int value = data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory freed for node with value: "<<value<<endl;
        }
};

//printing 
void printList(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

//insert
void insertAtEnd(Node *& head, int d){
    if(head==NULL){
        Node * newnode = new Node(d);
        head = newnode;
        return;
    }
    Node * newnode = new Node(d);
    //traversing to end
    Node * temp  = head;
    while(temp->next!=NULL) temp = temp ->next;

    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}
//reverse
void reverse(Node* &head, Node* curr, Node* prev){
    //base case
    if(curr==NULL){
        head = prev;
        return;
    }
    //processing
    Node* temp = curr->next;
    curr->next = prev;
    curr->prev = temp;
    
    prev=curr;//updations
    curr=temp;//updations

    //recursive calls
    reverse(head, curr, prev);
}

int main(){
    Node* head = NULL;
    insertAtEnd(head, 5);
    insertAtEnd(head, 3);
    insertAtEnd(head, 8);
    insertAtEnd(head, 1);
    insertAtEnd(head, 0);
    insertAtEnd(head, 2);
    printList(head);

    Node* prev=NULL;
    Node* curr = head;
    reverse(head, curr, prev);
    cout<<"after reversal: "<<endl;
    printList(head);

    return 0;
}