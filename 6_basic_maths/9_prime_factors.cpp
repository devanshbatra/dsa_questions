//find the prime factors of a number n.
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> findPrimeFactors(int n){
    vector<pair<int, int>> primeFactors;
    for(int i=2; i<=n; i++){
        int count = 0;
        while(n%i==0){
            n = n/i;
            count++;
        }
        if(count>0) primeFactors.push_back({i, count});
    }


    return primeFactors;

}

//TC: O(nlog(n)). if we consider the worst scenario that it was divided by 2 only then Nlog(N) other wise
//even lesser time than that 

//2) more optimal way.
//we will not go from n =2 to n, instead here also we will apply that sqrt(n) concept. But how,
//it was for divisors that they are in pairs. The fact is, you will have all your prime factors
//from 2 to sqrt(n) except the last one. 
//how can we say that the last number remaining is prime?
//because we tried every prime number less than sqrt(n) and repeatedly divided n by that number.
//if still something is remaining then it is a prime number.

//how can you say that only a single prime number is remaining?
//if more than one prime is remaining or more than one frequence of same prime is remaining.
//then it means our n should be equal to that prime(which is greater than sqrt(n)) * other prime(which
// is also greater than sqrt(n)).

vector<pair<int, int>> findPrimeFactors_2(int n){
    vector<pair<int, int>> primeFactors;
    for(int i=2; i*i<=n; i++){
        int count = 0;
        while(n%i==0){
            n = n/i;
            count++;
        }
        if(count>0) primeFactors.push_back({i, count});
    }

    if(n>1) primeFactors.push_back({n, 1});


    return primeFactors;

}

//TC: sqrt(n).log(n).
//sc: O(1).


int main(){
    vector<pair<int, int>> ans = findPrimeFactors_2(160);
    for(auto& i: ans) cout<<i.first<<" : "<<i.second<<endl;
}