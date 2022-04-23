#include<iostream>
#include<string>

using namespace std;
template <class T>
void swapIt(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

// USING TWO POINTERS
void reverseString(string& st, int n, int s, int e){
    //base case
    if(s>e) return ;

    // processing
    cout<<"swapping : "<<st[s]<<", "<<st[e]<<endl;
    swapIt(st[s], st[e]);

    //recursive call
    reverseString(st, n, s+1, e-1);
}

// USING SINGLE POINTER
void reverseString(string& st, int n, int j){
    int max = n-1, min = 0;
    //base case
    if(min+j>max-j) return ;

    // processing
    // cout<<"swapping : "<<st[s]<<", "<<st[e]<<endl;
    swapIt(st[min+j], st[max-j]);

    //recursive call
    reverseString(st, n, j+1);
}


int main(){
    string st= "abcde";
    int n = st.length();

    int s = 0, e=n-1, j=0;
    cout <<"before(using double pointers): "<<st<<endl;
    reverseString(st, n, s, e);
    cout <<"after(using double pointers): "<<st<<endl;
    cout<<endl;
    cout <<"before(using single pointers): "<<st<<endl;
    reverseString(st, n, j);
    cout <<"after(using single pointers): "<<st<<endl;


    return 0;
}