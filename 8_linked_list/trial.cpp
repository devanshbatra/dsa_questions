#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            next = NULL;
        }

        void insertAtHead(Node*& head, int data){
            Node* temp = new Node(data);
            if(head==NULL){
                head = temp;
                return;
            }
            temp->next = head;
            head = temp;
        }

        void insertAtEnd(Node*& head, int data){
            Node* newnode = new Node(data);
            if(head==NULL){
                head = newnode;
                return;
            }
            Node* temp = head;
            while(temp->next!=NULL) temp=temp->next;
            temp->next = newnode;
        }


        void insertAtMiddle(Node*& head, int data, int pos){
            if(head==NULL){
                insertAtHead(head, data);
                return;
            }

            int currPos = 0;
            Node* temp = head;

            while(currPos<pos-1){
                temp=temp->next;
                currPos++;
            }

            if(temp->next==NULL) {
                insertAtEnd(head, data);
                return;
            }

            Node* newnode = new Node(data);
            newnode->next = temp->next;
            temp->next = newnode;
        }


        void printList(Node* head){
            Node* temp = head;
            if(head==NULL){
                cout<<"empty list"<<endl;
                return;
            }
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }



        //deletion
        void deleteAtHead(Node* & head){
            if(head==NULL){
                cout<<"cannot delete list is empty"<<endl;
                return;
            }

            Node* todelete = head;
            head = head->next;
            delete todelete;

        }

        void deleteAtEnd(Node* & head){
            if(head==NULL) {
                cout<<"cannot delete"<<endl;
                return;
            }

            if(head->next==NULL){
                Node* todelete = head;

                head=NULL;
                delete todelete;
                return;
            }

            Node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            Node* todelete = temp->next;
            temp->next = NULL;
            delete todelete;

        }


        void deleteAtPos(Node*& head, int pos){
            if(pos==0){
                deleteAtHead(head);
                return;
            }
            
            Node* temp = head;
            int currPos = 0;

            while(currPos<pos-1){
                temp=temp->next;
                currPos++;
            }
            Node* todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;

        }

};


int main(){

    Node* head = NULL;

    head->insertAtHead(head, 5);
    head->insertAtHead(head, 6);
    head->insertAtEnd(head, 7);
    head->insertAtMiddle(head, 8, 1);
    head->printList(head);


    head->deleteAtPos(head, 3);
    head->printList(head);




    return 0;
}