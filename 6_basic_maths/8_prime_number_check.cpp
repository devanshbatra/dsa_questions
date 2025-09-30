#include <iostream>
using namespace std;
//Check if number is prime or not
//1. brute force
//go from 2 to n-1 and check if it is divisible with any of them. 
bool isPrime_1(int n){
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}

//TC: O(N)
//SC: O(1)


//2. Optimised
//see a pattern in the divisors of any number.(they exist in a pair).

//                |-----------|      
//take 36 = 1, 2, 3, 4, 6, 9, 12, 18, 36
//          |__|________|__________|___|
//             |________|__________|

//here all the number on the left and right side of sqrt(n) are in pairs.
//that means if 2 is dividing 36 then it is definate that 18 will also divide 36, no need to check that.
//so we will just check from i=2 to i<sqrt(n) or i*i<n. If we find any divisors that means it is not prime.
bool isPrime_1(int n){
    for(int i=2; i*i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}
//TC: sqrt(n) ans SC: O(1).
