/*
>>MergeSort in linked list is done on similar grounds of splitting it into two halves recursively and then merging
>>But here in linked list actual splitting is not done, rather we take two pointers and assign them the starting nodes
  of two halves.

poori kahani after reading gfg article.
>>Now for merging we again use recursion, we have to compare two linked lists with given starting nodes.
  We just need to handle a single case of comparing the element datas.
  we will make a node* result and save the ans of that case in that result and for result->next we make a recursive 
  call giving both the start pointers with one of them increased to next(the one that was smaller).
  here the base case will be : if any one of the start pointers that are continuously going next and next.
  if( one of them gets exhausted and returns NULL) return the other one.

*/
#include<iostream>
#include<unordered_map>
using namespace std;

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
    if(head==NULL) {
        cout<<"The list is empty"<<endl;
        return;
    }
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

void insertAtHead(Node* &head, int d){
    if(head==NULL){
        Node* newnode = new Node(d);
        head = newnode;
        return;
    }
    //creating a new node for the given data
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd2(Node* &head, int d){
    //creating a new node for the given data
    Node* temp = new Node(d);
    if(head==NULL){
        head = temp;
        return;
    }
    Node* tail = head;
    //traversing to the end 
    while(tail->next!=NULL) tail = tail->next;

    tail->next = temp;
}

//merging two split linked lists
Node* merge(Node* a, Node* b){
    //base case
    if(a==NULL) return b;
    else if(b==NULL) return a;

    Node* result = NULL;
    //rc
    if(a->data<=b->data){
        result = a;
        result ->next = merge(a->next, b);
    }else{
        result = b;
        result->next=merge(a, b->next);
    }

    return result;
}


//splitting the linked list into two halves by using the concept of finding middle element.
void split(Node* head, Node*& a, Node*& b){
    if(head==NULL) return;
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    //assigning the values to a and b
    a = head;
    b = slow->next;
    //now splitting bond between 2 halves
    slow->next = NULL; //important step
}


void mergeSort(Node*& head){
    //base case
    if(head==NULL || head->next==NULL) return;

    //splitting into two halves
    Node* a = NULL;
    Node* b = NULL;
    split(head, a, b);

    
    //call merge sort for the two halves
    mergeSort(a);
    mergeSort(b);

    //calling merge for two linked lists starting by a and b
    head = merge(a, b);
}


int main(){


    Node *head = NULL;
    
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    insertAtHead(head, 9);   
    insertAtHead(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 6);
    insertAtHead(head, 1);


    cout<<"Inserting 5 at end giving only head"<<endl;
    insertAtEnd2(head, 5);
    printList(head);

    mergeSort(head);
    cout<<"After sorting : "<<endl;
    printList(head);


    return 0;
}