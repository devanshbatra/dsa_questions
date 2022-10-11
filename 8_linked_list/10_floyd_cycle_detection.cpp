// Floyd’s cycle-finding algorithm is a pointer algorithm that uses only two pointers,
//  moving through the sequence at different speeds.
// this algorithm finds if the linked list has any cycle within itself.
// it uses the concept of slow (noob) racer and pro racer that we learnt before.(middle element)

// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=1

#include<iostream>
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


void insertAtEnd(Node* &tail, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    tail->next = temp;
    //updating tail
    tail  = temp;
}


Node* floydCycleDetection(Node* head){
    if(head==NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL){
        slow=slow->next;
        fast = fast->next;
        if(fast!=NULL) fast = fast->next;
        
        if(fast==slow){
            //now comes the main important step
            //see photo.
            slow = head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        };
    }
    return NULL;
}

//algorithm to remove the cycle
void cycleRemoval(Node* head){
    if(head==NULL){
        return;
    }
    Node* startingPos = floydCycleDetection(head);
    Node* temp = startingPos;
    while(temp->next!=startingPos){
        temp = temp -> next;
    }
    temp->next = NULL;
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

    // making a cycle 
    tail->next = head->next;


    cout<<endl;
    Node* cycle_start = floydCycleDetection(head);

    if(cycle_start)  cout<<"A cycle is detected in the linked list starting at: "
                        <<cycle_start->data<<endl;
    else cout<<"No cycle was detected."<<endl;

    // removing the cycle using cycle removal function.
    cycleRemoval(head);
    return 0;
}

//time complexity is: O(n)