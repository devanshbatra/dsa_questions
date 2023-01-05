#include <iostream>
using namespace std;

int fib(int i){
    if(i==0) return 0;
    if(i==1) return 1;

    return fib(i-1)+fib(i-2);
}

int main(){

    //print fibonacci.
    int n = 8;
    for(int i=0; i<n; i++){
        cout<<fib(i)<<" ";
    }

    return 0;
}