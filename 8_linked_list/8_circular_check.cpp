#include<iostream>
#include<map>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0
// iss ques ka logic bhi same he hai bs isme agar andar bhi kahin cycle ban rhi ho toh circular man rhe h.
//toh bas wo thoda alag ho jayega.

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
void printList(Node* tail){
    //empty condition
    if(tail==NULL) {
        cout<<"Cannot print, since list is empty"<<endl;
        return;
    }
    Node * temp  = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=tail);
    cout<<endl;
}

//insertion
void insertAfterValue(Node*&tail, int value, int data){
    Node* newnode = new Node(data);
    //empty list condition
    if(tail == NULL){
        newnode->next = newnode;
        tail = newnode;
        return;
    }


    //starting temp from first position
    Node* temp = tail->next;
    while(temp->data!=value){
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

//deletion
void deleteNode(Node*& tail, int value){
    //empty list condition
    if(tail==NULL){
        cout<<"list is empty, nothing to delete."<<endl;
        return;
    }
    //single element condition
    if(tail->next == tail){
        Node* curr = tail;
        tail = NULL;
        curr->next=NULL;
        delete curr;
        return;
    }

    Node* prev  = tail;
    Node * curr = prev->next;

    while(curr->data!=value){
        prev = prev->next;
        curr = prev->next;
    }
    
    prev->next = curr->next;
    if(curr==tail) tail = prev;
    curr->next = NULL;
    delete curr;

}


//approach 1
bool checkCircular(Node * head){
    if(head==NULL) return true;

    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    if(temp==head) return true;
    else return false;
}
//traverse every element once so TC: O(n) and iterative way hai so SC: const.


//approach 2 : <<<<using maps>>>>
//ham map<node*, bool> type ka banayenge aur ye store krte jayenge ki wo node visited hai ke nhi.
//jaisi he aisi map milti hai jo visited hai then we return true.
//aur jaise he aisi node milti hai jo NULL hai then return false.s
bool checkCircularMap(Node* head){
    if(head==NULL) return true;
    map<Node*, bool> store;
    Node* temp = head;
    while(temp!=NULL){
        if(store[temp]==true) {
            return true;
        }else{
            store[temp] = true;
        }
        temp=temp->next;
    }
    return false;
}

int main(){
    Node * tail = NULL;
    //inserting in empty list
    insertAfterValue(tail, 5, 3);
    insertAfterValue(tail, 3, 5);
    insertAfterValue(tail, 5, 6);
    insertAfterValue(tail, 6, 8); 
    insertAfterValue(tail, 3, 4);//inserted after 3
    insertAfterValue(tail, 8, 9);
    printList(tail);

    //deletions
    deleteNode(tail, 5);
    printList(tail);

    if(checkCircular(tail)) cout<<"The linked list is circular in nature"<<endl;
    else cout<<"the linked list is not circular in nature."<<endl;
    if(checkCircularMap(tail)) cout<<"The linked list is circular in nature checked using map"<<endl;
    else cout<<"the linked list is not circular in nature."<<endl;

    return 0;
}