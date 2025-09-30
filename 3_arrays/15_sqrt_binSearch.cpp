// Finding ssqrt using binary search 
// https://www.geeksforgeeks.org/problems/square-root-of-number-upto-given-precision/1
/*
we know that the ans of underroot n will lie between 0 to n
so 0 to n is our SEARCH SPACE
Now we apply bin search on 0 to n
if mid*mid > n our soln will be in 1st half do high=mid-1
if mid X mid < n ,this may be our possible  solution as we have to deal with decimals also and if root is 2.4 we 
have to return 2 only. So this is a very good approach to store this possible solution in some ans variable.
whenever we get this possible solution ans will be updated
if mid X mid = n then it is a match return it.

CONCEPT: -finding solution by minimizing the search space
*/
#include <iostream>

using namespace std;

int sqrt(int n){
    int l=0, h=n, ans = 1;
    while(l<=h){
        long long int mid = l+(h-l)/2;  //agar 2 ki pow 31 ka integer hua toh mid X mid fat jayegaisliye long long int use kiya
        if(mid * mid > n ){
            h=mid-1;
        } 
        else if(mid*mid < n){
            ans = mid;
            l=mid+1;
        }else{
            return mid;
        }
    }
    return ans;
}


// if we want precision of 2 decimals
// we found integer part, now add 0.1 continuously until ur sum*sum becomes less than given n
// for more precision add 0.01 to previous result.
double sqrt_preciseFunc(int n, double ans, int precision){ //hum ans ko double mein accept krenge
    double preciseAns = ans;//initialized with ans, taaki agar whole root aa jaye toh return mein ans he jaaye
    double factor = 1;
    for(int i=0; i<precision; i++){
        factor = factor/10;
        for(int j=0; j<9; j++){
            ans+=factor;
            if(ans*ans < n ) preciseAns = ans;
            else break;
        }
        ans = preciseAns;
    }

    return preciseAns;
    
}

int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    int integer_sqroot = sqrt(n);

    int precision = 3;
    double prec_sqrt = sqrt_preciseFunc(n, integer_sqroot, precision);
    cout<<integer_sqroot<<endl;
    cout<<prec_sqrt<<endl;

    return 0;
}