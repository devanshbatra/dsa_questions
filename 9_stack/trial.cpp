#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int> st, int size, int x){
    //base case 
    if(st.empty()){
        st.push(x);
        return;
    }
    
    int store = st.top();
    st.pop();
    //rc
    solve(st, size, x);
    //backtrack
    st.push(store);
    
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    int size = myStack.size();
    solve(myStack, size, x);
    return myStack;
}

int main(){
    
    return 0;
}