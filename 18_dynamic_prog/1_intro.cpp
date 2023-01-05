/*
Dynamic Programming: 
    solving a problem by learning from the paths and methods and applying them directly when they come later.

    We have two approached in dp:
        1) top down approach: recursion + memoization
        2) bottom up approach: tabulation.

    how to think that dp can be applied to a particular problem:
        1) A bigger problem can be solved by solving its subproblems.
        2) There is an overlapping of subproblems.

    MEMOIZATION: store the values of subproblems in a map/table.    

*/
//this is a simple fibonacci program in which if we make recursive tree then we can find out that it has 
// overlapping subproblems.

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