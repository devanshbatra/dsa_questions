// binary to decimal
// converting a negative number to binary.
#include <iostream>
#include <cmath>

using namespace std;
int main(){
    cout<<"Enter the binary number: "<<endl;
    int n, digit, ans=0, i=0; 
    cin>>n;
    
    while(n!=0){
        // digit = n&1; //last bit agar 1 hua to return 1 else return 0
        // but uppar wala method yahan nhi lgega bcoz yahan pr 10010 as a decimal treat hoga. 
        // wo method tab use hoga jb hame string ki form mein de rakha ho binary number

        // ab lgega normal method
        digit = n%10;
        ans = ans + digit*pow(2, i);
        i++;
        // n = n>>1;
        n/=10;
    }

    cout<<ans;

    return 0;
}