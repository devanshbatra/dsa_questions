// here the problem is to find the number of primes between a given range of numbers
// we were using simple sieve of erathostenes but we need to store the whole sieve array of the size of 
// upper range , and if the upper range is greater than 10 to the power 8 then it is impossible to store such 
// big array, that is why we use segmented sieve.
// see attchd ss for explanation
/*
so in segmented sieve we just make sieve array of a small segment.
i.e. if we need to find the numbers between a to b
and it will be given that b-a will not exceed the array size limit.
1> so generate prime numbers b/w 2 to underroot b and store all primes in an array named prime.
2> make another array of size b-a with all true
3> now unmark numbers in this array using multiples of prime[].
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
void printVec(vector<T> a){
    for(auto i: a){
        cout<<i<<" ";
    }cout<<endl;
}

vector<int> simSieve(int b){
    int n = sqrt(b);
    // cout<<" entered here "<<n<<", b:  "<<b<<endl;
    vector <bool> prime(n, true);

    for(int i=2; i<n; i++){
        if(prime[i]){
            for(int j = 2; i*j<=n; j++){
                prime[i*j]=false;
            }
        }
    }
    printVec(prime);
    vector<int> ans;
    for(int i = 2; i<=n; i++){
        if(prime[i]) ans.push_back(i);
    }

    printVec(ans);
    return ans;

}

int main(){
    int a=2, b=10;

    vector<int> rootPrimes = simSieve(b);
    int range = b-a+1;
    
    vector<bool> rangePrimes(range, true);

    for(auto x: rootPrimes){
        int multiple = ceil((a*1.0)/x);
        if(multiple == 1) multiple++;

        for(int j = multiple; x*j<=b; j++){
            int index = (x*j)-a;
            rangePrimes[index]=false;
            // cout<<"making "<<x<<"*"<<j<<" as false"<<endl;
        }
    }


    // now final contains all the primes between a and b.
    // extracting primes from final
    vector<int> ans;
    for(int i=0; i< range; i++){
        if(rangePrimes[i]) ans.push_back(i+a);
    }

    printVec(ans);
    return 0;
}