#include<iostream>
using namespace std;

//making a doubly linked list and applying different operations
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
// insert
void insertAtHead(Node* &head, int d){
    if(head==NULL){
        Node* newnode = new Node(d);
        head = newnode;
        return;
    }
    Node* newnode = new Node(d);
    newnode->next = head;
    head->prev = newnode;//extra line
    head = newnode;
}
void insertAtEnd(Node* &head, int d){
    //empty list condition
    if(head== NULL){
        Node* newnode = new Node(d);
        head = newnode;
        return;
    }
    Node* newnode = new Node(d);
    Node* temp = head;
    while(temp->next!=NULL) temp = temp->next;
    //reached on last node
    temp->next = newnode;
    newnode->prev = temp; //extra line
}
void insertAtMid(Node* &head, int d, int pos){
    //handling insertion at head
    if(pos==0) {
        insertAtHead(head, d);
        return;
    }

    Node *newnode  = new Node(d);
    Node *temp = head;
    int curr = 0;
    while(curr!=pos-1){
        temp = temp->next;
        curr++;
    }
    //handling tail insertion
    if(temp->next==NULL){
        insertAtEnd(head, d);
        return;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    newnode->prev = temp;
    temp->next = newnode;
}

//DELETION
void deleteAtHead(Node*& head){
    head->next->prev = NULL;
    Node* curr = head;
    head = head->next;

    //freeing memory
    curr->next = NULL;//important step (removing all links before deleting a node, otherwise address to next 
    //will also be deleted and the memory pointer chain will get disturbed)
    delete curr;
}

void deleteAtPos(Node *&head, int pos){
    //handling deletion at head
    if(pos==0){
        deleteAtHead(head);
        return;
    }
    //handling deletion at middle and end
    int curpos = 0;
    Node*temp = head;
    while(curpos<pos-1){
        temp = temp->next;
        curpos++;
    }
    //handling last position
    if(temp->next->next==NULL){
        Node* curr  = temp->next;
        temp->next = NULL;
        // curr->next=NULL;
        delete curr;
        return;
    }
    Node *curr = temp->next;
    curr->next->prev = temp;
    temp->next = curr->next;

    curr->next = NULL;
    delete curr;
}

int main(){
    //initiated from a node
    // Node* node1 = new Node(5);
    // Node* head  = node1;

    //initiated from NULL
    Node* head = NULL;
    cout<<"inserted 5 at start: "<<endl;
    insertAtHead(head, 5);
    printList(head);
    

    cout<<"inserted 3 at start: "<<endl;
    insertAtHead(head, 3);
    printList(head);

    cout<<"inserted 6, 12, 15 at end: "<<endl;
    insertAtEnd(head, 6);
    insertAtEnd(head, 12);
    insertAtEnd(head, 15);
    printList(head);

    cout<<"inserted 13 at 2nd position : "<<endl;
    insertAtMid(head, 13, 2);
    printList(head);

    cout<<"inserted 1 at 0th position : "<<endl;
    insertAtMid(head, 1, 0);
    printList(head);

    cout<<"inserted 33 at 7th position : "<<endl;
    insertAtMid(head, 33, 7);
    printList(head);

    //deletions    
    cout<<"deleted 5th position : "<<endl;
    deleteAtPos(head, 5);
    printList(head);

    cout<<"deleted 0th position : "<<endl;
    deleteAtPos(head, 0);
    printList(head);

    cout<<"deleted last 5th position : "<<endl;
    deleteAtPos(head, 5);
    printList(head);
    return 0;
}