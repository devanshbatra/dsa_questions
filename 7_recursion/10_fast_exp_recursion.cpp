#include<iostream>
#include<string>
// doing a to the power b using recursive approach
using namespace std;


// simple
int fast_exp(int a, int n){
    //base case 
    if(n==0) return 1;
    if(n==1) return a;

    int ans = fast_exp(a, n/2);

    // recursive call
    // odd case
    if(n&1) return ans*ans*2;
    else return ans*ans;
}

int main(){
    
    int a = 2, n=5;
    cout << fast_exp(a, n)<<endl;

    return 0;
}