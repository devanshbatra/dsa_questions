#include <iostream>
#include <vector>
#include <cmath>
/*
Here we will find the factorial of a big number mod m(where m = (10^9+7) using the modular arithmetic 
properties learnt before.

In competitive programming problems, sometimes they want answer in the form of (ans)%(10^9+7), this means that the actual answer to a problem lies above the range of 64-bit integer which is not possible to calculate so they want only the remainder left behind your actual answer. 
*/
using namespace std;
    
int main(){
    int n=712;
    int m = pow(10, 9)+7;//first prime number of 10 digits.

    int res=1;
    for(int i=n; i>0; i--){
        res = (res%m*i%m)%m;
    }

    cout<<res;
    return 0;
}

/*
ALSO THERE IS AN IMPORTANT FORMULA
GCD(A, B) * LCM(A, B) = A*B
*/