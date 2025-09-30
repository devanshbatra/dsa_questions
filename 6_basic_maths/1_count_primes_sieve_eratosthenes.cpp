// to count the number of primes till the given number.
// https://leetcode.com/problems/count-primes/

// if we do by brute force approach then it will be n^2 time complexity and will give tle

// so we use sieve of eratosthenes here
// it works on eleminating/removing our search space values before proceeding to next steps.
/*
1. make the search space and mark every number as prime 
2. ab starting 2 se shuru karo , jo prime ke table me aa rhe hai unko non prime mark kardo. 
// imp optimization: start marking non prime from square of the index you are on as usse kam
// toh ham pehle he mark kar chuke honge.

3. Another important optimization: no need to go from 2 to n. just go from 2 to sqrt(n).
    Why? We saw na in previous videos that if we disable all the composite numbers using the primes
    below sqrt(n) then after sqrt(n) only primes will remain and we have already marked them with true.
*/
#include <iostream>
#include <vector>

using namespace std;



int main(){

    int n=48357;

    int count = 0;
    vector<bool> prime(n, true);
    
    for(int i=2; (i*i)<n; i++){
        if(prime[i]){
            count++;
            for(int j=2; i*j<n; j++ ){ //optimization: start j from i*i.
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
