#include<iostream>
using namespace std;
//add two numbers which are represented by linked list.
/*
or another question on same logic is to add one to the number represented by linked list.
*/

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
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        return;
    }
    //creating a new node for the given data
    Node* temp = new Node(d);
    Node* tail = head;
    //traversing to the end 
    while(tail->next!=NULL) tail = tail->next;

    tail->next = temp;
}

//approach: we have to add like 831 and not like this 831 so we will reverse both the linked lists and then add them by giving 
//                               45                   45
// carry to the right. and then reverse the output list to get the answer.

//utility functions
Node* reverseList(Node* head){
    if(head==NULL || head->next==NULL ) return head;
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr->next;//storage
        curr -> next = prev;
        //updation
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* addNumbers(Node* first, Node* second){
    // reversing both the lists.
    first = reverseList(first);
    second  = reverseList(second);

    //result head
    Node* head = NULL;
    int carry = 0;

    while(first!=NULL && second!=NULL){
        int sum= first->data + second->data + carry;
        int result;
        if(sum>=10){
            result = sum-10;
            carry = 1;
        }else{
            result = sum;
            carry = 0;
        }
        insertAtEnd2(head, result);
        //updating
        first= first->next;
        second = second->next;
    }
    cout<<"Came here"<<endl;

    //if any one of them(list) remains
    while(first!=NULL){
        int sum = first->data + carry;
        int result;
        if(sum>=10){
            result = sum-10;
            carry = 1;
        }else{
            result = sum;
            carry = 0;
        }
        insertAtEnd2(head, result);
        //updating
        first = first->next;
    }
    while(second!=NULL){
        int sum = second->data + carry;
        int result;
        if(sum>=10){
            result = sum-10;
            carry = 1;
        }else{
            result = sum;
            carry = 0;
        }
        insertAtEnd2(head, result);
        //updating
        second = second->next;
    }

    //if carry comes at the last and a new digit has to be added. (important step)
    if(carry==1){
        insertAtEnd2(head, carry);
    }

    //now reverse the output to get the result
    head = reverseList(head);
    return head;    
}

/*same approach , but without so much loops, ( generic code )
    incorporating remaining first or remaining second list and remaining carry in one loop only.(interviewer can ask for this also).
*/
// Node* addNumbers2(Node* first, Node* second){
//     // reversing both the lists.
//     first = reverseList(first);
//     second  = reverseList(second);

//     //result head
//     Node* head = NULL;
//     int carry = 0;

//     while(first!=NULL || second!=NULL || carry!=0 ){

//         int val1 = 0;
//         if(first!=NULL) val1 = first->data;
//         int val2 = 0;
//         if(second!= NULL) val2 = second->data;

//         int sum= val1 + val2 + carry;
//         int result;
//         if(sum>=10){
//             result = sum-10;
//             carry = 1;
//         }else{
//             result = sum;
//             carry = 0;
//         }
//         insertAtEnd2(head, result);
//         //updating
//         if(first!=NULL){
//             first= first->next;
//         }
//         if(second!=NULL){
//             second = second->next;
//         }
//     }
//     //now reverse the output to get the result
//     head = reverseList(head);
//     return head;    
// }

int main(){

    Node* head1= NULL;
    
    // insertAtHead(head1, 6);
    insertAtHead(head1, 9);
    insertAtHead(head1, 3);
    insertAtHead(head1, 1);
    printList(head1);

    Node* head2 = NULL;
    // insertAtHead(head2, 8);
    // insertAtHead(head2, 7);
    insertAtHead(head2, 9);
    insertAtHead(head2, 3);
    printList(head2);
    
    Node* sumHead = addNumbers(head1, head2);

    printList(sumHead);

    return 0;
}

/*
time comp: reverse krne me oh of n, add krne mein O(n), then result ko reverse krne mein O(m+n) as the max len of the result can
 be m+n.

space complexity: we have used a result linked list of size O(max{m, n}).
*/