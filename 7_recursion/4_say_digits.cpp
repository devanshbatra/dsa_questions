//say digits: 
/*
you have to say the digits of the given number
eg: 413 - o/p = four one three.
*/

#include <iostream>
#include <string>
using namespace std;

void sayDigit(int n){
    //base case
    if(n==0) return;

    // recursive call
    sayDigit(n/10);

    // processing
    string storage[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int digit = n%10;
    cout<<storage[digit]<<" ";

//yahan par solution reverse mein print karna tha bcoz modulus 10 karke last digit aata h. and we needed reverse
// so we used the power of tail and head recursion and done processing after rc, so that processing
// occurs after reaching the base case.
}


int main(){
    int n;
    cin>>n;

    sayDigit(n);

    return 0;
}