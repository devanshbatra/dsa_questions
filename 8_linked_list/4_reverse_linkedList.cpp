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
    //checking empty condition
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

void reverseList(Node* & head){
    Node* prev= NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr->next; //for storing the value for future purposes
        curr->next = prev; //reversal operation

        //updation for next iteration
        prev = curr;
        curr = temp;
    }
    //ab curr NULL pe hoga aur prev last node pr jise ab hame head banana hai.
    head = prev;
}

//recursive method 
void reverseListRec(Node* & head, Node * curr, Node * prev){
    //base case
    if(curr==NULL){
        head=prev;
        return;
    }
    //processing 
    Node* temp = curr->next;
    curr->next = prev;
    prev=curr;
    curr=temp;

    //recursive call
    reverseListRec(head, curr, prev);
}

// recursive approach 2nd - requires only head pointer.
// this function will return the head of the reversed list, seen from lecture no. 45, 20:00.
// bilkul deep mein sochna he nhi hai, tum sirf last step ka dekh lo baaki recursion apne aap kr lega.
Node* reverse1(Node * head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* chotahead = reverse1(head->next);

    //now we need to do two works is already reversed list ke first element ke next ko head pe point karana
    //hai and head ko null pe
    //is tarah is step wala head bhi choti reverse linked list ka hissa ban jayega and in sabka head -
    // will be the chotahead, so return chotahead at end.
    head->next->next = head;
    head->next = NULL;

    return chotahead; 
}

int main(){
    Node * head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 9);
    insertAtHead(head, 2);
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    cout<<"Before reversal: "<<endl;
    printList(head);
    reverseList(head);
    cout<<"After reversal: "<<endl;
    printList(head);

    // recursive method
    Node* curr = head;
    Node* prev = NULL;
    reverseListRec(head, curr, prev);
    cout<<"Again reversed using recursive approach: "<<endl;
    printList(head);

    // recursive method 2
    cout<<"Again reversed using recursive approach number 2 "<<endl;
    head = reverse1(head);
    printList(head);
    

    return 0;
}