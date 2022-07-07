#include<iostream>
#include<stack>
#include<string>
using namespace std;

//use recursion to delete the middle element of the stack

void deleteMiddle(stack<int> &s, int size, int count){
    //base case
    if(count == size/2){
        s.pop();
        return;
    }


    int store = s.top();
    s.pop();

    // rc
    deleteMiddle(s, size, count+1);


    //multiple recursions krke jab wapas aayega
    //bache hue elements wapas daal do
    s.push(store);
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}

int main(){
    stack<int> s;
    s.push(4);
    s.push(5);
    s.push(2);
    s.push(9);

    printStack(s);

    //we know that we cannot access the middle element of the node without deleting the elements above it.
    //so we will use a recursive approach and reach the middle element (size/2) by removing the upper elements
    //and after deleting the middle element we will re-add those upper elements.

    int count = 0;//to count the number of nodes removed.
    int size= s.size();

    deleteMiddle(s, size, count);



    printStack(s);

    return 0;
}

/*
Now on similar grounds is this questiion: 
To insert an element at the bottom of the stack
https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=1
*/ 