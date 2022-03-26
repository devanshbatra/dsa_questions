// takes input an binary unsigned integer and return the number of one bits in it

#include <iostream>

using namespace std;



int main(){
    
    // slow method
    // taking a loop and then checking modulo and doing divide repeatedly
    uint32_t n, n1;
    int count=0, count1 = 0;
    cout<<"Enter the number: ";
    cin>>n;
    n1=n;
    while(n){
        if(n%10) count++;
        n/=10;
    }
    cout<<count<<endl;

    count=0;
    n=n1;


// THIS METHOD WILL WORK IF N IS DIRECTLY GIVEN NOT IN BINARY FORM
    // comparatively fast method by some bit manipulation
    // what we can do is check the last bit is one or not and start doing right shift
    // so that the last bit is removed until all are over or the number contains all 0
    while(n!=0){
        // checking last bit bby doing bitwise "and" operation
        if(n&1){
            count++;
            bool b=n&1;
            cout<<b<<endl;
        }
        n=n >> 1;
    }
    cout<<count;


    return 0;
}

