// converting a negative number to binary.
#include <iostream>
#include <cmath>

using namespace std;
int main(){
    cout<<"Enter the negative number: "<<endl;
    int n; 
    cin>>n;
    int nPositive = n-2*n;
    // cout<<nPositive;

    // now convert this positive form into binary and then find 2s complement to reverse it
    int digit, ans=0, i=0;
    while(nPositive!=0){
        digit = nPositive&1;
        ans = ans + digit*pow(10, i);
        nPositive = nPositive>>1;
        i++;
    }

    cout<<ans;
    // now for 2s complement, first find 1s complement and then add +1 to it.
    


    return 0;
}