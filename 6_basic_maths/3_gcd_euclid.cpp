#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
gcd is hcf ie highest common factor
according to euclid formula the gcd(a, b) = gcd(a-b, b) (where a>b-in every iteration) until any one of
 them is zero and the ans will be the non zero part.
or alternatively we can use gcd(a, b) = gcd(a%b, b) (where a>b-in every iteration)
This can be done either by recursion or iteratively.
*/

// done here by recursion
int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;

    if(a>b) return gcd(a-b, b);
    else return gcd(a, b-a);
}

int main(){
    int a=72, b=24;

    cout<<"gcd of a and b is: "<<gcd(a, b);

    return 0;
}

/*
ALSO THERE IS AN IMPORTANT FORMULA
GCD(A, B) * LCM(A, B) = A*B
*/