#include<iostream>
using namespace std;

// creating a linked list, traversing it and performing various functions on it.

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
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

void insertAtHead(Node* &head, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd2(Node* &head, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    Node* tail = head;
    //traversing to the end 
    while(tail->next!=NULL) tail = tail->next;

    tail->next = temp;
}
void insertAtEnd(Node* &tail, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    tail->next = temp;
    //updating tail
    tail  = temp;
}

void InsertAtMid(int data, int pos, Node * &head, Node * &tail){
    //now we have to cover some cases such that if the user wants to insert at position 0, then by this method 
    //we need a previous node which does not exist in case of pos 0.
    //condition for head
    if(pos==0) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    //creating a new node
    Node *newNode = new Node(data);
    int curPos = 0;

    while(curPos!=pos-1){
        temp = temp->next;
        curPos++;
    }
    //applying condition for tail, if the intended position is the last position then we have to update
    //tail also
    if(temp-> next == NULL) {
        insertAtEnd(tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// DELETION RELATED PROCESS

// 1. DELETE BY POSITION

void deleteAtHead(Node* &head){
    Node*curr = head; //(declared for memory freeing purposes)
    head = head->next;
    // freeing memory
    //pehle agar ispe koi link hai toh use hata do
    curr->next = NULL;
    delete curr;
}

void deleteNodePos(Node *&head, Node *&tail, int pos){
    //handling head deletion
    if(pos==0) {
        deleteAtHead(head);
        return;
    }

    
    //deletion at mid or end
    int curPos = 0;
    Node *temp = head;
    while(curPos != pos-1){
        temp = temp->next;
        curPos++;
    }


    // handling tail deletion(specially done for updating tail)
    if(temp->next->next==NULL){
        Node *curr = temp->next;
        temp->next = NULL;
        tail = temp;
        // freeing memory
        //pehle agar ispe koi link hai toh use hata do
        curr->next = NULL;
        delete curr;
        return;
    }

    Node* curr = temp->next;//(declared for memory freeing purposes)
    temp->next = temp->next->next;
    // freeing memory
    //pehle agar ispe koi link hai toh use hata do
    curr->next = NULL;
    delete curr;
    
}

int main(){

    //dynamic declaration of an object
    Node* node1 = new Node(100);
    // cout<<node1->data 
    //     <<" "<<node1->next<<endl;

    Node *head = node1;
    cout<<"head data: "<<head->data<<endl;
    printList(head);
    Node *tail = node1;
    
    insertAtHead(head, 12);
    insertAtHead(head, 10);
    insertAtHead(head, 13);
    insertAtHead(head, 7);
    printList(head);
 
    cout<<"Inserting 14 at end giving tail"<<endl;
    insertAtEnd(tail, 14);
    printList(head);

    cout<<"Inserting 45 at end giving only head"<<endl;
    insertAtEnd2(head, 45);
    printList(head);

    cout<<"Inserting 32 at 3rd position"<<endl;
    InsertAtMid(32, 3, head, tail);
    printList(head);
    cout<<"Inserting 5 at 0th position"<<endl;
    InsertAtMid(5, 0, head, tail);
    printList(head);
    cout<<"Inserting 55 at 9th (last) position"<<endl;
    InsertAtMid(55, 9, head, tail);
    printList(head);
    
    cout<<endl;
    cout<<"deletion operations: " << endl;
    cout<<"deleting the node at 3rd position: "<<endl;
    deleteNodePos(head, tail, 3);
    printList(head);

    cout<<"deleting the node at 0th position: "<<endl;
    deleteNodePos(head, tail, 0);
    printList(head);

    cout<<"deleting the node at 6th (last) position: "<<endl;
    deleteNodePos(head, tail, 6);
    printList(head);



    return 0;
}