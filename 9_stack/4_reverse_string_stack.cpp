#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    cout<<"Enter the string: ";
    string st;
    cin>>st;
    int n= st.length();
    cout<<"Before reversal: "<<st<<endl;
    stack<int> store;
    for(int i=0; i<n; i++){
        store.push(st[i]);
    }

    for(int i=0; i<n; i++){
        st[i] = store.top();
        store.pop();
    }

    cout<<"After reversal: "<<st<<endl;
    

    return 0;
}

/*
Here Time comp: O(n) and SC: O(n)
Swapping approach is better than this approach as this uses order of n space.
*/