// 0, 1, 1, 2, 3, 5, 8, 13

// without recursion
#include <iostream>

using namespace std;

// function for recursion
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    return fib(n-1)+fib(n-2);
}

int main(){
    
    int n;
    cout<<"Number of terms: ";
    cin>>n;
    int a, b, c, temp;
    a=0;
    b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=0; i<(n-2); i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }

    cout<<endl;

    // with recursion
    for(int i=0; i<n; i++){
        cout<<fib(i)<<" ";
    }

    return 0;
}

