#include <iostream>

using namespace std;

int factorial(int n) {
    int ans=1;
    while(n>0){
        ans = ans*n;
        n--;
    }
    return ans;
}

int ncr(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){
    int a, b;
 

    return 0;
}


