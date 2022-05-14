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
    //checking empty conditi    on
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


//function for finding length for approach one.
int getLength(Node* head){
    if(head==NULL) return 0;
    int length = 0;
    Node* temp = head;
    while(temp!= NULL){
        temp=temp->next;
        length++;
    }
    return length;
}

Node* getMiddle(Node* head){

    if(head==NULL) return head;
    if(head->next==NULL) return head;

    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }

    return slow;
}


int main(){
    Node * head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 9);
    insertAtHead(head, 2);
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    // insertAtHead(head, 12);

    printList(head);
    
    // approach one
    int length = getLength(head);
    int middle = (length/2)+1;
    cout<<"Length: "<<length<<" middle: "<<middle<<endl;
    Node* temp = head;
    int count=1;
    while(count!=middle){
        temp=temp->next;
        count++;
    }
    cout<<"Middle element by approach one is: "<<temp->data<<endl;
    //time complexity for approach one : we travesed every node one time so it will be O(n).

    //approach 2 - pro racer and noob racer wala example
    //take two pointer one is fast and other is slow(by exactly half)
    //when fast wala pointer traverses the whole list then the slow will be at middle
    // bus odd or even ko sambhalne ke liye fast ko ek saath nahi ek ek krke 2 steps move karna padega.

    //because we are using two pointers placed one after each other so list mein atleast 2 nodes toh honi 
    //he chahiye so 0 and 1 node wali list ke cases alag se likh denge.
    
    Node* slow = getMiddle(head);
    cout<<"the middle element using the 2nd approach is: "<<slow->data<<endl;
    
    // 2nd approach mein O(n/2)  => O(n) he aa rhi h time complexity but ye zyada optimized hai . ek he 
    // loop mein kaam ho gaya.

    return 0;
}