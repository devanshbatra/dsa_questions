#include <iostream>
using namespace std;
/*
if number of terms n = 5
fib(5) = fib(4) + fib(3)

fib(n) = fib(n-1)+ fib(n-2)


*/
int fib(int n){
    //base case
    if(n==0) return 0;
    if(n==1) return 1;

    // recursive call
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<fib(i)<<" ";
    }

    return 0;
}