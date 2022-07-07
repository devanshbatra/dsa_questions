#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            data = d;
            this->next = NULL; // similar to ---> (*this).next;
        }

        // destructor - will be called automatically when we free the memory for a node.
        ~Node(){
            int value = this->data;

            //iski koi zaroorat nahi hai as next wala link toh ham aise he free kr rhe h code mein.
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            // cout<<"memory freed for node with value: "<< value<<endl;
        }
};

void printList(Node* &head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

void insertAtHead(Node* &head, Node* & tail, int d){
    //creating a new node for the given data
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &head, Node* &tail, int d){
    Node* newnode = new Node(d);
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void deleteAtEnd(Node* & head, Node* & tail){
    if(head==NULL) return;
    if(head->next==NULL){
        Node* temp  = head;
        head = NULL;
        tail  = NULL;
        temp->next  = NULL;
        delete temp;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp  = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = NULL;
    tail = temp;
    toDelete->next = NULL;
    delete toDelete;
}


class Stack{
    public:
        int size;
        Node* head= NULL;
        Node* tail = NULL;

        //methods
        void push(int ele){
            insertAtEnd(head, tail, ele);
        }

        void pop(){
            if(head==NULL){
                cout<<"The stack is empty";
            }else{
                deleteAtEnd(head, tail);
            }
        }

        int peek(){
            if(tail==NULL){
                cout<<"The stack is empty"<<endl;
            }else{
                return tail->data;
            }
        }

        bool empty(){
            if(tail==NULL) return true;
            else return false;
        }
};

int main(){

    Stack st;
    st.push(33);
    st.push(56);
    st.push(23);
    st.push(2);
    st.push(3);
    st.push(8);
    cout<<st.peek()<<endl;
    while(!st.empty()){
        cout<<st.peek()<<" ";
        st.pop();
    }cout<<endl;

    return 0;
}