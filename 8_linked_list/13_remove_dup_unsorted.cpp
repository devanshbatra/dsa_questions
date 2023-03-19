#include<iostream>
#include<unordered_map>
using namespace std;
//removing duplicates from an unsorted list.
//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
/*
 here we have majorly 3 approaches:
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

/*
    
 1) traverse each node and chk - at each node traverse whole linked list from the next node and
    find if any duplicates exist for that node.
    TC: O(n^2), space: O(1) - (worst method).
*/
//this method is way slower and will definately give TLE in online assessment.
void removeDup1(Node*& head){
    if(head==NULL) return;
    Node* pres = head;
    while(pres!=NULL && (pres->next!=NULL) ){
        Node* prev = pres;
        Node* curr = pres->next;
        while(curr!=NULL){
            if(pres->data == curr->data){
                Node* temp = curr;
                prev->next = curr->next;
                //updation
                curr = curr->next;
                //deletion
                temp->next = NULL;
                delete temp;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        pres = pres->next;
    }
}


// ---------------------------------------------------------------------------------------------------------

/*
    2) First sort then remove- first sort the linked list using fast sorting methods and then use the previous ques
        concept of removing duplicates from sorted linked list.
        TC: O(nlogn) for sorting + O(n) for removal after sorting. = O(nlogn)
        SC: Agar merge sort recursion ke through hua toh thodi bohot lagegi space in stack se video.
*/
//merge sort full package
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

// Please note that this method doesn’t preserve the original order of elements.
//now using the concept of removing duplicates from sorted linked list
void removeDup2(Node* head){
    Node* curr = head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }else{
            curr = curr->next;
        }
    }
}

// ------------------------------------------------------------------------------------------------------------

/*
    3) Using maps- Store the visited nodes in the map and if any visited comes delete it.
        TC: O(n) traversed every node once.
        SC: O(n) made a hash map data structure.

    for more efficiency use unordered map here: 
    1) Reasons to use unordered_map:
            You need to keep count of some data (Example – strings) and no ordering is required.
            You need single element access i.e. no traversal.
    2) Reasons for using map
            You need ordered data.
            You would have to print/access the data (in sorted order).
            You need predecessor/successor of elements.
*/
void removeDup3(Node*& head){
    
    Node* temp = head;
    unordered_map<int, bool> visited;
    Node* prev = NULL;
    while(temp!=NULL){
        if(visited[temp->data]==true){
            //store
            Node* nodetodelete = temp;
            prev ->next = temp->next;
            temp = temp->next;
            
            //deletion
            nodetodelete->next = NULL;
            delete nodetodelete;
        }
        else{
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
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

    // 1>
    // removeDup1(head);

    // 2>
    // removeDup2(head);

    // 3> does't preserve order
    mergeSort(head);
    removeDup2(head);

    cout<<"After removing duplicates : "<<endl;
    printList(head);
    return 0;
}