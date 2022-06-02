#include<iostream>
using namespace std;
//implementing circular linked list
class Node{
    public: 
        int data;
        Node* next;

        Node(int d){
            data = d;
            this->next = NULL;
        }
        ~Node(){
            int value = data;
            if(this-> next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory freed for node with value: "<<value<<endl;
        }
};

//traversal
void printList(Node* head){
    if(head==NULL) {
        cout<<"The list is empty."<<endl;
        return;
    }

    //non empty
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<endl;

}

//insertion
void insertAfterValue(Node*&head, int value, int data){
    Node* newnode = new Node(data);
    //empty list condition
    if(head == NULL){
        newnode->next = newnode;
        head = newnode;
        return;
    }

    //non empty list
    //starting temp from first position
    Node* temp = head;
    while(temp->data!=value){
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void splitCyclic(Node* head, Node* & head1, Node*& head2){
    if(head==NULL){
        cout<<"list is empty, cannot split"<<endl;
        return;
    }
    //single element condition.
    if(head->next==head){
        head1 = head;
        head2 = head;
        return;
    }
    //more than one elements- finding the middle and then split
    Node* fast = head->next;
    Node* slow  = head;
    Node* prev = head;//ye fast ki speed se chalega but ek step kam chalega bas. just to store the last ele. of 2nd list.
    while(fast!=head){
        fast = fast->next;
        prev = prev->next;

        if(fast!=head){
            slow = slow->next;
            fast = fast->next;
            prev = prev->next;
        }
    }
    cout<<"Middle element is: "<<slow->data<<endl;
    //storing
    head1 = head;
    head2 = slow->next;
    //making it circular
    slow->next = head1;
    prev->next = head2;
}



int main(){
    Node * head = NULL;
    //inserting in empty list
    insertAfterValue(head, 5, 3);
    insertAfterValue(head, 3, 5);
    insertAfterValue(head, 5, 6);
    insertAfterValue(head, 6, 8); 
    insertAfterValue(head, 3, 4);//inserted after 3
    insertAfterValue(head, 8, 9);
    insertAfterValue(head, 9, 12);
    printList(head); 
    cout<<"head: "<<head->data<<endl;

    cout<<"Splitting the ll into two circular linked lists"<<endl;
    Node* head1 = NULL;
    Node* head2 = NULL;
    splitCyclic(head, head1, head2);
    printList(head1);
    printList(head2);
    return 0;
}