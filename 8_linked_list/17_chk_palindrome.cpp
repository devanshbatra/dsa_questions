#include<iostream>
#include<vector>
using namespace std;
//to check whether a linked list is pallindrome or not

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
    if(head==NULL) {
        Node* temp = new Node(d);
        head = temp;
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
    Node* tail = head;
    //traversing to the end 
    while(tail->next!=NULL) tail = tail->next;

    tail->next = temp;
}

//approach 1 (ARRAY APPRAOCH): by creating an array , copying contents of the list in the array and
//  then checking the pallindrome for array.

// checking pallindrome for array
bool chkPallinArr(vector<int> v){
    int n = v.size();
    int s = 0;
    int e = n-1;
    while(s<=e){
        if(v[s] != v[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool chkPallindrome1(Node* head){
    if(head==NULL) return false;
    vector<int> v;
    while(head!=NULL){
        v.push_back(head->data);
        head=head->next;
    }

    return chkPallinArr(v);

}
/*
TC: O(n) + O(n/2)  => O(n) + O(n)  => O(n)  
SC: O(n)  - not desired
*/

//Note: WE CANNOT CHECK FOR PALLINDROME BY REVERSING THE LINKED LIST AS AFTER REVERSING THE ORIGINAL LINKED
// LIST IS LOST

//APPROACH 2: (FINDING MIDDLE)-
/*
here we will find the middle element of the of the list and then reverse the second half
then put one pointer at head and one at next of middle, start comparing till end
if matched then pallindrome , if not matched then not pallindrome
it will work absolutely fine for both odd and even list- see by making in copy.
*/

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return slow;
}

// will return the head of the reversed list
Node* reverseSecondHalf(Node* middle){
    Node* prev = NULL;
    Node* curr = middle->next;
    if(curr==NULL) return middle;
    while(curr!=NULL){
        Node* temp = curr->next;//stored
        //reverse operation
        curr->next = prev;

        //updating
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool chkPallindrome2(Node* head){
    if(head->next==NULL) return true;
    Node* middle = findMiddle(head);
    cout<<"middle: "<<middle->data<<endl;

    //reversing the second half
    middle ->next = reverseSecondHalf(middle);


    //a will be on head and b will be on the start of second half
    Node* a = head;
    Node* b = middle->next;

    cout<<"a: "<<a->data<<", b: "<<b->data<<endl; 
    while(b!=NULL){
        if(a->data!=b->data) return false;

        a = a->next;
        b = b->next;
    }
    //agar yahan tk aa gaya h to return true
    return true;
}

int main(){

    Node *head = NULL;
    
    insertAtHead(head, 1);
    // insertAtHead(head, 2);
    // insertAtHead(head, 0);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 1);

    printList(head);



    if(chkPallindrome1(head)){
        cout<<"yes, the list is pallindrome according to method 1"<<endl;
    }else{
        cout<<"No, the list is not pallindrome according to method 1"<<endl;
    }

    if(chkPallindrome2(head)){
        cout<<"yes, the list is pallindrome according to method 2"<<endl;
    }else{
        cout<<"No, the list is not pallindrome according to method 2"<<endl;
    }


    return 0;
}