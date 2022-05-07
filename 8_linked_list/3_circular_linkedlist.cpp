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

//delete node
//here also we can delete using position or by using value but since we have done by position previously
// so now we will do it by giving value.
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
    //Now the curr points to the node to delete and prev points to the node previous to the node
    // to delete
    
    prev->next = curr->next;
    //updating tail if curr is at tail
    if(curr==tail) tail = prev;
    curr->next = NULL;
    delete curr;

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

    return 0;
}