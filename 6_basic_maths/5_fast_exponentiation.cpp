/*
Fast exponentiation is a method of performing a^b in less time complexity.
generally when we write a program to find a to the pow b: 
we iterate a loop b times and thus make the time complexity O(b)

But using fast exponentiation we can calculate the a to power b in O(log b) time
rules ==> see screenshot
a ^ b = a ^ (b/2)*2 ==> [a^(b/2)] ^ 2 for even
a ^ b = a ^ (b/2)*2 ==> [[a^(b/2)] ^ 2 ] * b for odd
we will perform the above operations either in iterative way or recursively.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// using iterative way

int main(){
    int a = 2, n=5;
    
    //to calculate a to the power n
    int res =1;
    while(n>0){
        //odd
        if(n&1){
            res = res*a;
        }
        a=a*a;
        n=n>>1; //right shift of 1 divides the number by 2 and is way less costly.
    }

    cout<<res;
    return 0;
}

// for its implementation with integer overflow and modulo arithmetics formulas refer to this question.
// https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146?leftPanelTab=1