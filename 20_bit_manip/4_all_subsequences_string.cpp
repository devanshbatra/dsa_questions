//we can use bit manipulation to find all the subsequences of a string or array.
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){

    string s = "abc";
    int n= s.length();

    //since length is n so, there will be 2^n subsequences possible.
    //so we will take a bit from 0 to (2^n)-1.

    for(int bitmask = 0; bitmask<pow(2, n); bitmask++){
        string currString = ""; 
        for(int i=0; i<n; i++){
            if(bitmask & (1<<i)) currString+=s[i];
        }
        cout<<currString<<endl;
    }

    return 0;
}