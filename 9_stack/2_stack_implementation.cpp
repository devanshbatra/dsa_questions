/*
Stack is implemented with classes in two ways using:
1> array 
2> linked list
*/
#include<iostream>
using namespace std;

// USING ARRAYS
//if it is a template than it can be used for any data type.
template <class T>
class Stack{
    public:
        //properties.
        T * arr;  
        int size;
        int top;

        Stack(int size){
            this->size = size;
            arr = new T[size];
            top = -1;
        }

        //methods
        int push(int ele){
            if(size-top>1){
                top++;
                arr[top] = ele;
            }else{
                cout<<"Cannot insert , stack overflow"<<endl;
            }
        }

        int pop(){
            if(top>=0){
                top--;
            }else{
                cout<<"Stack underflow"<<endl;
            }
        }

        int peek(){
            if(top>=0){
                return arr[top];
            }
            else{
                cout<<"stack is underflow"<<endl;
                return -1;
            }
        }

        bool empty(){
            if(top==-1) return true;
            else return false;
        }
};
//all operations of push(), pop(), peek() and empty() are done in O(1) time complexity.




int main(){

    Stack<int> st(5);
    st.push(33);
    st.push(56);
    st.push(23);
    st.push(2);
    st.push(3);
    st.push(8);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    if(st.empty()){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<"stack is not empty"<<endl;
    }
    return 0;
}

/*
Now try two stack question:
https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=1

-In this ques we have to implement two stacks using single array of a fixed given size.
-One approach would be to divide the array into two halves but it will waste much of the space.
-The best approach is to start first stack allocation from start and 2nd array allocation from end.

*/