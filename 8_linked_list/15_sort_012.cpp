#include<iostream>
using namespace std;
//sort a linked list consisting of only 0, 1 and 2.

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

void insertAtEnd2(Node* &head, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    Node* tail = head;
    //traversing to the end 
    while(tail->next!=NULL) tail = tail->next;

    tail->next = temp;
}

// approach 1
/*
Count the number of 0, 1 and 2s in the linked list and then change the data while traversing in
the linked list.
*/
void sort012_app1(Node* head){
    int arr[3]={0, 0, 0};
    Node* temp = head;
    while(temp!=NULL){
        arr[temp->data]++;
        temp = temp->next;
    }
    
    temp = head;
    while(temp!=NULL){
        if(arr[0]>0){
            arr[0]--;
            temp->data = 0;
        }else if(arr[1]>0){
            arr[1]--;
            temp->data = 1;
        }else{
            arr[2]--;
            temp->data = 2;
        }
        temp = temp->next;
    }
}

//approach 2: without changing the data.
// we will create 3 linked lists of zeroes , ones and twos and then merge them.
void sort012_app2(Node*& head){
    //creating 3 dummy nodes
    Node* head0 = new Node(-1);
    Node* tail0 = head0;
    Node* head1 = new Node(-1);
    Node* tail1 = head1;
    Node* head2 = new Node(-1);
    Node* tail2 = head2;

    //storing data in these three nodes
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==0){
            Node* newnode = new Node(0);
            tail0->next = newnode;
            tail0 = newnode;
        }else if(temp->data==1){
            Node* newnode = new Node(1);
            tail1-> next = newnode;
            tail1 = newnode;
        }else if(temp->data==2){
            Node* newnode = new Node(2);
            tail2->next = newnode;
            tail2= newnode;
        }
        temp = temp->next;
    }

    printList(head0);
    printList(head1);
    printList(head2);

    //merging the three nodes.
    if(head1->next!=NULL){
        tail0->next = head1->next;
    }else{
        tail0->next = head2->next;
    }
    tail1->next = head2->next;
    tail2->next = NULL; // to end the linked list
    //resetting heads
    head = head0->next;
    printList(head);
    //delete dummy nodes
    head0->next = NULL; //important step
    head1->next = NULL; //important step
    head2->next = NULL; //important step
    delete head1;
    delete head2;
    delete head0;
}
//TC: O(n)
//SC: O(n)

int main(){

    //dynamic declaration of an object
    Node* node1 = new Node(0);
    // cout<<node1->data 
    //     <<" "<<node1->next<<endl;

    Node *head = node1;
    cout<<"head data: "<<head->data<<endl;
    printList(head);
    Node *tail = node1;
    
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    printList(head);
 

    cout<<"Inserting 45 at end giving only head"<<endl;
    insertAtEnd2(head, 1);
    printList(head);

    cout<<"Sorting the 012: "<<endl;
    // sort012_app1(head);
    sort012_app2(head);
    printList(head);

    return 0;
}