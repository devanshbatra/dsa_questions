#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;

        Stack(int s){
            size = s;
            arr = new int[size];
            top = -1;
        }

        void pushS(int data){
            //check overflow
            if(size-top<=1) {
                cout<<"could not insert, stack overflow"<<endl;
                return;
            }

            top++;
            arr[top] = data;
        }

        void popS(){
            if(top==-1){
                cout<<"could not pop, stack underflow"<<endl;
                return;
            }

            top--;
        }

        int getSize(){
            return top+1;
        }

        int topS(){
            if(top==-1){
                cout<<"array underflow"<<endl;
                return -1;
            }

            return arr[top];

        }

        bool isEmpty(){
            if(top==-1) return true;
            else return false;
        }



};


int main(){


    Stack* s = new Stack(5);

    s->pushS(6);
    s->pushS(5);
    s->pushS(4);
    s->pushS(3);
    s->pushS(2);

    while(!s->isEmpty()){
        cout<<s->topS()<<" ";
        s->popS();
    }





    return 0;
}