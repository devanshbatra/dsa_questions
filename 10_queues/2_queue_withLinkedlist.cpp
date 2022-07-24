#include<iostream>

using namespace std;

//implementing queue using linked list

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(Node *& head, Node* &tail, int data){
    Node* newnode = new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    
    tail->next = newnode;
    tail= newnode;
}

void deleteAtHead(Node*& head, Node* & tail){
    if(head==NULL) return;
    if(head->next==NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    
}


class stack{
    Node* head = NULL;
    Node* tail = NULL;
    
    public:

    void push(int data){
        insertAtEnd(head, tail, data);
    }
    int pop(){
        if(head==NULL) return -1;

        int temp = head->data;
        deleteAtHead(head, tail);
        return temp;
    }
    int front(){
        if(head==NULL) return -1;

        return head->data;
    }
    bool empty(){
        if(head==NULL) return true;
        else return false;
    }


};

int main(){

    stack s;

    s.push(5);
    s.push(12);
    s.push(45);
    s.push(67);

    cout<<"The front element is: "<<s.front()<<endl;
    s.pop();
    cout<<"The front element is: "<<s.front()<<endl;

    // s.pop();
    // s.pop();
    // s.pop();

    if(s.empty()) cout<<"The queue is now empty"<<endl;
    else cout<<"Not empty!"<<endl;

    return 0;
}