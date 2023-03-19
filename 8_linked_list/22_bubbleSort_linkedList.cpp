#include<iostream>
using namespace std;

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

void bubbleSort(Node*& head){
    
}

int main(){
    Node * head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 9);
    insertAtHead(head, 2);
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 1);

    printList(head);

    return 0;
}