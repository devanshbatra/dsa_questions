/*
   *
  **
 ***
****
for n=4
isme print valur ek to * hai aur ek " " hai
so i waale loop ke andar do for loop chlenge ek ke baad ek.

===*
==**
=***
****

*/


#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j, k;

    for(i=1; i<=n; i++){
        for(j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(k=1; k<=i; k++){
            cout<<"*";
        }
        cout<<endl;
    }

    // another of similar type
    /*
        ****
         ***
          **
           * 
           
        ****
        =***
        ==**
        ===*
    */

   for(i=1; i<=n; i++){
        // space ke liye i-1
        for(j=1; j<=i-1; j++){
            cout<<" ";
        }
        // stars ke liye n-i+1
        for(j=1; j<=n-i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}
