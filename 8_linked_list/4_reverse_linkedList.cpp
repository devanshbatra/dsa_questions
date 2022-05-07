#include<iostream>
using namespace std;
//reverse a singly linked list
class Node{
    public: 
        int data;
        Node * next;
    Node(int d){
        data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    //checking empty condition
    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void printList(Node* &head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

void reverseList(Node* & head){
    Node* prev= NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr->next; //for storing the value for future purposes
        curr->next = prev; //reversal operation

        //updation for next iteration
        prev = curr;
        curr = temp;
    }
    //ab curr NULL pe hoga aur prev last node pr jise ab hame head banana hai.
    head = prev;
}

int main(){
    Node * head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 9);
    insertAtHead(head, 2);
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    cout<<"Before reversal: "<<endl;
    printList(head);
    reverseList(head);
    cout<<"After reversal: "<<endl;
    printList(head);
    

    return 0;
}