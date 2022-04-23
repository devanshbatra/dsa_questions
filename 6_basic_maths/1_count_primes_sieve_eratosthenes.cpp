// to count the number of primes till the given number.
// https://leetcode.com/problems/count-primes/

// if we do by brute force approach then it will be n^2 time complexity and will give the

// so we use sieve of eratosthenes here
// it works on eleminating/removing our search space values before proceeding to next steps.
/*
1. make the search space and mark every number as prime 
2. ab starting 2 se shuru karo , jo prime ke table me aa rhe hai unko non prime mark kardo

*/
#include <iostream>
#include <vector>

using namespace std;



int main(){

    int n=48357;

    int count = 0;
    vector<bool> prime(n, true);
    
    for(int i=2; i<n; i++){
        if(prime[i]){
            count++;
            for(int j=2; i*j<n; j++ ){
                prime[i*j] = false;
            }
        }
    }
    
    cout<<count;

    return 0;
}

/*
time complexity - n/2 + n/3 + n/4-------
n * harmonic progression of prime numbers
==> n*log(log(n))
*/
