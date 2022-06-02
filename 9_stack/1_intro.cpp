/*
Stack is a data structure that follow the LIFO (last in first out) technique of adding and removing elements
-> Stack is also included in stl with major operations like: push(data), pop(), empty(), top()- to access
    the topmost element
*/
#include<iostream>
#include<stack>

using namespace std;

int main(){

    //using stl
    stack<int> s;
    s.push(5);
    s.push(9);
    s.push(34);

    // cout<<"The top most element is the the last element entered: "<<s.top()<<endl;
    // //we can see the other elements by removing the topmost element.
    // cout<<"Is the stack empty: "<<(s.empty()?"Yes it is": "No, it has some elements")<<endl;
    // s.pop();
    // cout<<"Is the stack empty: "<<(s.empty()?"Yes it is": "No, it has some elements")<<endl;
    // cout<<"Now the topmost element is: "<<s.top()<<endl;
    // s.pop();
    // cout<<"Now the topmost element is: "<<s.top()<<endl;
    // s.pop();
    // cout<<"Is the stack empty: "<<(s.empty()?"Yes it is": "No, it has some elements")<<endl;
    // cout<<"Now the topmost element is: "<<s.top()<<endl;

    cout<<"The size of stack is: "<<s.size()<<endl;
    //to access all the elements in one go
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;

    return 0;
}