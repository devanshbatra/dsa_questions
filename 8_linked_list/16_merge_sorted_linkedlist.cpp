#include<iostream>
using namespace std;
//merge two sorted linked list.

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
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        return;
    }
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

//recursive method
//we will merge the two sorted linked list in a recursive manner
//we will take a variable result and recursively find it.

Node* merge_sorted_list(Node* head1, Node* head2){
    Node* result= NULL;
    // base case
    if(head1==NULL) return head2;
    else if(head2==NULL) return head1;
    

    //rc
    if(head1->data <= head2->data){
        result = head1;
        result->next = merge_sorted_list(head1->next, head2);
    }else{
        result = head2;
        result->next = merge_sorted_list(head1, head2->next);
    }

    return result;
}

// another approach - taught in lecture no. 49 - not a good approach , follow recursive one (its the standard one).

//utility function for insert at middle
void insertAtMiddle(Node* &first, Node* &middle, Node* &second){
    first->next = middle;
    middle->next = second;
}

Node* solve(Node* oneHead, Node* twoHead){

    //if only one element is present in the first list
    if(oneHead->next==NULL){
        oneHead->next=twoHead;
        return oneHead;
    }

    //going with approch - we have made the call such that the first element of first list is less than the first element of second list
    Node* temp = twoHead;
    Node* curr = oneHead->next;
    Node* prev = oneHead;


    while(curr!=NULL && temp!=NULL ){
        // cout<<"temp: "<<temp->data<<endl;
        // cout<<"prev: "<<prev->data<<endl;
        // cout<<"curr: "<<curr->data<<endl;
        if(temp->data<=curr->data && temp->data>=prev->data){
            Node* middle = temp;//storing , not to loose bachi hui linked list
            temp=temp->next;
            insertAtMiddle(prev, middle, curr);
            //update only prev pointers
            prev = prev->next;
        }else{
            //just update pointers
            prev = prev->next;
            curr=curr->next;

            // ab yahan pr agar curr NULL ho gaya to bachi hui 2nd list lost ho jayegi
            if(curr==NULL){
                prev->next=temp;    
                return oneHead;
            }
        }
    }
    return oneHead;
}

Node* merge_sorted2(Node* head1, Node * head2){

    //checking empty condition
    if(head1==NULL) return head2;
    else if(head2==NULL) return head1;

    Node* head = NULL;
    if(head1->data<=head2->data){
        head = solve(head1, head2);
    }else{
        head = solve(head2, head1);
    }
    return head;
}

int main(){

    Node* head1= NULL;
    
    insertAtHead(head1, 6);
    // insertAtHead(head1, 4);
    // insertAtHead(head1, 3);
    // insertAtHead(head1, 1);
    printList(head1);

    Node* head2 = NULL;
    insertAtHead(head2, 8);
    // insertAtHead(head2, 7);
    // insertAtHead(head2, 5);
    // insertAtHead(head2, 3);
    printList(head2);
    
    // Node * mergedHead = merge_sorted_list(head1, head2);
    Node * mergedHead = merge_sorted2(head1, head2);
    cout<<"Merged list is: "<<endl;
    printList(mergedHead);
    

    return 0;
}