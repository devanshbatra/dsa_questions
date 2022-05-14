#include<iostream>
using namespace std;
//reverse a singly linked list in k groups
//important question
// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644
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
    if(head == NULL ){
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

Node* reverseInK(Node* head, int k){
    //base case
    if(head==NULL || head->next == NULL) return head;

    //processing
    // reversing first k elements
    // iteration k times
    Node* prev = NULL;
    Node* temp = NULL;
    Node* curr = head;
    int count = 0;
    while(count<k && curr!=NULL){
        temp = curr->next;
        curr->next = prev;//reversal
        //updation
        prev = curr;
        curr = temp;
        count++;
    }
    //head not updated for the upper reversed list so head would be pointing to the previous head which
    //is at end now.
    //linking our list to the already reversed list came from recursion
    //basically it is recursive call
    if(curr!=NULL){//recursive mein head ko null bhejne ka fayda nhi hai wo uska next dhonde ga to error aayegi.      
        head->next = reverseInK(curr, k);
    }

    return prev;//in iterative way final head should be on the prev at last.
}


int main(){
    Node * head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 9);
    insertAtHead(head, 2);
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    insertAtHead(head, 12);
    insertAtHead(head, 0);
    insertAtHead(head, 7);
    cout<<"Before reversal: "<<endl;
    printList(head);
    int k= 3;
    
    head = reverseInK(head, k);

    cout<<"After reversal: "<<endl;
    printList(head);

    return 0;
}

//time complextiy : we are traversing every node only one time so O(n).
//space complexity : see the lecture no. 41 , for calculating space complexity of recursive algorithms by making stack.