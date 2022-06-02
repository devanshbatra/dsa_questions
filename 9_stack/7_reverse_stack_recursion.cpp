#include<iostream>
#include<stack>

using namespace std;
//IMPORTANT QUESTION
/*
To reverse the linked list using recursion. - 
-recently we have learnt how to insert an element at the bottom of the linked list using recursion(in O(n))
-so if we empty the stack and then start adding the element(jinko recursion ke time side
  mein rakha tha) , so that the last element will on the top.(bcoz sbse pehle usi ko insert at bottom kia hai)
*/

//ek tarah se bas ek case solve karna hai baaki ki reversed stack recursion dedega.

//utility function
void insertAtBottom(stack<int>& st, int x){
    //base case
    if(st.empty()){
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}

void reverseStack(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }

    int temp = st.top();
    st.pop();
    reverseStack(st);
    //readding the stored element at the bottom (leaving the last element at the top).
    insertAtBottom(st, temp);
}

int main(){

    stack<int> st;
    st.push(7);
    st.push(2);
    st.push(3);

    //tried before recursion
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;


    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;


    return 0;
}

/*
Time complexity: O(n^2) as reverse function take O(n) and at every step of reverse function we are doing
                    insert at bottom which also takes O(n).
SC: O(1).

*/