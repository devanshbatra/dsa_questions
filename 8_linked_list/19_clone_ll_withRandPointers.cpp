// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
// https://leetcode.com/problems/copy-list-with-random-pointer/
#include<iostream>
#include<unordered_map>
using namespace std;
/*
We have to clone a linked list with next as well as random pointers.(like one given in the screenshot).
Now cloning a simple linked list is easy but not easy with random pointers also.
WE CANNOT TEST THIS QUESTION HERE SO SEE LEETCODE FOR APPROACHES.
*/

class Node{
    public:
        int data;
        Node* next;
        Node* rand;

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


/*
approach 1: brute force , we know we can easily clone list with next pointers only and it will be done in O(n) time.
            after that we will travel to the original list and check how far is the random pointer is made.
            we will then point the random pointer of the clone list at the same distance.
            but this step will take O(n^2) time complexity.
            NOT CODING IT FOR NOW
*/

/*
approach 2: we will first clone the linked list with next pointers only.
            now what if we save a mapping of original and clone nodes in the first step using an unordered map
            so for random pointers
            whenever we need a random pointer of a cloned node
            cloneNode->random =  mapping[originalNode->random]

            TC: O(n), SC: O(n).
]*/

Node* cloneList(Node* head){
    Node* head2 = NULL;
    Node* temp = head;
    unordered_map<Node*, Node*> mapping;


    while(temp!=NULL){
        //creating a new node for clone list
        Node* newnode = new Node(temp->data);
        //storing in mapping
        mapping[temp] = newnode;
        //inserting the new node
        if(head2==NULL){
            head2 = newnode;
        }else{
            Node* tail  = head2;
            while(tail->next!=NULL){
                tail = tail->next;
            }
            tail->next = newnode;
        }
        temp = temp->next;
    }
    //checks and tests
    // cout<<"Cloned list: ";
    // printList(head2);
    // cout<<"Map: ";
    // unordered_map<Node*, Node*> :: iterator iter;
    // for(iter = mapping.begin(); iter!=mapping.end(); iter++){
    //     cout<<iter->first->data<<" : "<<iter->second->data<<endl;
    // }

    //now we have the cloned list with next pointers and a storage mapping
    //traversing the cloned list
    Node* originalNode = head;
    Node* cloneNode = head2;

    while(originalNode!=NULL){
        cloneNode->rand = mapping[originalNode->rand];
        cloneNode=cloneNode->next;
        originalNode = originalNode->next;  
    }
    return head2;
}

/*
Approach 3: Now, if we want to do it by not taking any extra space. that it SC: O(1).
            Then we have to do it by changing links.
            see screenshot attached for representation.
*/
//DONE ON: 
// https://leetcode.com/problems/copy-list-with-random-pointer/submissions/

Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* curr = head;
        
        //creating a clone list with next pointers only
        while(curr!=NULL){
            Node* newnode = new Node(curr->data);
            //insert at tail
            if(cloneHead==NULL){
                cloneHead = newnode;
                cloneTail = newnode;
            }else{
                cloneTail->next = newnode;
                cloneTail = newnode;
            }
            curr = curr->next;
        }
        
        //introducing original pointers in between clone pointers
        Node* temp = head;
        Node* temp2 = cloneHead;
        while(temp!=NULL && temp2!=NULL ){
            //diverting original list
            Node* next = temp->next;
            temp->next = temp2;
            temp = next;
            
            //diverting clone list
            next = temp2 -> next;
            temp2->next = temp;
            temp2 = next;
        }
        
        //adding random pointers to clone list
        curr = head;
        while(curr!=NULL){
            if(curr->next!=NULL){
                //agar curr ka random null hua then curr->next->random = curr->random
                //else curr ke next ka random = curr ke random ka next.
               curr->next-> rand = curr->rand? curr->rand->next: curr->rand;
            }
            curr = curr->next->next;
        }
        
        //removing real life mapping from list.
        temp = head;
        temp2 = cloneHead;
        while(temp!=NULL){
            temp -> next = temp2->next;
            temp = temp->next;
            if(temp!=NULL){
                temp2-> next = temp->next;
                temp2 = temp2->next;
            }else{
                temp2->next = NULL;
                temp2 = temp2->next;
            }
            
        }
        
        return cloneHead;
    }

int main(){

    Node* head= NULL;
    
    // insertAtHead(head, 6);   
    insertAtHead(head, 9);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    printList(head);

    cloneList(head);

    return 0;
}
