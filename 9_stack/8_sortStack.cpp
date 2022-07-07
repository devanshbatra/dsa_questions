#include <iostream>
#include <string>
#include <stack>

using namespace std;

// sort the stack

//there we will use recursion as usual to saperate and store each element until stack is empty 
//then we will use the function insertsorted that will re insert each in sorted manner.

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}

void insertSortedly(stack<int> &s, int data){
    //base cases
    if(s.empty()) {
        s.push(data);
        return;
    }
    if(s.top()<=data){
        s.push(data);
        return;
    }

    //rc
    int temp = s.top();
    s.pop();
    insertSortedly(s, data);
    s.push(temp);

}

void sort(stack<int>& s){
    //base case
    if(s.empty()){
        return;
    }

    //rc
    int temp = s.top();
    s.pop();
    sort(s);
    insertSortedly(s, temp);
}


int main(){

    stack<int> s;
    s.push(-6);
    s.push(7);
    s.push(4);
    s.push(2);
    s.push(-15);
    s.push(1);

    printStack(s);

    sort(s);

    printStack(s);

    return 0;
}

/*
Now do - to find if redundant braces exist in the string.
https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=1

for this question: (redundant brackets)
//time complexity is O(n)
space complexity is O(n)
*/