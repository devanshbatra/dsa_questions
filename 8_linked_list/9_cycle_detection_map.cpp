//will try to detect the cycle(not only complete cycle of circular linked list, but also
// the inner cycles.)
#include<iostream>
#include<map>
using namespace std;

//created class for circular LL
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


//detection of cycle and first node of cycle using bool element.
//here testing on circular list only but I have tested it on into single linked list by creating cycles on it.
Node* detectCycle(Node* head){
    if(head==NULL) return NULL;

    Node* temp = head;
    map<Node*, bool> visited;
    while(temp!=NULL){
        if(visited[temp]){
            return temp;
        }else {
            visited[temp] = true;
        }
        temp = temp->next;
    }
    return NULL;
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

    Node* start = detectCycle(tail);
    if(start){
        cout<<"cycle detected, and start is: "<<start->data<<endl;
    }else{
        cout<<"no cycle was detected"<<endl;
    }

    return 0;
}
//In this algorithm :
/*
Time complexity: O(n) , visited every node once.
Space complexity: O(n), made a map data structure of size n.
*/